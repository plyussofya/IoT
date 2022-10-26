#define btn_pin 12
#define A 4
#define B 5
#define C 6
#define D 7
#define E 8
#define FF 9
#define G 10
#define DP 11

void turnoff()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(FF, LOW);
  digitalWrite(G, LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(btn_pin, INPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(FF, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);
}

bool val_last = 1;
bool val = 1;
int count = 0;
int time = 0;

void loop() {
  val_last = val;
  val = digitalRead(btn_pin);

  if (val == 0 && val_last == 0)
  {
    if (time / 3 == 0)
    {
      turnoff();
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(FF, HIGH);
    }
    else if (time / 3 == 1)
    {
      turnoff();
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
    }
    else if (time / 3 == 2)
    {
      turnoff();
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(D, HIGH);
    }
    else if (time / 3 == 3)
    {
      turnoff();
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
    }
    else if (time / 3 == 4)
    {
      turnoff();
      digitalWrite(FF, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
    }
    else if (time / 3 == 5)
    {
      turnoff();
      digitalWrite(A, HIGH);
      digitalWrite(FF, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
    }
    else if (time / 3 == 6)
    {
      turnoff();
      digitalWrite(A, HIGH);
      digitalWrite(FF, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(G, HIGH);
    }
    else if (time / 3 == 7)
    {
      turnoff();
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
    }
    else if (time / 3 == 8)
    {
      turnoff();
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(FF, HIGH);
      digitalWrite(G, HIGH);
    }
    else if (time / 3 == 9)
    {
      turnoff();
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(FF, HIGH);
    }
    else
    {
      turnoff();
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(FF, HIGH);
    }
  }
}