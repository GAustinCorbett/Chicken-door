/*
 *  chickendoor.ino is the main control program to be run on an Arduino Uno
 *  Author: G. Austin Corbett
 *  License: GPLv3
 *  
 *  For documentation see 
 */
#include "IRbreak.h"
#include "RTClib.h"
#include "Dusk2Dawn.h"

//1.0 GLOBAL PARAMETERS
static float LAT = -124.1288634; //lat + long are for sunrise/sunset calcs
static float LONG = 40.9382061;     
static int UTCOFFSET = -8; //PST is 8 hours behind UTC

/*
 * pins A4 & A5 are taken for SDA & SCL on the RTC module respectively; they're dedicated i2C clock pins to let the uno interact with the RTC module 
*/

//1.1 INPUT PINS
static int IRSENSORPIN = 2;

//1.2 OUTPUT PINS


//1.3 SPECIAL 
//#define LEDPIN 13 //Not necessarily needed, but turning on pin 13 to output will turn on the onboard LED.  Kinda Cool.

//2.0 GLOBAL CLASSES
RTC_DS3231 rtc;  //Initialize the RTC object class to interact with the RTC module
IRbreak beam(IRSENSORPIN);  //Initialize irbreak beam object

//3.0 GLOBAL VARIABLES
int irlaststate = 0;

void setup() {
//SETUP THE RTC MODULE:   THIS NEEDS TO BE CHANGED TO USE THE NETWORK TIME WHEN THAT'S AVAILABLE.

#ifndef ESP8266
  while (!Serial); // for Leonardo/Micro/Zero
#endif
 
  Serial.begin(9600);

  delay(3000); // wait for console opening

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
//END SETUP OF RTC MODULE 
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
}
 
