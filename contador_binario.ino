// Contador binario de 4 bits
// Usa pines analogicos para contar
//
// Los pines encienden en efecto 'fade in' y
// apagan en efecto 'fade out'

//Pines analogicos
//3, 5, 9, 11
int pin[]={3,5,9,11};

void setup(){
  //Configuracion de pines como OUTPUT
  for(int i=0; i<=3; i++){
    pinMode(pin[i],OUTPUT);
  }
}

void loop(){
  int i=0, j=0;
  for(i=0; i<16; i++){
    for(j=0; j<4; j++){
      if(((i >> j) & 1) == 1){
        digitalWrite(pin[j],HIGH);
      }else{
        digitalWrite(pin[j],LOW);
      }
      delay(500);
    }
  }
}
