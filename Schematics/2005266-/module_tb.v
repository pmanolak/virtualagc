// Verilog testbench created by dumbTestbench.py
`timescale 100ns / 1ns

module agc;

reg rst = 1;
initial
  begin
    $dumpfile("agc.lxt2");
    $dumpvars(0, agc);
    # 1 rst = 0;
    # 1000 $finish;
  end

reg CLOCK = 0;
always #4.8828125 CLOCK = !CLOCK;

reg CCH11 = 0, CCHG_ = 0, CGA16 = 0, CH0705 = 0, CH0706 = 0, CH0707 = 0,
  CH1501 = 0, CH1502 = 0, CH1503 = 0, CH1504 = 0, CH3201 = 0, CH3202 = 0,
  CH3203 = 0, CH3204 = 0, CH3205 = 0, CH3206 = 0, CH3207 = 0, CH3208 = 0,
  CHWL01_ = 0, CHWL02_ = 0, CHWL03_ = 0, CHWL04_ = 0, CHWL05_ = 0, CHWL06_ = 0,
  CHWL07_ = 0, CHWL08_ = 0, CHWL09_ = 0, CHWL10_ = 0, CHWL11_ = 0, CHWL12_ = 0,
  CHWL13_ = 0, CHWL14_ = 0, FLASH = 0, FLASH_ = 0, GOJAM = 0, RCH11_ = 0,
  WCH11_ = 0, WCHG_ = 0, XB2_ = 0, XB5_ = 0, XB6_ = 0, XT0_ = 0, XT1_ = 0;

wire CCH05, CCH06, CCH12, CH1207, CH1208, CH1209, CH1210, CH1211, CH1212,
  CH1213, CH1214, CHOR01_, CHOR02_, CHOR03_, CHOR04_, CHOR05_, CHOR06_,
  CHOR07_, CHOR08_, COARSE, COMACT, DISDAC, ENERIM, ENEROP, ISSWAR, KYRLS,
  MROLGT, OPEROR, OT1207, OT1207_, RCH05_, RCH06_, RCH12_, RCmXmP, RCmXmY,
  RCmXpP, RCmXpY, RCmYmR, RCmYpR, RCmZmR, RCmZpR, RCpXmP, RCpXmY, RCpXpP,
  RCpXpY, RCpYmR, RCpYpR, RCpZmR, RCpZpR, S4BOFF, S4BSEQ, S4BTAK, STARON,
  TMPOUT, TVCNAB, UPLACT, VNFLSH, WCH05_, WCH06_, WCH12_, ZEROPT, ZIMCDU,
  ZOPCDU;

A16 iA16 (
  rst, CCH11, CCHG_, CGA16, CH0705, CH0706, CH0707, CH1501, CH1502, CH1503,
  CH1504, CH3201, CH3202, CH3203, CH3204, CH3205, CH3206, CH3207, CH3208,
  CHWL01_, CHWL02_, CHWL03_, CHWL04_, CHWL05_, CHWL06_, CHWL07_, CHWL08_,
  CHWL09_, CHWL10_, CHWL11_, CHWL12_, CHWL13_, CHWL14_, FLASH, FLASH_, GOJAM,
  RCH11_, WCH11_, WCHG_, XB2_, XB5_, XB6_, XT0_, XT1_, CCH12, CH1207, CHOR01_,
  CHOR02_, CHOR03_, CHOR04_, CHOR05_, CHOR06_, CHOR07_, CHOR08_, RCH12_,
  WCH12_, CCH05, CCH06, CH1208, CH1209, CH1210, CH1211, CH1212, CH1213, CH1214,
  COARSE, COMACT, DISDAC, ENERIM, ENEROP, ISSWAR, KYRLS, MROLGT, OPEROR,
  OT1207, OT1207_, RCH05_, RCH06_, RCmXmP, RCmXmY, RCmXpP, RCmXpY, RCmYmR,
  RCmYpR, RCmZmR, RCmZpR, RCpXmP, RCpXmY, RCpXpP, RCpXpY, RCpYmR, RCpYpR,
  RCpZmR, RCpZpR, S4BOFF, S4BSEQ, S4BTAK, STARON, TMPOUT, TVCNAB, UPLACT,
  VNFLSH, WCH05_, WCH06_, ZEROPT, ZIMCDU, ZOPCDU
);

initial $timeformat(-9, 0, " ns", 10);
initial $monitor("%t: %d", $time, CLOCK);

endmodule
