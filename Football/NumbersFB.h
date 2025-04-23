void BuzzerF(int ms, int cycle, int buzzer) {
  for (int i = 0; i < cycle; i++)
  {
    digitalWrite(buzzer, HIGH); // зуммер издает звук, за счет HIGH
    delay(ms);// задержка
    digitalWrite(buzzer, LOW); // зуммер не издает звук, за счет LOW
    delay(ms);// задержка
  }
}
