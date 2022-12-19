#define DATA_PIN 2
#define DATA_LEVEL LOW
#define SPACE_LEVEL HIGH
#define DATA true
#define SPACE false

#define DOT_DURATION 1
#define DASH_DURATION 3

#define LETTER_DURATION 3
#define WORD_DURATION 7

#define TU 100

long start_data, start_space;
long duration[20];
long duration_space[20];
bool color[20];
int index = 0;
int previous = SPACE_LEVEL;
bool isEndWord = false;
String CODES[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
char LETTERS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int NLETTRERS = 26;
String message = "";

void setup() {
  Serial.begin(9600);
  pinMode(DATA_PIN, INPUT);
}

void loop() {
  fill_arrays();
  decode_letter();
}

void decode_letter(){
  bool isEditing = false;
  for (int i=0; i < index; i++){
    if (duration[i] >= LETTER_DURATION and color[i] == SPACE){
      String code = "";
      for (int j=0; j < i; j++){
        //Serial.println(duration[j]);
        if (duration[j] == DASH_DURATION and color[j] == DATA){
          code += '-';
        }
        else if (duration[j] == DOT_DURATION and color[j] == DATA){
          code += '.';
        }
        duration[j] = 0;
      }
      duration[i] = 0;
      //Serial.println(code);
      for (int il=0; il < NLETTRERS; il++){
        if (code == CODES[il]){
      	 isEditing = true;
         message += LETTERS[il];
         Serial.print(message);
        }
      }
    }
    if (isEditing && isEndWord)
    {
      Serial.print("\n");
      index = 0;
      isEndWord = false;
    }
  }
  if (isEditing)
  {
  	index = 0;
    message = "";
  }
}

void fill_arrays(){
  int current = digitalRead(DATA_PIN);
  if (current == DATA_LEVEL && previous == SPACE_LEVEL){
    start_data = millis();
    duration[index] = int((millis() - start_space + 0.5 * TU) / TU);
    color[index] = SPACE;
    index++;
  }
  else if (current == SPACE_LEVEL && previous == DATA_LEVEL){
    isEndWord = false;
    start_space = millis();
    duration[index] = int((millis() - start_data + 0.5 * TU) / TU);
    color[index] = DATA;
    index++;
  }
  else if (isEndWord == false && current == SPACE_LEVEL && previous == SPACE_LEVEL){
    long temp = millis() - start_space;
    if (temp > TU * WORD_DURATION)
    {
    	isEndWord = true;
    	duration[index] = WORD_DURATION;
      	index++;
  	}
  }
  previous = current;
}
