/* Written by Muhammad Yaacob bin Hasan

QUIZ Button
Arduino Nano
Date : February 2019

*/ 
//Define Music
struct MusicStruct {
  int A = 550;
  int As = 582;
  int B = 617;
  int C = 654;
  int Cs = 693;
  int D = 734;
  int Ds = 777;
  int E = 824;
  int F = 873;
  int Fs = 925;
  int G = 980;
  int Gs = 1003;
  int A2 = 1100;
  int A2s = 1165;
  int B2 = 1234;
  int C3 = 1308;
  int C3s = 1385;
  int D3 = 1555;
}Music;

struct LengthStruct {
  float half = 0.5;
  float one = 1.0;
  float one_half = 1.5;
  float two = 2.0;
  float two_half = 2.5;
}Length;

int tempo = 400;

boolean musicPlayed = 0;

//Define buzzer
const int buzzer = 13;
boolean buzzerPlayedState = 0;


//Define Buttons
//Reset Button
int resetButtonPin = 2;
int ledResetButton = 3;

//Button1
int button1Pin = 5;
int led1Pin = 4;
int button1State = 0; 

//Button2
int button2Pin = 11;
int led2Pin = 10;
int button2State = 0; 

//Button3
int button3Pin = 9;
int led3Pin = 8;
int button3State = 0; 

//Button4
int button4Pin = 7;
int led4Pin = 6;
int button4State = 0; 

int resetButtonState = 0;
boolean pollingForPresses = 1;

int lastbutton1State = LOW;
int lastbutton2State = LOW;
int lastbutton3State = LOW;
int lastbutton4State = LOW;
int lastResetState = LOW;

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  pinMode(ledResetButton, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(resetButtonPin, INPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);

  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(ledResetButton, LOW);
  int reading1 = digitalRead(button1Pin);
  int reading2 = digitalRead(button2Pin);
  int reading3 = digitalRead(button3Pin);
  int reading4 = digitalRead(button4Pin);
  int readingReset = digitalRead(resetButtonPin);

    if(pollingForPresses==1){
      //Button 1
      if (reading1 != button1State && reading1 != lastbutton1State) {
        button1State = reading1;
        button1State = digitalRead(button1Pin);
        buzzerPlayedState = 1; 
              if (button1State == HIGH) {
                // turn LED on:
                  Serial.println("Button 1 ON");
                digitalWrite(led1Pin, HIGH);
                playBuzzer();
                pollingForPresses = 0;
              }
         buzzerPlayedState = 0; 
         button1State = 0;
      }
   
      //Button 2
      if (reading2 != button2State && reading2 != lastbutton2State) {
        button2State = reading2;
        button2State = digitalRead(button2Pin);
        buzzerPlayedState = 1;  
              if (button2State == HIGH) {
                // turn LED on:
                  Serial.println("Button 2 ON");
                digitalWrite(led2Pin, HIGH);
                playBuzzer();
                pollingForPresses = 0;
              }
         buzzerPlayedState = 0; 
         button2State = 0;
      }

      //Button 3
      if (reading3 != button3State && reading3 != lastbutton3State) {
        button3State = reading3;
        button3State = digitalRead(button3Pin);
        buzzerPlayedState = 1;   
              if (button3State == HIGH) {
                // turn LED on:
                  Serial.println("Button 3 ON");
                digitalWrite(led3Pin, HIGH);
                playBuzzer();
                pollingForPresses = 0;
              }
         buzzerPlayedState = 0; 
         button3State = 0;
      }

      //Button 4
      if (reading4 != button4State && reading4 != lastbutton4State) {
        button4State = reading4;
        button4State = digitalRead(button4Pin);
        buzzerPlayedState = 1;   
              if (button4State == HIGH) {
                // turn LED on:
                  Serial.println("Button 4 ON");
                digitalWrite(led4Pin, HIGH);
                playBuzzer();
                pollingForPresses = 0;
              }
         buzzerPlayedState = 0; 
         button4State = 0;
      }
      
    }
   //Check reset button
   
    if (pollingForPresses==0) {
    digitalWrite(ledResetButton, HIGH);
      if (readingReset != resetButtonState && readingReset != lastResetState) {
              resetButtonState = digitalRead(resetButtonPin);
          
              if (resetButtonState == HIGH) {
                Serial.println("Reset button HIGH");
                
                resetButtons();
              }
         
         resetButtonState = 0;
      }
    }
    
  lastResetState = readingReset;
  lastbutton1State = reading1;  
  lastbutton2State = reading2;
  lastbutton3State = reading3;  
  lastbutton4State = reading4;
  playMusic();
}


void resetButtons() {
  
  lastbutton1State = 0;
  lastbutton2State = 0;
  lastbutton3State = 0;
  lastbutton4State = 0;
  resetButtonState = 0;
  lastResetState = 0;
  
  button1State = 0;
  button2State = 0;
  button3State = 0;
  button4State = 0;
  
  Serial.println("All the Buttons is reset!");
  
  digitalWrite(ledResetButton, HIGH);
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
  digitalWrite(led3Pin, LOW);
  digitalWrite(led4Pin, LOW);
  digitalWrite(resetButtonPin, LOW);
  
  pollingForPresses = 1;
}

void playBuzzer(void){
  if(buzzerPlayedState == true){
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
  }

}

void playMusic(void){
  if(musicPlayed == 0){
  digitalWrite(ledResetButton, HIGH);
  setTone(buzzer, Music.B, tempo * Length.one);
  setTone(buzzer, Music.E, tempo * Length.one_half);
  setTone(buzzer, Music.G, tempo * Length.half);
  setTone(buzzer, Music.F, tempo * Length.one);
  setTone(buzzer, Music.E, tempo * Length.two);
  setTone(buzzer, Music.B2, tempo * Length.one);
  setTone(buzzer, Music.A2, tempo * Length.two_half);
  setTone(buzzer, Music.Fs, tempo * Length.two_half);
  
  setTone(buzzer, Music.E, tempo * Length.one_half);
  setTone(buzzer, Music.G, tempo * Length.half);
  setTone(buzzer, Music.F, tempo * Length.one);
  setTone(buzzer, Music.Ds, tempo * Length.two);
  setTone(buzzer, Music.F, tempo * Length.one);
  setTone(buzzer, Music.B, tempo * Length.two_half);

  digitalWrite(ledResetButton, LOW);
  musicPlayed++;
  }
  
}

void setTone(int pin, int note, int duration) {
  tone(pin, note, duration);
  delay(duration);
  noTone(pin);
}
