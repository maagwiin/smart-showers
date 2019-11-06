/* Trabalho referente à conclusão de curso pelo SENAI, pelo Projeto Inovação
 */
 
// declaração das variáveis
const int sens = 2; // sensor de fluxo d'água 
const int liga = 3; // botoeira para ativar o sistema
const int desl = 4; // botoeira para desligar o sistema
const int paus = 5; // botoeira para pausar o sistema
const int buzz = 6; // sinalizador sonoro
const int valv = 7; // válvula 

int estad = 0;
int contaPulso = 0; // variável para contagem dos pulsos emitidos pelo sensor de vazão
int contPulso = 0; 
double cont = 0;
float vaza = 0; //
double cons = 0; //


void setup() {
  estad = 0;
  Serial.begin(9600);
  pinMode(sens, INPUT);
  pinMode(liga, INPUT_PULLUP);
  pinMode(desl, INPUT_PULLUP);
  pinMode(paus, INPUT_PULLUP);
  pinMode(buzz, OUTPUT);
  pinMode(valv, OUTPUT);
  
}

void loop() {
  if(digitalRead(liga) == LOW){
    estad = 1;
    
  }
  if(digitalRead(desl) == LOW){
    estad = 0;

  } 
  if(digitalRead(paus) == LOW){
    estad = 2;
    
  }
/*---------------------------------------------------------------------------------------------------    */

  if(estad == 0){
    pinMode(sens, INPUT);
    Serial.println("DESLIGADO");
    digitalWrite(valv, LOW);
    contaPulso = 0;
    vaza = 0;
    cons = 0;
    contPulso = 0;
    cont = 0;
    
  }

  if(estad == 1) {
    Serial.println(cons);
    attachInterrupt(0, pulso, RISING);
    digitalWrite(valv, HIGH);
    contaPulso = 0; //Zera a variável para contar os giros por segundos
    sei(); //Habilita interrupção
    delay (1000); //Aguarda 1 segundo
    cli(); //Desabilita interrupção


    cont = contPulso;
    vaza = contaPulso / 5.5;; //faz o calculo da vazão em L/m
    cons = (cont)/ 330; //Faz o cauculo do consumo em L
  }

   if(estad == 2){ 
    Serial.println("PAUSE");
    digitalWrite(valv, LOW); 
   }

   if(cons >= 2){ 
    estad = 3;
   }

   if(estad == 3){
    cons = 0;
    pinMode(sens, OUTPUT);
    contaPulso = 0;
    vaza = 0;
    contPulso = 0;
    cont = 0;
    digitalWrite(buzz, HIGH);
    delay(100000);
    estad = 4;    
   }

   if(estad == 4){
    digitalWrite(buzz, LOW);
    delay(1000000);
    estad = 0;
   }
   
}

void pulso(){

    contaPulso++; 
    contPulso++;
}


