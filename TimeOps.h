/* 
 * TimeOps.h - Library for comparing Dusk2Dawn.h sunrise/sunset times 
 *  and RTClib.h DateTime objects
 *  Created by G. Austin Corbett gaustincorbett@gmail.com, 2019
 *  Relased via GPLv3
 */
 
#ifndef TimeOps_h
#define TimeOps_h

#include "RTClib.h"
#include "Arduino.h"
#include "Dusk2Dawn.h" 

class TimeOps{
    public:
        TimeOps(RTC_DS3231 &rtc, Dusk2Dawn &d2d );
        int nextEvent();  //  1 = sunset/closing event, 0 = sunrise/opening event
        int nextEventTime(); //Time of next event in minutes from midnight
        int con2MinFromMid( Datetime &adate); //convert DateTime object to minutes from midnight
        
    private:
        Dusk2Dawn &d2d_;
        RTC_DS3231 &rtc_;
       
        int sunrise_;
        int sunset_;

#endif
