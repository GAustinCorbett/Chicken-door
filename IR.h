/*
    IR.h - Library for interacting with the IR breakbeam sensor and arduino uno
    Created by G. Austin Corbett gaustincorbett@gmail.com, 2019
    Released via GPLv3
*/

#ifndef IR
#define IR

#include "Arduino.h"

class IR {
    public: 
        IR(const int &SENSORPIN , const int &TXPWRPIN, const int &RXPWRPIN);
        int getStatus();
        void turnOn();
        void turnOff();
    private:
        const int &_SENSORPIN; 
        const int &_TXPWRPIN;
        const int &_RXPWRPIN;
};

#endif
