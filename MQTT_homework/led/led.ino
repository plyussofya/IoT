#define led_pin 3

void setup() {
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available() > 0){
    int value = Serial.read();
    if (value == '0'){
      digitalWrite(led_pin, LOW);
    }
    else if (value == '1'){
      digitalWrite(led_pin, HIGH);
    }
  }
}
