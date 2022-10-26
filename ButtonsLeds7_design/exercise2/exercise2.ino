#define btn_pin 3
#define led_pin 10

bool light = false;
bool step = false;
int val, value;
int power = 255;

void setup(){
  pinMode(btn_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  val = digitalRead(btn_pin);
  if (val != value){
    val = digitalRead(btn_pin);
    long press = millis();

    while (digitalRead(btn_pin)){
      if (millis() - press >= 500 && light){
        while (digitalRead(btn_pin)){
          if (step){
            power = min(power + 1, 255);
          }
          else{
            power = max(power - 1, 15);
          }
          analogWrite(led_pin, power);
          delay(10);
        }
        step = !step;
      }
      delay(10);
    }

    if (millis() - press < 500){
      if (val){
          light = !light;
      }
      if (light){
        analogWrite(led_pin, power);
      }
      else{
        analogWrite(led_pin, 0);
      }
    }
  }
  value = val;
}