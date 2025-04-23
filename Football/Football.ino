#define CLK 2
#define DIO 3
#include "IRremote.h" 
#include "GyverTM1637.h"
#include "NumbersFB.h"


GyverTM1637 disp(CLK, DIO);

bool startGame = false;
uint32_t Now, clocktimer;
const int btn = A5;
const int buzzer = 13;
const int goal = A0;
uint8_t results[11] = {_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, false};

int a = 0;
int b = 10;
int c = 10;
int d = 0;

bool wait = false;



void setup() {

  pinMode(btn, INPUT);
  pinMode(buzzer, OUTPUT);
  
  
  Serial.begin(9600);

  disp.clear();
  disp.brightness(7);  // яркость, 0 - 7 (минимум - максимум)
}


void loop() {
  if (startGame == false){
    int checkClick = analogRead(btn);
    if(checkClick>500){
      for (int i = 0; i < 3; i++){
        if(i <2){
          BuzzerF(3, 50, buzzer);
          delay(500);
        }else{
          BuzzerF(1, 150, buzzer);
          delay(500);
        }
      }
      startGame = true;  
    }
  }else{
    if(wait == true){
      int checkGoal = analogRead(goal);
      if(checkGoal < 500){
        BuzzerF(1, 200, buzzer);
        Goal();

      }
    }else{
      delay(100);
      disp.clear();
      disp.displayByte(results[a], results[b], results[c], results[d]);
      disp.point(true);
      wait = true;
    }
  }
}


void Goal(){
  if (a < 9 && b == 10){
    a = a + 1;
  }else if(a == 9 && b == 10){
    a = 1;
    b = 0;
  }else if(a < 10 && b < 9){
    b = b + 1;
  }else if(a < 10 && b == 9){
    a = a + 1;
    b = 0;
  }else if(a == 10 && b == 10){
    a = 0;
    b = 10;
  }
  wait = false;
  return;
}
