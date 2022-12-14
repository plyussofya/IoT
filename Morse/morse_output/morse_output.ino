#define DATA_PIN 9
#define DATA_LEVEL LOW
#define SPACE_LEVEL HIGH

#define DOT_DURATION 1
#define DASH_DURATION 3

#define LETTER_DURATION 3
#define WORD_DURATION 7

#define TU 100

String CODES[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
char LETTERS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int NLETTRERS = 26;

void setup() {
  Serial.begin(9600);
  pinMode(DATA_PIN, OUTPUT);
  digitalWrite(DATA_PIN, SPACE_LEVEL);
}

void loop() {
  if(Serial.available() >= 1){
    char letter = Serial.read();
    if (letter == ' '){
      send_sep_word();
    }
    else{
      for (int il = 0; il < NLETTRERS; il++){
        if (letter == LETTERS[il]){
          String code = CODES[il];
          send_letter(code);
        }
      }
    }  
  }
}

void send_letter(String code) {
  Serial.println(code);
  int code_len = code.length(); 
  for (int i = 0; i < code_len; i++){
     char symbol = code[i];
     if (symbol == '.'){
       digitalWrite(DATA_PIN, DATA_LEVEL);
       delay(DOT_DURATION * TU);
      }
      else{
        digitalWrite(DATA_PIN, DATA_LEVEL);
        delay(DASH_DURATION * TU);
      }
      digitalWrite(DATA_PIN, SPACE_LEVEL);
      delay(TU);
   }
   delay((LETTER_DURATION - 1) * TU);
}

void send_sep_word(){
  digitalWrite(DATA_PIN, SPACE_LEVEL);
  delay((WORD_DURATION - LETTER_DURATION) * TU);
  Serial.print(" ");
}
