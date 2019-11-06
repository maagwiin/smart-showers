

void buzzerr() {
  digitalWrite(8,HIGH);
  delay (5000);
  digitalWrite(8,LOW);
  delay (5000);
  Serial.println("passou 1");
  ligado = 8;
  
}
