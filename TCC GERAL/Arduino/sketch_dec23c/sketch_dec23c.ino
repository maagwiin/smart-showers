void setup() {
  // put your setup code here, to run once:

}

void loop() {
  tone(5,1500); //Buzzer acionando
    delay (1000); //Buzzer acionado (1 segundo de zoeira irritante)
    noTone(5); //buzzer desacionando
    delay(1000);
}
