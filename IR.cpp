#include "Arduino.h"
#include "IR.h"

IR::IR(const int &SENSORPIN , const int &TXPWRPIN, const int &RXPWRPIN):_SENSORPIN{SENSORPIN},_TXPWRPIN{TXPWRPIN},_RXPWRPIN{RXPWRPIN}{
   
    pinMode(_SENSORPIN, INPUT_PULLUP); //should be input_pullup?
    digitalWrite(_SENSORPIN, HIGH); //Turn on the pull-up, probably redundant
    
    //Initialize in an unpowered state:
    pinMode(_TXPWRPIN, OUTPUT);
    digitalWrite(_TXPWRPIN, LOW); 
    pinMode(_RXPWRPIN, OUTPUT);
    digitalWrite(_RXPWRPIN, LOW); 

    int onoff;
}

int IR::getStatus(){
    return(digitalRead(_SENSORPIN)); // 1 = broken beam
}

void IR::turnOn(){
    digitalWrite(_TXPWRPIN, HIGH);
    digitalWrite(_RXPWRPIN, HIGH);
    delay(1000); //Give it a second to get a reading.
}

void IR::turnOff(){
    digitalWrite(_TXPWRPIN, LOW);
    digitalWrite(_RXPWRPIN, LOW);
}
