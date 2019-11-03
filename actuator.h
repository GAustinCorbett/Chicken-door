/*
    actuator.h - Library for interacting with the linear actuator (via NO relays) and an arduino uno
    Created by G. Austin Corbett gaustincorbett@gmail.com, 2019
    Released via GPLv3
*/

#ifndef actuator_h
#define actuator_h

#include "Arduino.h"
#include "IRbreak.h"

class actuator
{
    public:
        actuator(int OPENPIN, int CLOSEPIN, int IRSENSORPIN, int MOTORDELAY);
        int openDoor();
        int closeDoor();
    private:
        int _OPENPIN;
        int _CLOSEPIN; 
        int _IRSENSORPIN;
        //IRbreak _beam;
        int _MOTORDELAY;
};

#endif
