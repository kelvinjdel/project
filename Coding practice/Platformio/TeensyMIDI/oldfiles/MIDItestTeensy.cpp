#include <Arduino.h>
#include <Bounce2.h>
#include <MIDI.h>

const int numButtons = 12;
const int buttonPins[numButtons] = {23, 22, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
const int baseNote = 60;
const int channel = 1;
const int buzzerPin = 14;
Bounce buttons[numButtons];

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  MIDI.begin();
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as OUTPUT
  for (int i = 0; i < numButtons; i++) {
    buttons[i].attach(buttonPins[i], INPUT_PULLDOWN);
    buttons[i].interval(25);
  }
}

void loop() {
  for (int i = 0; i < numButtons; i++) {
    buttons[i].update();
    if (buttons[i].rose()) {
      int note = baseNote + i;
      MIDI.sendNoteOn(note, 127, channel);
      tone(buzzerPin, note * 2); // Play the tone on the buzzer
    }
    if (buttons[i].fell()) {
      int note = baseNote + i;
      MIDI.sendNoteOff(note, 0, channel);
      noTone(buzzerPin); // Stop playing the tone on the buzzer
    }
  }
}
