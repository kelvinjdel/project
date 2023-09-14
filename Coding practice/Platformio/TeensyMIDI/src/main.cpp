#include <Arduino.h>
#include <Bounce.h>
#include <ClickEncoder.h>

const int channel = 1;
const int num = 12;
const int buttonPins[num] = {2,3,4,5,6,7,8,9,10,11,12,24};
const int RotaryPins[3] = {28,27,26}; //A B SW
C

ClickEncoder encoder(RotaryPins[0], RotaryPins[1], RotaryPins[2]);
volatile bool aFlag = false;
volatile bool bFlag = false;
volatile bool check= false;


int keySignatureIndex = 0;
int currentOctave = 4;
int basenote = 64;

typedef Bounce BounceArray[num];
BounceArray button = {
  Bounce(buttonPins[0], 15),
  Bounce(buttonPins[1], 15),
  Bounce(buttonPins[2], 15),
  Bounce(buttonPins[3], 15),
  Bounce(buttonPins[4], 15),
  Bounce(buttonPins[5], 15),
  Bounce(buttonPins[6], 15),
  Bounce(buttonPins[7], 15),
  Bounce(buttonPins[8], 15),
  Bounce(buttonPins[9], 15),
  Bounce(buttonPins[10], 15),
  Bounce(buttonPins[11], 15)
};
void handleA() {
  
  aFlag = digitalRead(RotaryPins[0]);
  check=true;
}
void handleB() {
  bFlag = digitalRead(RotaryPins[1]);
  check=true;
}


void handleclick() {
  currentOctave = 4;
  basenote = 52; // MIDI note for E4
  keySignatureIndex = 0;
  
}

void handleButtonPress(int index) {
  button[index].update();
  if (button[index].fallingEdge()) {
    usbMIDI.sendNoteOn((basenote + index), 99, channel);
  } else if (button[index].risingEdge()) {
    usbMIDI.sendNoteOff((basenote + index), 0, channel);
  }
}

void setup() {
  for (int i = 0; i < num; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  encoder.setAccelerationEnabled(true);
  pinMode(RotaryPins[2], INPUT_PULLDOWN);
  pinMode(RotaryPins[1], INPUT_PULLUP);
  pinMode(RotaryPins[0], INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(RotaryPins[2]), handleclick, CHANGE);
  attachInterrupt(digitalPinToInterrupt(RotaryPins[0]), handleA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(RotaryPins[1]), handleB, CHANGE);
}

void loop() {
  
    if (check) {
    int16_t encoderDelta = 0;

    if (aFlag != bFlag) {
      encoderDelta = 1;
    } else {
      encoderDelta = -1;
    }

    int previousKeySignatureIndex = keySignatureIndex;
    keySignatureIndex = (keySignatureIndex + encoderDelta + 12) % 12; // we get a value between 0 and 12

    if (previousKeySignatureIndex == 11 && keySignatureIndex == 0) {
      currentOctave = min(currentOctave + 1, 6); // max value will always be E6
    } else if (previousKeySignatureIndex == 0 && keySignatureIndex == 11) {
      currentOctave = max(currentOctave - 1, 2); // min value will always be E2
    }

    basenote = (12 * currentOctave) + 4 + keySignatureIndex; //MIDI conversion to note

    check = false;
  
  }
  for (int i = 0; i < num; i++) {
    handleButtonPress(i);
  }
  while (usbMIDI.read()) {
    // ignore incoming messages
  }
}
