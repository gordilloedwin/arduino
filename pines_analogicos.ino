// pines analogicos con voltaje variable
// doble recorrido

int pines[]={3,5,9,11};
//int i=0;

void setup(){
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);
  apagarTodo();
}

void loop(){
  int i=0;
  for(i=0; i<=3; i++){
    encendido(pines[i]);
  }
  for(i=3; i>=0; i--){
    encendidoR(pines[i]);
  }
  apagarTodo();
  delay(300);
}

void encendido(int pin){
  int i=0;
  for(i=0; i<255; i++){
    analogWrite(pin,i);
    delay(4);
  }
}

void encendidoR(int pin){
  int i=0;
  for(i=255; i>=0; i--){
    analogWrite(pin,i);
    delay(4);
  }
}

void apagarTodo(){
  int i=0;
  for(i=0; i<=3; i++){
    analogWrite(pines[i],0);
  }
}
