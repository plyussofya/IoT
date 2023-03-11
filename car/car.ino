//56 СКОРОСТЬ 47 НАПРАВЛЕНИЕ
#define motorRight1 4       // Правый мотор.
#define motorRight2 5
#define motorLeft1 6        // Левый мотор.
#define motorLeft2 7
#define PIN_TRIG 9
#define PIN_ECHO 10
#define IPin A0

bool go = false;
bool rotate_left = false;
bool rotate_right = false;

long duration = 0;
long fdist = 0;
long ldist = 0;
int MIN_L = 20;
int MAX_L = 25;

void setup() {
  pinMode (motorRight1, OUTPUT);
  pinMode (motorRight2, OUTPUT);
  pinMode (motorLeft1, OUTPUT);
  pinMode (motorLeft2, OUTPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  Serial.begin (9600);
}

void loop() {
  float volts = analogRead(IPin) * 0.0048828125;
  float ldist = 32 * pow(volts, -1.10);
//  Serial.println(ldist);
  
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);
  duration = pulseIn(PIN_ECHO, HIGH);
  fdist = (duration / 2) / 29.1;
//  Serial.println(fdist);

  delay(100);
  update_state();
  do_action();
  delay(250);
}

void update_state() {
   if (ldist > MAX_L) {
    go = false;
    rotate_right = false;
    rotate_left = true;
  }
  else if (ldist < MIN_L && fdist < MIN_L) {
    go = false;
    rotate_left = false;
    rotate_right = true;
    }
  else if (ldist < MIN_L && fdist > MIN_L) {
    go = true;
    rotate_right = false;
    rotate_left = false;
  }
  else{
    go = false;
    rotate_right = false;
    rotate_left = false;
  }
}

void do_action() {
  if (go) {
    digitalWrite (motorLeft2, HIGH);
    analogWrite (motorLeft1, 250);
    digitalWrite (motorRight1, HIGH);
    analogWrite (motorRight2, 250);
  } else if (rotate_right) {
    digitalWrite (motorLeft2, HIGH);
    analogWrite (motorLeft1, 250);
    digitalWrite (motorRight1, LOW);
    analogWrite (motorRight2, 250);
  } else if (rotate_left) {
    digitalWrite (motorLeft2, HIGH);
    analogWrite (motorLeft1, 150);
    digitalWrite (motorRight1, HIGH);
    analogWrite (motorRight2, 250);
  } else {
    analogWrite(motorLeft1, 0);
    analogWrite(motorRight2, 0);
  }
}
