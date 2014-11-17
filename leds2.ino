//Pines para LEDs que se moveran
int pines[]={2,3,4,5,6,7,8,9,10};

//Pin que permanecera fijo
int pin=11;

//opcion esta variable cambia segun la pulsacion
//PIN que navega las opciones
// 1 pulsacion: LEDs(0->8|8->0) funcion: funcionUno();
// 2 pulsacion: LEDs(0->8)      funcion: funcionDos();
// 3 pulsacion: LEDs(8->0)      funcion: funcionTres();
int selector=12;

int selector2=13;

//seleccion actual
int seleccion=0;

//Sentido de los LEDs
int direccion=0;

//Configuracion Arduino
void setup(){
  
  //Configuracion de pines en salida
  for(int i=0; i<=8; i++){
    pinMode(pines[i], OUTPUT);
  }
  
  //Pin 11 estatico
  pinMode(pin,OUTPUT);
  
  //Pin encendido
  digitalWrite(pin,HIGH);
  
  //selector de modos de LED
  pinMode(selector, OUTPUT);
  
  pinMode(selector2, OUTPUT);
  
  Serial.begin(9600);  //Se abre el puerto USB (serie)
}

void loop(){
  
  if(digitalRead(selector2)==HIGH){
    delay(2000);
    if(direccion==0){
      pines[0]=2;
      pines[1]=3;
      pines[2]=4;
      pines[3]=5;
      pines[4]=6;
      pines[5]=7;
      pines[6]=8;
      pines[7]=9;
      pines[8]=10;
      direccion=1;
    }
    else{
      pines[8]=2;
      pines[7]=3;
      pines[6]=4;
      pines[5]=5;
      pines[4]=6;
      pines[3]=7;
      pines[2]=8;
      pines[1]=9;
      pines[0]=10;
      direccion=0;
    }
  }
  
  if(digitalRead(selector)==HIGH){
    seleccion++;
    Serial.print("Valor de seleccion: ");
    Serial.println(seleccion);
    switch(seleccion){
      case 1:
        funcionUno();
        break;
       case 2:
         funcionDos();
         break;
       case 3:
         funcionTres();
         break;
       case 4:
         funcionCuatro();
         break;
       case 5:
         funcionCinco();
         break;
       case 6:
         seleccion=0;
         break;
    }
  }
  else{
    long rand;
    rand = random(2,10);
    Serial.println(rand);
    
//    digitalWrite(pines[rand],HIGH);
//    delay(50);
//    digitalWrite(pines[rand],LOW);
    //delay(1000);
    
    for(int i=0; i<=rand; i++){
      digitalWrite(pines[i],HIGH);
      delay(i+1*15);
    }
    for(int j=0; j<=rand; j++){
      digitalWrite(pines[j],LOW);
    }
  }
  delay(50);
  
  
}


// 1 pulsacion: LEDs(0->8|8->0) funcion: funcionUno();
void funcionUno(){
  Serial.println("FuncionUno() corriendo");
  for(int i=0; i<=8; i++){
    digitalWrite(pines[i],HIGH);
    delay(56);
  }
  
  for(int j=8; j>=0; j--){
    digitalWrite(pines[j],LOW);
    delay(56);
  }
}

// 2 pulsacion: LEDs(0->8)      funcion: funcionDos();
void funcionDos(){
  Serial.println("FuncionDos() corriendo");
  for(int i=0; i<=8; i++){
    digitalWrite(pines[i],HIGH);
    delay(90);
    digitalWrite(pines[i],LOW);
  }
}

void funcionTres(){
  Serial.println("FuncionTres() corriendo");
  for(int a=0; a<2; a++){
    for(int i=0; i<=8; i++){
      digitalWrite(pines[i],HIGH);
    }
    delay(200);
    for(int i=0; i<=8; i++){
      digitalWrite(pines[i],LOW);
    }
    delay(100);
  }
}

void funcionCuatro(){
  Serial.println("FuncionCuatro() corriendo");
  int linea1[]={2,5,8};
  int linea2[]={3,6,9};
  int linea3[]={4,7,10};
  
  for(int i=0; i<3; i++){
    digitalWrite(linea1[i],HIGH);
  }
  delay(150);
  for(int i=0; i<3; i++){  
    digitalWrite(linea1[i],LOW);
  }
  delay(50);
  ////////////////////////////////////////
  for(int i=0; i<3; i++){
    digitalWrite(linea2[i],HIGH);
  }
  delay(150);
  for(int i=0; i<3; i++){  
    digitalWrite(linea2[i],LOW);
  }
  delay(50);
  ///////////////////////////////////////
  for(int i=0; i<3; i++){
    digitalWrite(linea3[i],HIGH);
  }
  delay(150);
  for(int i=0; i<3; i++){  
    digitalWrite(linea3[i],LOW);
  }
  delay(50);

}

void funcionCinco(){
  Serial.println("FuncionCinco() corriendo");
  int linea[]={2,5,8,9,6,3,4,7,10};
  for(int i=0; i<9; i++){
    digitalWrite(linea[i],HIGH);
    delay(150);
  }
//  delay(150);
  for(int i=0; i<9; i++){  
    digitalWrite(linea[i],LOW);
    delay(150);
  }
//  delay(50);
}
