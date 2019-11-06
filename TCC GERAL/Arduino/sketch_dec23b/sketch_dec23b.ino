const int sensor = 2;
const int liga = 3;
const int desliga = 4;
const int aviso = 5;
const int block = 6;
const int pause = 7;
int ligado = 0;
int contaPulso = 0;
int buz = 0;
double vazao = 0; //Variável para armazenar o valor em L/min
double consumoL = 0; //Variável para armazenar o valor em L
int contpulso = 0;

void incpulso(){ //comando do attach
contaPulso++; //Incrementa a variável de pulsos
contpulso++;
}

void setup() {
  Serial.begin(9600);
  pinMode(liga, INPUT); //Botoeira Liga
  pinMode(desliga, INPUT); //Botoeira Desliga
  pinMode(pause,INPUT);
  pinMode(aviso, OUTPUT); //Saída Buzzer
  pinMode(block, OUTPUT); //Saída Relé Valvula
  pinMode(sensor, INPUT); //Entrada do Sensor
  attachInterrupt(0, incpulso, RISING); //Configura o pino 2(Interrupção 0) para trabalhar como interrupção
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

void avis(){
  ligado = 3;
}

void deslig(){
  ligado = 4;
}

void offf(){
  ligado = 5;
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
      digitalWrite(block,LOW);
      int contaPulso = 0;
      int contpulso = 0;
      double vazao = 0; //Variável para armazenar o valor em L/min
      double consumoL = 0; //Variável para armazenar o valor em L
   
  }
  
  if(ligado == 1){
    digitalWrite(block,HIGH);
    contaPulso = 0; //Zera a variável para contar os giros por segundos
    sei(); //Habilita interrupção
    delay (1000); //Aguarda 1 segundo
    cli(); //Desabilita interrupção

    vazao = contaPulso / 5.5;; //faz o calculo da vazão em L/m
    consumoL = contpulso / 330; //Faz o cauculo do consumo em L
    Serial.println(consumoL);

  }
  if(ligado == 2){
    digitalWrite(block,LOW);
   
   
  }

  if (consumoL > 3) { //consumo atinge 1 Litro
    buz=1;
  }

  if(buz == 1){ 
    avis();
    }
  
  if(ligado == 3){
    digitalWrite(aviso,HIGH); //Buzzer acionando
    delay (2000);//Buzzer acionado (1 segundo de zoeira irritante)
    digitalWrite(aviso,LOW); //buzzer desacionando
    
    deslig();
    
  }

  if(ligado == 4){
    delay (5000); //5 segundos pro lerdo terminar de enxaguar
    offf();
  }

  if(ligado == 5){
      digitalWrite(block,LOW);
      int contaPulso = 0;
      int contpulso = 0;
      double vazao = 0; //Variável para armazenar o valor em L/min
      
   
  }

  
  }






