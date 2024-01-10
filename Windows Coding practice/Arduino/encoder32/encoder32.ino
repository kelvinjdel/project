/*     Arduino Rotary Encoder Tutorial
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
 
 #define A 5
 #define B 4
 #define sw 15

unsigned long _lastIncReadTime= micros();
unsigned long _lastDecReadTime= micros();
int _pauseLength =25000;
volatile int counter =0;

 void setup() { 
   pinMode (A,INPUT_PULLUP);
   pinMode (B,INPUT_PULLUP);
   pinMode (sw, INPUT_PULLDOWN);
   attachInterrupt(digitalPinToInterrupt(A), read_encoder, CHANGE); //IRS
   attachInterrupt(digitalPinToInterrupt(B), read_encoder, CHANGE);
   Serial.begin (9600);
   // Reads the initial state of the A
   Serial.println("initiating");
 } 

void loop() { 

  static int lastCounter=0;
  if (counter !=lastCounter)
  {
    Serial.println(counter);
    lastCounter= counter;
  }
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
}


