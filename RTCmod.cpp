#include "Arduino.h"
#include "RTClib.h"
#include "RTCmod.h"

RTCmod::RTCmod()
{
  RTC_DS3231 rtc;

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
}
