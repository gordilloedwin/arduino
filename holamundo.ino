// El Hola Mundo de Arduino
// Hace parpadear el LED interno de la placa ubicado en el PIN 13.

int pin=13;

void setup() {
     pinMode(pin, OUTPUT);
 }

 void loop() {
   digitalWrite(pin,HIGH);
   delay(1000);
   digitalWrite(pin,LOW);
   delay(100);
 }
