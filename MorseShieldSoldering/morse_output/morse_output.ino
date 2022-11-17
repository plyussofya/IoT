#define DATA_PIN 9
#define DATA_LEVEL LOW
#define SPACE_LEVEL HIGH
#define DASH_DURATION 3
#define DOT_DURATION 7
#define TU 100

String CODES[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
char LETTERS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int NLETTRERS = 27;

void setup() {
  Serial.begin(9600);
  pinMode(DATA_PIN, OUTPUT);
  digitalWrite(DATA_PIN, SPACE_LEVEL);
}

void loop() {
  if(Serial.available() >= 1){
    char iletter = Serial.read();
    if (iletter == ' '){
      send_sep_word();
    }
    else{
      for (int il = 0; il < NLETTRERS; il++){
        if (iletter == LETTERS[il]){
          Serial.print(LETTERS[il]);
          String code = CODES[il];
          send_letter(code);
        }
      }
    }  
  }
}

void send_letter(String code) {
  int code_len = code.length(); 
  for (int i = 0; i < code_len; i++){
     char symbol = code[i];
     if (symbol == '.'){
       digitalWrite(DATA_PIN, DATA_LEVEL);
       delay(TU);
      }
      else{
        digitalWrite(DATA_PIN, DATA_LEVEL);
        delay(DASH_DURATION * TU);
      }
      digitalWrite(DATA_PIN, SPACE_LEVEL);
      delay(TU);
   }
   delay((DASH_DURATION - 1) * TU);
}

void send_sep_word(){
  digitalWrite(DATA_PIN, SPACE_LEVEL);
  delay((DOT_DURATION - DASH_DURATION) * TU);
  Serial.print(" ");
}