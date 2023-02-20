#define led_pin1 2
#define led_pin2 3
#define led_pin3 4
#define led_pin4 5
#define led_pin5 6
#define led_pin6 7

void setup() {
  Serial.begin(9600);
  pinMode(led_pin1, OUTPUT);
  pinMode(led_pin2, OUTPUT);
  pinMode(led_pin3, OUTPUT);
  pinMode(led_pin4, OUTPUT);
  pinMode(led_pin5, OUTPUT);
  pinMode(led_pin6, OUTPUT); 
}

void led_control(bool status1, bool status2, bool status3, bool status4, bool status5, bool status6) {
  digitalWrite(led_pin1, status1);
  digitalWrite(led_pin2, status2);
  digitalWrite(led_pin3, status3);
  digitalWrite(led_pin4, status4);
  digitalWrite(led_pin5, status5);
  digitalWrite(led_pin6, status6);
}

void led_off() {
  led_control(0, 0, 0, 0, 0, 0);
}
void led_all() {
  led_control(1, 1, 0, 0, 0, 0);
}

void led_row1() {
  led_control(1, 0, 0, 0, 0, 0);
}
void led_row2() {
  led_control(0, 1, 0, 0, 0, 0);
}

void led_one() {
  led_control(1, 0, 1, 0, 1, 1);
}
void led_two() {
  led_control(1, 0, 1, 1, 1, 0);
}
void led_three() {
  led_control(1, 0, 0, 1, 1, 1);
}
void led_four() {
  led_control(1, 0, 1, 1, 0, 1);
}
void led_five() {
  led_control(0, 1, 1, 0, 1, 1);
}
void led_six() {
  led_control(0, 1, 1, 1, 1, 0);
}
void led_seven() {
  led_control(0, 1, 0, 1, 1, 1);
}
void led_eight() {
  led_control(0, 1, 1, 1, 0, 1);
}

void led_12() {
  led_control(1, 0, 1, 0, 1, 0);
}
void led_13() {
  led_control(1, 0, 0, 0, 1, 1);
}
void led_14() {
  led_control(1, 0, 1, 0, 0, 1);
}
void led_15() {
  led_control(1, 1, 1, 0, 1, 1);
}
void led_23() {
  led_control(1, 0, 0, 1, 1, 0);
}
void led_24() {
  led_control(1, 0, 1, 1, 0, 0);
}
void led_26() {
  led_control(1, 1, 1, 1, 1, 0);
}
void led_34() {
  led_control(1, 0, 0, 1, 0, 1);
}
void led_37() {
  led_control(1, 1, 0, 1, 1, 1);
}
void led_56() {
  led_control(0, 1, 1, 0, 1, 0);
}

void led_123() {
  led_control(1, 0, 0, 0, 1, 0);
}
void led_234() {
  led_control(1, 0, 0, 1, 0, 0);
}
void led_567() {
  led_control(0, 1, 0, 0, 1, 0);
}
void led_678() {
  led_control(0, 1, 0, 1, 0, 0);
}

void loop() {
  led_all();
  delay(2500);
  led_row1();
  delay(2500);
  led_row2();
  delay(2500);
  led_one();
  delay(2500);
  led_two();
  delay(2500);
  led_three();
  delay(2500);
  led_four();
  delay(2500);
  led_five();
  delay(2500);
  led_six();
  delay(2500);
  led_seven();
  delay(2500);
  led_eight();
  delay(2500);
  led_12();
  delay(2500);
  led_13();
  delay(2500);
  led_14();
  delay(2500);
  led_15();
  delay(2500);
  led_23();
  delay(2500);
  led_24();
  delay(2500);
  led_26();
  delay(2500);
  led_34();
  delay(2500);
  led_37();
  delay(1000);
  led_56();
  delay(2500);
  led_123();
  delay(2500);
  led_234();
  delay(2500);
  led_567();
  delay(2500);
  led_678();
  delay(2500);  
  led_off();
  delay(3000); 
}
