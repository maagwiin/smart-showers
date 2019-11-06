 const int liga = 3;
const int pause = 7;
const int desliga = 4;
const int block = 6;
int ligado = 0;
void setup() {
  Serial.begin(9600);
  pinMode(liga,INPUT_PULLUP);
  pinMode(desliga,INPUT_PULLUP);
  pinMode(pause,INPUT_PULLUP);
  pinMode(block,OUTPUT);

}

void on(){
  ligado = 1;
}

void off(){
  ligado = 0;
}

void paus(){
  ligado = 2;
}


void loop() {
  if(digitalRead(liga) == LOW){
    on();
  }

  if(digitalRead(desliga) == LOW){
    off();
  }

  if(digitalRead(pause) == LOW){
    paus();
  }


  if(ligado == 0){
    digitalWrite(block,LOW);
    Serial.println("Desligado");
  }
  if(ligado == 1){
    digitalWrite(block,HIGH);
    Serial.println("Ligado");
  }
  if(ligado == 2){
    digitalWrite(block,LOW);
    Serial.println("Pause");
  }


}











