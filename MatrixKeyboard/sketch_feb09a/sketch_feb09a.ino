#define pin3 3
#define pin4 4
#define pin5 5
#define pin6 6

void setup() {
  Serial.begin(9600);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
}

void loop() {
  String result = "";
  pinMode(pin6, INPUT);
  pinMode(pin5, OUTPUT);
  digitalWrite(pin5, HIGH);
  
  if (digitalRead(pin3) == 1 && digitalRead(pin4) == 0) {
    result += "1";
  }
  else if (digitalRead(pin3) == 1 && digitalRead(pin4) == 1) {
    result += "12";
  }
  else if (digitalRead(pin3) == 0 && digitalRead(pin4) == 1) {
    result += "2";
  }
  
  digitalWrite(pin5, LOW);
  pinMode(pin5, INPUT);
  delay(100);
  pinMode(pin6, OUTPUT);

  digitalWrite(pin6, HIGH);
  if (digitalRead(pin3) == 1 && digitalRead(pin4) == 0) {
    result += "3";
  }
  else if (digitalRead(pin3) == 1 && digitalRead(pin4) == 1) {
    result += "34";
  }
  else if (digitalRead(pin3) == 0 && digitalRead(pin4) == 1) {
    result += "4";
  }
  digitalWrite(pin6, LOW);

  if (result.length()!= 0){
    Serial.println(result);
  }
  delay(100);
}
