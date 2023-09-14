#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
static const unsigned char PROGMEM logo_bmp[] =
{ 0b00000000, 0b11000000,
  0b00000001, 0b11000000,
  0b00000001, 0b11000000,
  0b00000011, 0b11100000,
  0b11110011, 0b11100000,
  0b11111110, 0b11111000,
  0b01111110, 0b11111111,
  0b00110011, 0b10011111,
  0b00011111, 0b11111100,
  0b00001101, 0b01110000,
  0b00011011, 0b10100000,
  0b00111111, 0b11100000,
  0b00111111, 0b11110000,
  0b01111100, 0b11110000,
  0b01110000, 0b01110000,
  0b00000000, 0b00110000 };

 #define A 5
 #define B 4
 #define sw 15

unsigned long _lastIncReadTime= micros();
unsigned long _lastDecReadTime= micros();
int _pauseLength =25000;
volatile int counter =9;
const String KeySignatureSharp[12] = {"E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#"};
const String KeySignatureFlat[12] = {"E", "F", "Gb", "G", "Ab", "A", "Bb", "B", "C", "Db", "D", "Eb"};

void testtext();
void read_encoder();

void setup() { 
   pinMode (A,INPUT_PULLUP);
   pinMode (B,INPUT_PULLUP);
   attachInterrupt(digitalPinToInterrupt(A), read_encoder, CHANGE); //IRS
   attachInterrupt(digitalPinToInterrupt(B), read_encoder, CHANGE);
   Serial.begin (9600);
   // Reads the initial state of the A
   Serial.println("initiating");
   if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
   display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
  display.drawPixel(10, 10, SSD1306_WHITE);

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  delay(2000);


  testtext();    
} 

void loop() { 
  static int lastCounter=0;
  if (counter !=lastCounter)
  {
    Serial.println(counter);
    lastCounter= counter;
    testtext();
  }
}

void testtext(void) {
  display.clearDisplay();

  display.setTextSize(2); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  String keysignature= KeySignatureFlat[counter];
  display.println((keysignature));
  display.display();      // Show initial text
  delay(100);

}


void read_encoder() //IRS, change in A or B causes this interrupt
{
  static uint8_t old_AB=3; //11, rotary encoder is in rest position
  static int8_t encval =0;
  static const int8_t enc_states[]= {0,-1,1,0,1, 0,0,-1,-1,0,0,1,0,1,-1,0}; //16 state FSM

  old_AB<<=2; //11 becomes 1100, or 12 for the FSM
  if(digitalRead(A)) old_AB|=0x02; 
  if(digitalRead(B)) old_AB |= 0x01;
 
 encval += enc_states[(old_AB &0x0f)]; //only uses first 4 bits for the state

  if(encval >3)
  { 
  int changevalue=1;
    if((micros()- _lastIncReadTime)< _pauseLength)
    {
    changevalue=10*changevalue;
    }
  _lastIncReadTime=micros();
  counter= counter + changevalue;
  encval=0;
  }
  else if (encval<-3 )
  {
    int changevalue =-1;
    if((micros()- _lastDecReadTime)< _pauseLength) 
    {
      changevalue=10*changevalue;
    }
    _lastDecReadTime=micros();
    counter=counter + changevalue;
    encval=0;
  } 
  if (counter >=12)
  {counter=12;
  }
  else if (counter<=0)
  {counter=0;
  }
  }
