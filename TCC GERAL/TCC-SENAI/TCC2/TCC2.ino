float vazao = 0; //Variável para armazenar o valor em L/min
float consumoL = 0; //Variável para armazenar o valor em L
int contaPulso; //Variável para a quantidade de pulsos
const int liga = 3; //Define botão Liga
const int desliga = 4; //Define botão Desliga
const int aviso = 5; //Define saida do aviso
const int block = 6; //Define o bloqueio da agua
int estadoLiga = 0; //Zera as variáveis
int estadoDesliga = 0; //Zera as variáveis
int ligado = 0; //Zera as variáveis


void setup() {
  pinMode(liga, INPUT); //Botoeira Liga
  pinMode(desliga, INPUT); //Botoeira Desliga
  pinMode(aviso, OUTPUT); //Saída Buzzer
  pinMode(block, OUTPUT); //Saída Relé Valvula
  pinMode(2, INPUT); //Entrada do Sensor
  attachInterrupt(0, incpulso, RISING); //Configura o pino 2(Interrupção 0) para trabalhar como interrupção
}

void loop() {
  estadoLiga = digitalRead(liga); //Armazena botão na variável
  estadoDesliga = digitalRead(desliga); //Armazena botão na variável

  if (estadoLiga == HIGH) { //botao liga pressionado
    ligado = ligado + 1; //incrementa o valor 1 na variavel ligado
  }

  if (estadoDesliga == HIGH) { //botao desliga pressionado
    ligado = 0; //zera a variável ligado
  }

  if (ligado = 1) { //se o valor de ligado for 1 inicia o sistema
    digitalWrite(block, HIGH); //desbloqueia a valvula

    contaPulso = 0; //Zera a variável para contar os giros por segundos
    sei(); //Habilita interrupção
    delay (1000); //Aguarda 1 segundo
    cli(); //Desabilita interrupção

    vazao = contaPulso / 10; //faz o calculo da vazão em L/m
    consumoL = (vazao / 60) + consumoL; //Faz o cauculo do consumo em L

  }
    
   if (ligado = 2){ //com o botão liga pressionado novamente, "ligado" vai para 2(ESTADO DE PAUSA)
      digitalWrite(block, LOW); //Bloqueia valvula
  }

  if (ligado = 3){ //com o botão liga pressionado novamente, "ligado" vai para 3(ESTADO DE "DESPAUSE" ahuhsaushua)
     ligado = ligado - 2; //Ligado volta pro valor 1
     }

  if (consumoL >= 1) { //consumo atinge 1 Litro
    digitalWrite(aviso, HIGH); //Buzzer acionando
    delay (1000); //Buzzer acionado (1 segundo de zoeira irritante)
    digitalWrite(aviso, LOW); //buzzer desacionando
    delay (10000); //10 segundos pro lerdo terminar de enxaguar
    digitalWrite(block, LOW); //bloqueio da valvula JÁ ERA DOIDÃO, SE FUDEU
  }
}
void incpulso(){ //comando do attach
contaPulso++; //Incrementa a variável de pulsos
}
