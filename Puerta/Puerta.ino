/*
 *Autor: Cristian Josafat Flores Ramirez
 *
 *Puerta que al estar abierta emite una luz
 *y cuanta las veces que se abrio con la ayuda de
 *reed switch, sensor magnetico
 * Licencia GNU General Public License (GNU GPL)
 */
    
#include <avr/sleep.h>                    //Se utiliza la libreria sleep
    
int contacto = 2;                         //variable donde el pin sera el sensor y donde se utilizara la interrrupcion
int led= 13;                              //variable del pin donde se coloca la alarma visual
int contador = 0;                         //Variable para contar cuanta veces ah sido abierta


//Metodp para para quitar el modo sleep del arduino
void despertar (){
  sleep_disable();                         //desactiva el modos sleep del arduino
    contador ++;                               //Incrementa en 1 el contador
  Serial.print(contador);                    //Imprime el contador en la consola
  Serial.print("\n");                        //Salto de linea en consola
  detachInterrupt (2);                     //Desactiva la interrupcion
} 



void setup (){
  Serial.begin(9600);                       //Habilita el puerto serial para enviar informacion a la pc
  pinMode(contacto,INPUT);                  //variable contacto sera de entrada
  pinMode(led, OUTPUT);                     //Variable led sera de salida
  ADCSRA = 0;                               //Minimiza el consumo de energia
  set_sleep_mode (SLEEP_MODE_PWR_DOWN);     //Modo en el que dormira el aduino
  sleep_enable();                           //Pone a dormir el arduino
  attachInterrupt (contacto, despertar, RISING); //Activa la interrupcion con la variable contacto, llama al metodo despertar y enciende los pines
  interrupts ();  
}
    
void loop(){
  if (digitalRead(contacto)==HIGH){          //Se envia un pulso alto al contacto

  digitalWrite(led,HIGH);                     //Apaga el led
         
  }else{
     digitalWrite(led,LOW);                 //Enciende el led
  }
}

