// For I2C       
#include <Wire.h>       
// Libraries for Matrix       
#include "Adafruit_LEDBackpack.h"       
#include "Adafruit_GFX.h"       
Adafruit_8x8matrix matrix = Adafruit_8x8matrix(); 
int count = 0;     
void setup() {       
 Serial.begin(9600);       
 // Good idea to send data to both        
 // device and serial as it helps with       
 // troubleshooting.        
 Serial.println("8x8 LED Matrix Test");       
 // set the address       
 matrix.begin(0x70);        
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
   matrix.print(count);       
   // write the data out to the matrix      
   matrix.writeDisplay();      
 // how fast the characters are displayed       
   delay(150);
   if (count<9){
    count = count + 1;
   }else{
    count = 0;
   }
 }        