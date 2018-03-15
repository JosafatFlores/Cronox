    #include <avr/sleep.h>
    
    int contacto = 2;
    int led= 13; 
    int contador = 0;

 void wake ()
    {
      // cancel sleep as a precaution
      sleep_disable();
      // precautionary while we do other stuff
      detachInterrupt (2);
    }  // end of wake
    
    void setup () 
      {
    Serial.begin(9600);
      pinMode(contacto,INPUT);
      pinMode(led, OUTPUT); 
       ADCSRA = 0;  
      set_sleep_mode (SLEEP_MODE_PWR_DOWN);  
      sleep_enable();
      attachInterrupt (contacto, wake, RISING);

    interrupts ();  

    }
    
    void loop(){
      if (digitalRead(contacto)==HIGH){
        contador ++;
        Serial.print(contador);
          digitalWrite(led,HIGH); 
          delay(2000) ;
      }else{
        digitalWrite(led,LOW); 
      }
    }

