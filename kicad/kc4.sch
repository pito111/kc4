EESchema Schematic File Version 4
EELAYER 26 0
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
L teensy:Teensy4.0 U1
U 1 1 5F4A7DA2
P 4200 3450
F 0 "U1" H 4200 5065 50  0000 C CNN
F 1 "Teensy4.0" H 4200 4974 50  0000 C CNN
F 2 "" H 3800 3650 50  0001 C CNN
F 3 "" H 3800 3650 50  0001 C CNN
	1    4200 3450
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC550 T1
U 1 1 5F4A8140
P 3700 6300
F 0 "T1" H 3891 6346 50  0000 L CNN
F 1 "BC550C" H 3891 6255 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 3900 6225 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC547.pdf" H 3700 6300 50  0001 L CNN
	1    3700 6300
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 5F4A828A
P 3800 5950
F 0 "D1" V 3838 5833 50  0000 R CNN
F 1 "LED" V 3747 5833 50  0000 R CNN
F 2 "" H 3800 5950 50  0001 C CNN
F 3 "~" H 3800 5950 50  0001 C CNN
	1    3800 5950
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D2
U 1 1 5F4A8732
P 4000 5950
F 0 "D2" V 4038 5833 50  0000 R CNN
F 1 "LED" V 3947 5833 50  0000 R CNN
F 2 "" H 4000 5950 50  0001 C CNN
F 3 "~" H 4000 5950 50  0001 C CNN
	1    4000 5950
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R1
U 1 1 5F4A886E
P 3800 5650
F 0 "R1" H 3870 5696 50  0000 L CNN
F 1 "330" H 3870 5605 50  0000 L CNN
F 2 "" V 3730 5650 50  0001 C CNN
F 3 "~" H 3800 5650 50  0001 C CNN
	1    3800 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5F4A88CD
P 4000 5650
F 0 "R2" H 4070 5696 50  0000 L CNN
F 1 "330" H 4070 5605 50  0000 L CNN
F 2 "" V 3930 5650 50  0001 C CNN
F 3 "~" H 4000 5650 50  0001 C CNN
	1    4000 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5F4A8969
P 1500 4650
F 0 "R5" H 1430 4604 50  0000 R CNN
F 1 "4.7k" H 1430 4695 50  0000 R CNN
F 2 "" V 1430 4650 50  0001 C CNN
F 3 "~" H 1500 4650 50  0001 C CNN
	1    1500 4650
	-1   0    0    1   
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5F4A8A52
P 3800 6500
F 0 "#PWR?" H 3800 6250 50  0001 C CNN
F 1 "GNDD" H 3804 6345 50  0000 C CNN
F 2 "" H 3800 6500 50  0001 C CNN
F 3 "" H 3800 6500 50  0001 C CNN
	1    3800 6500
	1    0    0    -1  
$EndComp
$Comp
L Sensor_Temperature:DS18B20 U3
U 1 1 5F4A8D2F
P 1150 4800
F 0 "U3" H 920 4846 50  0000 R CNN
F 1 "DS18B20" H 920 4755 50  0000 R CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 150 4550 50  0001 C CNN
F 3 "http://datasheets.maximintegrated.com/en/ds/DS18B20.pdf" H 1000 5050 50  0001 C CNN
	1    1150 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 6100 3800 6100
Wire Wire Line
	4000 5500 3800 5500
Connection ~ 3800 6100
$Comp
L power:GNDD #PWR?
U 1 1 5F4A96F6
P 1150 5100
F 0 "#PWR?" H 1150 4850 50  0001 C CNN
F 1 "GNDD" H 1154 4945 50  0000 C CNN
F 2 "" H 1150 5100 50  0001 C CNN
F 3 "" H 1150 5100 50  0001 C CNN
	1    1150 5100
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5F4A976F
P 1150 4500
F 0 "#PWR?" H 1150 4350 50  0001 C CNN
F 1 "+3V3" H 1165 4673 50  0000 C CNN
F 2 "" H 1150 4500 50  0001 C CNN
F 3 "" H 1150 4500 50  0001 C CNN
	1    1150 4500
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5F4A97A9
P 3800 5500
F 0 "#PWR?" H 3800 5350 50  0001 C CNN
F 1 "+3V3" H 3815 5673 50  0000 C CNN
F 2 "" H 3800 5500 50  0001 C CNN
F 3 "" H 3800 5500 50  0001 C CNN
	1    3800 5500
	1    0    0    -1  
$EndComp
Connection ~ 3800 5500
$Comp
L Driver_Display:CR2013-MI2120 U2
U 1 1 5F4AA0AB
P 1500 3400
F 0 "U2" H 1500 4178 50  0000 C CNN
F 1 "LCD ILI9341 320x240" H 1500 4087 50  0000 C CNN
F 2 "Display:CR2013-MI2120" H 1500 2700 50  0001 C CNN
F 3 "http://pan.baidu.com/s/11Y990" H 850 3900 50  0001 C CNN
	1    1500 3400
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5F4AA8D6
P 1500 2600
F 0 "#PWR?" H 1500 2450 50  0001 C CNN
F 1 "+3V3" H 1515 2773 50  0000 C CNN
F 2 "" H 1500 2600 50  0001 C CNN
F 3 "" H 1500 2600 50  0001 C CNN
	1    1500 2600
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5F4AA91A
P 1500 4000
F 0 "#PWR?" H 1500 3750 50  0001 C CNN
F 1 "GNDD" H 1504 3845 50  0000 C CNN
F 2 "" H 1500 4000 50  0001 C CNN
F 3 "" H 1500 4000 50  0001 C CNN
	1    1500 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 3600 2450 4600
Wire Wire Line
	2450 3600 2300 3600
Wire Wire Line
	2300 3500 2550 3500
Wire Wire Line
	2550 3500 2550 4000
$Comp
L Device:Battery_Cell BT1
U 1 1 5F4ABAC3
P 2300 5800
F 0 "BT1" H 2418 5896 50  0000 L CNN
F 1 "3V CR2032" H 2418 5805 50  0000 L CNN
F 2 "" V 2300 5860 50  0001 C CNN
F 3 "~" V 2300 5860 50  0001 C CNN
	1    2300 5800
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5F4AC4F1
P 2300 5900
F 0 "#PWR?" H 2300 5650 50  0001 C CNN
F 1 "GNDD" H 2304 5745 50  0000 C CNN
F 2 "" H 2300 5900 50  0001 C CNN
F 3 "" H 2300 5900 50  0001 C CNN
	1    2300 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 2800 2350 3700
Wire Wire Line
	2350 3700 2300 3700
Wire Wire Line
	2350 2800 1500 2800
Wire Bus Line
	2750 1300 5750 1300
Entry Wire Line
	2750 2800 2850 2900
Entry Wire Line
	2750 2700 2850 2800
Entry Wire Line
	2750 2600 2850 2700
Entry Wire Line
	2750 2500 2850 2600
Wire Wire Line
	2850 2600 3100 2600
Wire Wire Line
	3100 2700 2850 2700
Wire Wire Line
	2850 2800 3100 2800
Wire Wire Line
	3100 2900 2850 2900
Wire Wire Line
	2850 3000 3100 3000
Entry Wire Line
	2750 2900 2850 3000
Wire Wire Line
	2300 3100 3100 3100
Wire Wire Line
	2300 3200 3100 3200
Wire Wire Line
	2300 3300 3100 3300
Wire Wire Line
	2300 3400 3100 3400
Wire Wire Line
	2550 4000 3100 4000
Wire Wire Line
	2450 4600 3100 4600
Entry Wire Line
	2950 2400 3050 2500
Entry Wire Line
	2950 2300 3050 2400
Entry Wire Line
	2950 2200 3050 2300
Entry Wire Line
	2950 2100 3050 2200
Wire Wire Line
	3050 2200 3100 2200
Wire Wire Line
	3050 2300 3100 2300
Wire Wire Line
	3050 2400 3100 2400
Wire Wire Line
	3050 2500 3100 2500
Entry Wire Line
	5450 2500 5550 2600
Entry Wire Line
	5450 2700 5550 2800
Entry Wire Line
	5450 2900 5550 3000
Entry Wire Line
	5450 3000 5550 3100
Entry Wire Line
	5350 4000 5450 4100
Entry Wire Line
	5350 3900 5450 4000
Entry Wire Line
	5350 3700 5450 3800
Entry Wire Line
	5350 3100 5450 3200
Entry Wire Line
	5350 3600 5450 3700
Entry Wire Line
	5350 3500 5450 3600
Entry Wire Line
	5350 3400 5450 3500
Entry Wire Line
	5350 3300 5450 3400
Entry Wire Line
	5350 3200 5450 3300
Entry Wire Line
	5350 4800 5450 4900
Entry Wire Line
	5350 4700 5450 4800
Wire Bus Line
	2950 1700 5550 1700
Wire Wire Line
	5450 2500 5300 2500
Wire Wire Line
	5300 2700 5450 2700
Wire Wire Line
	5450 2900 5300 2900
Wire Wire Line
	5300 3000 5450 3000
Entry Wire Line
	5650 2300 5750 2400
Entry Wire Line
	5650 2400 5750 2500
Wire Wire Line
	5650 2300 5300 2300
Wire Wire Line
	5300 2400 5650 2400
Wire Wire Line
	5300 3100 5350 3100
Wire Wire Line
	5350 3200 5300 3200
Wire Wire Line
	5300 3300 5350 3300
Wire Wire Line
	5350 3400 5300 3400
Wire Wire Line
	5300 3500 5350 3500
Wire Wire Line
	5350 3600 5300 3600
Wire Wire Line
	5300 3700 5350 3700
Wire Wire Line
	5350 3900 5300 3900
Wire Wire Line
	5300 4000 5350 4000
Wire Wire Line
	5350 4700 5300 4700
Wire Wire Line
	5300 4800 5350 4800
Wire Bus Line
	5450 4900 5750 4900
Connection ~ 5750 1300
$Comp
L Switch:SW_Push SW1
U 1 1 5F4E1F1F
P 1850 5200
F 0 "SW1" V 1896 5152 50  0000 R CNN
F 1 "Program" V 1805 5152 50  0000 R CNN
F 2 "" H 1850 5400 50  0001 C CNN
F 3 "" H 1850 5400 50  0001 C CNN
	1    1850 5200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1500 2600 1500 2800
Connection ~ 1500 2800
$Comp
L power:GNDD #PWR?
U 1 1 5F4F3E9F
P 1850 5400
F 0 "#PWR?" H 1850 5150 50  0001 C CNN
F 1 "GNDD" H 1854 5245 50  0000 C CNN
F 2 "" H 1850 5400 50  0001 C CNN
F 3 "" H 1850 5400 50  0001 C CNN
	1    1850 5400
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push_45deg Key1
U 1 1 5F4F4126
P 6700 1800
F 0 "Key1" H 6700 2078 50  0000 C CNN
F 1 "k1" H 6700 1987 50  0000 C CNN
F 2 "" H 6700 1800 50  0001 C CNN
F 3 "" H 6700 1800 50  0001 C CNN
	1    6700 1800
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push_45deg Key?
U 1 1 5F4F8B33
P 7000 1800
F 0 "Key?" H 7000 2078 50  0000 C CNN
F 1 "k1" H 7000 1987 50  0000 C CNN
F 2 "" H 7000 1800 50  0001 C CNN
F 3 "" H 7000 1800 50  0001 C CNN
	1    7000 1800
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push_45deg Key?
U 1 1 5F4F9D1F
P 6700 2250
F 0 "Key?" H 6700 2528 50  0000 C CNN
F 1 "k1" H 6700 2437 50  0000 C CNN
F 2 "" H 6700 2250 50  0001 C CNN
F 3 "" H 6700 2250 50  0001 C CNN
	1    6700 2250
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push_45deg Key?
U 1 1 5F4FAEED
P 7000 2250
F 0 "Key?" H 7000 2528 50  0000 C CNN
F 1 "k1" H 7000 2437 50  0000 C CNN
F 2 "" H 7000 2250 50  0001 C CNN
F 3 "" H 7000 2250 50  0001 C CNN
	1    7000 2250
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push_45deg Key?
U 1 1 5F4FC0C3
P 7300 1800
F 0 "Key?" H 7300 2078 50  0000 C CNN
F 1 "k1" H 7300 1987 50  0000 C CNN
F 2 "" H 7300 1800 50  0001 C CNN
F 3 "" H 7300 1800 50  0001 C CNN
	1    7300 1800
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push_45deg Key?
U 1 1 5F4FD2A1
P 6700 2600
F 0 "Key?" H 6700 2878 50  0000 C CNN
F 1 "k1" H 6700 2787 50  0000 C CNN
F 2 "" H 6700 2600 50  0001 C CNN
F 3 "" H 6700 2600 50  0001 C CNN
	1    6700 2600
	1    0    0    -1  
$EndComp
Connection ~ 6600 1700
Wire Wire Line
	6600 1700 6600 1400
Connection ~ 6600 2150
Wire Wire Line
	6600 2150 6600 1700
Connection ~ 6600 2500
Wire Wire Line
	6600 2500 6600 2150
Connection ~ 6900 1700
Wire Wire Line
	6900 1700 6900 1400
Connection ~ 6900 2150
Wire Wire Line
	6900 2150 6900 1700
Connection ~ 7200 1700
Wire Wire Line
	7200 1700 7200 1400
Wire Wire Line
	6350 1900 6800 1900
Connection ~ 6800 1900
Wire Wire Line
	6800 1900 7100 1900
Connection ~ 7100 1900
Wire Wire Line
	7100 1900 7400 1900
Connection ~ 7400 1900
Wire Wire Line
	7400 1900 7600 1900
Wire Wire Line
	6350 2350 6800 2350
Connection ~ 6800 2350
Wire Wire Line
	6800 2350 7100 2350
Connection ~ 7100 2350
Wire Wire Line
	7100 2350 7600 2350
Wire Wire Line
	6350 2700 6800 2700
Wire Wire Line
	6800 2700 7600 2700
Entry Wire Line
	6500 1300 6600 1400
Entry Wire Line
	6800 1300 6900 1400
Entry Wire Line
	7100 1300 7200 1400
Entry Wire Line
	6250 1800 6350 1900
Entry Wire Line
	6250 2250 6350 2350
Entry Wire Line
	6250 2600 6350 2700
Connection ~ 6800 2700
$Comp
L Device:R R3
U 1 1 5F50E93B
P 3350 6300
F 0 "R3" V 3143 6300 50  0000 C CNN
F 1 "4.7k" V 3234 6300 50  0000 C CNN
F 2 "" V 3280 6300 50  0001 C CNN
F 3 "~" H 3350 6300 50  0001 C CNN
	1    3350 6300
	0    1    1    0   
$EndComp
Wire Wire Line
	3100 3800 2650 3800
Wire Wire Line
	2650 3800 2650 5000
Wire Wire Line
	1850 5000 2650 5000
Wire Wire Line
	2750 3500 3100 3500
Wire Wire Line
	1450 4800 1500 4800
Connection ~ 1500 4800
Wire Wire Line
	1500 4800 3100 4800
Connection ~ 1150 4500
Wire Wire Line
	1150 4500 1500 4500
$Comp
L Device:R_PHOTO R7
U 1 1 5F52E82C
P 4750 6000
F 0 "R7" H 4820 6046 50  0000 L CNN
F 1 "PhotoRes" H 4820 5955 50  0000 L CNN
F 2 "" V 4800 5750 50  0001 L CNN
F 3 "~" H 4750 5950 50  0001 C CNN
	1    4750 6000
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5F52E8ED
P 4750 6150
F 0 "#PWR?" H 4750 5900 50  0001 C CNN
F 1 "GNDD" H 4754 5995 50  0000 C CNN
F 2 "" H 4750 6150 50  0001 C CNN
F 3 "" H 4750 6150 50  0001 C CNN
	1    4750 6150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5F52EA20
P 4750 5700
F 0 "R6" H 4820 5746 50  0000 L CNN
F 1 "120k" H 4820 5655 50  0000 L CNN
F 2 "" V 4680 5700 50  0001 C CNN
F 3 "~" H 4750 5700 50  0001 C CNN
	1    4750 5700
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5F52EB6F
P 4750 5550
F 0 "#PWR?" H 4750 5400 50  0001 C CNN
F 1 "+3V3" H 4765 5723 50  0000 C CNN
F 2 "" H 4750 5550 50  0001 C CNN
F 3 "" H 4750 5550 50  0001 C CNN
	1    4750 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 4700 3050 4700
Wire Wire Line
	3050 4700 3050 5200
Wire Wire Line
	3050 5200 4450 5200
Wire Wire Line
	4450 5200 4450 5850
Wire Wire Line
	4450 5850 4750 5850
Connection ~ 4750 5850
Wire Bus Line
	5550 1700 6250 1700
Connection ~ 5550 1700
Text Label 6550 1200 0    79   ~ 0
Columns
Text Label 6050 1650 0    79   ~ 0
Rows
Text Label 6250 1000 0    98   ~ 0
Keyboard-Matrix
Text Label 7300 2650 0    79   ~ 0
etc.
Wire Wire Line
	7200 1700 7200 2900
Wire Wire Line
	6900 2150 6900 2900
Wire Wire Line
	6600 2500 6600 2900
Wire Wire Line
	2750 5450 2300 5450
Wire Wire Line
	2300 5450 2300 5600
Wire Wire Line
	2750 3500 2750 5450
Wire Wire Line
	2950 4500 2950 6300
Wire Wire Line
	2950 6300 3200 6300
Wire Wire Line
	2950 4500 3100 4500
Wire Bus Line
	5750 1300 5750 4900
Wire Bus Line
	6250 1700 6250 3000
Wire Bus Line
	2950 1700 2950 2400
Wire Bus Line
	5550 1700 5550 3100
Wire Bus Line
	5750 1300 7600 1300
Wire Bus Line
	2750 1300 2750 2900
Wire Bus Line
	5450 3200 5450 4900
$EndSCHEMATC
