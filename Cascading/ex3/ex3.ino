#define clock_pin 10
#define reset_pin 11

String number = "";
long pr = 0;
int pos = 0;

void setup(){
  pinMode(reset_pin, OUTPUT);
  pinMode(clock_pin, OUTPUT);
  resetNumber();
  Serial.begin(9600);
}

void loop(){
  if (Serial.available()){
    number = "";
    pos = 0;
    while (Serial.available()){
      number += char(Serial.read());
      delay(50);
    }
  }
  while (millis() - pr >= 1000){
    pr = millis();
    if (pos == 0){
      pos++;
      if (number.length() > 2){
        resetNumber();
        break;
      }
    }
    int show = (number[pos - 1] - '0') * 10 + number[pos] - '0';
    showNumber(show);
    pos++;
    pos %= number.length();
  }
}

void resetNumber(){
  digitalWrite(reset_pin, HIGH);
  digitalWrite(reset_pin, LOW);
}

void showNumber(int n){
  resetNumber();
  for (byte i=0; i < n; i++) {
    digitalWrite(clock_pin, HIGH);
    digitalWrite(clock_pin, LOW);
  }
}