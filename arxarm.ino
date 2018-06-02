#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial bt(8, 9);

bool a1 = false;
bool a2 = false;
bool b1 = false;
bool b2 = false;
bool c1 = false;
bool c2 = false;

bool claw1 = false;
bool claw2 = false;


Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;



int x1 = 90;
int x2 = 90;
int x3 = 60;
int x4 = 90;


void setup() {
  servo1.write(x1); //This codes for stabilisation
  servo2.write(x2); //|\\ Opposite motors
  servo3.write(x2); \\|// Opposite motors
  servo4.write(x3);
  servo5.write(x1);

  Serial.begin (9600);
  bt.begin(9600);

  servo1.attach(4);
  servo2.attach(6);
  servo3.attach(7);
  servo4.attach(3);
  servo5.attach(2);
}

void loop() {

  if (bt.available())
  {
    char data = bt.read();
    Serial.println(data);
    
    if (data == '1') {
      a1 = true;
      a2 = false;
      b1 = false;
      b2 = false;
      c1 = false;
      c2 = false;
    }

    if (data == '3') {

      a1 = false;
      a2 = true;
      b1 = false;
      b2 = false;
      c1 = false;
      c2 = false;
    }


    if (data == '7') {

      a1 = false;
      a2 = false;
      b1 = true;
      b2 = false;
      c1 = false;
      c2 = false;
    }

    if (data == '9') {

      a1 = false;
      a2 = false;
      b1 = false;
      b2 = true;
      c1 = false;
      c2 = false;
    }

    if (data == 'x') {

      a1 = false;
      a2 = false;
      b1 = false;
      b2 = false;
      c1 = true;
      c2 = false;
    }

    if (data == 'y') {

      a1 = false;
      a2 = false;
      b1 = false;
      b2 = false;
      c1 = false;
      c2 = true;
    }

    if (data == '0') {
      a1 = false;
      a2 = false;
      b1 = false;
      b2 = false;
      c1 = false;
      c2 = false;
      claw1 = false;
      claw2 = false;
    }

    if (data == 'a') {
      claw1 = true;
      claw2 = false;
    }

    if (data == 'b') {
      claw1 = false;
      claw2 = true;
    }
  }


  if (claw1 == true) {
    if (x4 < 180) {
      x4 += 1;
      servo5.write(x4);
      delay(15);
    }
  } else if (claw2 == true) {
    if (x4 > 0) {
      x4 -= 1;
      servo5.write(x4);
      delay(15);
    }
  }

  if (a1 == true) {
    if (x1 < 180) {
      x1 += 1;
      servo1.write(x1);
      delay(5);
    }
  } else if (a2 == true) {
    if (x1 > 0) {
      x1 -= 1;
      servo1.write(x1);
      delay(5);
    }
  } else if (b1 == true) {
    if (x2 > 0) {
      x2 -= 1;
      servo2.write(x2);
      servo3.write(180 - x2);
      delay(30);
    }

  } else if (b2 == true) {
    if (x2 < 180) {
      x2 += 1;
      servo2.write(x2);
      servo3.write(180 - x2);
      delay(30);
    }
  } else if (c1 == true) {
    if (x3 < 180) {
      x3 += 1;
      servo4.write(x3);
      delay(30);
    }
  } else if (c2 == true) {
    if (x3 > 0) {
      x3 -= 1;
      servo4.write(x3);
      delay(30);
    }
  }
}
