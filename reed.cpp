/*
    reed.cpp - constructor & methods for reedswitch.h, a library for interacting with the
    reed switch sensors and the arduino.
    The reed switch should be connected with one leg going to sensor pin, and the other leg 
    going to GND.  (THIS IS VERY IMPORTANT, OTHERWISE SWITCH WILL NEVER TRIGGER.)
    Created by G. Austin Corbett gaustincorbett@gmail.com 2019
    Released under GPLv3
*/

#include "Arduino.h"
#include "reed.h"

//Class constructor, sets the class input int as the input pin for the sensor
reed::reed(const int &SENSORPIN):_SENSORPIN{SENSORPIN}
{
    //This stabilizes the circuit against noise but inverts logic:
    pinMode(_SENSORPIN, INPUT_PULLUP);
 
    // Enables the internal pullup resistor to stabilize against noise. 
    digitalWrite(_SENSORPIN, HIGH);

}

int reed::getStatus()
{
    if (digitalRead(_SENSORPIN))
    {
        return(0);    
    }
    else
    {
        return (1);
    } 
}
