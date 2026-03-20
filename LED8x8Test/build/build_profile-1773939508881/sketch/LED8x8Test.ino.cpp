#include <Arduino.h>
#line 1 "/Users/omartolba/CSE-1012-Project/LED8x8Test/LED8x8Test.ino"
// For I2C       
#include <Wire.h>       
// Libraries for Matrix       
#include "Adafruit_LEDBackpack.h"       
#include "Adafruit_GFX.h"       
Adafruit_8x8matrix matrix = Adafruit_8x8matrix();      

int ledPin = 15;

#line 10 "/Users/omartolba/CSE-1012-Project/LED8x8Test/LED8x8Test.ino"
void setup();
#line 21 "/Users/omartolba/CSE-1012-Project/LED8x8Test/LED8x8Test.ino"
void loop();
#line 10 "/Users/omartolba/CSE-1012-Project/LED8x8Test/LED8x8Test.ino"
void setup() {       
 Serial.begin(9600);       
 // Good idea to send data to both        
 // device and serial as it helps with       
 // troubleshooting.        
 Serial.println("8x8 LED Matrix Test");       
 // set the address       
 matrix.begin(0x70);       
 pinMode(ledPin, OUTPUT);
}       
       
void loop() {       
 // Make sure where led 0x0 is:       
 // And it is working       
 matrix.setTextSize(1);       
 matrix.setTextColor(LED_ON);      
   // clear the matrix       
   matrix.clear();       
   // position the cursor      
   matrix.setCursor(0,0);       
   // text to print      
   matrix.print("T");       
   // write the data out to the matrix      
   matrix.writeDisplay();      
 // how fast the characters are displayed       
   delay(150);   
   
    digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  Serial.println("HERE");
 }      
