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
const float LAT = -124.1288634; //Lat + Long for sunrise/sunset calcs
const float LONG = 40.9382061; 
const float UTCOFFSET = -8;  //PST is 8 hours behind UTC
const int MOTORDELAY = 120000; //Time to wait for door to fully open/close


//Class instances
const relay openRel(OPENRELPIN); 
const relay closeRel(CLOSERELPIN);
const actuator act(openRel, closeRel, MOTORDELAY);
const IR ir(IRSENSORPIN, IRTXPWR, IRRXPWR);
const Door door(ir , act);
const Dusk2Dawn d2d(LAT, LONG, UTCOFFSET);
RTC_DS3231 rtc; //Potentially needs to have time reset, not sure if being const would interfere.
TimeOps timeObj(rtc, d2d);

void setup() {
   Serial.begin(9600);
   delay(3000);
   
  //initialization for RTC:
  #ifndef ESP8266
    while (!Serial); // for Leonardo/Micro/Zero
  #endif
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  //END initialization for RTC
}

void loop() {
    if (timeObj.currentTime().operator>=(timeObj.nextEventTime())){
        if (timeObj.nextEvent()=='sunset'){
            door.close();
        }
        else{
            door.open();
        }
        delay(90000);  //Wait 90 sec to make sure timeObj.update() kicks comparison to next minute
        timeObj.update();
    }
  /*
  act.lengthen();
  Serial.println("Lengthening");
  delay(1500);
  act.halt();
  Serial.println("Halt");
  delay(1500);
  act.shorten();
  Serial.println("Shortening");
  delay(1500);
  act.halt();
  Serial.println("Halt");
  //*/

  /*
  closeRel.on();
  Serial.println("closerel on");
  delay(1500);
  closeRel.off();
  Serial.println("closerel off");
  openRel.on();
  Serial.println("Openrel on");
  delay(1500);
  openRel.off();
  Serial.println("Openrel off");
  //*/
}
