/*  actuator.h - Library for interacting with arduino and a linear actuator via two relays
 *              one for opening, one for closing.  Assuming here that they are NO.  
 *  Created by G. Austin Corbett guastincorbett@gmail.com, 2019
 *  Released via GPLv3 
 */
  
#ifndef actuator_h
#define actuator_h

#include "Arduino.h"
#include "relay.h"

class actuator{
    public:
        actuator(const relay &openRel, const relay &closeRel);
        int lengthen();  // trigger the opening relay
        int shorten();   // trigger the closing relay 
        int halt();      // Untrigger both relays
        int status();  // return -1 = shortening or short, 0 = stopped, 1 = lengthening or long
    private:
        const relay &_openRel;
        const relay &_closeRel;
        int state; //-1 = shortening or short, 0 = stopped, 1 = lengthening or long

};
#endif
