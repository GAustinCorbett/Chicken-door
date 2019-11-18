/*  Door.cpp - Library for controlling Door object composed of ir and actuator objects
 *  Created by G. Austin Corbett gaustincorbett@gmail.com
 *  Release GPLv3 2019 
 */

#include "Arduino.h"
#include "actuator.h"
#include "IR.h"
#include "Door.h"

Door::Door(const IR &ir, const actuator &act):ir_{ir},act_{act}{
    state_ = 0; //I'm not sure this is what it should default to. 
}

void Door::open(){
    act_.halt();  //stop the actuator if it isn't already
    act_.lengthen();  //open the Door
    
    delay(act_.MOTORDELAY);  //Wait for the Door to open all the way
    
    act_.halt();  //shut off the relay
    state_ = 0;
}
void Door::close(){

    ir_.turnOn();
    unsigned long start_time = 0;
    int i = 0;
    bool failstatus = false;

    // If sensor beam is broken, test every 10 seconds, if it stays broken for 
    // more than 60 seonds, assume failed and close Door without safety sensor
    while(i<6 && ir_.getStatus()){
        i++;
        if(i == 6){
            failstatus = true;
            act_.halt();
            act_.shorten();
            delay(act_.MOTORDELAY);
            act_.halt();
            ir_.turnOff();  
            state_ = 1;
            // SEND AN ERROR IF WIFI!
            return;
        }
        delay(10000);
    }
   
    // Gets here if the sensor is working:
    act_.shorten();  //begin closing the Door
    start_time = millis();  //check current time in milliseconds

    while(Door::isTimeUp(start_time)!=1){
       if(ir_.getStatus()){ //if beam is broken, open Door and start over (2 min cycle)
           act_.halt();
           open(); 
           start_time = millis();  //reset the clock
           act_.shorten();   //and start closing again.
       }
    }
    act_.halt();
    ir_.turnOff();
    state_ = 1;
    return;
}


int Door::getStatus(){
    return(state_);
}

void Door::setState(int state){
    state_ = state;
}

bool Door::isTimeUp(unsigned long start_time){
    unsigned long current_time = millis();
    unsigned long end_time = start_time + act_.MOTORDELAY;
    
    //if not wrapped around
    if(start_time < end_time){
        if( current_time < end_time){
            return false;
        }
        else {
            return true;
        }
    }
    //if wrapped around
    else{
        if( (current_time > start_time) || (current_time < end_time) ){
            return false;
        }
        else
            return true;
    }
}
