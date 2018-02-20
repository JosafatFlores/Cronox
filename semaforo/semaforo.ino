/*
 *Autor: Cristian Josafat Flores Ramirez
 *
 *Semaforo vehicular y peatonal con un pulsador para ceder el paso
 *al peaton y detener los automoviles, auxiliado con un poteciometro
 *para dar tiempo de alto en los autos
 *
 *licencia GNU General Public License (GNU GPL)
 */


int boton = 8;            //Pin de pulsador
int verdeA = 9;           //Pin Semeaforo verde de autos  
int amarilloA = 10;       //Pin semaforo amarillo de autos
int rojoA = 11;           //Pin semaforo rojo autos
int verdeP = 12;          //Pin semaforo verde de peaton
int rojoP = 13;           //Pin semaforo rojo de peaton

void setup() {
  pinMode(boton , INPUT);       //Boton entrda
  pinMode(verdeA, OUTPUT);      //led salida verde autos 
  pinMode(amarilloA, OUTPUT);   //led salida amarillo autos
  pinMode(rojoA, OUTPUT);       //led salida Rojo autos
  pinMode(verdeP, OUTPUT);      //led salida verde Peaton
  pinMode(rojoA, OUTPUT);       //led salida Rojo peaton
  Serial.begin(9600);           
}

void loop() {
  int estado  = digitalRead(boton);   //Variable que recibe la informacion del boton
  
   // Rutina que mantienen el semaro de autos para avanzar y el de peatones en alto
  
  if(estado == 0 ){                   //if que se mantiene mmientras no se presiona el boton
    digitalWrite(verdeA, HIGH);       //led Verde autos encendido
    digitalWrite(amarilloA, LOW);     //led amarillo autos apagado
    digitalWrite(rojoA, LOW);         //led rojo autos apagado
  
    digitalWrite(verdeP, LOW);        //led verde peatones apagado
    digitalWrite(rojoP, HIGH);        //led rojo peteanos encendido
  }
 
  if((estado == 1) ){                 //if que se activa al activar el boton
    
  int valor = analogRead(2);          //Variable que toma el el valor del potenciometro
  valor = valor*10;                   //operacion que multiplica *10 el valor del potenciometro
    Serial.println(valor);            //imprime el valor tomado y multiplicado del potenciometro
    for(int i = 0;i < 3;i++){         //ciclo for para parpadear el led amarillo de autos
      digitalWrite(verdeA, LOW);      //led Verde autos apagado
      digitalWrite(amarilloA, HIGH);  //led amarillo autos encendido
      digitalWrite(rojoA, LOW);       //led rojo autos apagado
      delay(200);                     //tiempo de 200 milisegundos

      digitalWrite(verdeA, LOW);      //led verde autos apagado
      digitalWrite(amarilloA, LOW);   //led amarillo autos apagado
      digitalWrite(rojoA, LOW);       //led rojo autos apagado
      delay(200);                     //tiempo de 200 milisegundos
    }


    //Rutina que mantiene semaforo de autos en alto y de peatones con permizo de cruzar
    digitalWrite(verdeA, LOW);        //led verde autos apagado
    digitalWrite(amarilloA, LOW);     //led amarillo autos apagado
    digitalWrite(rojoA, HIGH);        //led rojo autos encendido
 
    digitalWrite(verdeP, HIGH);       //led verde peatones encendido
    digitalWrite(rojoP, LOW);         //led rojo peatones apagaddo
    delay(valor);                     //tiempo tomado y multiplicado del potenciometro


    //rutina que mantiene el semaforo de autos en verde y el de peatones en rojo para evitar bromas
    digitalWrite(verdeA, HIGH);       //led verde autos encendido
    digitalWrite(amarilloA, LOW);     //led amarillo autos apagado
    digitalWrite(rojoA, LOW);         //led rojo autos apagado

    digitalWrite(verdeP, LOW);        //led verde peatones apagado
    digitalWrite(rojoP, HIGH);        //led rojo peatones encendido
    delay(5000);                      //tiempo de 5000 milisegunddos
  }
}
