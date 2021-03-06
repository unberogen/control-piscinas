EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L TL062 U2
U 1 1 59C381E4
P 4150 3700
F 0 "U2" H 4150 3900 50  0000 L CNN
F 1 "TL032" H 4150 3500 50  0000 L CNN
F 2 "Housings_SOIC:SO-8_5.3x6.2mm_Pitch1.27mm" H 4150 3700 50  0001 C CNN
F 3 "" H 4150 3700 50  0001 C CNN
	1    4150 3700
	1    0    0    -1  
$EndComp
$Comp
L TL062 U2
U 2 1 59C38265
P 6600 3600
F 0 "U2" H 6600 3800 50  0000 L CNN
F 1 "TL032" H 6600 3400 50  0000 L CNN
F 2 "Housings_SOIC:SO-8_5.3x6.2mm_Pitch1.27mm" H 6600 3600 50  0001 C CNN
F 3 "" H 6600 3600 50  0001 C CNN
	2    6600 3600
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x03 J2
U 1 1 59C3830E
P 5350 2600
F 0 "J2" H 5350 2800 50  0000 C CNN
F 1 "Con(-5v)" H 5350 2400 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x03_Pitch2.54mm" H 5350 2600 50  0001 C CNN
F 3 "" H 5350 2600 50  0001 C CNN
	1    5350 2600
	0    1    1    0   
$EndComp
$Comp
L Conn_01x03 J1
U 1 1 59C3846F
P 8300 3200
F 0 "J1" H 8300 3400 50  0000 C CNN
F 1 "ConArduino" H 8300 3000 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x03_Pitch2.54mm" H 8300 3200 50  0001 C CNN
F 3 "" H 8300 3200 50  0001 C CNN
	1    8300 3200
	-1   0    0    1   
$EndComp
$Comp
L LED D1
U 1 1 59C384EC
P 7500 2050
F 0 "D1" H 7500 2150 50  0000 C CNN
F 1 "LED" H 7500 1950 50  0000 C CNN
F 2 "LEDs:LED_D3.0mm" H 7500 2050 50  0001 C CNN
F 3 "" H 7500 2050 50  0001 C CNN
	1    7500 2050
	1    0    0    -1  
$EndComp
$Comp
L SW_DIP_x01 SW1
U 1 1 59C38750
P 2900 4200
F 0 "SW1" H 2900 4350 50  0000 C CNN
F 1 "SW_DIP_x01" H 2900 4050 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_DIP_x1_W7.62mm_Slide_LowProfile" H 2900 4200 50  0001 C CNN
F 3 "" H 2900 4200 50  0001 C CNN
	1    2900 4200
	0    1    1    0   
$EndComp
$Comp
L Conn_Coaxial J3
U 1 1 59C38813
P 2350 3600
F 0 "J3" V 2360 3720 50  0000 C CNN
F 1 "Conn_Coaxial" V 2465 3600 50  0000 C CNN
F 2 "Connectors_TE-Connectivity:BNC_Socket_TYCO-AMP_LargePads" H 2350 3600 50  0001 C CNN
F 3 "" H 2350 3600 50  0001 C CNN
	1    2350 3600
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 59C389B6
P 1750 5650
F 0 "#PWR01" H 1750 5400 50  0001 C CNN
F 1 "GND" H 1750 5500 50  0000 C CNN
F 2 "" H 1750 5650 50  0001 C CNN
F 3 "" H 1750 5650 50  0001 C CNN
	1    1750 5650
	1    0    0    -1  
$EndComp
Text Notes 5100 2200 0    60   ~ 0
+5
Text Notes 5250 2000 0    60   ~ 0
gnd
Text Notes 5450 2200 0    60   ~ 0
-5
Text Notes 8650 3350 0    60   ~ 0
out
Text Notes 8650 3250 0    60   ~ 0
+5
Text Notes 8650 3100 0    60   ~ 0
gnd
$Comp
L R R2
U 1 1 59C3991F
P 6500 4350
F 0 "R2" V 6580 4350 50  0000 C CNN
F 1 "30K 1%" V 6500 4350 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 6430 4350 50  0001 C CNN
F 3 "" H 6500 4350 50  0001 C CNN
	1    6500 4350
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 59C399AC
P 6150 4550
F 0 "R3" V 6230 4550 50  0000 C CNN
F 1 "75K 1%" V 6150 4550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Vertical" V 6080 4550 50  0001 C CNN
F 3 "" H 6150 4550 50  0001 C CNN
	1    6150 4550
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 59C39A65
P 5750 3700
F 0 "R1" V 5830 3700 50  0000 C CNN
F 1 "30K 1%" V 5750 3700 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 5680 3700 50  0001 C CNN
F 3 "" H 5750 3700 50  0001 C CNN
	1    5750 3700
	0    1    1    0   
$EndComp
$Comp
L CP C5
U 1 1 59C39AD6
P 4250 2750
F 0 "C5" H 4275 2850 50  0000 L CNN
F 1 "10uF" H 4275 2650 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D7.5mm_P2.50mm" H 4288 2600 50  0001 C CNN
F 3 "" H 4250 2750 50  0001 C CNN
	1    4250 2750
	0    -1   -1   0   
$EndComp
$Comp
L CP C7
U 1 1 59C39BB0
P 4350 4950
F 0 "C7" H 4375 5050 50  0000 L CNN
F 1 "10uF" H 4375 4850 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D7.5mm_P2.50mm" H 4388 4800 50  0001 C CNN
F 3 "" H 4350 4950 50  0001 C CNN
	1    4350 4950
	0    1    1    0   
$EndComp
$Comp
L C C3
U 1 1 59C39C13
P 4250 3100
F 0 "C3" H 4275 3200 50  0000 L CNN
F 1 "C0.1uF" H 4275 3000 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 4288 2950 50  0001 C CNN
F 3 "" H 4250 3100 50  0001 C CNN
	1    4250 3100
	0    1    1    0   
$EndComp
$Comp
L C C4
U 1 1 59C39C7E
P 4350 4600
F 0 "C4" H 4375 4700 50  0000 L CNN
F 1 "0.1uF" H 4375 4500 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 4388 4450 50  0001 C CNN
F 3 "" H 4350 4600 50  0001 C CNN
	1    4350 4600
	0    1    1    0   
$EndComp
$Comp
L C C6
U 1 1 59C39CCF
P 4900 4500
F 0 "C6" H 4925 4600 50  0000 L CNN
F 1 "0.1uF" H 4925 4400 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 4938 4350 50  0001 C CNN
F 3 "" H 4900 4500 50  0001 C CNN
	1    4900 4500
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR02
U 1 1 59C3AD0C
P 8950 3200
F 0 "#PWR02" H 8950 3050 50  0001 C CNN
F 1 "+5V" H 8950 3340 50  0000 C CNN
F 2 "" H 8950 3200 50  0001 C CNN
F 3 "" H 8950 3200 50  0001 C CNN
	1    8950 3200
	-1   0    0    1   
$EndComp
$Comp
L -VDC #PWR03
U 1 1 59C3AD3E
P 6150 5700
F 0 "#PWR03" H 6150 5600 50  0001 C CNN
F 1 "-VDC" H 6150 5950 50  0000 C CNN
F 2 "" H 6150 5700 50  0001 C CNN
F 3 "" H 6150 5700 50  0001 C CNN
	1    6150 5700
	-1   0    0    1   
$EndComp
Wire Wire Line
	4100 2750 4050 2750
Wire Wire Line
	4050 2750 4050 3400
Wire Wire Line
	3850 3100 4100 3100
Connection ~ 4050 3100
Wire Wire Line
	4400 3100 4400 2750
Wire Wire Line
	4050 4000 4050 4950
Wire Wire Line
	4050 4950 4200 4950
Wire Wire Line
	3750 4600 4200 4600
Connection ~ 4050 4600
Wire Wire Line
	4500 4600 4650 4600
Wire Wire Line
	4650 4600 4650 4950
Wire Wire Line
	4500 4950 4900 4950
Wire Wire Line
	4900 5250 4900 4650
Connection ~ 4650 4950
Wire Wire Line
	4900 4350 3600 4350
Wire Wire Line
	3600 4350 3600 3800
Wire Wire Line
	3600 3800 3850 3800
Wire Wire Line
	6900 3600 8500 3600
Wire Wire Line
	8500 3600 8500 3300
Wire Wire Line
	5900 3700 6300 3700
Wire Wire Line
	5600 3700 4450 3700
Wire Wire Line
	6150 3700 6150 4400
Connection ~ 6150 3700
Wire Wire Line
	6350 4350 6150 4350
Connection ~ 6150 4350
Wire Wire Line
	6650 4350 7150 4350
Wire Wire Line
	7150 4350 7150 3600
Connection ~ 7150 3600
Wire Wire Line
	2500 3600 3850 3600
Wire Wire Line
	2350 5250 2350 3800
Wire Wire Line
	2350 4650 2900 4650
Wire Wire Line
	2900 4650 2900 4500
Wire Wire Line
	2900 3900 2900 3600
Connection ~ 2900 3600
Wire Wire Line
	5350 2400 5350 1600
Wire Wire Line
	1750 1600 8650 1600
Wire Wire Line
	8650 1600 8650 3100
Wire Wire Line
	8650 3100 8500 3100
Wire Wire Line
	1750 1600 1750 5650
Wire Wire Line
	1750 5250 4900 5250
Connection ~ 5350 1600
Connection ~ 2350 4650
Connection ~ 2250 5250
Connection ~ 4900 4950
Connection ~ 2350 5250
Wire Wire Line
	6300 3500 6150 3500
Wire Wire Line
	6150 3500 6150 1600
Connection ~ 6150 1600
Wire Wire Line
	6150 4700 6150 5700
Wire Wire Line
	3750 5500 7450 5500
Wire Wire Line
	3750 5500 3750 4600
Connection ~ 6150 5500
Wire Wire Line
	3850 3100 3850 2300
Wire Wire Line
	3850 2300 5250 2300
Wire Wire Line
	5250 2300 5250 2400
Wire Wire Line
	4750 2300 4750 2850
Wire Wire Line
	4750 2850 8950 2850
Wire Wire Line
	8950 2050 8950 3200
Wire Wire Line
	8950 3200 8500 3200
Connection ~ 4750 2300
Wire Wire Line
	4400 3100 6150 3100
Connection ~ 6150 3100
Wire Wire Line
	5450 2400 5450 2300
Wire Wire Line
	5450 2300 7450 2300
Wire Wire Line
	7450 2300 7450 5500
$Comp
L R R4
U 1 1 59C3C4FD
P 8050 2050
F 0 "R4" V 8130 2050 50  0000 C CNN
F 1 "1K" V 8050 2050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 7980 2050 50  0001 C CNN
F 3 "" H 8050 2050 50  0001 C CNN
	1    8050 2050
	0    1    1    0   
$EndComp
Wire Wire Line
	8950 2050 8200 2050
Connection ~ 8950 2850
Wire Wire Line
	7900 2050 7650 2050
Wire Wire Line
	7350 2050 7000 2050
Wire Wire Line
	7000 2050 7000 1600
Connection ~ 7000 1600
Wire Wire Line
	4900 4350 4900 3700
Connection ~ 4900 3700
Connection ~ 1750 5250
$EndSCHEMATC
