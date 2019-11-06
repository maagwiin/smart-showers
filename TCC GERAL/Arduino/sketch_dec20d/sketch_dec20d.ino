const int liga = 3; //Define botão Liga
const int desliga = 4; //Define botão Desliga
const int block = 6; //Define o bloqueio da agua
int estadoLiga = digitalRead(liga); //Armazena botão na variável
int estadoDesliga = digitalRead(desliga); //Armazena botão na variável
int ligado = 0;
void setup() {
  pinMode(liga, INPUT); //Botoeira Liga
  pinMode(desliga, INPUT); //Botoeira Desliga
  pinMode(block, OUTPUT); //Saída Relé Valvula}
  digitalWrite(block, LOW);
  Serial.begin(9600);
}
void loop() {
  if(digitalRead(liga) == HIGH) { //botao liga pressionado
  ligaa();
  }
  if(ligado == 1){
    Serial.println("oi");
    digitalWrite(block,HIGH);          
  }
            }

void ligaa(){
  ligado++;
}

