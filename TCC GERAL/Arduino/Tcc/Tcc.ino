const int sensor = 2;       //Declaração do pino
const int liga = 3;         //Declaração do pino
const int desliga = 4;      //Declaração do pino
const int valvula = 6;      //Declaração do pino
const int pause = 7;        //Declaração do pino
const int buzzer = 8;       //Declaração do pino
int estado = 0;
int contaPulso = 0;
int contpulso = 0;
int cont = 0;
double vazao = 0;
double consumoL = 0;

void setup() {
  estado = 0;
  Serial.begin(9600);                   //Inicia a cominicação serial
  pinMode(sensor,INPUT);                //Declaração do modo do pino
  pinMode(liga,INPUT_PULLUP);                  //Declaração do modo do pino
  pinMode(desliga,INPUT_PULLUP);               //Declaração do modo do pino
  pinMode(valvula,OUTPUT);              //Declaração do modo do pino
  pinMode(pause,INPUT_PULLUP);                 //Declaração do modo do pino
  pinMode(buzzer,OUTPUT);               //Declaração do modo do pino
  attachInterrupt(0, incpulso, RISING); //configura o pino 2, interrupt zero para trabalhar com interrupção rising
}

void loop() {
  if(digitalRead(liga) == HIGH){     //Executa função on() se o liga for pressionado
    on();
    }

  if(digitalRead(pause) == HIGH){    //Executa função paus() se o pause for pressionado
    paus();
    }

  if(digitalRead(desliga) == HIGH){  //Executa função off() se o desliga for pressionado
    off();
    }  


  if(estado = 0){     //Zera variáveis quando "estado = 0"
    estado = 0;
    digitalWrite(valvula,LOW);
    contaPulso = 0;
    contpulso = 0;
    cont = 0;
    Serial.print("Desligado");
    
    } 

  if(estado = 1){
    digitalWrite(valvula,HIGH);   //Libera a água
    contaPulso = 0; //Zera a variável para contar os giros por segundos
    sei(); //Habilita interrupção
    delay (1000); //Aguarda 1 segundo
    cli(); //Desabilita interrupção
    cont= contpulso;
    vazao = contaPulso / 5.5;; //faz o calculo da vazão em L/m
    consumoL = (cont)/ 330; //Faz o cauculo do consumo em L
    Serial.println(consumoL);
    
    }

}
