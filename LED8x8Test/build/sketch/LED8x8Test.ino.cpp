#include <Arduino.h>
#line 1 "/Users/asherhenning/Documents/GitHub/CSE-1012-Project/LED8x8Test/LED8x8Test.ino"
/*************************************************** 
  This is a library for our I2C LED Backpacks

  Designed specifically to work with the Adafruit LED Matrix backpacks 
  ----> http://www.adafruit.com/products/872
  ----> http://www.adafruit.com/products/871
  ----> http://www.adafruit.com/products/870

  These displays use I2C to communicate, 2 pins are required to 
  interface. There are multiple selectable I2C addresses. For backpacks
  with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
  with 3 Address Select pins: 0x70 thru 0x77

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
int ledPin = 15;

#line 29 "/Users/asherhenning/Documents/GitHub/CSE-1012-Project/LED8x8Test/LED8x8Test.ino"
void setup();
#line 66 "/Users/asherhenning/Documents/GitHub/CSE-1012-Project/LED8x8Test/LED8x8Test.ino"
void loop();
#line 29 "/Users/asherhenning/Documents/GitHub/CSE-1012-Project/LED8x8Test/LED8x8Test.ino"
void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  
  matrix.begin(0x70);  // pass in the address
  pinMode(ledPin, OUTPUT);
}

static const uint8_t PROGMEM
  smile_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 },
  neutral_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10111101,
    B10000001,
    B01000010,
    B00111100 },
  frown_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100 };

void loop() {
  matrix.clear();
  matrix.drawBitmap(0, 0, smile_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, neutral_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();
  matrix.drawBitmap(0, 0, frown_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);

  matrix.clear();      // clear display
  matrix.drawPixel(0, 0, LED_ON);  
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.clear();
  matrix.drawLine(0,0, 7,7, LED_ON);
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.clear();
  matrix.drawRect(0,0, 8,8, LED_ON);
  matrix.fillRect(2,2, 4,4, LED_ON);
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.clear();
  matrix.drawCircle(3,3, 3, LED_ON);
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);

  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);
  for (int8_t x=0; x>=-36; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("Hello");
    matrix.writeDisplay();
    delay(100);
  }
  matrix.setRotation(3);
  for (int8_t x=7; x>=-36; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print("World");
    matrix.writeDisplay();
    delay(100);
  }
  matrix.setRotation(0);

  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
}

#line 1 "/Users/asherhenning/Documents/GitHub/CSE-1012-Project/LED8x8Test/lightsTest.ino"
/*************************************************** 
  This is a library for our I2C LED Backpacks

  Designed specifically to work with the Adafruit LED Matrix backpacks 
  ----> http://www.adafruit.com/products/872
  ----> http://www.adafruit.com/products/871
  ----> http://www.adafruit.com/products/870

  These displays use I2C to communicate, 2 pins are required to 
  interface. There are multiple selectable I2C addresses. For backpacks
  with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
  with 3 Address Select pins: 0x70 thru 0x77

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
int count = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  
  matrix.begin(0x70);  // pass in the address
}

static const uint8_t PROGMEM
  smile_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 },
  neutral_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10111101,
    B10000001,
    B01000010,
    B00111100 },
  frown_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100 },
  zero_bmp[] =
  { B00111100,
    B01100110,
    B01100110,
    B01100110,
    B01100110,
    B01100110,
    B00111100,
    B00000000 },
  one_bmp[] =
  { B00011000,
    B00111000,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00111100,
    B00000000 },

two_bmp[] =
  { B00111100,
    B01100110,
    B00000110,
    B00001100,
    B00011000,
    B00110000,
    B01111110,
    B00000000 },

three_bmp[] =
  { B00111100,
    B01100110,
    B00000110,
    B00011100,
    B00000110,
    B01100110,
    B00111100,
    B00000000 },
four_bmp[] =
  { B00001100,
    B00011100,
    B00101100,
    B01001100,
    B01111110,
    B00001100,
    B00001100,
    B00000000 },
five_bmp[] =
  { B01111110,
    B01100000,
    B01100000,
    B01111100,
    B00000110,
    B01100110,
    B00111100,
    B00000000 },
six_bmp[] =
  { B00111100,
    B01100000,
    B01100000,
    B01111100,
    B01100110,
    B01100110,
    B00111100,
    B00000000 },

seven_bmp[] =
  { B01111110,
    B00000110,
    B00001100,
    B00011000,
    B00011000,
    B00011000,
    B00011000,
    B00000000 },

eight_bmp[] =
  { B00111100,
    B01100110,
    B01100110,
    B00111100,
    B01100110,
    B01100110,
    B00111100,
    B00000000 },

nine_bmp[] =
  { B00111100,
    B01100110,
    B01100110,
    B00111110,
    B00000110,
    B00000110,
    B00111100,
    B00000000 },

// --- Two-digit numbers: left nibble | right nibble ---

ten_bmp[] =
  { B10011110, //10
    B10100001,
    B10100001,
    B10100001,
    B10100001,
    B10100001,
    B10100001,
    B10011110 },

eleven_bmp[] =
  { B10001000, //11
    B10001000,
    B10001000,
    B10001000,
    B10001000,
    B10001000,
    B10001000,
    B10001000 },

twelve_bmp[] =
  { B10011100,
    B10100010,  //1 2
    B10000001,
    B10000001,
    B10000010,
    B10000100,
    B10001000,
    B10011111 },

thirteen_bmp[] =
  { B10011110,
    B10100001,
    B10000001, //1 3
    B10001110,
    B10000001,
    B10000001,
    B10100001,
    B10011110 },

fourteen_bmp[] =
  { B10100001,
    B10100001,
    B10100001,
    B10111111,
    B10000001, //1 4
    B10000001,
    B10000001,
    B10000001 },

fifteen_bmp[] =
  { B10111111,
    B10100000,
    B10100000, //1 5
    B10011110,
    B10000001,
    B10000001,
    B10000001,
    B10111110 },

sixteen_bmp[] =
  { B10111111,
    B10100000,
    B10100000, //1 6
    B10100000,
    B10111110,
    B10100001,
    B10100001,
    B10111110 },

seventeen_bmp[] =
  { B10111110,
    B10000001,
    B10000010, //17 
    B10000100,
    B10001000,
    B10010000,
    B10100000,
    B10100000 },

eighteen_bmp[] =
  { B10011110, //1 8
    B10100001,
    B10100001,
    B10100001,
    B10111111,
    B10100001,
    B10100001,
    B10011110 },

nineteen_bmp[] =
  { B10011110, //1 9
    B10100001,
    B10100001,
    B10100001,
    B10111111,
    B10000001,
    B10000001,
    B10011110 },

twenty_bmp[] =
  { B01100111, //2 0 
    B10010101,
    B00010101,
    B00010101,
    B00100101,
    B01000101,
    B10000101,
    B11110010 };
const uint8_t* digits[] = {
  zero_bmp,
  one_bmp,
  two_bmp,
  three_bmp,
  four_bmp,
  five_bmp,
  six_bmp,
  seven_bmp,
  eight_bmp,
  nine_bmp,
  ten_bmp,
  eleven_bmp,
  twelve_bmp,
  thirteen_bmp,
  fourteen_bmp,
  fifteen_bmp,
  sixteen_bmp,
  seventeen_bmp,
  eighteen_bmp,
  nineteen_bmp,
  twenty_bmp
};
void loop() {
  matrix.setRotation(3);
  matrix.clear();
  matrix.drawBitmap(0, 0, digits[count], 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);
  if (count ==20){
    count = 0;
  }else{
    count = count + 1;
  }

  // matrix.clear();
  // matrix.drawBitmap(0, 0, two_bmp, 8, 8, LED_ON);
  // matrix.writeDisplay();
  // delay(500);

  // matrix.clear();
  // matrix.drawBitmap(0, 0, three_bmp, 8, 8, LED_ON);
  // matrix.writeDisplay();
  // delay(500);

  // matrix.clear();      // clear display
  // matrix.drawPixel(0, 0, LED_ON);  
  // matrix.writeDisplay();  // write the changes we just made to the display
  // delay(500);

  // matrix.clear();
  // matrix.drawLine(0,0, 7,7, LED_ON);
  // matrix.writeDisplay();  // write the changes we just made to the display
  // delay(500);

  // matrix.clear();
  // matrix.drawRect(0,0, 8,8, LED_ON);
  // matrix.fillRect(2,2, 4,4, LED_ON);
  // matrix.writeDisplay();  // write the changes we just made to the display
  // delay(500);

  // matrix.clear();
  // matrix.drawCircle(3,3, 3, LED_ON);
  // matrix.writeDisplay();  // write the changes we just made to the display
  // delay(500);

  // matrix.setTextSize(1);
  // matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  // matrix.setTextColor(LED_ON);
  // for (int8_t x=0; x>=-36; x--) {
  //   matrix.clear();
  //   matrix.setCursor(x,0);
  //   matrix.print("Hello");
  //   matrix.writeDisplay();
  //   delay(100);
  // }
  // matrix.setRotation(3);
  // for (int8_t x=7; x>=-36; x--) {
  //   matrix.clear();
  //   matrix.setCursor(x,0);
  //   matrix.print("World");
  //   matrix.writeDisplay();
  //   delay(100);
  // }
  // matrix.setRotation(0);
}
