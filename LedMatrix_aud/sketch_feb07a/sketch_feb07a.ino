#define led_pin3 3
#define led_pin4 4
#define led_pin5 5
#define led_pin6 6

void setup() {
  pinMode(led_pin3, OUTPUT);
  pinMode(led_pin4, OUTPUT);
  pinMode(led_pin5, OUTPUT);
  pinMode(led_pin6, OUTPUT);
}
void off(){
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, LOW);
}
void first(){
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, HIGH);
  digitalWrite(led_pin5, HIGH);
  digitalWrite(led_pin6, LOW);
}
void second(){
  digitalWrite(led_pin3, HIGH);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, HIGH);
  digitalWrite(led_pin6, LOW);
}
void third(){
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, HIGH);
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, HIGH);
}
void fourth(){
  digitalWrite(led_pin3, HIGH);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, HIGH);
}
void fs(){
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, HIGH);
  digitalWrite(led_pin6, LOW);
}
void tf(){
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, LOW);
  digitalWrite(led_pin6, HIGH);
}
void ft(){
  digitalWrite(led_pin3, LOW);
  digitalWrite(led_pin4, HIGH);
  digitalWrite(led_pin5, HIGH);
  digitalWrite(led_pin6, HIGH);
}
void sf(){
  digitalWrite(led_pin3, HIGH);
  digitalWrite(led_pin4, LOW);
  digitalWrite(led_pin5, HIGH);
  digitalWrite(led_pin6, HIGH);
}

void loop() {
  first();
  delay(1000);
  off();
  delay(500);
  second();
  delay(1000);
  off();
  delay(500);
  third();
  delay(1000);
  off();
  delay(500);
  fourth();
  delay(1000);
  off();
  delay(500);
  fs();
  delay(1000);
  off();
  delay(500);
  tf();
  delay(1000);
  off();
  delay(500);
  ft();
  delay(1000);
  off();
  delay(500);
  sf();
  delay(1000);
  off();
  delay(50000);
}
