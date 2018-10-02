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

reg AD0 = 0, ADS0 = 0, AUG0_ = 0, B15X = 0, BR1 = 0, BR12B_ = 0, BR1B2B = 0,
  BR1B2B_ = 0, BR1B2_ = 0, BR1_ = 0, BR2_ = 0, CCS0 = 0, CCS0_ = 0, CDUSTB_ = 0,
  CGA6 = 0, DAS0 = 0, DAS1 = 0, DAS1_ = 0, DCA0 = 0, DCS0 = 0, DIM0_ = 0,
  DINC = 0, DINC_ = 0, DIVSTG = 0, DV0 = 0, DV1376 = 0, DV1376_ = 0, DV376_ = 0,
  DV4B1B = 0, DV4_ = 0, DXCH0 = 0, FETCH1 = 0, GOJAM = 0, IC11 = 0, IC15 = 0,
  IC17 = 0, IC6 = 0, IC7 = 0, IC9 = 0, INCR0 = 0, INKL = 0, INOTLD = 0,
  L01_ = 0, L02A_ = 0, L15A_ = 0, MASK0 = 0, MCDU = 0, MINC = 0, MON_ = 0,
  MONpCH = 0, MP0T10 = 0, MP1 = 0, MP1_ = 0, MP3_ = 0, MSU0 = 0, NDXX1_ = 0,
  P01 = 0, P04 = 0, P05_ = 0, PCDU = 0, PHS4_ = 0, PINC = 0, PRINC = 0,
  PTWOX = 0, R15 = 0, R6 = 0, RADRG = 0, RADRZ = 0, RAND0 = 0, RBSQ = 0,
  RRPA = 0, RSTK_ = 0, RUPT0 = 0, RUPT1 = 0, S01 = 0, S01_ = 0, S02 = 0,
  S02_ = 0, S03 = 0, S03_ = 0, S04 = 0, S04_ = 0, S05 = 0, S05_ = 0, S06 = 0,
  S06_ = 0, S07 = 0, S07_ = 0, SHIFT = 0, STBE = 0, STBF = 0, STFET1_ = 0,
  STOP_ = 0, STRT2 = 0, SU0 = 0, T01 = 0, T01_ = 0, T02 = 0, T02_ = 0,
  T03 = 0, T03_ = 0, T04 = 0, T04_ = 0, T05 = 0, T06 = 0, T06_ = 0, T07 = 0,
  T07_ = 0, T08 = 0, T08_ = 0, T09 = 0, T10 = 0, T10_ = 0, T11 = 0, T11_ = 0,
  T12 = 0, T12USE_ = 0, TL15 = 0, WAND0 = 0, d10XP1 = 0, d10XP8 = 0, d11XP2 = 0,
  d1XP10 = 0, d2XP3 = 0, d2XP5 = 0, d2XP7 = 0, d2XP8 = 0, d3XP2 = 0, d3XP6 = 0,
  d3XP7 = 0, d4XP11 = 0, d5XP12 = 0, d5XP15 = 0, d5XP21 = 0, d5XP28 = 0,
  d5XP4 = 0, d6XP5 = 0, d6XP8 = 0, d7XP19 = 0, d7XP4 = 0, d7XP9 = 0, d8PP4 = 0,
  d8XP6 = 0, d9XP1 = 0, d9XP5 = 0;

wire A2X_, BXVX, CGMC, CI_, CLXC, DVXP1, EXT, IL01, IL01_, IL02, IL02_,
  IL03, IL03_, IL04, IL04_, IL05, IL05_, IL06, IL06_, IL07, IL07_, L2GD_,
  MCRO_, MONEX, MONEX_, MOUT, NEAC, PIFL_, PONEX, POUT, PSEUDO, R1C_, RB1F,
  RB1_, RB_, RCH_, RC_, RDBANK, RG_, RPTSET, RSTKX_, RSTKY_, RUS_, RU_,
  RZ_, ST1, ST2, ST2_, TIMR, TOV_, TSGU_, TWOX, WA_, WB_, WG_, WL_, WOVR,
  WQ_, WSC_, WS_, WYD_, WY_, WZ_, ZAP, ZAP_, ZIP, ZIPCI, ZOUT, d2PP1, d7XP14;

A6 iA6 (
  rst, AD0, ADS0, AUG0_, B15X, BR1, BR12B_, BR1B2B, BR1B2B_, BR1B2_, BR1_,
  BR2_, CCS0, CCS0_, CDUSTB_, CGA6, DAS0, DAS1, DAS1_, DCA0, DCS0, DIM0_,
  DINC, DINC_, DIVSTG, DV0, DV1376, DV1376_, DV376_, DV4B1B, DV4_, DXCH0,
  FETCH1, GOJAM, IC11, IC15, IC17, IC6, IC7, IC9, INCR0, INKL, INOTLD, L01_,
  L02A_, L15A_, MASK0, MCDU, MINC, MON_, MONpCH, MP0T10, MP1, MP1_, MP3_,
  MSU0, NDXX1_, P01, P04, P05_, PCDU, PHS4_, PINC, PRINC, PTWOX, R15, R6,
  RADRG, RADRZ, RAND0, RBSQ, RRPA, RSTK_, RUPT0, RUPT1, S01, S01_, S02, S02_,
  S03, S03_, S04, S04_, S05, S05_, S06, S06_, S07, S07_, SHIFT, STBE, STBF,
  STFET1_, STOP_, STRT2, SU0, T01, T01_, T02, T02_, T03, T03_, T04, T04_,
  T05, T06, T06_, T07, T07_, T08, T08_, T09, T10, T10_, T11, T11_, T12, T12USE_,
  TL15, WAND0, d10XP1, d10XP8, d11XP2, d1XP10, d2XP3, d2XP5, d2XP7, d2XP8,
  d3XP2, d3XP6, d3XP7, d4XP11, d5XP12, d5XP15, d5XP21, d5XP28, d5XP4, d6XP5,
  d6XP8, d7XP19, d7XP4, d7XP9, d8PP4, d8XP6, d9XP1, d9XP5, IL01, IL01_, IL02,
  IL02_, IL03, IL03_, IL04, IL04_, IL05, IL05_, IL06, IL06_, IL07, IL07_,
  MONEX_, RB_, RC_, RDBANK, RPTSET, RSTKX_, RSTKY_, RU_, ST2_, WG_, WSC_,
  WY_, ZIPCI, d2PP1, A2X_, BXVX, CGMC, CI_, CLXC, DVXP1, EXT, L2GD_, MCRO_,
  MONEX, MOUT, NEAC, PIFL_, PONEX, POUT, PSEUDO, R1C_, RB1F, RB1_, RCH_,
  RG_, RUS_, RZ_, ST1, ST2, TIMR, TOV_, TSGU_, TWOX, WA_, WB_, WL_, WOVR,
  WQ_, WS_, WYD_, WZ_, ZAP, ZAP_, ZIP, ZOUT, d7XP14
);

initial $timeformat(-9, 0, " ns", 10);
initial $monitor("%t: %d", $time, CLOCK);

endmodule
