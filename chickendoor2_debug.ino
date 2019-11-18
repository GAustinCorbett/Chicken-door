#include "relay.h"
#include "actuator.h"
#include "IR.h"
#include "Door.h"
#include "Dusk2Dawn.h"
#include "RTClib.h" 
#include "TimeOps.h"

//OUTPUT PINS
const int OPENRELPIN = 2; //open relay pin
const int CLOSERELPIN = 3; //close relay pin
const int IRTXPWR = 5;
const int IRRXPWR = 6;

//INPUT PINS  
const int IRSENSORPIN = 4; 

//RTC PINS
    // These are taken but needn't be declared:
    // SCL = A5 on Uno, Digtial 21 on Mega
    // SDA = A4 on Uno, Digital 20 on Mega

//OTHER PARAMETERS:
const float LAT = 40.9382; //Lat + Long for sunrise/sunset calcs
const float LONG = -124.1288; 
const float UTCOFFSET = -8.0;  //PST is 8 hours behind UTC
const long MOTORDELAY = 120000; //Time to wait for door to fully open/close
const int SUNSETOFFSET = 40;  //Door close time = sunset_time + SUNSETOFFSET (minutes)
const int SUNRISEOFFSET = -30; //Door close time = sunrise_time+ SUNRISEOFFSET (minutes)

//Class instances
const relay openRel(OPENRELPIN); 
const relay closeRel(CLOSERELPIN);
const actuator act(openRel, closeRel, MOTORDELAY);
const IR ir(IRSENSORPIN, IRTXPWR, IRRXPWR);
const Door door(ir , act);
const Dusk2Dawn d2d(LAT, LONG, UTCOFFSET);
RTC_DS3231 rtc; //Potentially needs to have time reset, not sure if being const would interfere.
TimeOps timeObj(rtc, d2d, SUNRISEOFFSET,  SUNSETOFFSET);


void setup() {
  Serial.begin(9600);
  delay(2000);
  Serial.println("Beginning setup");
  //initialization for RTC:
#ifndef ESP8266
  while (!Serial); // for Leonardo/Micro/Zero
#endif

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
    timeObj.update();
}

void loop() {
    ///*
    Serial.print("timeObj.nextEvent(): ");
    Serial.println(timeObj.nextEvent());
    Serial.print("timeObj.nextEventTime().hour(): ");
    Serial.print(timeObj.nextEventTime().hour());
    Serial.print(":");
    Serial.println(timeObj.nextEventTime().minute());
    Serial.print("timeObj.currentTime().hour(): ");
    Serial.print(timeObj.currentTime().hour());
    Serial.print(":");
    Serial.println(timeObj.currentTime().minute());
        
    if (timeObj.currentTime().operator>(timeObj.nextEventTime())){
        if (timeObj.nextEvent()=="sunset"){
            door.close();
        }
        else{
            door.open();
        }
        delay(90000);  //Wait 90 sec to make sure timeObj.update() kicks comparison to next minute
        timeObj.update();
    }  
    delay(60000);
}
