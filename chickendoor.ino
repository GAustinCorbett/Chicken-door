/*
 *  chickendoor.ino is the main control program to be run on an Arduino Uno
 *  Author: G. Austin Corbett
 *  License: GPLv3
 *  
 *  For documentation see 
 */
#include "IRbreak.h"
#include "RTClib.h"
#include "RTCmod.h"
#include "Dusk2Dawn.h"
#include "actuator.h"

//1.0 GLOBAL PARAMETERS
static float LAT = -124.1288634; //lat + long are for sunrise/sunset calcs
static float LONG = 40.9382061;     
static int UTCOFFSET = -8; //PST is 8 hours behind UTC
static long MOTORDELAY = 120000; //120 seconds, in miliseconds

/*
  pins A4 & A5 are taken for SDA & SCL on the RTC module respectively; they're dedicated i2C clock pins to let the uno interact with the RTC module 
*/

//1.1 INPUT PINS
static int IRSENSORPIN = 2;
static int OPENSENSORPIN = 5;
static int CLOSESENSORPIN = 6; 

//1.2 OUTPUT PINS
static int OPENPIN = 3;
static int CLOSEPIN = 4; 

//1.3 SPECIAL 
//#define LEDPIN 13 //Not necessarily needed, but turning on pin 13 to output will turn on the onboard LED.  Kinda Cool.

//2.0 GLOBAL CLASSES
//RTC_DS3231 rtc;  //Initialize the RTC object class to interact with the RTC module
RTCmod rtcmodule;
IRbreak beam(IRSENSORPIN);  //Initialize irbreak beam object
actuator act(OPENPIN, CLOSEPIN, IRSENSORPIN, OPENSENSORPIN, CLOSESENSORPIN, MOTORDELAY);
//3.0 GLOBAL VARIABLES
int irlaststate = 0;

void setup() {

}

void loop() {

  // put your main code here, to run repeatedly:
  if (beam.getStatus() && !irlaststate) {
    Serial.println("Unbroken");
  }
  if (!beam.getStatus() && irlaststate) {
    Serial.println("Broken");
  }
  irlaststate = beam.getStatus();
  DateTime now = rtcmodule.rtc.now();
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  
  if(!act.openDoor())
  {
    /*throw exception*/
  }  

}
 
