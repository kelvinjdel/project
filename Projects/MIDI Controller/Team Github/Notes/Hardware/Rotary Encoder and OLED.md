![[Pasted image 20230911094900.png]]
![[Pasted image 20230911094914.jpg]]
![[Pasted image 20230911095441.jpg]]

| ESP32 | Rotary Encoder                  | OLED |
| ----- | ------------------------------- | ---- |
| 2     | A        (grey wire)(pull up)              |      |
| 4     | B        (purple wire)(pull up) |      |
| 15    | SW      (white wire)(pull down) |      |
| 21    |                                 | SDA (red wire) |
| 22    |                                 | SCLK (orange wire)|
| 3.3V  |                                 |      |
| GND      |                                 |      |

testing code with some issues
A. trouble connecting to COM port
B. counter states not showing

A. fixed through updating, not having serial monitor open together, and potential cable issues 
B. debugging with multimeter

Sw high at 3.3V,
A is low
B is high
Pin 2 only .7V output, switched to pin 5

encoder works when switched to pin 5