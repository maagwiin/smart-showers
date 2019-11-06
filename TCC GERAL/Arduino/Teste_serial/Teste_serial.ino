//Programa : Modulo Bluetooth HC-06 - Leds
//Autor : Adilson Thomsen
 
//Armazena o caracter recebido
char buf;
 
void setup()
{
  //Define os pinos dos leds como saida
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}
 
void loop()
{
  while(Serial.available() > 0)
  {
    buf = Serial.read();
    //Caso seja recebido R, acende o led vermelho
    if (buf == 'L')
    {
      digitalWrite(3, HIGH);
      Serial.println("LAMPADA LIGADA");
    }
    //Caso seja recebido G, acende o led verde
    if (buf == 'B')
    {
      tone(4, 1500);
      Serial.println("BUZER LIGADO !");
      delay(1000);
      noTone(4);
      
    }

    if (buf == 'D'){
      digitalWrite(3,LOW);
      Serial.println("Lampada Desligada");
    }

    if (buf == 'C')
    {
      tone(4, 2000);
      Serial.println("BUZER LIGADO !");
      delay(1000);
      noTone(4);

  }

  if (buf == 'E')
    {
      tone(4, 3000);
      Serial.println("BUZER LIGADO !");
      delay(1000);
      noTone(4);
}

if (buf == 'F')
    {
      tone(4, 500);
      Serial.println("BUZER LIGADO !");
      delay(1000);
      noTone(4);
    }
  }
}
