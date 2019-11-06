const int sensor = 2;       //Declaração do pino
const int liga = 3;         //Declaração do pino
const int desliga = 4;      //Declaração do pino
const int valvula = 6;      //Declaração do pino
const int pause = 7;        //Declaração do pino
const int buzzer = 8;       //Declaração do pino

void setup() {
  pinMode(sensor,INPUT);    //Declaração do modo do pino
  pinMode(liga,INPUT);      //Declaração do modo do pino
  pinMode(desliga,INPUT);   //Declaração do modo do pino
  pinMode(valvula,OUTPUT);  //Declaração do modo do pino
  pinMode(pause,INPUT);     //Declaração do modo do pino
  pinMode(buzzer,OUTPUT);   //Declaração do modo do pino
}

void loop() {
  // put your main code here, to run repeatedly:

}
