#define forward 11
#define backward 10

void setup() {
  Serial.begin(9600);
  pinMode(forward, OUTPUT);
  pinMode(backward, OUTPUT);
}

void motor_control(bool direction, int velocity) {
  if (direction) {
    analogWrite(forward, velocity);
    analogWrite(backward, 0);
  }
  else {
    analogWrite(backward, velocity);
    analogWrite(forward, 0);
  }
}

void loop() {
  while (Serial.available()) {
    int message = Serial.readString().toInt();
    Serial.println(message);
    if (message == 0){
      motor_control(true, 0);
    }
    while (!Serial.available()) {}
    long sp = Serial.readString().toInt();
    Serial.println(sp);
    if (message == 1) {
      motor_control(true, sp);
    }
    if (message == 2) {
      motor_control(false, sp);
    }
  }
  //  motor_control(true, 75);
  //  delay(2000);
  //  motor_control(false, 255);
  //  delay(2000);
}
