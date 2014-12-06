// These variables store the flash pattern
// and the current state of the LED
 
int ledPin = 13; // the number of the LED pin
int ledState = LOW; // ledState used to set the LED
unsigned long previousMillis = 0; // will store last time LED was updated
long OnTime = 250; // milliseconds of on-time
long OffTime = 750; // milliseconds of off-time
int i=0;
 
void setup()
{
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}
 
void loop()
{
  bindLeds();
  Serial.println(millis());
}

void bindLeds(){
  // check to see if it's time to change the state of the LED
  unsigned long currentMillis = millis();
  
  if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
  {
    ledState = LOW; // Turn it off
    previousMillis = currentMillis; // Remember the time
    digitalWrite(random(2,5), ledState); // Update the actual LED
  }
  else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
  {
    ledState = HIGH; // turn it on
    previousMillis = currentMillis; // Remember the time
    digitalWrite(random(2,5), ledState);	// Update the actual LED
  }
}
