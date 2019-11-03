/*
    actuator.cpp - Library for interacting with the linear actuator (via 2 N.O. relays)
    Authored by G. Austin Corbett gaustincorbett@gmail.com 
    Released under GPLv3
*/

#include "Arduino.h"
#include "actuator.h"
#include "IRbreak.h"

//class constructor for "actuator" class.  Initializes the trigger pins for the opening relay and closing door relay

actuator::actuator(int OPENPIN, int CLOSEPIN, int IRSENSORPIN , int MOTORDELAY)
{
    // set the pinMode on the Arduino to OUTPUT for the trigger pins.  
    // When switched to "HIGH" (+5V) the relay will close the circuit and run the actuator

    pinMode(OPENPIN, OUTPUT);
    pinMode(CLOSEPIN, OUTPUT);
  
    //Ensure that both trigger pins are set to low (0v) at boot
    digitalWrite(OPENPIN, LOW);
    digitalWrite(CLOSEPIN, LOW);
    
    //initialize the private variables of the class: 
    _OPENPIN = OPENPIN;
    _CLOSEPIN = CLOSEPIN; 
    _IRSENSORPIN = IRSENSORPIN; 
    //IRbreak _beam(_IRSENSORPIN); //irbreak instance to check status of ir break sensor on closing  
    _MOTORDELAY = MOTORDELAY;
}

int actuator::openDoor()
{
    /*
    Need to add a check of the door sensors here, and a method to throw an exception
    if we arrive here with the door sensor not showing 'closed'.
    */ 
    
    digitalWrite(_OPENPIN, HIGH); 
    delay(_MOTORDELAY); //wait 2 minutes
    
    /*
    Add check if successful?, else try again or return(1); 
    */ 
    digitalWrite(_OPENPIN, LOW);
    return(0);
}

int actuator::closeDoor()
{
    IRbreak beam(_IRSENSORPIN);
    beam.getStatus();
}
