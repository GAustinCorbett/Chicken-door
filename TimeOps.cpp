/*  
 *  TimeOps.cpp - a library to convert between different time types and offer a
 *  appropriate comparisons.  Dusk2Dawn returns sunrise/sunset times based on a date
 *  (and lat/long timezone) based on a day and RTClib has it's own DateTime class
 *  with coparison operators 
 *  Created by G. Austin Corbett, gaustincorbett@gmail.com 2019
 *  Released GPLv3, 2019
 */
#include "RTClib.h"
#include "Arduino.h"
#include "Dusk2Dawn.h"
#include "TimeOps.h"

TimeOps::TimeOps(RTC_DS3231 &rtc, const Dusk2Dawn &d2d):rtc_{rtc}, d2d_{d2d} { 

    update();
}

//updat the now_ mark DateTime object and the sunrise_/sunset_ integers from Dusk2Dawn
void TimeOps::update(){
    now_ = rtc_.now();

    //false refers to Daylight Savings Time.  DateTime doesn't use it
    //so it's easiest to just ignore DST I think. 
    sunrise_ = d2d_.sunrise(now_.year(), now_.month(), now_.day(), false); 
    sunset_ = d2d_.sunset(now_.year(), now_.month(), now_.day(), false);
}

DateTime TimeOps::currentTime(){
    return(rtc_.now());
}

// This is a little dodgy. operator>() uses DateTime and if intToDT 
// picks the wrong date, logical test fails.   I THINK I got it right tho?
String TimeOps::nextEvent(){ 
    String nextEvent_; 
    
    if (now_.operator>(intToDT(sunrise_)) && now_.operator<(intToDT(sunset_))){
        nextEvent_ = "sunset" ;
    }
    else{
        nextEvent_ = "sunrise";
    }
    return(nextEvent_);
}

DateTime TimeOps::nextEventTime(){
    if (nextEvent_ == "sunset"){
        return(intToDT(sunset_));
    }
    else{
        return(intToDT(sunrise_));
    }
}

//Convert next event integer minutes from last midnight to a DateTime Object:
DateTime TimeOps::intToDT(int event){
    int event_hours = floor(event/60.0); // just event/60 would probably work here?
    int event_minutes = (event - event_hours*60);
    
    DateTime dt(now_.year(), now_.month(), now_.day(), event_hours, event_minutes, 0);
   
   // now is after noon, it was set after closing the door, so next event is sunrise
    // And it occurs on the following day from now_.
    if( now_.hour() > 12){  
        dt = dt.operator+(TimeSpan(1,0,0,0)); //adds one day to dt. 
    }
    return(dt); 
}
