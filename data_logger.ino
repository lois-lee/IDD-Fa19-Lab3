/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/
#include <EEPROM.h>
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
int state = 0;
int note1;
int note2;
int note3;
int note4;
int noteDurations[] = {
  18, 18, 18, 18
};

int melody[] = {
  1,1,1,1
};

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH  && state == 1) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    note1 = map(analogRead(A0), 0, 1023, 31, 4978);
    Serial.println("recording note 1!");
    Serial.println(note1);
    delay(2000);
    note2 = map(analogRead(A0), 0, 1023, 31, 4978);
    Serial.println("recording note 2!");
    Serial.println(note2);
    delay(2000);
    note3 = map(analogRead(A0), 0, 1023, 31, 4978);
    Serial.println("recording note 3!");
    Serial.println(note3);
    delay(2000);
    note4 = map(analogRead(A0), 0, 1023, 31, 4978);
    Serial.println("recording note 4!");
    Serial.println(note4);

    
    EEPROM.put(0, note1);
    EEPROM.put(5, note2);
    EEPROM.put(10, note3);
    EEPROM.put(20, note4);
    state = 0;
  } 
  if (buttonState == LOW  && state == 0){
    // turn LED off:
    digitalWrite(ledPin, LOW);
    Serial.println("done recording");
    state = 1;
    EEPROM.get(0, melody[0]);
    EEPROM.get(5, melody[1]);
    EEPROM.get(10, melody[2]);
    EEPROM.get(20, melody[3]);

    Serial.println("waiting...");
    delay(3000);
    Serial.println("playing the melody!");
    Serial.println(melody[0]);
    Serial.println(melody[1]);
    Serial.println(melody[2]);
    Serial.println(melody[3]);
    play();
  }
}

void play(){
    for (int thisNote = 0; thisNote < 4; thisNote++) {
    int noteDuration = 5000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}
