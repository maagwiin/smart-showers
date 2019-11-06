const int liga = 3;
const int desliga = 4;
const int pause = 7;
void setup() {
  pinMode(liga, INPUT); //Botoeira Liga
  pinMode(desliga, INPUT); //Botoeira Desliga
  pinMode(pause,INPUT);
  Serial.begin(9600);
}

void loop() {
   if(digitalRead(liga) == HIGH){
   Serial.print("Liga");
  }

  if(digitalRead(desliga) == HIGH){
    Serial.print("Desliga");
  }

  if(digitalRead(pause) == HIGH){
    Serial.println("Pause");
  }

}
