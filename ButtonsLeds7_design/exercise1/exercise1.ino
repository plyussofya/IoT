#define btn_pin 3
#define led_pin 10
             
int flag = 0;               

void setup()
{
  pinMode(btn_pin, INPUT);
  pinMode(led_pin, OUTPUT); 
}  

void loop()
{
  int val = digitalRead(btn_pin);
  if(val == HIGH && flag == 0){                                              
      digitalWrite(led_pin, !digitalRead(led_pin));
      flag = 1;
  }
  if(val == LOW && flag == 1){
      flag = 0;
  }  
}
