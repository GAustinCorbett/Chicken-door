/*
    IRbreak.h - Library for interacting with the IR breakbeam sensor and arduino uno
    Created by G. Austin Corbett gaustincorbett@gmail.com, 2019
    Released via GPLv3
*/

#ifndef IRbreak_h
#define IRbreak_h

#include "Arduino.h"

class IRbreak
{
    public: 
        IRbreak(int SENSORPIN);
        int getStatus();
    private:
        int _SENSORPIN; 
};

#endif

