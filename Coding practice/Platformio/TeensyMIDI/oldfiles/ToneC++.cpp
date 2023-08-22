#include <Arduino.h>
#include <Bounce2.h>

const int numButtons = 4;
const int buttonPins[numButtons] = {0, 1, 2, 3};
const int buzzerPin = 14;
const int baseNote = 60;

Bounce buttons[numButtons];

void setup() {
  pinMode(buzzerPin, OUTPUT);
  for (int i = 0; i < numButtons; i++) {
    buttons[i].attach(buttonPins[i], INPUT_PULLDOWN);
    buttons[i].interval(25);
  }
}

void playTone(int pin, int note, int duration) {
  int frequency = 440 * pow(2, (note - 69) / 12.0);
  tone(pin, frequency, duration);
}

void loop() {
  for (int i = 0; i < numButtons; i++) {
    buttons[i].update();
    if (buttons[i].rose()) {
      int note = baseNote + i;
      playTone(buzzerPin, note, 100);
    }
  }
}