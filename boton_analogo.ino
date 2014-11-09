// Se controla un motor vibrador con un pulso digital
// se descubrió que el boton digital funciona a modo de
// potenciometro variando el voltaje de respuesta.


int analogPin=5;  //Lectura del boton analogo
float val=0;
float v;

int pinMotor=11; //Pin al que esta conectado el motor

void setup()
{
  Serial.begin(9600);       //Configuracion del serial
  pinMode(pinMotor,OUTPUT);  //Voltaje variable al motor
}

void loop()
{
  val = analogRead(analogPin);
  if((val*0.0049)>=1.2)
  {
    //Serial.print("Voltaje: ");
    Serial.print((val*0.0049));
    //Serial.println(" volts.");
    //Serial.print("Moviendo motor a: ");
    Serial.print(" ---- ");
    Serial.println(((val/2)*0.0196));
    //Serial.println(" volts.");
    
    analogWrite(pinMotor,((val/2)));
  }
  else{
    analogWrite(pinMotor,0);
  }
  //delay(10);
  //
}
