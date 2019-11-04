/*  doorsensor.h - Library for interacting with the reed switch sensors on the door
 *  Created by G. Austin Corbett gaustincorbett@gmail.com, 2019
 *  GPLv3
*/

#ifndef doorsensor_h
#define doorsensor_h

#include "Arduino.h"

class doorsensor
{
    public:
        doorsensor(int SENSORPIN);
        int getStatus();
    private:
        int _SENSORPIN;
};
#endif
