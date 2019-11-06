boolean botao = 8;   // define pino 8 vinculado a uma variavel
                                 // booleana
                  
 boolean led = 13;   // define o pino 13 vinculado a uma variável
                              // booleana
                  

 void setup() {

  pinMode ( botao , INPUT_PULLUP);   // define que o pino botão
                                                          // será uma entra digital com
                                                          // pull up interno a tivado.
  pinMode ( led , OUTPUT);                  // define como saida digital   
}

 void loop() {

     /// por o pull Up manter a etrada sempre em nível alto, deve-se usar
     /// uma lógica inversa, ou seja, o botão ligado a entrada digital deve
     ///chavear o GND

   if ( digitalRead (botao) == 0 ){     // se a entrada botão for igual a 0
     digitalWrite (led, HIGH);            // acende o led do pino 13
     delay (1000);                            // por 1 segundo
    }
    else {                                        // se não
    digitalWrite (led, LOW);             // led apagado.
    }
  

  }
