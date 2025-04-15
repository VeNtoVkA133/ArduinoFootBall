void Buzzer(int ms, int buzzer) {
  for (int i = 0; i < 100; i++)
  {
    digitalWrite(buzzer, HIGH); // зуммер издает звук, за счет HIGH
    delay(ms);// задержка
    digitalWrite(buzzer, LOW); // зуммер не издает звук, за счет LOW
    delay(ms);// задержка
  }
}
