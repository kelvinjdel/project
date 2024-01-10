https://www.youtube.com/watch?v=hI0UBvpuRTw

Started putting Mugu together, messed up power supply design structure for the motor driver, so I took a break while I focus on Control Systems. 

For now, the power supply was with two coin cell, CR2023 in series via Lilypads to turn on/off, and a TP4056 recharging module, of which I am not too familiar with 

https://dlnmh9ip6v2uc.cloudfront.net/datasheets/Prototyping/TP4056.pdf

I think I need to reassess the datasheet, but I don't think any of the components used in testing were damaged, as the test was a very light 1kHz at "100 speed" arduino test to see how the uno shield would react. at this point, I had to refocus on my Midterm and come back to Mugu on friday


Week 2 update:

I updated the motor shield to use mosfets and have begun circuit analysis on a power supply, but I am likely to use the previous circuit in another project as well for fun.

For now, I have done a good amount of progress designing and building a music box, so I have an 98735a Max I2S amplifier soldered to an ESP8266, 

Currently working on Neovim environment stuff to close out the day. I will get back to working on this tomorrow as well.

Week 3 update:
I bought some assorted ICs to play with and will be aiming to get a Mugu test run going today :3

Winter break: 
I am starting some work on the power supply after some research, and have soldered a 2s 18650 battery with a bms, and will test charging and the motor performance to get a better understanding of the datasheet ratings of amperage and wattage of the digital system of the UNO
https://us.reddit.com/r/AskElectronics/wiki/batteries#wiki_bms_is_not_a_charger

Mugu is using 9900mAh, 4 motors
https://www.verical.com/datasheet/adafruit-brushless-dc-motors-3777-5912007.pdf

12/28/2023
Testing an esp8266 mic system that takes from the ADC through DMA
https://www.youtube.com/watch?v=pPh3_ciEmzs

12/31/23 
looking into Motor shield schematics before I start testing with the new battery:
https://learn.adafruit.com/assets/9536

Drew sparks today for the first time out of my bench power supply which was cool, precharged my batteries' bms and am now getting 8.035 at the leads and I am going to test the next part

Everything seems to be working okay. next test should prioritize handling my amperage, so I will look to solutions later (maybe some sort of high impedance with  conversion via resistance for amperage to voltage reading of the microcontroller, leading to Ohms law estimations.) Ideally, each motor's amperage can be read, killed, and controlled with the Microcontroller's estimations. Some PID elements could be done, sending information to the FPGA. Right now, I am labelling the motors, and I will be dissecting the header files for now.

I finished editing my initial test file and so far all my tests look good. I will see if I can implement that camera with it or something along those lines, but I am excited to continue to test

1/2/23 

Working on fixing my Neovim Config today. Mugu's progress comes from my patience.

11/10/23

![[Pasted image 20240110114731.png]]
added some configurations to my terminal and can start working on my project. I want to have something visual to show for Mugu by the 22nd