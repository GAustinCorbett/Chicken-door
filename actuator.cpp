/*  actuator.cpp - Library for controlling a linear actuator w/2 relays & an Arduino
 *  Created by G. Austin Corbett gaustincorbett@gmail.com, 2019
 *  Released: GPLv3, 2019
 */

#include "Arduino.h"
#include "actuator.h"

actuator::actuator(const relay &openRel, const relay &closeRel, const long &MOTORDELAY):_openRel{openRel} , _closeRel{closeRel} , MOTORDELAY{MOTORDELAY}{
    state = 0;
}    
    
void actuator::lengthen(){
    _closeRel.off(); // Turn off closing relay Just in case
    _openRel.on();   // Turn on opening relay and leave on
    state = 1;
}
    
void actuator::shorten(){
    _openRel.off(); // Turn off closing relay Just in case
    _closeRel.on();   // Turn on opening relay and leave on
    state = -1;
}

void actuator::halt(){
    _openRel.off();
    _closeRel.off();
    state = 0;
}

int actuator::status(){
    return(state);
}
