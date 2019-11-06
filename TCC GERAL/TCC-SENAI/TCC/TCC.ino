float vazao = 0; //Variável para armazenar o valor em L/min
float consumoL = 0; //Variável para tirar o consumo
int contaPulso; //Variável para a quantidade de pulsos
int incpulso = 0;
const int liga = 3; //Define botão Liga
const int desliga = 4; //Define botão Desliga
const int aviso = 5; //Define saida do aviso
const int block = 6; //Define o bloqueio da agua
int estadoLiga = 0;
int estadoDesliga = 0;
int ligado = 0;


void setup() {
  pinMode(liga, INPUT); //Botoeira Liga
  pinMode(desliga, INPUT); //Botoeira Desliga
  pinMode(aviso, OUTPUT); //Saída Buzzer
  pinMode(block, OUTPUT); //Saída Relé Valvula
  pinMode(2, INPUT); //Entrada do Sensor
  attachInterrupt(0, incpulso, RISING); //Configura o pino 2(Interrupção 0) para trabalhar como interrupção
}

void loop() {
  estadoLiga = digitalRead(liga);
  estadoDesliga = digitalRead(desliga);

  if (estadoLiga == HIGH) {
    ligado = ligado + 1;
  }

  if (estadoDesliga == HIGH) {
    ligado = 0;
  }

  if (ligado = 1) {
    digitalWrite(block, HIGH);

    contaPulso = 0; //Zera a variável para contar os giros por segundos
    sei(); //Habilita interrupção
    delay (1000); //Aguarda 1 segundo
    cli(); //Desabilita interrupção

    vazao = contaPulso / 10;
    consumoL = (vazao / 60) + consumoL;

  }
    
   if (ligado = 2){
      digitalWrite(block, LOW);
  }

  if (ligado = 3){
     ligado = ligado - 2;
     }

  if (consumoL >= 1) {
    digitalWrite(aviso, HIGH);
    delay (1000);
    digitalWrite(aviso, LOW);
    delay (10000);
    digitalWrite(block, LOW);
  }
void incpulso ()
{
contaPulso++; //Incrementa a variável de pulsos
}
