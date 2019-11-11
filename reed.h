/*  reed.h - Library for interacting with the reed switch sensors on the door
 *  Created by G. Austin Corbett gaustincorbett@gmail.com, 2019
 *  GPLv3
*/

#ifndef reed_h
#define reed_h

#include "Arduino.h"

class reed
{
    public:
        reed(const int &SENSORPIN);
        int getStatus();
    private:
        const int &_SENSORPIN;
};
#endif
