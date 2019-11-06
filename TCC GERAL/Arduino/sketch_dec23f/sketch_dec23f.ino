void setup() {
  pinMode(8,OUTPUT);
  Serial.begin(9600);
}

void loop() {
digitalWrite(8,HIGH);
  delay (5000);
  digitalWrite(8,LOW);
  delay (5000);
  Serial.println("passou 1");
