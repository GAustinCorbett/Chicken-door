/*
    RTCmod.h - Library for interacting with the RTClib object which interacts with the RTC hardware module and arduino uno
    Created by G. Austin Corbett gaustincorbett@gmail.com, 2019
    Released via GPLv3
*/

#ifndef RTCmod_h
#define RTCmod_h

#include "Arduino.h"
#include "RTClib.h"

class RTCmod
{
    public: 
        RTCmod();
        RTC_DS3231 rtc;
    private: 
};

#endif
