#include <Arduino.h>
#include <Bounce.h>
#include <ClickEncoder.h>
#include <TeensyThreads.h> 



const int channel = 1;
const int num=12;
const int buttonPins[num]={23,22, 2, 3, 4 ,5 , 6, 7, 8, 9, 10, 11};
const int RotaryPins[3]= {35, 34, 36}; //A B SW
const String KeySignatureSharp[12] = {"E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#"};
const String KeySignatureFlat[12] = {"E", "F", "Gb", "G", "Ab", "A", "Bb", "B", "C", "Db", "D", "Eb"};
const unsigned long encoderCheckInterval = 100;

ClickEncoder encoder(RotaryPins[0], RotaryPins[1], RotaryPins[2]);

int keySignatureIndex= 0;
int currentOctave = 4;
int basenote= 64;

typedef Bounce BounceArray[num];
BounceArray button = {
  Bounce(buttonPins[0], 5),
  Bounce(buttonPins[1], 5),
  Bounce(buttonPins[2], 5),
  Bounce(buttonPins[3], 5),
  Bounce(buttonPins[4], 5),
  Bounce(buttonPins[5], 5),
  Bounce(buttonPins[6], 5),
  Bounce(buttonPins[7], 5),
  Bounce(buttonPins[8], 5),
  Bounce(buttonPins[9], 5),
  Bounce(buttonPins[10], 5),
  Bounce(buttonPins[11], 5)
};
void readInputsTask(void *pvParameters) {
  for (;;) {
    encoder.service();
  ClickEncoder::Button buttonState = encoder.getButton();
  //latch switch value on encoder
  int16_t encoderDelta = encoder.getValue();
  //latch A/B values for the encoder

  
  if (encoderDelta != 0) // if theres a change in the encoder value
   {
    keySignatureIndex = (keySignatureIndex + encoderDelta + 12) % 12; //we get a value between 0 and 12
    if (encoderDelta > 0) {
      currentOctave = min(currentOctave+1, 6); //max value will always be E6
      //Serial.println(KeySignatureSharp[keySignatureIndex]); //Index defines which note is pressed, useful for display
    } else {
      currentOctave= max(currentOctave-1,2); //min value will always be E2
      //Serial.println(KeySignatureFlat[keySignatureIndex]);//display info
    }
  }
  basenote= (12*currentOctave)+4 +keySignatureIndex; //MIDI conversion to note
 if (buttonState == ClickEncoder::Clicked) {
    currentOctave = 4;
    basenote = 52; // MIDI note for E4
    keySignatureIndex = 0;
  }
  
  for(int i = 0; i < num; i++) {
    button[i].update();
    //update each button
  }
    // Add delay before reading the inputs again
    delay(10);
  }
}

void processMIDITask(void *pvParameters) {
  for (;;) {
    for(int i = 0; i < num; i++) {
    if (button[i].risingEdge()) {
      usbMIDI.sendNoteOn((basenote + i), 99, channel);  
    }
  }

  
  for(int i = 0; i < num; i++) {
    if (button[i].fallingEdge()) {
      usbMIDI.sendNoteOff((basenote+i), 0, channel);  
    }
  }

    // Add delay before processing MIDI messages again
    delay(10);
  }
}

void readPiezoAnalogInputsTask(void *pvParameters) {
  for (;;) {
    // Read piezo/analog inputs and perform FFT
    // ...

    // Add delay before reading the inputs again
    delay(10);
  }
}

void setup() {
  // Your existing setup code...
for (int i = 0; i < num; i++) {
    pinMode(buttonPins[i], INPUT_PULLDOWN);
  }
  encoder.setAccelerationEnabled(true);
  pinMode(RotaryPins[2], INPUT_PULLDOWN);
  // Create tasks
 threads.addThread(readInputsTask, NULL,1024);
threads.addThread(processMIDITask,NULL, 1024);
threads.addThread(readPiezoAnalogInputsTask,NULL, 1024);


  // Start the scheduler
threads.start();
}

// Empty loop since the tasks are handled by the scheduler
void loop() {
}
