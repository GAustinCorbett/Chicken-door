    /* 
     *  relay.cpp - library to set up and control relays with arduino
     *  Created by G. Austin Corbett gaustincorbett@gmail.com 2019
     *  Released: GPLv3
     * 
     *  Relay should be triggerable by the 'HIGH' voltage of Arduino logic pin
     *  
     */

#include "Arduino.h"
#include "relay.h"

//Class constructor: Set up the trigger pin, initially untriggered.

relay::relay(const int &TRIGGERPIN):_TRIGGERPIN{TRIGGERPIN}{
    pinMode(_TRIGGERPIN, OUTPUT);  
    digitalWrite(_TRIGGERPIN, LOW);  //Probably unneccessary
    state = 0;  // initial state is untriggered = 0
}

int relay::on(){
    digitalWrite(_TRIGGERPIN, HIGH);
    state = 1;
    return(0);
}

int relay::off(){
    digitalWrite(_TRIGGERPIN, LOW);
    state = 0; 
    return(0);
}

int relay::status(){
    return(state);
}
