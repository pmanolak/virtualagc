#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Copyright:      None - the author (Ron Burkey) declares this software to
                be in the Public Domain, with no rights reserved.
Filename:       disassemblerAGC.py
Purpose:        Disassembler for an AGC core-rope image (i.e., a .binsource 
                or .bin file).  I was tempted to call this program LUY (the 
                opposite of YUL), but I've resisted the temptation.  
History:        2022-09-25 RSB  Created.
                2022-09-28 RSB  Can now find not only INTPRET, but (I think)
                                all subroutines with calling sequences like
                                TC/CADR or TC/2CADR. which I believe is just
                                BANKCALL, IBNKCALL, POSTJUMP, USPRCADR for
                                the former and NOVAC, FINDVAC for the latter.
                2022-10-05 RSB  Working for core rope, I think.
                2022-10-06 RSB  Added erasable matching.
                2022-10-07 RSB  Accounted for differences between address 
                                encoding of single-word vs double-word basic
                                instructions. Fixed encoding for interpretive
                                arguments.  Began adding --check.
                2022-10-08 RSB  Added some ordering enforcement, including
                                --hint.
                2022-10-13 RSB  I consider the Block II disassembler (but not
                                the BLK2 variant) to be working reasonably
                                well now.
                2022-10-14 RSB  Removed recursive descent entirely.
"""

#=============================================================================
# *** NOTE THAT MOST OF MY OWN MODULES ARE IMPORTED FARTHER DOWN! ***

# Standard modules.
import sys
import copy

# Some temporary code useful for debugging.
from engineering import endOfImplementation
# Parse command-line arguments.
import parseCommandLine as cli
if cli.block1:
    from auxiliaryBlockI import *
else:
    from auxiliary import *

#=============================================================================
# Initialize globals.

# Erasable contents.
erasable = []
for bank in range(numErasableBanks):
    erasable.append([-1]*sizeErasableBank)

# Core-rope contents.
unusedCore = -1
core = []
for bank in range(numCoreBanks):
    core.append([unusedCore]*sizeCoreBank)

# i/o channel contents
iochannels = [-1]*numIoChannels

# Disassembly contents.  There's one entry for each word of core, representing
# the disassembled form of that word.  The entries are tuples having the 
# following formats:
# For basic instructions:           (Opcode, Operand|"")
# For basic data:                   ("", Data)
# For interpretive, 2 instructions: (False, Instruction1, Instruction2)
# For interpretive, 1 instruction:  (False, Instruction, "")
# For interpretive, operand only:   (False, "", Operand)
# For interpretive, store:          (False, StoreInstruction, Address)
# In particular, basic vs interpretive is determined by 2-tuples vs 3-tuples.
unusedDisassembly = ()
disassembly = []
for bank in range(numCoreBanks):
    disassembly.append([unusedDisassembly]*sizeCoreBank)

#=============================================================================
# *** IMPORT REMAINDER OF MY OWN MODULES ***.  

# Reader for .bin/.binsource files.
from readCoreRope import readCoreRope
# Disassembler for a single basic instruction.
if cli.block1:
    from disassembleBasicBlockI import disassembleBasic
elif cli.blk2:
    from disassembleBasicBLK2 import disassembleBasic
else:
    from disassembleBasic import disassembleBasic
# Disassembler for a single line of interpreter instructions plus arguments.
if cli.block1:
    from disassembleInterpretiveBlockI import disassembleInterpretive, interpretiveStart
else:
    from disassembleInterpretive import disassembleInterpretive, interpretiveStart
# Semi-emulation of instruction operations on erasable.
from semulate import semulate
# Search for "special" subroutines like INTPRET and BANKCALL.
if cli.block1:
    from searchSpecialBlockI import searchPatterns
else:
    from searchSpecial import searchPatterns
from searchFunctions import importFlexFile, searchSpecial, specialSubroutines

# If necessary, import patterns from a file specified by the --flex
# command-line switch, and append them to the searchPatterns dictionary
# above prior to searching for the special subroutines.
if cli.flexFilename != "":
    importFlexFile(cli.flexFilename, searchPatterns)

#=============================================================================
# Read the input file.

readCoreRope(core, cli, numCoreBanks, sizeCoreBank)

#=============================================================================
# Read the --check file.

checkErasable = {}
checkCore = {}
underline = "------------"
divider = "=============================="
def addCheckSymbol(line, offset0, offset1, offset2):
    global checkErasable, checkCore
    fields = line.strip().split()
    while underline in fields:
        fields.remove(underline)
    while divider in fields:
        fields.remove(divider)
    for i in range(0, len(fields), 3):
        if "E" not in fields[i] and "F" not in fields[i]:
            continue
        symbol = fields[i+1].strip().replace("'", "!")
        address = fields[i+2].strip()
        addressFields = address.split(",")
        if len(addressFields) == 1:
            value = int(addressFields[0], 8)
            if value < 0o1400:
                bank = value // sizeErasableBank
                offset = value % sizeErasableBank
                checkErasable[symbol] = (bank, offset)
            else:
                bank = value // sizeCoreBank
                offset = value % sizeCoreBank
                checkCore[symbol] = (bank, offset)
        else:
            offset = int(addressFields[1], 8)
            if addressFields[0][0] == "E":
                bank = int(addressFields[0][1:], 8)
                checkErasable[symbol] = (bank, offset % sizeErasableBank)
            else:        
                bank = int(addressFields[0], 8)
                checkCore[symbol] = (bank, offset % sizeCoreBank)

if cli.checkFilename != "":
    f = open(cli.checkFilename, "r")
    inSymbols = False
    for line in f:
        if line[:12] == "Symbol Table":
            inSymbols = True
            continue
        if "Unresolved symbols" == line[:18]:
            inSymbols = False
            continue
        if not inSymbols:
            continue
        if line[:2] != "  ":
            continue
        addCheckSymbol(line, 7, 12, 25)
        addCheckSymbol(line, 55, 60, 73)
        addCheckSymbol(line, 103, 108, 121)   
    f.close

#=============================================================================
# Search for special symbols like INTPRET, BANKCALL, ....  Their addresses
# will be stored as specialSubroutines["INTPRET"] (and so on).

searchSpecial(core, searchPatterns, disassembleBasic)

if cli.findFilename != "":
    print("┌─────────────────────────────────────────────────────────────────┐")
    print('│ Matches for "special" symbols or --flex symbols appear below.   │')
    print("│ Note: The special symbols found here match some AGC version,    │")
    print("│ but may not match the selected baseline.  Matches vs the        │")
    print("│ specific baseline may appear later, in the core section.        │")
    print("└─────────────────────────────────────────────────────────────────┘")
specialFixedFixed = {}
for symbol in sorted(specialSubroutines):
    addressTuple = specialSubroutines[symbol]
    bank = addressTuple[0]
    address = addressTuple[1]
    addressString, fAddress = getAddressString(bank, address)
    if cli.specialOnly or cli.findFilename != "":
        print("%-8s = %s" % (symbol, addressString))
    if fAddress != -1:
        specialFixedFixed[fAddress] = addressTuple

INTPRET = specialSubroutines["INTPRET"][2]

if cli.specialOnly:
    sys.exit(0)

#=============================================================================
# Auxiliary functions.

# For instructions like "TC SYMBOL", tries to determine how many data words 
# follow the TC ... e.g., if the invocation is
#
#           TC      SYMBOL
#           OCT     ...
#           ...
#           OCT     ...
#
# the question being answered is "How many OCTs are there?"  Usually there are
# 0, of course, but for the various "special subroutines" searched for above,
# there's often a fixed number of 1 or 2 OCTs.  However, there are also weird
# cases among the special subroutines (POLY, PHASCHNG, ...) where the number
# of OCTs is variable, and has to be determined by explicitly parsing the next
# word(s) immediately following the TC.  That's what the following function.
# does. Comanche 055 is taken as the official documentation for figuring this
# out.
def getDataWords(core, bank, offset, symbol, dataWords):
    offset += 1
    if symbol == "POLY":
        # The data words are the SP degree and the DP
        # coefficients of the polynomial.
        degree = core[bank][offset]
        dataWords = 1 + 2 * (degree + 1)
    elif symbol in ["PHASCHNG", "2PHSCHNG"]:
        dataWords = 1 # Will increment below in various ways.
        if symbol == "2PHSCHNG":
            dataWords += 1
            offset += 1
        firstWord = core[bank][offset]
        phasechangeType = (firstWord & 0o14000) >> 11
        A = firstWord & 0o02000
        if phasechangeType == 0: # "type A"
            D = 0
        elif phasechangeType == 1: # "type C"
            D = firstWord & 0o01000
        else: # phasechangeType == 2 or 3, "type B"
            D = firstWord & 0o04000
        if D > 0:
            dataWords += 1
        if A > 0:
            dataWords += 2
    return dataWords

# Disassemble a memory range, which can include any combination of basic
# and interpreter instructions.  But cannot contain data, unless it's
# related the the case of a TC to a special function that requires data
# word(s) immediately following the TC.  The parameters are:
#   core, erasable, iochannels are (usually) the global structures of the
#               same name.  For recursive use of disassembleRange, though,
#               local copies of erasable and iochannels are used instead.
#               Basically, they are only used by the response function (see
#               below), and then only if the response function calls 
#               semulate().  In other words, if the response function does 
#               not use semulate(), then erasable and iochannels could be 
#               set to anything (such as an integer), in order to minimize 
#               execution time and memory usage.
#   bank        The memory-bank number.
#   start       Starting address within the bank.  This is the 4-digit part
#               of the address (2000-7777) as it would appear in fixed-fixed
#               (4000-7777) or fixed (XX,2000-XX,3777), and not the offset
#               (0000-1777) into the bank.  Disassembling erasable is not
#               supported.
#   end         Stop when reaching this address.  I.e., end-1 is
#               the last address actually disassembled.
#   response    A function to be executed after each location is
#               disassembled.  Such a function has parameters:
#                   core, erasable, iochannels (as above)
#                   occasion    0 - octal, 1 - basic, 2 - interpretive.
#                   bank        (as above)
#                   address     (as in start, end above)
#                   left        The opcode for basic, or left opcode 
#                               for interpretive.
#                   right       The operand for basic, or right opcode
#                               or argument for interpretive.
#               The response function returns True if it wants the
#               the disassembly to end (if, for example, it is performing
#               pattern matches and has succeeded in finding a match), but
#               in general returns False.
#   inBasic     Boolean. True if the first address is a basic
#               instruction, False if the first address is
#               interpretive.
#   autoQuit    Boolean. True if should quit prior to reaching the selected
#               end address when reaching a TCF or a TC that is believed
#               not to return, or other similar conditions in which there
#               is reason to believe that the next address won't contain
#               disassemblable code. 
#   autoCCS     Boolean.  The CCS instruction is problematic in regard to 
#               autoQuit=True; the 4 successive locations are typically all
#               basic code, but sometimes they are not.  For maximal 
#               prudence, therefore, we should immediately quit upon
#               encountering any CCS (autoCCS=True).  For typical 
#               scenarios (autoCCS=False), on the other hand, not only would 
#               we not want to quit upon finding a CCS, but indeed would not 
#               want to quit on TCF instructions in the 3 words immediately 
#               following the CCS ... but would still want to quit for a TCF
#               in the fourth word.
# The disassembleRange() function returns False, unless it terminates early
# due to a response function, in which case it returns True.

def disassembleRange(core, erasableOnEntry, iochannelsOnEntry, bank, start, 
                     end, response, inBasic=True, autoQuit=False,
                     autoCCS=False):
    erasable = copy.deepcopy(erasableOnEntry)
    iochannels = copy.deepcopy(iochannelsOnEntry)
    dataWords = 0
    extended = 0
    state = interpretiveStart()
    address = start
    sinceCCS = 10
    while address < end:
        offset = address % sizeCoreBank
        if dataWords > 0:
            if response(core, erasable, iochannels, 0, bank, address, "OCT", 
                    "%05o" % core[bank][offset]):
                return True
            dataWords -= 1
            address += 1
            continue
        if inBasic:
            noReturn = False
            opcode, operand, extended = \
                disassembleBasic(core[bank][offset], extended)
            try:
                nOperand = int(operand, 8)
            except:
                nOperand = -1
            if opcode == "TC" and nOperand in specialFixedFixed:
                    searchPattern = specialFixedFixed[nOperand][3]
                    symbol = specialFixedFixed[nOperand][4]
                    operand = symbol
                    noReturn = searchPattern["noReturn"]
                    dataWords = getDataWords(core, bank, offset, symbol, 
                                             searchPattern["dataWords"])
                    if symbol == "INTPRET":
                        inBasic = False
            if response(core, erasable, iochannels, 
                     1, bank, address, opcode, operand):
                return True
            address += 1
            
            if autoQuit:
                # Quit prematurely if we can't predict that the next
                # address will contain code, or what type of code it is,
                # due to a transfer of control. Conditional branches, 
                # by the way, are no problem.
                
                sinceCCS += 1
                
                if opcode in ["RETURN", "RESUME"]:
                    break
                # Various other instructions for which I decline to predict
                # the behavior vis-a-vis transfer of control.
                elif opcode in ["DTCB", "DTCF", "EDRUPT", 
                                "TCAA", "XLQ", "XXALQ"]:
                    break
                # Is a TC to a "special function" known not to return?
                elif opcode == "TC" and noReturn:
                    break
                # A TCF instruction does not return.  However, there are
                # exceptions to consider:  In a jump table, there will be
                # a long series of TCF instructions, on which we shouldn't
                # quit.  Also, TCFs in the 3-word shadow of a CCS shouldn't
                # be cause to quit.
                elif opcode == "TCF":
                    if sinceCCS > 3:
                        dummyOpcode, dummyOperand, dummyExtended = \
                            disassembleBasic(core[bank][offset+1], extended)
                        if dummyOpcode != "TCF":
                            break
                # CCS
                elif opcode == "CCS":
                    if autoCCS:
                        break
                    else:
                        sinceCCS = 0
        else:
            disassembly, inBasic = \
                disassembleInterpretive(core, bank, offset, state)
            for entry in disassembly:
                left = entry[0]
                right = entry[1]
                argument = entry[2]
                if right == "":
                    right = argument
                if response(core, erasable, iochannels,
                         2, bank, address, left, right):
                    return True
                offset += 1
                address += 1
    return False
    
#=============================================================================
# Perform some options (based on command-line settings), which bypass
# all of the normal disassembly workflow and then exit.

# Command-line switch:  --dump
if cli.dump:
    if cli.block1:
        bankList = range(startingCoreBank, numCoreBanks)
    else:
        bankList = [2, 3, 0, 1] + list(range(4, numCoreBanks))
    for bank in bankList:
        print()
        print("BANK=%o" % bank)
        for row in range(128):
            if row % 4 == 0:
                print()
            if row % 32 == 0:
                if row > 0:
                    print(";")
                    print()
            line = ""
            for col in range(8):
                o = core[bank][8 * row + col]
                if o == unusedCore:
                    line += "  @   "
                else:
                    line += "%05o " % o
            print(line)
    sys.exit(0)

# Command-line switch:  --specs

# Converts an opcode,operand pair into a pattern for pattern matching.
# The occasion parameter is 0 for data, 1 for basic, 2 for interpretive.
def patternize(occasion, opcode, operand):
    if occasion == 0:
        pattern = "_"
    else:
        pattern = opcode + "_"
        # Recognize operands we have to ignore, which are
        # NNNN or NN,NNNN.
        fields = operand.split(",")
        if not fields[0].isdigit() or \
                (len(fields) > 1 and not fields[1].isdigit()):
            pattern += operand
    return pattern

if cli.specsFilename != "":

    # A response function for disassembleRange().
    def printSpec(core, erasable, iochannels,
                  occasion, bank, address, opcode, operand):
        print("\t" + patternize(occasion, opcode, operand))
        return False

    # First, read the entire specifications file selected on the
    # command line into memory as the patternSpecs list.
    f = open(cli.specsFilename, "r")
    patternSpecs = []
    erasableSpecs = []
    lastBank = 0
    for line in f:
        fields = line.upper().split("#")[0].strip().split()
        if len(fields) == 0:
            continue
        if fields[0] not in [ "+", "-" ] and fields[1] != "=": # Spec for core
            for i in range(len(fields)):
                # Remove any extraneous comma at the end of the field.
                if fields[i][-1:] == "," and fields[i][:-1].isdigit():
                    fields[i] = fields[i][:-1]
                if fields[i].isdigit():
                    fields[i] = int(fields[i], 8) % sizeCoreBank
            if fields[1] == ".":
                fields[1] = lastBank
            elif isinstance(fields[1], int):
                lastBank = fields[1]
            patternSpec = { "symbol": fields[0], "dbank": fields[1], 
                            "dstart": fields[2], "inBasic": True}
            for i in range(3, len(fields)):
                if fields[i] == "I":
                    patternSpec["inBasic"] = False
                elif isinstance(fields[i], int):
                    patternSpec["dend"] = fields[i]
            patternSpecs.append(patternSpec)
        elif len(fields) in [3, 5]:  # Spec for erasable or program label aliases.
            erasableSpecs.append(line.strip())
    f.close()

    for i in range(len(patternSpecs)):
        if "dend" not in patternSpecs[i]:
            patternSpecs[i]["dend"] = patternSpecs[i+1]["dstart"]
            
    # Now iterate through all of the different specification in the 
    # patternSpecs list, forming patterns suitable for pattern-matching.
    for patternSpec in patternSpecs:
        symbol = patternSpec["symbol"]
        if patternSpec["inBasic"]:
            print(symbol, "basic")
        else:
            print(symbol, "interpretive")
        disassembleRange(core, erasable, iochannels,
                         patternSpec["dbank"], patternSpec["dstart"], 
                         patternSpec["dend"], printSpec, 
                         patternSpec["inBasic"])
    # And write out the erasable specs, which we're just passing through
    # as-is:
    for spec in erasableSpecs:
        print(spec)
    sys.exit(0)

# Command-line switch:  --pattern
if cli.pattern:
    indent = '                '
    
    # A response function for disassembleRange().
    def printPattern(core, erasable, iochannels,
                     occasion, bank, address, opcode, operand):
        operandString = '"' + operand + '"'
        if len(operand) == 4 and operand.isdigit():
            operandString = ''
        print(indent + '        [True, ["%s"], [%s]],' % \
              (opcode, operandString))
        return False
    
    print('    "%s": [{' % cli.symbol)
    print(indent + '    "dataWords": 0,')
    print(indent + '    "noReturn": False,')
    print(indent + '    "pattern": [')
    disassembleRange(core, erasable, iochannels, 
                     cli.dbank, cli.dstart, cli.dend, printPattern, 
                     cli.dbasic)
    print(indent + '     ],')
    print(indent + '    "ranges": [[0o%02o, 0o0000, 0o%04o]]' \
                        % (cli.dbank, sizeCoreBank))
    print(indent + '}],')
    sys.exit(0)

# Command-line switch:  --dtest
if cli.dtest:

    # A response function for disassembleRange().
    def printDisassembly(core, erasable, iochannels,
                         occasion, bank, address, left, right):
        print("%02o,%04o    %05o         %-12s %s" \
              % (bank, address, core[bank][address % sizeCoreBank], left, right))
        return False
    
    disassembleRange(core, erasable, iochannels,
                     cli.dbank, cli.dstart, cli.dend, printDisassembly, 
                     cli.dbasic)
    sys.exit(0)
    
# Command-line switch:  --find
if cli.findFilename != "":

    # In the specs file and internally for this matching process, symbol names
    # that are supposed to contain an apostrophe have an exclamation point 
    # instead.  The following function is used to reverse this in symbols as
    # they're printed out.
    def norm(symbol):
        return symbol.replace("!", "'")

    # First step: Read in the entire pattern file into the dictionaries
    # desiredMatches
    erasableSpecs = []
    programLabelAliasSpecs = {}
    fixedReferences = {}
    desiredMatches = { "basic": {}, "interpretive": {}}
    maxPatternLength = { "basic": 0, "interpretive": 0}
    basicOrInterpretive = "(none)"
    symbol = "(none)"
    desiredOrdering = { "basic": [], "interpretive": [] }
    programAliases = set()

    f = open(cli.findFilename, "r")
    for line in f:
        fields = line.strip().split()
        if len(fields) < 1:
            continue
        if fields[0] == "+": # Erasable specs
            symbols = \
                fields[1].replace("['", "").replace("']", "").split("','")
            references = fields[2].replace("[(", "").replace(")]", "")
            references = references.split("),(")
            for i in range(len(references)):
                references[i] = references[i][1:-1]
                r1 = references[i].split("',")
                r2 = r1[1].split(",'")
                references[i] = (r1[0], int(r2[0]), r2[1])
            erasableSpecs.append({  "symbols": symbols,
                                    "references": references,
                                    "referencedAddresses": [] })
        elif fields[0] == "-": # Specs for references to fixed.
            referencedSymbol = fields[1]
            if referencedSymbol not in fixedReferences:
                fixedReferences[referencedSymbol] = []
            fixedReferences[referencedSymbol].append( 
                (fields[2], int(fields[3], 8), fields[4])
            )
            
        elif len(fields) > 1 and fields[1] == "=": # Program label alias specs
            if fields[2] not in programLabelAliasSpecs:
                programLabelAliasSpecs[fields[2]] = []
            programLabelAliasSpecs[fields[2]].append((int(fields[4], 8), 
                                                          fields[0]))
            programAliases.add(fields[0])
        elif line[:1] != '\t': # Core rope specs
            symbol = fields[0]
            basicOrInterpretive = fields[1]
            desiredMatches[basicOrInterpretive][symbol] = []
            desiredOrdering[basicOrInterpretive].append(symbol)
        else:
            desiredMatches[basicOrInterpretive][symbol].append(line.strip())
    for symbol in cli.ignore:
        for basicOrInterpretive in ["basic", "interpretive"]:
            if symbol in desiredMatches[basicOrInterpretive]:
                desiredMatches[basicOrInterpretive].pop(symbol)
                desiredOrdering[basicOrInterpretive].remove(symbol)
    f.close()
    for basicOrInterpretive in ["basic", "interpretive"]:
        for symbol in desiredMatches[basicOrInterpretive]:
            if len(desiredMatches[basicOrInterpretive][symbol]) \
                    > maxPatternLength[basicOrInterpretive]:
                maxPatternLength[basicOrInterpretive] \
                    = len(desiredMatches[basicOrInterpretive][symbol])
            if False:
                print(symbol, basicOrInterpretive, 
                    desiredMatches[basicOrInterpretive][symbol])
    symbolsSought = { "basic": desiredMatches["basic"].keys(),
                      "interpretive": desiredMatches["interpretive"].keys()}
    symbolsFound = { "basic": {}, "interpretive": {}}
    
    print("┌─────────────────────────────────────────────────────────────────┐")
    print("│ Matches of the core rope vs the specific baseline appear below. │")
    print("│ Note:  Symbols of the form 'Rbb,aaaa' do not appear in baseline │")
    print("│ source code.  They apply to code that is unlabeled in the       │")
    print("│ baseline but that immediately succeeds data.                    │")
    print("└─────────────────────────────────────────────────────────────────┘")

    # Next, try to find these patterns in core.  This is entirely a
    # brute-force procedure which does not rely on recursive disassembly.
    # We simply go to each location in every memory bank, and start 
    # disassembling until we either find one of the patterns or else 
    # can eliminate all of them, at which point we move on to the next
    # location.
    
    coreUsed = []
    for bank in range(numCoreBanks):
        coreUsed.append([False]*sizeCoreBank)
    
    # Response function for disassembleRange().
    symbols = []
    indexIntoPatterns = 0
    basicOrInterpretive = "basic"
    def match(core, erasable, iochannels,
                  occasion, bank, address, opcode, operand):
        global symbols, indexIntoPatterns, cli
          
        # Turn current disassembled location into a pattern.
        pattern = patternize(occasion, opcode, operand)
        
        # Now try to match the pattern with those read from the specs file.
        if cli.disjoint and coreUsed[bank][address % sizeCoreBank]:
            symbols = []
        if len(symbols) == 0:
            #print("I am here")
            return True
        forElimination = []
        for symbol in symbols:
            desiredPatterns = desiredMatches[basicOrInterpretive][symbol]
            if len(desiredPatterns) <= indexIntoPatterns:
                print("Implementation error A", "%02o" % bank, 
                    "%04o" % address, symbol, indexIntoPatterns, 
                    len(desiredPatterns), desiredPatterns)
                sys.exit(1)
            desiredPattern = desiredPatterns[indexIntoPatterns]
            if desiredPattern != pattern:
                forElimination.append(symbol)
            elif indexIntoPatterns == len(desiredPatterns) - 1:
                # Match!  However, if it's one of those symbols we're
                # supposed to skip the initial matches for, then let's do
                # that instead.
                if symbol not in cli.skips \
                        or cli.skips[symbol] == 0:
                    symbols = [symbol]
                    return True
                else:
                    cli.skips[symbol] -= 1
                    forElimination.append(symbol)
        for symbol in forElimination:
            symbols.remove(symbol)
        indexIntoPatterns += 1
        return False
    
    if len(cli.oBanks) > 0:
        findBanks = cli.oBanks.split(",")
        for i in range(len(findBanks)):
            findBanks[i] = int(findBanks[i], 8)
    else:
        findBanks = list(range(numCoreBanks))
    if len(cli.pBanks) > 0:
        dummy = cli.pBanks.split(",")
        for i in range(len(dummy)):
            dummy[i] = int(dummy[i], 8)
            findBanks.remove(dummy[i])
        findBanks = dummy + findBanks
    for bank in findBanks:
        #print("# Match bank %02o." % bank)
        for address in range(sizeCoreBank, sizeCoreBank + sizeCoreBank):
            avoiding = False
            for avoid in cli.avoid:
                if bank == avoid[0] and address >= avoid[1] \
                        and address < avoid[2]:
                    avoiding = True
                    break
            if avoiding:
                continue
            for basicOrInterpretive in ["basic", "interpretive"]:
                inBasic = (basicOrInterpretive == "basic")
                if len(symbolsSought[basicOrInterpretive]) == 0:
                    break
                if len(symbolsSought[basicOrInterpretive]) == 0:
                    break
                if cli.disjoint and coreUsed[bank][address % sizeCoreBank]:
                    continue
                symbols = []
                for symbol in desiredOrdering[basicOrInterpretive]:
                    ok = True
                    if symbol in cli.hintAfter:
                        for before in cli.hintAfter[symbol]:
                            if before in desiredOrdering["basic"] or \
                                    before in desiredOrdering["interpretive"]:
                                ok = False
                                break
                    if ok:
                        symbols.append(symbol)
                indexIntoPatterns = 0
                end = address + maxPatternLength[basicOrInterpretive]
                if end > sizeCoreBank + sizeCoreBank:
                    end = sizeCoreBank + sizeCoreBank
                if disassembleRange(core, erasable, iochannels,
                                 bank, address, end, match, 
                                 inBasic):
                    # If a match has been found at this address,
                    # the symbols list should now contain a
                    # single entry, which is the name of the
                    # match.  Otherwise, it should be the case
                    # that the symbols list is now empty.
                    if len(symbols) > 1:
                        print("Implementation error B")
                        sys.exit(1)
                    elif len(symbols) == 0:
                        continue
                    symbol = symbols[0]
                    symbolsFound[basicOrInterpretive][symbol] \
                        = (bank, address)
                    endAddress = address + \
                        len(desiredMatches[basicOrInterpretive][symbol])
                    for a in range(address, endAddress):
                        if False and bank == 0o16 and a >=0o2504 and a < 0o2520:
                            print(symbol, "overwriting %02o,%04o" % (bank, a))
                        coreUsed[bank][a % sizeCoreBank] = True
                    del desiredMatches[basicOrInterpretive][symbol]
                    desiredOrdering[basicOrInterpretive].remove(symbol)
                    symbolsSought = { 
                        "basic": desiredMatches["basic"].keys(),
                        "interpretive": desiredMatches["interpretive"].keys()
                        }
                    nSymbol = norm(symbol)
                    addressString, fAddress = getAddressString(bank, address)
                    print("%-8s = %s" % (nSymbol, addressString))
                    if nSymbol in programLabelAliasSpecs:
                        for spec in programLabelAliasSpecs[nSymbol]:
                            addressString, fAddress = \
                                getAddressString(bank, address + spec[0])
                            print("%-8s = %s" % (spec[1], addressString))
                            symbolsFound[basicOrInterpretive][spec[1]] = \
                                (bank, address + spec[0])
                            
    #print("symbolsFound =", symbolsFound)
    #print("symbolsSought =", symbolsSought)
        
    if cli.debugLevel == 0:
        # At this point, the program labels have undergone matching.  We'd now
        # like to use the results of those matches for erasable matching as well.
        # The idea is that each erasable symbol defined in baseline erasable, we
        # have a list of the subroutines that reference them, and the lines of
        # the subroutine that do so.  For any of those subroutines that have been
        # matched above, we can go to those lines of the subroutines in the 
        # rope dump and find the address being used.  If it's the same address
        # for all of the references, then we can assume that that's the address
        # associated with that particular erasable symbol in the rope dump.
        foundErasables = {}
        print("┌─────────────────────────────────────────────────────────────────┐")
        print("│ Matches for variables in erasable memory appear below.          │")
        print("└─────────────────────────────────────────────────────────────────┘")
        totalCertainErasables = 0
        totalUncertainErasables = 0
        totalUnreferencedErasables = 0
        for spec in erasableSpecs:
            symbols = spec["symbols"]
            references = spec["references"]
            for reference in references:
                programLabel = reference[0]
                if programLabel in symbolsFound["basic"]:
                    location = symbolsFound["basic"][programLabel]
                    foundBasic = True
                elif programLabel in symbolsFound["interpretive"]:
                    location = symbolsFound["interpretive"][programLabel]
                    foundBasic = False
                else:
                    spec["referencedAddresses"].append("(none)")
                    continue
                bank = location[0]
                lineNumber = reference[1]
                address = location[1] + lineNumber
                referenceType = reference[2]
                context = core[bank][address % sizeCoreBank]
                if referenceType in ["B", "C", "D"]:
                    if referenceType == 'C':
                        context = ~context
                    elif referenceType == 'D':
                        context -= 1
                    context &= 0o1777
                    if context < 0o1400:
                        referenced1 = context // sizeErasableBank
                        referenced2 = 0o1400 + (context % sizeErasableBank)
                        referencedAddress = "E%o,%04o" % (referenced1, referenced2)
                    else:
                        referenced2 = 0o1400 + (context % sizeErasableBank)
                        referencedAddress = "E?,%04o" % referenced2
                elif referenceType in ['S', 'A', 'L', 'I', 'E', 'H']:
                    if referenceType == 'I':
                        context = ~context
                    if referenceType not in ['L', 'E', 'H']:
                        context -= 1
                    context &= 0o3777
                    referenced1 = context // sizeErasableBank
                    referenced2 = 0o1400 + (context % sizeErasableBank)
                    if referenceType == 'E' and context > 0o03:
                        referencedAddress = "E?,%04o" % referenced2
                    else:
                        referencedAddress = "E%o,%04o" % (referenced1, referenced2)  
                spec["referencedAddresses"].append(referencedAddress)
            # Information about all code references to this erasable symbol
            # collected.  We now have to perform some statistics to decide
            # what we can report about what address we can report for this
            # symbol.
            sSymbols = str(sorted(symbols)).replace("[", "").replace("]", "")
            sSymbols = sSymbols.replace("'", "").replace(", ", " = ")
            stats = {}
            for i in range(len(spec["references"])):
                programLabel = spec["references"][i]
                a = spec["referencedAddresses"][i]
                if a == "(none)":
                    continue
                if a not in stats:
                    stats[a] = [programLabel]
                else:
                    stats[a].append(programLabel)
            keys = list(stats.keys())
            certain = False
            if len(keys) == 1:
                certain = True
                chosen = keys[0]
            elif len(keys) == 2:
                if (keys[0][1] == "?" or keys[1][1] == "?") \
                        and keys[0][2:] == keys[1][2:]:
                    if keys[0][1].isdigit():
                        chosen = keys[0]
                    else:
                        chosen = keys[1]
                    certain = True 
                else:
                    chosen = "E?,????" 
            else:
                chosen = "E?,????"
            total = 0
            for stat in stats:
                total += len(stats[stat])
            if not certain:
                if total == 0:
                    if False:
                        print("┌─────────────────────────────────────────────────────────────────┐")
                        print("│ Unable to detect references to the following variable.          │")
                        print("└─────────────────────────────────────────────────────────────────┘")
                else:
                    print("┌─────────────────────────────────────────────────────────────────┐")
                    print("│ Discrepancies for review:                                       │")
                    for stat in stats:
                        msg = stat + ":"
                        for p in stats[stat]:
                            if len(msg) > 48:
                                print("│ %-63s │" % msg)
                                msg = "        "
                            msg += "  %s +%o" % (norm(p[0]), p[1])
                        print("│ %-63s │" % msg)
                    print("└─────────────────────────────────────────────────────────────────┘")
            elif chosen[:3] in ["E0,", "E1,", "E2,"]:
                bank = int(chosen[1], 8)
                address = int(chosen[3:], 8)
                chosen = "%04o (%s)" % (sizeErasableBank * bank + address % sizeErasableBank, chosen)
            if chosen != "E?,????":
                for symbol in symbols:
                    foundErasables[symbol] = chosen
            if total != 0:
                print("%-8s" % norm(sSymbols), "=", chosen, "(%d references)" % total)
            if total == 0:
                totalUnreferencedErasables += 1
            elif certain:
                totalCertainErasables += 1
            else:
                totalUncertainErasables += 1
         
        print("┌─────────────────────────────────────────────────────────────────┐")
        print("│ Matches for references to fixed memory appear below.            │")
        print("└─────────────────────────────────────────────────────────────────┘")
        # Quick pass to get a list of all the references.
        observedReferences = {}
        fixedFound = {}
        for referencedSymbol in sorted(fixedReferences):
            if referencedSymbol in symbolsFound["basic"] or \
                    referencedSymbol in symbolsFound["interpretive"] or \
                    referencedSymbol in programAliases:
                continue
            for references in fixedReferences[referencedSymbol]:
                referringSymbol = references[0]
                offsetFromReferrer = references[1]
                referenceType = references[2]
                if referringSymbol in symbolsFound["basic"]:
                    location = symbolsFound["basic"][referringSymbol]
                elif referringSymbol in symbolsFound["interpretive"]:
                    location = symbolsFound["interpretive"][referringSymbol]
                else:
                    continue
                if referencedSymbol not in observedReferences:
                    observedReferences[referencedSymbol] = []
                bank = location[0]
                offset = (location[1] + offsetFromReferrer) % sizeCoreBank
                context = core[bank][offset]
                if referenceType in ['B', 'D']:
                    address12 = context & 0o7777
                    if referenceType == 'D':
                        address12 -= 1
                    if address12 < sizeCoreBank:
                        continue
                    if address < 0o4000:
                        observedReferences[referencedSymbol].append(["??", 
                            address12 % sizeCoreBank, references])
                    else:
                        observedReferences[referencedSymbol].append([
                            address12 // sizeCoreBank, 
                            address12 % sizeCoreBank, references])
                elif referenceType in ['S', 'A', 'L', 'I', 'E', 'H', 'K']:
                    if referenceType == 'I' or \
                            (referenceType == 'K' and (context & 0o40000) != 0):
                        context = ~context
                    if referenceType not in ['L', 'E', 'H']:
                        context -= 1
                    context &= 0o77777
                    if bank >= 0o20 and referenceType != 'L':
                        context |= 0o40000
                    if bank >= 0o40:
                        context += 0o20000
                    observedReferences[referencedSymbol].append([
                        context // sizeCoreBank, context % sizeCoreBank, references]) 
        # Final pass to check for consistency and print report.
        for referencedSymbol in sorted(observedReferences):
            references = observedReferences[referencedSymbol]
            referencesByAddress = {}
            for reference in references:
                referencingSymbol = reference[2]
                offsetWithinReference = reference[2][1]
                if reference[0] == "??":
                    context = "??"
                else:
                    context = "%02o" % reference[0]
                context += ",%04o" % reference[1]
                if context not in referencesByAddress:
                    referencesByAddress[context] = {}
                if referencingSymbol not in referencesByAddress[context]:
                    referencesByAddress[context][referencingSymbol] = []
                referencesByAddress[context][referencingSymbol].append(offsetWithinReference)
            keys = list(referencesByAddress.keys())
            if len(keys) == 0:
                continue
            elif len(keys) == 1:
                context = keys[0]
                fields = context.split(",")
                sBank = fields[0]
                if sBank == "??":
                    bank = sBank
                else:
                    bank = int(sBank, 8)
                add = int(fields[1], 8) + sizeCoreBank
                print("%-8s = %s,%04o (%d references)" % (referencedSymbol, \
                                                sBank, add, len(references)))  
                fixedFound[referencedSymbol] = (bank, add)
            elif len(keys) == 2 and (keys[0][-4:] == keys[1][-4:]):
                context = keys[0]
                fields = context.split(",")
                sBank = fields[0]
                if sBank == "??":
                    bank = sBank
                else:
                    bank = int(sBank, 8)
                add = int(fields[1], 8) % sizeCoreBank + sizeCoreBank
                print("%-8s = ??,%04o (%d references)" % (referencedSymbol, \
                                                add, len(references)))  
                fixedFound[referencedSymbol] = (bank, add)
            else:
                for a in sorted(referencesByAddress):
                    try:
                        print("# %s" % a)    
                    except:
                        print(a, file=sys.stderr)
                        sys.exit(1)
                print("%s = ??,???? (%d references)" % (referencedSymbol, len(references)))
    
    print()
    print("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━")
    print("Summary of the match process.")
    print()
    print('Note: A "match" occurs when separate means of identifying the')
    print("location of a label produce identical bank numbers and offsets.")
    print('"Consistency" differs, in that the offsets into the banks are all')
    print("identical, but that some bank numbers may have been indeterminate.")
    print("For example:")
    print("                 01,2345 matches 01,2345")
    print("            ??,2345 is consistent with 01,2345")
    print("       01,2345 mismatches 02,2345, 01,2346, and ??,2346")
    print()
    print("Special symbols:")
    found = 0
    notFound = 0
    for symbol in sorted(specialSubroutines):
        addressTuple = specialSubroutines[symbol]
        bank = addressTuple[0]
        address = addressTuple[1]
        fAddress = addressTuple[2]
        if fAddress == -1 and (bank == -1 or address == -1):
            print("%-8s" % norm(symbol), "not found")
            notFound += 1
        else:
            found += 1
    print("Total matched:", found)
    print("Total unmatched:", notFound)
    if notFound:
        print()
        print("Note: Special symbols are matched using generalized patterns")
        print("which attempt to be AGC-version agnostic, so unmatched special")
        print("symbols above are indicative neither of the symbols")
        print("necessarily being absent nor of a serious problem.")
    print()
    print("Core:")
    for basicOrInterpretive in ["basic", "interpretive"]:
        for symbol in symbolsSought[basicOrInterpretive]:
            print("%s (%s) not found" % (norm(symbol), basicOrInterpretive))
    print("Total matched: %d" % \
        (len(symbolsFound["basic"]) + len(symbolsFound["interpretive"])))
    print("Total unmatched:  %d" % \
        (len(symbolsSought["basic"]) + len(symbolsSought["interpretive"])))
    print()
    if cli.debugLevel == 0:
        print("Erasable:")
        print("Total matched:", totalCertainErasables)
        print("Total partially matched:", totalUncertainErasables) 
        print("Total unreferenced by code:", totalUnreferencedErasables)
        if totalUnreferencedErasables > 0:
            print()
            print("Note: The matching process is heuristic in nature, and")
            print('not 100% inclusive, so the "unreferenced" variables mentioned')
            print("above are not necessarily absent from the software.")
        print()
        print("Note: Map of core used by disassembly is in disassemblerAGC.core.")
        f = open("disassemblerAGC.core", 'w')
        for bank in range(numCoreBanks):
            print("BANK = %02o" % bank, file=f)
            for offset in range(0, sizeCoreBank, 0o100):
                row = "%04o:" % (offset + sizeCoreBank)
                for i in range(0o100):
                    if 0 == i % 8:
                        row += " "
                    if coreUsed[bank][offset + i]:
                        row += "X"
                    else:
                        row += "O"
                print(row, file=f)
        f.close()
    
    if cli.checkFilename != "":
    
        print()
        print("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━")
        print("Cross-check vs baseline assembly listing.")
        print()
        print("Core:")
        coreMatch = 0
        coreMismatch = 0
        for basic in symbolsFound:
            for symbol in symbolsFound[basic]:
                bank1 = symbolsFound[basic][symbol][0]
                address1 = symbolsFound[basic][symbol][1] % sizeCoreBank
                if symbol in checkCore:
                    bank2 = checkCore[symbol][0]
                    address2 = checkCore[symbol][1]
                else:
                    fields = symbol.split(",")
                    if len(fields) == 2 and fields[0][0] == "R" \
                            and fields[0][1:].isdigit() \
                            and fields[1].isdigit():
                        bank2 = int(fields[0][1:], 8)
                        address2 = int(fields[1], 8) % sizeCoreBank
                    else:
                        print("Implementation error:  Symbol check", norm(symbol))
                        continue
                if bank1 == bank2 and address1 == address2:
                    coreMatch += 1
                else:
                    coreMismatch += 1
                    print("%-8s is at %02o,%04o but should be at %02o,%04o" \
                        % (norm(symbol), bank1, address1 + sizeCoreBank,
                            bank2, address2 + sizeCoreBank))
                            
        print("Total matched =", coreMatch)
        print("Total unmatched =", coreMismatch)
        
        if cli.debugLevel == 0:
            print()
            print("Erasable:")
            erasableMatch = 0
            erasablePartialMatch = 0
            erasableMismatch = 0
            for symbol in sorted(foundErasables):
                #print(symbol, "=", foundErasables[symbol])
                found = foundErasables[symbol].replace("(", "").replace(")", "")
                fields = found.split(",")
                bank1 = fields[0][-1]
                if bank1 != "?":
                    bank1 = int(bank1, 8)
                address1 = int(fields[1], 8)
                bank2 = checkErasable[symbol][0]
                address2 = checkErasable[symbol][1] + 0o1400
                if bank1 == bank2 and address1 == address2:
                    erasableMatch += 1
                elif bank1 == "?" and address1 == address2:
                    erasablePartialMatch += 1
                else:
                    erasableMismatch += 1
                    if bank1 == "?":
                        print("%-8s E?,%04o != E%o,%04o" % \
                            (norm(symbol), address1, bank2, address2))
                    else:
                        print("%-8s E%o,%04o =? E%o,%04o" % \
                            (norm(symbol), bank1, address1, bank2, address2))
            print("Total matched =", erasableMatch)
            print("Total consistent =", erasablePartialMatch)
            print("Total mismatched =", erasableMismatch)
            
            print()
            print("Fixed references:")
            fixedMatch = 0
            fixedPartialMatch = 0
            fixedMismatch = 0
            for symbol in sorted(fixedFound):
                found = fixedFound[symbol]
                bank1 = found[0]
                address1 = found[1]
                if symbol not in checkCore:
                    continue
                bank2 = checkCore[symbol][0]
                address2 = checkCore[symbol][1] + sizeCoreBank
                if bank1 == bank2 and address1 == address2:
                    fixedMatch += 1
                elif bank1 == "??" and address1 == address2:
                    fixedPartialMatch += 1
                else:
                    fixedMismatch += 1
                    try:
                        if isinstance(bank1, int):
                            bank1 = "%02o" % bank1
                        print("%-8s %s,%04o != %02o,%04o" % \
                                (norm(symbol), bank1, address1, bank2, address2))
                    except:
                        print(norm(symbol), bank1, address1, bank2, address2, file=sys.stderr)
                        sys.exit(1)
            print("Total matched =", fixedMatch)
            print("Total consistent =", fixedPartialMatch)
            print("Total mismatched =", fixedMismatch)
                
    sys.exit(0)
    

