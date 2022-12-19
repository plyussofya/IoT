const int trig_pin = 4;
const int echo_pin = 5;

void init_sensor(){
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  digitalWrite(trig_pin, LOW);
}

float get_range(){
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(5);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  long duration = pulseIn(echo_pin, HIGH);
  float distance = (duration / 2) / 29.1;
  return distance;
}
