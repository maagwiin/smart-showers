const int liga = 3;
const int desliga = 4;
const int pause = 7;
int ligado = 0;
void setup() {
  pinMode(liga, INPUT); //Botoeira Liga
  pinMode(desliga, INPUT); //Botoeira Desliga
  pinMode(pause,INPUT);
  Serial.begin(9600);
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
  if(digitalRead(liga) == HIGH){
    on();
  }

  if(digitalRead(desliga) == HIGH){
    off();
  }

  if(digitalRead(pause) == HIGH){
    paus();
  }

 if(ligado == 0){
    
    Serial.println("Desligado");
 
  }

  if(ligado == 1){
    
    Serial.println("Ligado");
  
}

 if(ligado == 2){
    Serial.println("Pause");
   
  }

}



