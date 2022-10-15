#include <SoftwareSerial.h>

class Robo{
  int fA, tA, fB, tB;
  public:
    Robo(int pinFA, int pinTA, int pinFB, int pinTB){
      fA = pinFA;
      pinMode(fA, OUTPUT);
      tA = pinTA;
      pinMode(tA, OUTPUT);
      fB = pinFB;
      pinMode(fB, OUTPUT);
      tB = pinTB;
      pinMode(tB, OUTPUT);
    }
    void direita(){
      // Motor A
      digitalWrite(fA, LOW); 
      digitalWrite(tA, HIGH);
      // Motor B
      digitalWrite(fB, HIGH);
      digitalWrite(tB, LOW);
    }
    void esquerda(){
      // Motor A
      digitalWrite(fA, HIGH);
      digitalWrite(tA, LOW);
      // Motor B
      digitalWrite(fB, LOW);
      digitalWrite(tB, HIGH);
    }
    void frente(){
      // Motor A
      digitalWrite(fA, HIGH);
      digitalWrite(tA, LOW);
      // Motor B
      digitalWrite(fB, HIGH);
      digitalWrite(tB, LOW);
    }
    void tras(){
      // Motor A
      digitalWrite(fA, LOW);
      digitalWrite(tA, HIGH);
      // Motor B
      digitalWrite(fB, LOW);
      digitalWrite(tB, HIGH);
    }
    void parar(){
      // Motor A
      digitalWrite(fA, LOW);
      
      digitalWrite(tA, LOW);
      // Motor B
      digitalWrite(fB, LOW);
      digitalWrite(tB, LOW);
    }
    void esquiva(){
      // Motor A
      digitalWrite(fA, HIGH);
      digitalWrite(tA, LOW);
      // Motor B
      digitalWrite(fB, LOW);
      digitalWrite(tB, HIGH);
      delay(1000);
    }
};

char texto;
SoftwareSerial bluetooth(12, 13); // RX, TX  

Robo MrR(7,6,5,4);

void setup() {
  // Inicializa as comunicações
  bluetooth.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if(bluetooth.available()){
    texto = bluetooth.read();
    Serial.println(texto);
  }
  if(texto == 'F'){
    MrR.frente();
  }
  else if(texto == 'B'){
    MrR.tras();
  }
  else if(texto == 'L'){
    MrR.esquerda();
  }
  else if(texto == 'R'){
    MrR.direita();
  }
  else if(texto == 'G' or texto == 'H'){
    MrR.esquerda();
  }
  else if(texto == 'I' or texto == 'J'){
    MrR.direita();
  }
  else if(texto == 'X'){
    MrR.esquiva();
  }
  else {
    MrR.parar();
  }
}
