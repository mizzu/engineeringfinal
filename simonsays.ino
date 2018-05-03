const int buttonPin1 = 2; // button for led 1
const int ledPin1 =  13; // output for led 1
const int buttonPin2 = 3; // button for led 2
const int ledPin2 =  12; // output for led 2
const int buttonPin3 = 4; // button for led 3
const int ledPin3 =  11;  // output for led 3
const int piezoPin = 9; // output for piezo
const int simondelay = 200; // how fast simon displays the LED
int introd = 0; //global to detect if it's the initial run of the program
int intone = 0; // deprecated
int l = 0; //used efor the value that needs to be compared

int buttonState1 = 0; // states of button 1, 2 and 3
int buttonState2 = 0; 
int buttonState3 = 0;

int simons[20]; //length of total sequence
int at = 0; // global value for where the current sequence is at
int wait = -1; //semaphore for detecting input

void setup() { // sets up the pins
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(piezoPin, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
}

void intro() { // an intro bit that is played before each game is played
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

int getval(){ // this repeats until a value is obtained in the main loop
  
  buttonState1 = digitalRead(buttonPin1);

  buttonState2 = digitalRead(buttonPin2);
  
  buttonState3 = digitalRead(buttonPin3); // grabs the state of each pin

  if(buttonState1 == HIGH && buttonState2 == HIGH && buttonState3 == HIGH)
    noTone(piezoPin); // if they're not pressed, don't play a sound
  
  if (buttonState1 == HIGH) {
        digitalWrite(ledPin1, LOW);
  }
  else { // if the corresponding pin is pressed
        digitalWrite(ledPin1, HIGH); // light the LED
        tone(piezoPin, 1000); // play its corresponding sound
        while(buttonState1 == LOW) {
          buttonState1 = digitalRead(buttonPin1); //wait until the LED is depressed so multiple values aren't obtained
        }
        digitalWrite(ledPin1, LOW); // shut off the LED
        noTone(piezoPin); // stop the sound
        return 0; // returning the corresponding led value
  }
  if (buttonState2 == HIGH) // this repeats for each button
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
  return -1; // if -1 is returned (semaphore) loops again until it gets a value 0-2
}

void says(int r) { // this just plays simons current sequence
    if (r == 0) {
        digitalWrite(ledPin1, HIGH); // if the value is LED 0, lights LED 0
        tone(piezoPin, 1000); // plays LED 0 sound
        delay(simondelay); // delays by the global value
        noTone(piezoPin); //turns off sound
        digitalWrite(ledPin1, LOW);  // turns off LED
        delay(200);
  }
  if (r == 1){ //process repeats for each value in the current sequence
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

void simon(){ //where simon generates a random number
  int k = random(3); // gets a random number 0-2
  simons[at] = k; // adds it to simons current sequence
  at++; // increments for the next placement
  for(int i = 0; i < at; i++)
    says(simons[i]); //replays simon's new sequence
}

void win(){ // sound for winning
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
  introd = 0; //resets the game
}

void initt(){ // initializes the sequence and gets a random seed so the game is fairly randomized
  for(int i = 0; i < sizeof(simons); i++)
    simons[i] = -1;
  at = 0;
  randomSeed(analogRead(0));
}

void lose(){ // losing theme, inspired by Oregon Trail
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
    for(int i = 0; i < 20; i++){ //flashes the LEDs
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
  introd = 0; // resets the game
}

void loop() { // master loop
  if (introd == 0){ // if the game is not initalized
    intro(); // plays intro sound
    initt(); // initializes the sequence
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin1, LOW); // resets all LEDs
    delay(1000); // waits before starting the game to help the user prepare
    introd = 1; // sets this variable to one, so the game will not reinitalize on the next loop until a win or loss
  }
  simon(); // generates a new value in the sequence
  wait = -1; // initalizes the semaphore
  for(l = 0; l < at; l++) // for every value in the sequence
    {
      while(wait == -1)
        wait = getval(); // get the users value
      if(simons[l] != wait) { // and compare it with the current value in the sequence
        lose(); // lose if it's different
        at = 0; // resets the game location of the current sequence
        break; // breaks out of the loop to reinitialize
      }
       wait = -1; // if it's not correct, reinitialize the sempahore for getval();
    }
  if(at == 20){ // if the input is at the max value
  win(); // play the win sound and reset
  }
  delay(500); // delays between simon and user inputs to help differentiate
}

