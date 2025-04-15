#include <SPI.h>
#include "IRremote.h"
#include "NumbersFB.h"
// значения для вывода цифр 0-9
byte numbers[10] = {
  B00000011,//0
  B10011111,//1
  B00100101,//2
  B00001101,//3
  B10011001,//4
  B01001001,//5
  B01000001,//6
  B00011111,//7
  B00000001,//8
  B00001001
};//9

// B12345678
// 1 - a
// 2 - b
// 3 - v
// 4 - d
// 5 - e
// 6 - f
// 7 - g
// 8 - dp

// схема восьмисегметного индикатора
//    a
//  f   b
//    g
//  e   c
//    d   gp
//




// восьмисегментные индикаторы
int digits[4] = {2, 3, 4, 5};
// пин SS (управляющий индикаторами восьмисегментнека)
int pin_ss = 8;
//принимающий порт А0 принимающий изменение вольтажа
int footballGoal = 14;
int btn = 19;
int buzzer = 6;
//переменная для хранения измененого вольтажа
int checkGoal;


unsigned char i,j;
void setup()
{
  Serial.begin(9600); // выставляем скорость COM порта
  pinMode(btn, INPUT);
  pinMode(footballGoal, INPUT);
  pinMode(buzzer, OUTPUT);


  SPI.begin();
  // Сконфигурировать контакты как выходы
  pinMode(pin_ss, OUTPUT);
  for (int i = 0; i < 4; i++)
  { pinMode(digits[i], OUTPUT);
    digitalWrite(digits[i], HIGH);
    digitalWrite(digits[i], LOW);
  }
}
void loop()
{

  if (analogRead(btn) > 500) {
    StartGame();
  }
  delay(1);
}




void StartGame() {
  for (int i = 0; i < 6; i++) {
    digitalWrite(pin_ss, LOW);

    digitalWrite(digits[0], HIGH);
    digitalWrite(digits[1], HIGH);
    digitalWrite(digits[2], HIGH);
    digitalWrite(digits[3], HIGH);

    SPI.transfer(B00000010);
    digitalWrite(pin_ss, HIGH);
    if (i<5){
      Buzzer(4,buzzer);
    }else{
      Buzzer(1,buzzer);  
    }

    delay(500);

    digitalWrite(digits[0], LOW);
    digitalWrite(digits[1], LOW);
    digitalWrite(digits[2], LOW);
    digitalWrite(digits[3], LOW);

    digitalWrite(buzzer, LOW);

    digitalWrite(pin_ss, LOW);
    delay(500);
  }
  digitalWrite(digits[0], HIGH);
  digitalWrite(digits[3], HIGH);
  SPI.transfer(numbers[1]);


  checkGoal = analogRead(footballGoal);
  if ( checkGoal < 50) { // если данные пришли
    Goal();
  }
}


void Goal() {
  digitalWrite(pin_ss, LOW);

}
//
//
//
//
//
//  for(int i = 0; i <10; i++){
//    digitalWrite(pin_ss, LOW);
//    SPI.transfer(numbers[i]);
//    delay(1000);
//    digitalWrite(pin_ss, HIGH);
//  }
//
//
//
//  Serial.println( check ); // печатаем данные
//
//
//}
