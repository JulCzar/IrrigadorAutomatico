#include <Servo.h>

//Quantidade de modulos cadastrados
const int n = 3;

Servo servos[n];
const int posTemp[n] = {A0, A1, A2};
const int posUmid[n] = {A3, A4, A5};

void setup() {
  //instância das leituras analógicas
  for (int i = 0; i < n; i++) {
    pinMode(posTemp[i], INPUT);
    pinMode(posUmid[i], INPUT);
    servos[i].attach(i+3);
  }
  
  //Saidas digitais (LEDS)
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  for (int i = 0; i < n; i++) {
    int sensorTemp = posTemp[i];
    int sensorUmid = posUmid[i];
    Servo torneira = servos[i];
    int LedStatus = i + 6;

    /*Leitura e Conversão do valor dos sensores de temperatura e
      umidade, para Celsius e Porcentagem, respectivamente.*/
    int temp = (-40 + 0.488155 * (analogRead(sensorTemp) - 20) + 1);
    int umid = map(analogRead(sensorUmid), 1023, 0, 0, 100);

    // Verificação da umidade e temperatura para atuação na torneira.
    if (umid <= 30) {
      torneira.write(225 + temp);
      digitalWrite(LedStatus, HIGH);
    } else if (umid <= 50) {
      torneira.write(145 + temp);
      digitalWrite(LedStatus, HIGH);
    } else if (umid <= 74) {
      torneira.write(90 + temp);
      digitalWrite(LedStatus, HIGH);
    } else {
      torneira.write(0);
      digitalWrite(LedStatus, LOW);
    }
  }

  delay(50); // Delay a little bit to improve simulation performance
}