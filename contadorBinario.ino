//Pines para LEDs que se moveran
int pines[]={2,3,4,5,6,7,8,9,10};

int selector=12;

int selector2=13;

int binario=0;

int k=0;

//k=255;

//Configuracion Arduino
void setup(){
  
  //Configuracion de pines en salida
  for(int i=0; i<=8; i++){
    pinMode(pines[i], OUTPUT);
  }
  
  
  //selector de modos de LED
  pinMode(selector, OUTPUT);
  
  pinMode(selector2, OUTPUT);
  
  Serial.begin(9600);  //Se abre el puerto USB (serie)
}

void loop(){
    binario++;
    if(binario>255){
      binario=0;
    }
    Serial.print("Decimal: ");
    Serial.println(binario);
    Serial.println("Presentando numero binario");
    k=binario;
    for(int i=2; i<=9; i++){
      digitalWrite(i,k%2);
      k=k/2;
    }
    delay(1000);
}
