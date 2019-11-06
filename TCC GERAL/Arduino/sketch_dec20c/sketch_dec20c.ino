const int ledPin = 7; // Pino ao qual o LED será conectado
int caractere = Serial.read();
void setup() {
Serial.begin(9600);
pinMode(ledPin, OUTPUT); // Pino 13 será de saída de sinais
}
void loop(){
  
 if (Serial.read(1) {
      digitalWrite(ledPin,LOW);
  }
   if (Serial.read(0)) {
    digitalWrite(ledPin,LOW);
  }

}
