// Parecido a Knight Rider pero con pulsadores 
// para variar la dirección de recorrido de los LEDs.
// @autor: Edgar Casanova Cardoz
// @email: ecardoz@idun.com.mx

int pulsador=2; //  Primer pulsador
int pulsador2=3;//  Segundo pulsador

int pin[]={8,9,10,11}; // Array para recorrer LEDs con 
                       // primer pulsador
                       
int pin2[]={11,10,9,8};// Array para recorrer LEDs con
                       // segundo pulsador

int i=0;    // Declaracion del index

void setup(){
  pinMode(pulsador,OUTPUT); //Configuracion pin pulsador
  pinMode(pulsador2,OUTPUT);//Configuracion pin pulsador2
  
  for(i=0; i<4; i++){       //Configuracion de pines de
    pinMode(pin[i], OUTPUT);//los LEDs
  }
}

void loop(){
  //Deteccion del primer pulsador
  if(digitalRead(pulsador)==HIGH){    
    for(i=0; i<4; i++){
     digitalWrite(pin[i],HIGH);
     delay(500);
     digitalWrite(pin[i],LOW);
     delay(100);
   }
  }
  
  //Deteccion del segundo pulsador
  if(digitalRead(pulsador2)==HIGH){
    for(i=0; i<4; i++){
     digitalWrite(pin2[i],HIGH);
     delay(500);
     digitalWrite(pin2[i],LOW);
     delay(100);
   }
  }
}
