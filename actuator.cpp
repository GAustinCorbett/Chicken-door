/*
    actuator.cpp - Library for interacting with the linear actuator (via 2 N.O. relays)
    Authored by G. Austin Corbett gaustincorbett@gmail.com 
    Released under GPLv3
*/

#include "Arduino.h"
#include "actuator.h"
#include "IRbreak.h"

/*
 * class constructor for "actuator" class.  Initializes the trigger pins for the opening relay and closing door relay

 */
actuator::actuator(int OPENPIN, int CLOSEPIN, int IRSENSORPIN , int CLOSESENSORPIN, int OPENSENSORPIN, int MOTORDELAY)
{
    // set the pinMode on the Arduino to OUTPUT for the trigger pins.  
    // When switched to "HIGH" (+5V) the relay will close the circuit and run the actuator

    pinMode(OPENPIN, OUTPUT);
    pinMode(CLOSEPIN, OUTPUT);
  
    //Ensure that both trigger pins are set to low (0v) at boot:
    digitalWrite(OPENPIN, LOW);
    digitalWrite(CLOSEPIN, LOW);
    
    //initialize the private variables of the class: 
    _OPENPIN = OPENPIN; //open door relay trigger pin
    _CLOSEPIN = CLOSEPIN;  //close door relay trigger pin
    _IRSENSORPIN = IRSENSORPIN;
    _CLOSESENSORPIN = CLOSESENSORPIN;   
    _OPENSENSORPIN = OPENSENSORPIN;
    //IRbreak _beam(_IRSENSORPIN); //irbreak instance to check status of ir break sensor on closing  
    _MOTORDELAY = MOTORDELAY;
}

/*
 * When called, openDoor() should change the relay trigger pin to high for long enough 
 * that the actuator can run it's full length.  (Actuator switches off automatically at
 * end of run, but the pin output needs to be reset to 0V
*/
int actuator::openDoor()
{
    /*
     * Need to add a check of the door sensors here, and a method to throw an exception
     * if we arrive here with the door sensor not showing 'closed'.
    */ 
    digitalWrite(_CLOSEPIN, LOW); //Just in case we forgot to untrigger closing relay
    digitalWrite(_OPENPIN, HIGH);  //Trigger the Opening relay
    delay(_MOTORDELAY); //wait, should be ~2 minutes
    
    /*
    Add check if successful via door sensors?, else try again or return(1)?
    */ 

    //Untrigger the relay & return no error:
    digitalWrite(_OPENPIN, LOW); 
    return(0);
}

int actuator::closeDoor()
{
    digitalWrite(_OPENPIN, LOW); //Just in case. 
    IRbreak beam(_IRSENSORPIN); 
    beam.getStatus();
}
