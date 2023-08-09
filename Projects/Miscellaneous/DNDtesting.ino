//www.elegoo.com
//2016.12.9
#include <LiquidCrystal.h>
#include "IRremote.hpp" //Library for IR remotes
#include <stdlib.h> //useful for stuff
#include <Arduino.h>
#include "init.h"
/*fix this later
enum MyEnum {
    CASE1,
    CASE2,
    CASE3
};

void func_case1(){   }
void func_case2(){   }
void func_case3(){   }

std::map<std::string, MyEnum> myMap;
myMap["case1"] = CASE1;
myMap["case2"] = CASE2;
myMap["case3"] = CASE3;

void (*functions[])() = {func_case1, func_case2, func_case3};
std::string input = "case1";
MyEnum value = myMap[input];

functions[value](); // calls the corresponding function.

//void setup////////////////*/
void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Player *head;
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode");
  IrReceiver.begin(receiver, ENABLE_LED_FEEDBACK);
  lcd.begin(16, 2);
  lcd.print("Roll Initiative");
  for (int i=0;i<3;i++)
  {
    players[i].armor=13;
    players[i].hp=12;
    players[i].initiative=3;
  }
}/*--(end setup )---*/



///////////void loop//////////////

void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  while(allPlayers(players)==false)
  {//we stay stuck in this loop until all players are ready
    if (IrReceiver.decode()) // have we received an IR signal?
    {
      Serial.println("UP->num->Player");
      translateIR();//first button press should be "UP"
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

                    //for the transition
                    //then the number, then the player
                    //so 9 button presses total
      //UP-> number -> PLAYER -> UP -> number -> PLAYER
      if(remote== "POWER")//sets when player is set
      {
        players[0].initiative=num;//num is already set
        players[0].ready =1; 
      }
      else if(remote=="FUNC/STOP")//UP to avoid putting num in 
                                  //player 2
      {
        players[1].initiative=num;//then we set the num
        players[1].ready=1;       //then player to receive func
      }
      else if(remote=="VOL+")     //etc
      {                           //eventually this will be
        players[2].initiative=num;//much simpler as we can just 
        players[2].ready=1;       //hash the values to eachother
      }
      IrReceiver.resume();      
      if(allPlayers(players)==true) 
      {
        bubblesort(players, 3);    //sort before the end
      }
    }
  }
  //end if all players havent finished rolling
  
  lcd.clear(); 
  lcd.print("Fight!!");
  lcd.setCursor(0,1);
  for(int i = 0; i < 3; i++) 
  {
    printPlayerInitiative(players, i);
    waitForEQ();
  }
  roundn++;
}
