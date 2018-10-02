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

reg ADS0 = 0, BR1 = 0, BR12B_ = 0, BR1B2_ = 0, BR1_ = 0, BR2 = 0, BR2_ = 0,
  BRDIF_ = 0, C24A = 0, C25A = 0, C26A = 0, C27A = 0, C30A = 0, C37P = 0,
  C40P = 0, C41P = 0, C42P = 0, C43P = 0, C44P = 0, CCS0 = 0, CCS0_ = 0,
  CGA5 = 0, CHINC_ = 0, DAS0 = 0, DAS0_ = 0, DAS1 = 0, DAS1_ = 0, DIV_ = 0,
  DV1 = 0, DV1_ = 0, DV4 = 0, DV4_ = 0, DXCH0 = 0, EDSET = 0, FETCH0 = 0,
  FETCH0_ = 0, GOJ1 = 0, GOJ1_ = 0, GOJAM = 0, IC1 = 0, IC10 = 0, IC10_ = 0,
  IC11_ = 0, IC12 = 0, IC12_ = 0, IC13 = 0, IC14 = 0, IC15_ = 0, IC16 = 0,
  IC16_ = 0, IC2 = 0, IC2_ = 0, IC3 = 0, IC4 = 0, IC5 = 0, IC5_ = 0, IC8_ = 0,
  IC9 = 0, INCSET_ = 0, INKL_ = 0, INOUT = 0, INOUT_ = 0, MASK0 = 0, MASK0_ = 0,
  MONWBK = 0, MONpCH = 0, MP0 = 0, MP3 = 0, MP3_ = 0, MSU0 = 0, MSU0_ = 0,
  NDX0_ = 0, PRINC = 0, QXCH0_ = 0, RAND0 = 0, READ0 = 0, ROR0 = 0, RSM3 = 0,
  RSM3_ = 0, RUPT0 = 0, RXOR0 = 0, RXOR0_ = 0, S11 = 0, S12 = 0, SHANC_ = 0,
  SHIFT = 0, SHIFT_ = 0, STD2 = 0, STFET1_ = 0, T01 = 0, T01_ = 0, T02_ = 0,
  T03_ = 0, T04_ = 0, T05_ = 0, T06_ = 0, T07_ = 0, T08_ = 0, T09_ = 0,
  T10_ = 0, T11_ = 0, T12 = 0, T12USE_ = 0, T12_ = 0, TC0 = 0, TC0_ = 0,
  TCF0 = 0, TCSAJ3_ = 0, TS0 = 0, TS0_ = 0, WAND0 = 0, WOR0 = 0, XT0_ = 0,
  XT2_ = 0, XT3_ = 0, XT4_ = 0, XT5_ = 0, XT6_ = 0, YB0_ = 0, YT0_ = 0,
  d4XP5 = 0, d5XP11 = 0;

wire A2X_, CI_, DV1B1B, DV4B1B, DVST, GNHNC, MONEX_, NDR100_, NISQ_, OCTAD2,
  OCTAD3, OCTAD4, OCTAD5, OCTAD6, P03, PARTC, PINC, PINC_, PTWOX, R6, RAD,
  RA_, RB_, RC_, RG_, RL10BB, RL_, RQ, RSCT, RSTRT, RSTSTG, RU_, RZ_, SCAD,
  SCAD_, ST2_, TMZ_, TOV_, TPZG_, TRSM, TSGN_, TSUDO_, U2BBK, WA_, WB_,
  WG_, WL_, WS_, WY12_, WYD_, WY_, WZ_, Z15_, Z16_, d10XP1, d10XP6, d10XP8,
  d11XP2, d2XP7, d2XP8, d3XP6, d5XP12, d5XP15, d5XP21, d6XP8, d7XP4, d7XP9,
  d9XP5;

A5 iA5 (
  rst, ADS0, BR1, BR12B_, BR1B2_, BR1_, BR2, BR2_, BRDIF_, C24A, C25A, C26A,
  C27A, C30A, C37P, C40P, C41P, C42P, C43P, C44P, CCS0, CCS0_, CGA5, CHINC_,
  DAS0, DAS0_, DAS1, DAS1_, DIV_, DV1, DV1_, DV4, DV4_, DXCH0, EDSET, FETCH0,
  FETCH0_, GOJ1, GOJ1_, GOJAM, IC1, IC10, IC10_, IC11_, IC12, IC12_, IC13,
  IC14, IC15_, IC16, IC16_, IC2, IC2_, IC3, IC4, IC5, IC5_, IC8_, IC9, INCSET_,
  INKL_, INOUT, INOUT_, MASK0, MASK0_, MONWBK, MONpCH, MP0, MP3, MP3_, MSU0,
  MSU0_, NDX0_, PRINC, QXCH0_, RAND0, READ0, ROR0, RSM3, RSM3_, RUPT0, RXOR0,
  RXOR0_, S11, S12, SHANC_, SHIFT, SHIFT_, STD2, STFET1_, T01, T01_, T02_,
  T03_, T04_, T05_, T06_, T07_, T08_, T09_, T10_, T11_, T12, T12USE_, T12_,
  TC0, TC0_, TCF0, TCSAJ3_, TS0, TS0_, WAND0, WOR0, XT0_, XT2_, XT3_, XT4_,
  XT5_, XT6_, YB0_, YT0_, d4XP5, d5XP11, A2X_, CI_, DV1B1B, MONEX_, P03,
  PARTC, RA_, RB_, RC_, RG_, RL_, RU_, RZ_, ST2_, TMZ_, TOV_, TSGN_, WA_,
  WB_, WG_, WL_, WS_, WY12_, WYD_, WY_, WZ_, Z15_, Z16_, d10XP6, DV4B1B,
  DVST, GNHNC, NDR100_, NISQ_, OCTAD2, OCTAD3, OCTAD4, OCTAD5, OCTAD6, PINC,
  PINC_, PTWOX, R6, RAD, RL10BB, RQ, RSCT, RSTRT, RSTSTG, SCAD, SCAD_, TPZG_,
  TRSM, TSUDO_, U2BBK, d10XP1, d10XP8, d11XP2, d2XP7, d2XP8, d3XP6, d5XP12,
  d5XP15, d5XP21, d6XP8, d7XP4, d7XP9, d9XP5
);

initial $timeformat(-9, 0, " ns", 10);
initial $monitor("%t: %d", $time, CLOCK);

endmodule
