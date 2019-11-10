/*  relay.h - library for setup / interaction with relays.
 *  Created by G. Austin Corbett gaustincorbett@gmail.com, 2019
 *  GPLv3
     */ 

#ifndef relay_h
#define relay_h

#include "Arduino.h"

class relay{
    public:
        relay(const int &TRIGGERPIN);
        int on();
        int off();
        int status();
        
    private:
        const int &_TRIGGERPIN;
        int state;
};
#endif
