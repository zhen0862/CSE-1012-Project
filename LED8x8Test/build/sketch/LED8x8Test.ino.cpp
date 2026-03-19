#include <Arduino.h>
#line 1 "/Users/omartolba/CSE-1012-Project/LED8x8Test/LED8x8Test.ino"
int ledPin1 = 15; //Green LED

#line 3 "/Users/omartolba/CSE-1012-Project/LED8x8Test/LED8x8Test.ino"
void setup();
#line 9 "/Users/omartolba/CSE-1012-Project/LED8x8Test/LED8x8Test.ino"
void loop();
#line 3 "/Users/omartolba/CSE-1012-Project/LED8x8Test/LED8x8Test.ino"
void setup() {
  // put your setup code here, to run once:

  pinMode(ledPin1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(ledPin1, HIGH);
  delay(1000);
  digitalWrite(ledPin1, LOW);
  delay(1000);
}


