void setup() {
  pinMode(3, INPUT);
  Serial.begin(9600);

}

void loop() {


  if(digitalRead(3) ==HIGH){
    Serial.println("Ligado");
  }

 
}
