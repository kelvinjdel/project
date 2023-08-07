Testing out running the same demo that was used with the UNO.

### STM32 Pin configurations

|TFT_eSPI|STM32|Wire color|
| -----------  | ----------- |-|
| VCC| 5V |red|
|  GND  |GND |black|
|GND | GND|black|
|NC|NC|
|NC|NC|
|NC|NC|
|SCK| A0| green|
|SDA | A1|blue|
| DC | A2| yellow|
|RST | A3| orange|
|CS| A4| white|

Having issues with displaying on TFT, will use Oscilloscope to test SPI pin outputs and hopefully make more visible progress with the project. 

I am also finding the Arduino environment and the embedded system software environments to be a hard place to debug. I currently am setting Serial.println("test") breakdown points to see where the errors are being made in the flow, but I would really like the ability to break down the Cpp files even further to see where the errors are occurring relative to the hardware. 

This has been a challenging learning curve, but I am developing debugging habits to make the process even smoother for the long-term problems that may arise should we need to change other aspects of the project. For example, I would like to use an FPGA to handle many of the peripheral and hardware-accelerating processes.
