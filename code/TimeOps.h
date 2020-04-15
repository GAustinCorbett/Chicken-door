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
        TimeOps(RTC_DS3231 &rtc, const Dusk2Dawn &d2d, const int &SUNRISEOFFSET, const int &SUNSETOFFSET );
        void update(); //update the now_ DateTime obj and the sunrise/sunset integer times
        DateTime currentTime(); 
        String nextEvent();  //  1 = sunset/closing event, 0 = sunrise/opening event
        DateTime nextEventTime(); //DateTime object of next event 
    private:
        DateTime intToDT(int event);
        const Dusk2Dawn &d2d_;
        RTC_DS3231 &rtc_;
        const int &SUNRISEOFFSET_;
        const int &SUNSETOFFSET_;
        DateTime now_;
        int sunrise_;
        int sunset_;
        String nextEvent_;
};
#endif
