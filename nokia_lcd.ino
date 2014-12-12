/********************************************************************
Modified by Edgar Casanova Cardoz
http://idun.com.mx
ecardoz@idun.com.mx
github.com/ecardoz

Display bitmap images on PCD8544 GLCD
Bitmap images are 80 x 45 in size

********************************************************************/

#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Please use a level shifter (ex. 74HC4050) if you're using a 5V Arduino
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)

Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

void setup()   {
  Serial.begin(9600);

  display.begin();
  
  display.setContrast(59);

  display.clearDisplay();   
}


void loop() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Arduino\nMexico");
  display.display();
  delay(5000);
  display.clearDisplay();
}
