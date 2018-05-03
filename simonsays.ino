const int buttonPin1 = 2;  
const int ledPin1 =  13;      
const int buttonPin2 = 3;  
const int ledPin2 =  12;      
const int buttonPin3 = 4;  
const int ledPin3 =  11;  
const int piezoPin = 9;
const int simondelay = 200;
int introd = 0;
int intone = 0;
int l = 0;

int buttonState1 = 0;
int buttonState2 = 0; 
int buttonState3 = 0;

int simons[20];
int at = 0;
int wait = -1;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(piezoPin, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
}

void intro() {
  tone(piezoPin, 1000);
  digitalWrite(ledPin1, LOW);
  delay(200);
  digitalWrite(ledPin1, HIGH);
  noTone(piezoPin);
  tone(piezoPin, 1500);
  digitalWrite(ledPin2, LOW);
  delay(200);
  digitalWrite(ledPin2, HIGH);
  noTone(piezoPin);
  tone(piezoPin, 2000);
  digitalWrite(ledPin3, LOW);
  delay(200);
  digitalWrite(ledPin3, HIGH);
  noTone(piezoPin);
  tone(piezoPin, 1500);
  digitalWrite(ledPin2, LOW);
  delay(200);
  digitalWrite(ledPin2, HIGH);
  noTone(piezoPin);
  tone(piezoPin, 1000);
  digitalWrite(ledPin1, LOW);
  delay(200);
  digitalWrite(ledPin1, HIGH);
  noTone(piezoPin);
}

int getval(){
  
  buttonState1 = digitalRead(buttonPin1);

  buttonState2 = digitalRead(buttonPin2);
  
  buttonState3 = digitalRead(buttonPin3);

  if(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH)
    noTone(piezoPin);
  
  if (buttonState1 == HIGH) {
        digitalWrite(ledPin1, LOW);
  }
  else {
        digitalWrite(ledPin1, HIGH);
        tone(piezoPin, 1000);
        while(buttonState1 == LOW) {
          buttonState1 = digitalRead(buttonPin1);
        }
        digitalWrite(ledPin1, LOW);
        noTone(piezoPin);
        return 0;
  }
  if (buttonState2 == HIGH) 
        digitalWrite(ledPin2, LOW);
  else {
        digitalWrite(ledPin2, HIGH);
        tone(piezoPin, 1500);
        while(buttonState2 == LOW) {
          buttonState2 = digitalRead(buttonPin2);
        }
        digitalWrite(ledPin2, LOW);
        noTone(piezoPin);
        return 1;
  }
  if (buttonState3 == HIGH) {
        digitalWrite(ledPin3, LOW);
  }
  else {
        digitalWrite(ledPin3, HIGH);
        tone(piezoPin, 2000);
        while(buttonState3 == LOW) {
          buttonState3 = digitalRead(buttonPin3);
        }
        digitalWrite(ledPin3, LOW);
        noTone(piezoPin);
        return 2;
  }
  return -1;
}

void says(int r) {
    if (r == 0) {
        digitalWrite(ledPin1, HIGH);
        tone(piezoPin, 1000);
        delay(simondelay);
        noTone(piezoPin);
        digitalWrite(ledPin1, LOW);
        delay(200);
  }
  if (r == 1){
        digitalWrite(ledPin2, HIGH);
        tone(piezoPin, 1500);
        delay(simondelay);
        noTone(piezoPin);
        digitalWrite(ledPin2, LOW);
        delay(200);
  }
  if (r == 2){
        digitalWrite(ledPin3, HIGH);
        tone(piezoPin, 2000);
        delay(simondelay);
        noTone(piezoPin);
        digitalWrite(ledPin3, LOW);
        delay(200);
  }
}

void simon(){
  int k = random(3);
  simons[at] = k;
  at++;
  for(int i = 0; i < at; i++)
    says(simons[i]);
}

void win(){
  delay(200);
  tone(piezoPin, 433);
  delay(150);
  noTone(piezoPin);
  tone(piezoPin, 483);
  delay(150);
  noTone(piezoPin);
  tone(piezoPin, 293);
  delay(150);
  noTone(piezoPin);
  tone(piezoPin, 522);
  delay(300);
  noTone(piezoPin);
  introd = 0;
}

void initt(){
  for(int i = 0; i < sizeof(simons); i++)
    simons[i] = -1;
  at = 0;
  randomSeed(analogRead(0));
}

void lose(){
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  delay(200);
  tone(piezoPin, 242);
  delay(200);
  noTone(piezoPin);
  tone(piezoPin, 272);
  delay(150);
  noTone(piezoPin);
  tone(piezoPin, 288);
  delay(150);
  noTone(piezoPin);
  tone(piezoPin, 323);
  delay(150);
  noTone(piezoPin);
  tone(piezoPin, 363);
  delay(300);
  noTone(piezoPin);
  tone(piezoPin, 483);
  delay(300);
  noTone(piezoPin);
  tone(piezoPin, 363);
  delay(150);
  noTone(piezoPin);
  tone(piezoPin, 383);
  delay(250);
  tone(piezoPin, 483);
  delay(400);
  noTone(piezoPin);
  tone(piezoPin, 383);
  delay(150);
  noTone(piezoPin);
  tone(piezoPin, 363);
  delay(250);
  tone(piezoPin, 483);
  delay(400);
  noTone(piezoPin);
  tone(piezoPin, 242);
  delay(200);
  noTone(piezoPin);
  tone(piezoPin, 272);
  delay(150);
  noTone(piezoPin);
  tone(piezoPin, 288);
  delay(150);
  noTone(piezoPin);
  tone(piezoPin, 323);
  delay(150);
  noTone(piezoPin);
  tone(piezoPin, 363);
  delay(200);
  noTone(piezoPin);
  tone(piezoPin, 483);
  delay(300);
  noTone(piezoPin);
  tone(piezoPin, 548);
  delay(200);
  noTone(piezoPin);
  tone(piezoPin, 578);
  delay(200);
  noTone(piezoPin);
  tone(piezoPin, 548);
  delay(200);
  noTone(piezoPin);
  tone(piezoPin, 483);
  delay(200);
  noTone(piezoPin);
  delay(50);
  tone(piezoPin, 483);
    for(int i = 0; i < 20; i++){
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  delay(30);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  delay(30);
  }
  noTone(piezoPin);
  introd = 0;
}

void loop() {
  if (introd == 0){
    intro();
    initt();
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin1, LOW);
    delay(1000);
    introd = 1;
  }
  simon();
  wait = -1;
  for(l = 0; l < at; l++)
    {
      while(wait == -1)
        wait = getval();
      if(simons[l] != wait) {
        lose();
        at = 0;
        break;
      }
       wait = -1;
    }
  if(at == 20){
  win();
  }
  delay(500);
}

