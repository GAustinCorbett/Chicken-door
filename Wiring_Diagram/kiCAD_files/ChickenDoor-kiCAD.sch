EESchema Schematic File Version 4
LIBS:ChickenDoor-kiCAD-cache
EELAYER 30 0
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
L ChickenDoor-kiCAD-rescue:Arduino_UNO_R3-MCU_Module A?
U 1 1 5DE0B9A7
P 7750 3050
F 0 "A?" H 7750 4231 50  0000 C CNN
F 1 "Arduino_UNO_R3" H 7750 4140 50  0000 C CNN
F 2 "Module:Arduino_UNO_R3" H 7750 3050 50  0001 C CIN
F 3 "https://www.arduino.cc/en/Main/arduinoBoardUno" H 7750 3050 50  0001 C CNN
	1    7750 3050
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_DC M_LInear_Actuator
U 1 1 5DE0D523
P 2850 5150
F 0 "M_LInear_Actuator" H 3008 5146 50  0000 L CNN
F 1 "Motor_DC" H 3008 5055 50  0000 L CNN
F 2 "" H 2850 5060 50  0001 C CNN
F 3 "~" H 2850 5060 50  0001 C CNN
	1    2850 5150
	0    -1   -1   0   
$EndComp
$Comp
L Device:Battery_Cell 12VDC
U 1 1 5DE348E7
P 4000 2350
F 0 "12VDC" H 4118 2446 50  0000 L CNN
F 1 "Battery_Cell" H 4118 2355 50  0000 L CNN
F 2 "" V 4000 2410 50  0001 C CNN
F 3 "~" V 4000 2410 50  0001 C CNN
	1    4000 2350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4850 4350 5000 4350
Wire Wire Line
	5000 4750 4850 4750
Wire Wire Line
	4850 3450 6200 3450
Wire Wire Line
	6200 3450 6200 2650
Wire Wire Line
	6200 2650 7250 2650
Wire Wire Line
	7250 2750 6400 2750
Wire Wire Line
	6400 2750 6400 3750
Wire Wire Line
	6400 3750 4850 3750
Wire Wire Line
	9350 2900 8950 2900
Wire Wire Line
	8950 2900 8950 3750
Wire Wire Line
	8950 3750 8250 3750
Wire Wire Line
	9350 2800 8850 2800
Wire Wire Line
	8850 2800 8850 3850
Wire Wire Line
	8850 3850 8250 3850
$Comp
L Timer_RTC:DS3231M U?
U 1 1 5DE74A54
P 9850 3000
F 0 "U?" H 9850 2511 50  0000 C CNN
F 1 "DS3231M" H 9850 2420 50  0000 C CNN
F 2 "Package_SO:SOIC-16W_7.5x10.3mm_P1.27mm" H 9850 2400 50  0001 C CNN
F 3 "http://datasheets.maximintegrated.com/en/ds/DS3231.pdf" H 10120 3050 50  0001 C CNN
	1    9850 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9850 3400 9850 4150
Wire Wire Line
	9850 4150 7850 4150
Wire Wire Line
	7950 2050 9750 2050
Wire Wire Line
	9750 2050 9750 2600
$Comp
L Device:Battery_Cell 3.6V
U 1 1 5DE7D916
P 10500 2950
F 0 "3.6V" H 10618 3046 50  0000 L CNN
F 1 "Battery_Cell" H 10618 2955 50  0000 L CNN
F 2 "" V 10500 3010 50  0001 C CNN
F 3 "~" V 10500 3010 50  0001 C CNN
	1    10500 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	10500 2750 10500 2600
Wire Wire Line
	10500 2600 9850 2600
Wire Wire Line
	10500 3050 10500 3400
Wire Wire Line
	10500 3400 9850 3400
Connection ~ 9850 3400
Wire Wire Line
	4850 4150 4900 4150
Wire Wire Line
	5000 4150 5000 2850
Wire Wire Line
	4850 4550 4900 4550
Wire Wire Line
	4900 4550 4900 4150
Connection ~ 4900 4150
Wire Wire Line
	4900 4150 5000 4150
Connection ~ 7850 4150
Connection ~ 7650 4150
Wire Wire Line
	7650 4150 7750 4150
Connection ~ 7750 4150
Wire Wire Line
	7750 4150 7850 4150
$Comp
L Switch:SW_Push_Open EMERGENCYSTOP
U 1 1 5DEE2522
P 3500 2350
F 0 "EMERGENCYSTOP" H 3500 2565 50  0000 C CNN
F 1 "SW_Push_Open" H 3500 2474 50  0000 C CNN
F 2 "" H 3500 2550 50  0001 C CNN
F 3 "~" H 3500 2550 50  0001 C CNN
	1    3500 2350
	-1   0    0    1   
$EndComp
Wire Wire Line
	3800 2350 3700 2350
Entry Wire Line
	5650 2750 5750 2850
Entry Wire Line
	4150 2750 4250 2850
Entry Wire Line
	4900 2750 5000 2850
Wire Wire Line
	5750 2850 5750 4150
Wire Wire Line
	5750 4150 7650 4150
Wire Wire Line
	4250 2850 4250 3450
Entry Wire Line
	4050 2750 4150 2650
$Comp
L sensor_optical_ir_breakbeam_sensor:Sensor_Optical_IR_breakbeam_Sensor U?
U 1 1 5DFB487E
P 7500 1700
F 0 "U?" H 6525 2415 50  0000 C CNN
F 1 "Sensor_Optical_IR_breakbeam_Sensor" H 6525 2324 50  0000 C CNN
F 2 "" H 7500 1700 50  0001 C CNN
F 3 "" H 7500 1700 50  0001 C CNN
	1    7500 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 1400 7050 1850
Wire Wire Line
	7050 1850 5700 1850
Entry Wire Line
	5600 2750 5700 2650
Wire Wire Line
	5700 2650 5700 1850
Wire Wire Line
	6000 1400 5700 1400
Wire Wire Line
	5700 1400 5700 1850
Connection ~ 5700 1850
Wire Wire Line
	6000 1250 6000 900 
Wire Wire Line
	7250 2950 7150 2950
Wire Wire Line
	7150 2950 7150 1250
Wire Wire Line
	7150 1250 7050 1250
Wire Wire Line
	7250 3050 7200 3050
Wire Wire Line
	7200 3050 7200 900 
Wire Wire Line
	7200 900  6000 900 
Wire Wire Line
	6000 1550 6000 3150
Wire Wire Line
	6000 3150 7250 3150
$Comp
L sw_dpdt_msm_center-off:SW_DPDT_MSM_Center-OFF SW_RockerSW_manual_moto_ctl
U 1 1 5DF5CA63
P 2600 3600
F 0 "SW_RockerSW_manual_moto_ctl" H 2642 4285 50  0000 C CNN
F 1 "SW_DPDT_MSM_Center-OFF" H 2642 4194 50  0000 C CNN
F 2 "" H 2600 3600 50  0001 C CNN
F 3 "~" H 2600 3600 50  0001 C CNN
	1    2600 3600
	0    -1   -1   0   
$EndComp
$Comp
L relay_h-l_12vdc_5vtrigger_nc_no:Relay_H-L_12VDC_5vTrigger_NC_NO K?
U 1 1 5DE3FD87
P 4550 4450
F 0 "K?" H 4980 4496 50  0001 L CNN
F 1 "Relay_H-L_12VDC_5vTrigger_NC_NO" V 4980 4405 50  0000 L CNN
F 2 "Relay_THT:Relay_SPDT_SANYOU_SRD_Series_Form_C" H 5000 4400 50  0001 L CNN
F 3 "http://www.sanyourelay.ca/public/products/pdf/SRD.pdf" H 4150 4550 50  0001 C CNN
	1    4550 4450
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push_DPDT SW_Toggle-auto-or-manual?
U 1 1 5E6F2DFB
P 2900 4600
F 0 "SW_Toggle-auto-or-manual?" V 2946 4212 50  0000 R CNN
F 1 "SW_Push_DPDT" V 2855 4212 50  0000 R CNN
F 2 "" H 2900 4800 50  0001 C CNN
F 3 "~" H 2900 4800 50  0001 C CNN
	1    2900 4600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2600 4400 2200 4400
Wire Wire Line
	2200 4400 2200 3800
Wire Wire Line
	3000 4400 3000 4100
Wire Wire Line
	3000 4100 2600 4100
Wire Wire Line
	2600 4100 2600 3800
Wire Wire Line
	3200 4400 4250 4400
Wire Wire Line
	4250 4400 4250 4650
Wire Wire Line
	2800 4400 2800 4250
Wire Wire Line
	2800 4250 4250 4250
Wire Wire Line
	2700 4800 2700 4900
Wire Wire Line
	2700 4900 2650 4900
Wire Wire Line
	2650 4900 2650 5150
Wire Wire Line
	3100 4800 3100 4900
Wire Wire Line
	3100 4900 3150 4900
Wire Wire Line
	3150 4900 3150 5150
Wire Wire Line
	2700 3400 2700 2350
Wire Wire Line
	2700 2350 3300 2350
Wire Wire Line
	4100 2350 4150 2350
Wire Wire Line
	4150 2350 4150 2650
Wire Wire Line
	4250 2850 2500 2850
Wire Wire Line
	2500 2850 2500 3400
Wire Wire Line
	3800 2350 3800 3850
Connection ~ 3800 2350
Wire Wire Line
	5000 4350 5000 4750
Wire Wire Line
	4100 3850 4100 3100
Wire Wire Line
	4100 3100 5200 3100
Wire Wire Line
	5200 3100 5200 4350
Wire Wire Line
	5200 4350 5000 4350
Wire Wire Line
	3800 3850 4100 3850
Wire Bus Line
	4050 2750 5800 2750
Connection ~ 4100 3850
Wire Wire Line
	4100 3850 4250 3850
Connection ~ 5000 4350
$EndSCHEMATC
