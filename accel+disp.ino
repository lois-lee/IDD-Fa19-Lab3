// Basic demo for accelerometer readings from Adafruit LIS3DH

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

// include the library code:
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int redPin = A0;
int greenPin = A2;
int bluePin = A1;
// Used for software SPI
#define LIS3DH_CLK 13
#define LIS3DH_MISO 12
#define LIS3DH_MOSI 11
// Used for hardware & software SPI
#define LIS3DH_CS 10

// software SPI
//Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS, LIS3DH_MOSI, LIS3DH_MISO, LIS3DH_CLK);
// hardware SPI
//Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS);
// I2C
Adafruit_LIS3DH lis = Adafruit_LIS3DH();

void setup(void) {
#ifndef ESP8266
  while (!Serial);     // will pause Zero, Leonardo, etc until serial console opens
#endif

  Serial.begin(9600);
  lcd.begin(16, 2);

  Serial.println("LIS3DH test!");
  
  if (! lis.begin(0x18)) {   // change this to 0x19 for alternative i2c address
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("LIS3DH found!");
  
  lis.setRange(LIS3DH_RANGE_4_G);   // 2, 4, 8 or 16 G!
  
  Serial.print("Range = "); Serial.print(2 << lis.getRange());  
  Serial.println("G");
}

void loop() {
  lis.read();      // get X Y and Z data at once
  // Then print out the raw data
  Serial.print("X:  "); Serial.print(lis.x); 
  Serial.print("  \tY:  "); Serial.print(lis.y); 
  Serial.print("  \tZ:  "); Serial.print(lis.z); 
  

  /* Or....get a new sensor event, normalized */ 
  sensors_event_t event; 
  lis.getEvent(&event);
  
  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("\t\tX: "); Serial.print(event.acceleration.x);
  Serial.print(" \tY: "); Serial.print(event.acceleration.y); 
  Serial.print(" \tZ: "); Serial.print(event.acceleration.z); 
  Serial.println(" m/s^2 ");

  if(lis.x > 0 && lis.y > 0 && lis.z > 0){
      setColor(255, 0, 0);  // red
      delay(1000);
  }
  if(lis.x > 0 && lis.y <= 0 && lis.z > 0){
      setColor(0, 255, 0);  // green
      delay(1000);
  }
  if(lis.x > 0 && lis.y > 0 && lis.z <= 0){
      setColor(0, 0, 255);  // blue
      delay(1000);
  }
  if(lis.x <= 0 && lis.y > 0 && lis.z > 0){
      setColor(80, 0, 80);  // purple
      delay(1000);
  }
  if(lis.x <= 0 && lis.y > 0 && lis.z > 0){
      setColor(0, 255, 255);  // aqua
      delay(1000);
  }
  if(lis.x <= 0 && lis.y > 0 && lis.z <= 0){
      setColor(255, 255, 0);  // yellow
      delay(1000);
  }
  if(lis.x <= 0 && lis.y <= 0 && lis.z <= 0){
      setColor(80, 0, 80);  // purple
      delay(1000);
  } 
  if(lis.x > 0 && lis.y <= 0 && lis.z <= 0){
      setColor(255, 0, 0);  // red
      delay(1000);
  }
 
//  setColor(255, 0, 0);  // red
//  delay(1000);
//  setColor(0, 255, 0);  // green
//  delay(1000);
//  setColor(0, 0, 255);  // blue
//  delay(1000);
//  setColor(255, 255, 0);  // yellow
//  delay(1000);  
//  setColor(80, 0, 80);  // purple
//  delay(1000);
//  setColor(0, 255, 255);  // aqua
//  delay(1000);

  
  Serial.println();
  lcd.clear();

  lcd.display();
  // Print a message to the LCD.
  lcd.print(" X:");
  lcd.print(lis.x);
    delay(1000);
  lcd.clear();
  lcd.print(" Y:");
  lcd.print(lis.y);
    delay(1000);
  lcd.clear();
  lcd.print(" Z:");
  lcd.print(lis.z);
  delay(1000);
  lcd.clear();

  delay(200); 
}
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
