    #include "relay.h"
    #include "actuator.h"
    
    int PARAM1 = 2;
    int PARAM2 = 3;
    int MOTORDELAY = 120000;
    
    const relay openRel(PARAM1); 
    const relay closeRel(PARAM2);
    
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
