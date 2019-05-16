EESchema Schematic File Version 5
LIBS:module-cache
EELAYER 29 0
EELAYER END
$Descr B 17000 11000
encoding utf-8
Sheet 14 24
Title "BLOCK I LOGIC FLOW S, MODULE A21, DRAWING 1006556"
Date "2018-11-25"
Rev "Draft"
Comp ""
Comment1 "Modules A21"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 1525 9950 0    140  Input ~ 28
+3VDC
Text HLabel 1525 10225 0    140  Input ~ 28
0VDC
$Comp
L D3NOR-+3VDC-0VDC-nd1021041:D3NOR-+3VDC-0VDC-nd1021041-1_5-___ U1503
U 1 1 5BFB4276
P 9250 7575
F 0 "U1503" H 9250 7900 140 0001 C CNB
F 1 "D3NOR-+3VDC-0VDC-nd1021041-1_5-___" H 9250 8000 140 0001 C CNN
F 2 "" H 9250 8050 140 0001 C CNN
F 3 "" H 9250 8050 140 0001 C CNN
F 4 "60413" H 9250 7575 140 0000 C CNB "Location"
	1    9250 7575
	1    0    0    -1  
$EndComp
$Comp
L AGC_DSKY:ConnectorGeneric J1
U 125 1 5BFB4277
P 10725 3000
F 0 "J1" H 10725 3325 140 0001 C CNN
F 1 "ConnectorGeneric" H 10725 3425 140 0001 C CNN
F 2 "" H 10725 3475 140 0001 C CNN
F 3 "" H 10725 3475 140 0001 C CNN
F 4 "TSGN/" H 10050 2925 140 0000 C BNB "Caption"
	125  10725 3000
	-1   0    0    1   
$EndComp
$Comp
L D3NOR-NC-0VDC-expander-nd1021041:D3NOR-NC-0VDC-expander-nd1021041-1_5-___ U1501
U 1 1 5BFB427C
P 8400 4250
F 0 "U1501" H 8400 4575 140 0001 C CNB
F 1 "D3NOR-NC-0VDC-expander-nd1021041-1_5-___" H 8400 4675 140 0001 C CNN
F 2 "" H 8400 4725 140 0001 C CNN
F 3 "" H 8400 4725 140 0001 C CNN
F 4 "60423" H 8325 4250 130 0000 C CNB "Location"
	1    8400 4250
	1    0    0    -1  
$EndComp
$Comp
L D3NOR-+3VDC-0VDC-nd1021041:D3NOR-+3VDC-0VDC-nd1021041-1_5-___ U1502
U 1 1 5BFB4281
P 8425 3000
F 0 "U1502" H 8425 3325 140 0001 C CNB
F 1 "D3NOR-+3VDC-0VDC-nd1021041-1_5-___" H 8425 3425 140 0001 C CNN
F 2 "" H 8425 3475 140 0001 C CNN
F 3 "" H 8425 3475 140 0001 C CNN
F 4 "60422" H 8425 3000 140 0000 C CNB "Location"
	1    8425 3000
	1    0    0    -1  
$EndComp
$Comp
L AGC_DSKY:ConnectorGeneric J1
U 142 1 5BFB4282
P 7150 8625
F 0 "J1" H 7150 8950 140 0001 C CNN
F 1 "ConnectorGeneric" H 7150 9050 140 0001 C CNN
F 2 "" H 7150 9100 140 0001 C CNN
F 3 "" H 7150 9100 140 0001 C CNN
F 4 "A21_142_A24_5" H 6000 8550 140 0000 C BNB "Caption"
	142  7150 8625
	1    0    0    -1  
$EndComp
$Comp
L AGC_DSKY:ConnectorGeneric J1
U 140 1 5BFB4284
P 10850 7575
F 0 "J1" H 10850 7900 140 0001 C CNN
F 1 "ConnectorGeneric" H 10850 8000 140 0001 C CNN
F 2 "" H 10850 8050 140 0001 C CNN
F 3 "" H 10850 8050 140 0001 C CNN
F 4 "TSGN2/" H 10100 7500 140 0000 C BNB "Caption"
	140  10850 7575
	-1   0    0    1   
$EndComp
Wire Wire Line
	6300 4975 7225 4975
Wire Wire Line
	7225 4975 7225 4600
Wire Wire Line
	7225 4600 7775 4600
Wire Wire Line
	6300 3900 7775 3900
Wire Wire Line
	6300 2850 6725 2850
Wire Wire Line
	6725 2850 6725 3350
Wire Wire Line
	6725 3350 7800 3350
Wire Wire Line
	6300 1725 7225 1725
Wire Wire Line
	7225 1725 7225 2650
Wire Wire Line
	7225 2650 7800 2650
Wire Wire Line
	9325 3000 9700 3000
Wire Wire Line
	9200 4250 9700 4250
Wire Wire Line
	9700 4250 9700 3000
Connection ~ 9700 3000
Wire Wire Line
	9700 3000 10450 3000
Wire Wire Line
	10150 7575 10575 7575
Wire Wire Line
	8625 7925 8075 7925
Wire Wire Line
	8075 7925 8075 8625
Wire Wire Line
	8075 8625 7425 8625
Wire Wire Line
	8625 7225 8075 7225
Wire Wire Line
	8075 7225 8075 6525
Wire Wire Line
	8075 6525 5950 6525
Text HLabel 6300 4975 0    140  Input ~ 28
g60036
Text HLabel 6300 1725 0    140  Input ~ 28
g60037
Text HLabel 6300 2850 0    140  Input ~ 28
g60071
Text HLabel 6300 3900 0    140  Input ~ 28
g60038
Text HLabel 5950 6525 0    140  Input ~ 28
g60075
$Comp
L AGC_DSKY:Node2 N?
U 1 1 5CE5DD2F
P 2450 9950
AR Path="/5F3224B7/5CE5DD2F" Ref="N?"  Part="1" 
AR Path="/6006531B/5CE5DD2F" Ref="N1401"  Part="1" 
F 0 "N1401" H 2450 10050 50  0001 C CNN
F 1 "Node2" H 2450 10125 50  0001 C CNN
F 2 "" H 2450 9950 50  0001 C CNN
F 3 "" H 2450 9950 50  0001 C CNN
F 4 "+3VDC" H 2375 9950 140 0001 R CNB "Caption"
	1    2450 9950
	-1   0    0    1   
$EndComp
$Comp
L AGC_DSKY:Node2 N?
U 1 1 5CE5DD38
P 2450 10225
AR Path="/5F3224B7/5CE5DD38" Ref="N?"  Part="0" 
AR Path="/6006531B/5CE5DD38" Ref="N1402"  Part="1" 
F 0 "N1402" H 2450 10325 50  0001 C CNN
F 1 "Node2" H 2450 10400 50  0001 C CNN
F 2 "" H 2450 10225 50  0001 C CNN
F 3 "" H 2450 10225 50  0001 C CNN
F 4 "0VDC" H 2375 10225 140 0001 R CNB "Caption"
	1    2450 10225
	-1   0    0    1   
$EndComp
Wire Wire Line
	1525 10225 2375 10225
Wire Wire Line
	1525 9950 2375 9950
$EndSCHEMATC