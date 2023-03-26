#include <SoftwareSerial.h>

#define motorRight1 4       // Правый мотор.
#define motorRight2 5
#define motorLeft1 6        // Левый мотор.
#define motorLeft2 7

SoftwareSerial mySerial(0, 1); // RX, TX

int speed = 250;
char message = 's';

void setup() {
  Serial.begin(115200);
  mySerial.begin(115200);
  pinMode (motorRight1, OUTPUT);
  pinMode (motorRight2, OUTPUT);
  pinMode (motorLeft1, OUTPUT);
  pinMode (motorLeft2, OUTPUT);
}

void loop() {
  if (mySerial.available() > 0) {
    char message = (char)mySerial.read();
    Serial.write(message);

    if (message == 'f') {
      forward();
    }
    else if (message == 'b') {
      backward();
    }
    else if (message == 'r') {
      rotate_right();
    }
    else if (message == 'l') {
      rotate_left();
    }
    else if (message == 's') {
      stop();
    }
  }
}

void forward() {
  digitalWrite (motorLeft2, HIGH);
  analogWrite (motorLeft1, speed);
  digitalWrite (motorRight1, HIGH);
  analogWrite (motorRight2, speed);
}
void backward() {
  digitalWrite (motorLeft2, LOW);
  analogWrite (motorLeft1, speed);
  digitalWrite (motorRight1, LOW);
  analogWrite (motorRight2, speed);
}
void rotate_right() {
  digitalWrite (motorLeft2, HIGH);
  analogWrite (motorLeft1, speed);
  digitalWrite (motorRight1, LOW);
  analogWrite (motorRight2, speed);
}
void rotate_left() {
  digitalWrite (motorLeft2, HIGH);
  analogWrite (motorLeft1, 150);
  digitalWrite (motorRight1, HIGH);
  analogWrite (motorRight2, speed);
}
void stop() {
  analogWrite(motorLeft1, 0);
  analogWrite(motorRight2, 0);
}
