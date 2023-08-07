 This week, I have been mostly working on getting a demonstration going of my progress by displaying a simple game on the Arduino Uno using a joystick and an SPI display. 

I was able to display a moving circle using some simple header files and the Arduino IDE on Tuesday. I then decided to make the switch to the STM32 Nucleo Board to move towards testing more complex graphic libraries. Ensuring that the Microcontroller is communicating properly to the display in SPI will lay the foundation for a smooth integration with more complex libraries and their associated software, like LVGL, Squareline Studio, Makecode, etc.

### STM32 Pin configurations

|TFT_eSPI|STM32|Wire color|
| -----------  | ----------- |-|
| VCC| 5V |red|
|  GND  |GND |black|
|GND | GND|black|
|NC|NC|
|NC|NC|
|NC|NC|
|SCK| D15| green|
|SDA | D14|blue|
| DC | D10| yellow|
|RST | D9| orange|
|CS| D8| white|

I am currently encountering a failure with the SPI display and the Microcontroller, as the display only displays a white screen, with the error being a miscommunication between my compiled code and the hardware. The fault is that one or more of the signals to the display aren't working as intended. 

My plans for debugging have been to trace the code back through the header files to examine the areas in which I may have made an error. I learned the efficiency of adding "Serial.print()" in the lines of code to help dictate where the errors in communication were happening. 

My next step will be to change the pins used for the Nucleo Board, as I believe I chose the wrong pins (A0-4 seem to be ADC, whereas the D pins are GPIO). I also have an oscilloscope I plan to use should the system still not show as intended.

My Weekly Schedule from now until May will be to work on finishing a quick demo for the STM32 and Teensy boards on Tuesday, and then to adjust my plans as I take my professors' advice into consideration. I can begin testing more complicated libraries once in the following week or two, and then take each week by week as I test different display and system options for the project and take more advice from my professors. 
| week | date     | task                           | challenges                                                                    |
| ---- | -------- | ------------------------------ | ----------------------------------------------------------------------------- |
| 1    | March 6  | demo SPI and TFT communication | STM32, Teensy, Arduino, personal oscilloscope unfamiliarity                   |
| 2    | March 13 | display a sprite               | unfamiliarity with sprites and TFT_eSPI and LVGL libraries                    |
| 3    | March 20 | implement GUI                  | Many C/C++ libraries to learn and experiment                                  |
| 4    | March 27 | Game Implementation/coding     | organization and efficiency in testing and debugging,                         |
| 5    | April 3  | Game Implementation/coding     | some hardware and software options to keep track of                           |
| 6    | April 10 | Peripherals                    | possibilities to implement FPGA parallel processing as a hardware accelerator |
| 7    | April 17 | Prototyping                    | Soldering                                                                     |     |          |                                |                                                                               |


