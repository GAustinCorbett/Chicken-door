/*  door.h - Library to create a door object built from actuator & IR break sensor.
 *  Created by G. Austin Corbett gaustincorbett@gmail.com
 *  Release via GPLv3, 2019
 *
 */

#ifndef door_h
#define door_h

#include "Arduino.h"
#include "relay.h"
#include "actuator.h"
#include "IR.h"

class door{
      
    public:
        door(const IR &ir, const actuator &act);
        void close();
        void open();
        int getStatus(); //door status: 0 = open, 1 = closed
        void setState(int state);
    private:
        int state_; 
        bool isTimeUp(unsigned long start_time);
        //int the_time_;
        const actuator &act_;
        const IR &ir_;
};

#endif
