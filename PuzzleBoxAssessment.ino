//Digital Outputs
const int led1 = 1;
const int led2 = 2;
const int led3 = 3;
const int led4 = 4;
const int led5 = 5;
const int ledred = 6;
const int ledgreen = 7;
const int ledblue = 8;
const int led6 = 9;
const int led7 = 10;
const int led8 = 11;
const int led9 = 12;

//Analog Inputs
const int potPin = A0;
const int button1 = A1;
const int button2 = A2;
const int button3 = A3;
const int photoSensor1 = A4;
const int photoSensor2 = A5;


//Calabration Variables
int lightCal1;
int lightCal2;
int lightVal;

//Decliration of inputs and outputs
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(ledred, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(ledblue, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(potPin, INPUT);
  lightCal1 = analogRead(photoSensor1);
  lightCal2 = analogRead(photoSensor2);
}

void loop(){
  potentiometerPuzzle();
  buttonPuzzle();
  photoPuzzle();
}

//This secton of the puzzle uses 3 push buttons and 5 LEDs, you need to push the buttons in the right configuration in order to illuminate all 4 leds.
void buttonPuzzle() {
  if (analogRead(button1) > 245 ){ 
    toggle(led1);
    toggle(led3);
    delay(500);
   }
  
   if (analogRead(button2) > 245 ){
    toggle(led1);
    toggle(led2);
    toggle(led4);
    delay(500);
   }
  
    if (analogRead(button3) > 245 ){
    toggle(led2);
    toggle(led4);
    delay(500);
   }
  
   
   if (digitalRead(led1) && digitalRead(led2) && digitalRead(led3) && digitalRead(led4)){
    delay(500);
    digitalWrite(led5, HIGH);
   } else digitalWrite(led5, LOW);

}

//Function to allow the toggling of leds. 
void toggle(int lednumber){
    digitalWrite(lednumber, !digitalRead(lednumber));
}

//Function to set and write the colour for the potentiometer puzzle
void setColour(int redValue, int greenValue, int blueValue) { 
  analogWrite(ledred, redValue);
  analogWrite(ledgreen, greenValue);
  analogWrite(ledblue, blueValue);
}

//This secton of the puzzle uses a potentiometer and RGB led, you need to make the RGB led a certain colour.
void potentiometerPuzzle(){
  int colour = analogRead(potPin);
    if (colour == 0 && colour <=12){
       setColour(0, 0, 0);
    }
    else if (colour >= 13 && colour <=112){
       setColour(255, 204, 0);
    }
    else if (colour >= 113 && colour <=212){
       setColour(255, 104, 0);
    }  
     else if (colour >= 213 && colour <=312){
       setColour(255, 0, 0);
    }  
     else if (colour >= 313 && colour <=412){
       setColour(255, 255, 255);
    }  
     else if (colour >= 413 && colour <=512){
       setColour(255,255,255);
    }  
     else if (colour >= 513 && colour <=612){
       setColour(170, 0, 200);
    }  
     else if (colour >= 613 && colour <=712){
       setColour(0, 0, 255);
    }  
     else if (colour >= 713 && colour <=812){
      setColour(0, 255, 205);
    }  
     else if (colour >= 813 && colour <=912){
       setColour(51, 153, 51);
    }  
     else if (colour >= 913 && colour <=1012){
      setColour(0, 255, 0);
    }  
     else if (colour >= 1013 && colour <=1023){
       setColour(0, 0, 0);
    } 
    if (colour >= 713 && colour <=812){
      delay(500);
      digitalWrite(led6, HIGH);
   } else digitalWrite(led6, LOW); 
}

//This section of the puzzle uses a photoresistor and a RGB indicator, 3 photo resistors have to be held at the right value to the section to be complete. 
void photoPuzzle(){
  if (lightVal < lightCal1 - 10){
    digitalWrite(led7, LOW);
  }
  else {
    digitalWrite(led7, LOW);
  }
  if (lightVal < lightCal2 - 60){
    digitalWrite(led8, LOW);
  }
  else {
    digitalWrite(led8, LOW);
  }

  if (digitalRead(led7) && digitalRead(led8)){
    delay(500);
    digitalWrite(led9, HIGH);
    //toggle(led7);
    //toggle(led8);
   } 
   else digitalWrite(led9, LOW); 
}

void puzzleComplete(){
  if (digitalRead(led5) && digitalRead(led6) && digitalRead(led9)){
    delay(500); 
    
  }
}
