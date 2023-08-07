
# Arcade Game System K1 (temporary)

##Early Expectations
- platformer created from [[Makecode]]'s Makecode system
- raspberry PI or similar
- VGA(640x480) resolution
- 60 Hz refresh rate
- Hardware acceleration using CMOD S7 FPGA
	- controller input logic, graphical acceleration, etc

## Goals
- Incorporates features for a Dungeons and Dragons table
	- machine learning camera that can translate player rolls to send to algorithms
	- Internet/Software integration for editing maps from tools such as Roll20/Talespire
	- Character sheet/API data management
	These examples are very low priority as they are mostly Computer Science based but
	should add alot of depth to our technical skills 

- Multiplayer Arcade Game
	- roguelike 2/3 player survival game
	- co-op platformer
	- 6 player airhockey table
	These are also very hopeful goals, but would similarly add alot of depth to our resumes should we strive to tackle the challenges that may arise from adding extra featuress

- Rhythm game 
	- incorporates a midi style controller with a guitar or keyboard for a fun rhythm game
	- The guitar midi controller would signal to system using a matrix of resistors to identify what fret and string is being played, similar to how a keypad works. Complications may arise from the bulky nature of such a circuit.
	- Another option with the midi controller is to have a signal processing unit that identifies the note being played through an ADC. For example, a sensor that detects the frequency of sound being played would then be broken down to the game logic to identify whether or not the correct input was given.
	

## Technical ideology
- This project will lead us through the thought process of engineering from the
brainstorming to mass production. The final documentation will seek to explain the different methods and research enlisted to provide minimal power consumption, price, and details
including the datasheets, schematics, and PCB for a production team to utilize. 



# Architecture
## Display
- [[Display Planner]] #display 
## Microcontroller
- [[Microcontroller Planner]] #microcontroller
## FPGA
- [[FPGA Planner]] #fpga 
## Software
- [[Makecode]]
- [[PlatformIO Notes]]
- [[Spellbook/Education/Workstation/git-repo/Projects/MIDI Controller/Team Github/Notes/Software/Arduino]]

# Material list
	will be expanded further in detail
- PC workspace environment 
	- Software and Toolchains
	- File Management
	- Data Storage
- STM32 Nucleo board
- Teensy 4.1
- TIVA C Launchpad (borrowing)
- Arduino Mega and Nano
- CMOD S7 FPGA
- ICs
	- EEPROMS
	- Resistors
	- LEDs
	- LS74 chips
	- Buttons/Switches
- Digital Equipment
	- Soldering Iron/set
	- Portable Multimeter
	- Portable Oscilloscope
- Arduino Components
	- IR remote
	- Joystick
	- Accelerometer
	- etc.
- Raspberry PI 3 Model B
- Displays
	- 3 HiLetgo HD44680 1602 LCD display modules
	- DSD ST7735S LCD 160x120 
	- Raspberry Pi touch screen
	- Expected VGA/HDMI
- Misc.
	- Keyboard
	- Mouse
	- etc.


