void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(8,OUTPUT);

}

void loop() {
  digitalWrite(8,HIGH);
  delay (5000);
  digitalWrite(8,LOW);
  delay (5000);
  Serial.println("passou 1");

}
