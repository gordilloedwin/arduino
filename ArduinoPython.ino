/*
* Lectura de datos desde el puerto Serial.
* La información se envía desde Python usando pySerial
* Ver: serialio.py
*/

int contador=0;
int pin=8;

void setup() {                
  pinMode(pin, OUTPUT);
  Serial.begin(9600); 
  Serial.println("Listo patron...");
}

void loop() {
  char inByte = ' ';
  if(Serial.available()){
    char inByte = Serial.read();
    Serial.println(inByte);
    if(inByte == '1'){
      digitalWrite(pin, HIGH);
      delay(1000);
    }else if(inByte == '0'){
      digitalWrite(pin, LOW);
      delay(1000);
    }
    Serial.println(inByte);
  }
  delay(1000);
}
