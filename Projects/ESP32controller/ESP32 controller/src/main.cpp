#include <Arduino.h>
#include <Wire.h>
#include <MAX98357A.h>



// Define the audio pins connected to the MAX98357A
#define MAX98357A_DIN 27
#define MAX98357A_LRCK 12
#define MAX98357A_BCLK 14

// Create a MAX98357A object
MAX98357A amplifier(Wire, MAX98357A_DIN, MAX98357A_LRCK, MAX98357A_BCLK);

void setup() {
  // Start the I2C bus
  Wire.begin(I2C_SDA, I2C_SCL);

  // Initialize the MAX98357A
  amplifier.begin();

  // Set the volume to 50%
  amplifier.setVolume(0.5);
}

void loop() {
  // Play a 440 Hz tone for 1 second
  amplifier.playTone(440, 1000);

  // Wait for a second
  delay(1000);

  // Play a 660 Hz tone for 1 second
  amplifier.playTone(660, 1000);

  // Wait for a second
  delay(1000);
}