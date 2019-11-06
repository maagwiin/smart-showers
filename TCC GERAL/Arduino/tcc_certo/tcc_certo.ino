const int sensor = 2;       //Declaração do pino
const int liga = 3;         //Declaração do pino
const int desliga = 4;      //Declaração do pino
const int valvula = 6;      //Declaração do pino
const int pause = 7;        //Declaração do pino
const int buz = 5;
int estado = 0;
int contaPulso;
int contpulso;
float vazao;
double consumoL;
double cont;
long lastTime = 0; 
long priDelay = 1000;



void on() {
 estado = 1;
}

void paus() {
 estado = 2;
}

void off() {
 estado = 0;
}





void setup() {
  estado = 0;
  Serial.begin(9600);                   //Inicia a cominicação serial
  pinMode(liga,INPUT_PULLUP);                  //Declaração do modo do pino
  pinMode(desliga,INPUT_PULLUP);               //Declaração do modo do pino
  pinMode(valvula,OUTPUT);              //Declaração do modo do pino
  pinMode(pause,INPUT_PULLUP);                 //Declaração do modo do pino
  pinMode(buz,OUTPUT);
  pinMode(sensor,INPUT);                //Declaração do modo do pino
  
}

void loop() {
  if(digitalRead(liga) == LOW){     //Executa função on() se o liga for pressionado
    on();
    }

  if(digitalRead(pause) == LOW){    //Executa função paus() se o pause for pressionado
    paus();
    }

  if(digitalRead(desliga) == LOW){  //Executa função off() se o desliga for pressionado
    off();
    }  

/*-------------------------------------------------------------------------------------------*/

   if(estado == 0){     //Zera variáveis quando "estado = 0"
    estado = 0;
    digitalWrite(valvula,LOW);
    contaPulso = 0;
    contpulso = 0;
    cont = 0;
    Serial.println("Desligado");
    consumoL = 0;
    estado = 0;
    lastTime = 0;
    
   }
   
    if(estado == 1){
    attachInterrupt(0, incpuls, RISING); //configura o pino 2, interrupt zero para trabalhar com interrupção rising
    digitalWrite(valvula,HIGH);   //Libera a água
    Serial.println(consumoL);
    
    contaPulso = 0; //Zera a variável para contar os giros por segundos
    sei(); //Habilita interrupção
    delay (1000); //Aguarda 1 segundo
    cli(); //Desabilita interrupção
    
    cont= contpulso;
    vazao = contaPulso / 5.5;; //faz o calculo da vazão em L/m
    consumoL = (cont)/ 330; //Faz o cauculo do consumo em L
    lastTime = 0;
    }

    if(estado == 2){
      digitalWrite(valvula,LOW);
      Serial.println("Pausado");
      contaPulso = 0;
      }

   

/*-----------------------------------------------------------------------------------------------------------------*/

   if(consumoL >= 2){
    contaPulso = 0;
    contpulso = 0;
    cont = 0;
    estado = 3;
   
    
   }

   if(estado == 3){
      consumoL = 0;
      digitalWrite(buz, HIGH);
      lastTime = millis();
      estado = 4;
    
   }

   while (estado == 4){
    Serial.println(millis() - lastTime);
    if((millis() - lastTime) > priDelay){
      Serial.println("lastTime");
      estado = 5;
            }
   }

   if(estado == 5){
    digitalWrite(buz, LOW);
   }
}

void incpuls(){
  contaPulso++; //Incrementa a variável de contagem dos pulsos
  contpulso++;

}

