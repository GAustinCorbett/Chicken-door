    #include "relay.h"
    #include "actuator.h"
   
    //OUTPUT PINS
    const int OPENRELPIN = 2; //open relay pin
    const int CLOSERELPIN = 3; //close relay pin
    const int IRTXPWR = 5;
    const int IRRXPWR = 6;
    
    //INPUT PINS  
    const int IRSENSORPIN = 4; 
    //RTC PINS
        // These are taken but needn't be declared:
        // SCL = A5 on Uno, Digtial 21 on Mega
        // SDA = A4 on Uno, Digital 20 on Mega

    //OTHER PARAMETERS:
    const float LAT = -124.1288634; //Lat + Long for sunrise/sunset calcs
    const float LONG = 40.9382061; 
    const float UTCOFFSET = -8;  //PST is 8 hours behind UTC
    const int MOTORDELAY = 120000; //Time to wait for door to fully open/close
    

    //Class instances
    const relay openRel(OPENRELPIN); 
    const relay closeRel(CLOSERELPIN);
    const actuator act(openRel, closeRel, MOTORDELAY);
    
    void setup() {
        // put your setup code here, to run once:
       Serial.begin(9600);
       delay(10);
    }
    
    void loop() {
      ///*
      
      act.lengthen();
      Serial.println("Lengthening");
      delay(1500);
      
      act.halt();
      Serial.println("Halt");
      delay(1500);
      
    
      act.shorten();
      Serial.println("Shortening");
      delay(1500);
      
      
      act.halt();
      Serial.println("Halt");
      //*/
    
      ///*
      closeRel.on();
      Serial.println("closerel on");
      delay(1500);
    
      closeRel.off();
      Serial.println("closerel off");
    
      openRel.on();
      Serial.println("Openrel on");
      delay(1500);
      openRel.off();
      Serial.println("Openrel off");
      //*/
    }
