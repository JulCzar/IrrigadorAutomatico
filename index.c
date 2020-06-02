#include <Servo.h>

int SensorUmid_1 = 0;
int SensorUmid_2 = 0;
int SensorUmid_3 = 0;
int SensorTemp_1 = 0;
int SensorTemp_2 = 0;
int SensorTemp_3 = 0;

//Instância dos servo-motor;
Servo servo_3;
Servo servo_4;
Servo servo_5;

void setup() {
  //Leituras analógicas
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  //Saidas digitais
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  
  //Instância dos servo-motor;
  servo_3.attach(3);
  servo_4.attach(4);
  servo_5.attach(5);
}

void loop() {
  //Leituras dos sensores de temperatura
  SensorTemp_1 = (-40 + 0.488155 * (analogRead(A2) - 20) + 1);
  SensorTemp_2 = (-40 + 0.488155 * (analogRead(A1) - 20) + 1);
  SensorTemp_3 = (-40 + 0.488155 * (analogRead(A0) - 20) + 1);

  //Leitura dos sensores de humidade
  SensorUmid_1 = analogRead(A3);
  SensorUmid_2 = analogRead(A4);
  SensorUmid_3 = analogRead(A5);

  //Transforma a leitura do sensor de umidade em porcentagem
  SensorUmid_1 = map(SensorUmid_1, 1023, 0, 0, 100);
  SensorUmid_2 = map(SensorUmid_2, 1023, 0, 0, 100);
  SensorUmid_3 = map(SensorUmid_3, 1023, 0, 0, 100);

  //Modulo do primeiro sensor de umidade
  if (SensorUmid_1 <= 50) {
    servo_3.write(225 + SensorTemp_1);
  } else if (SensorUmid_1 <= 60) {
    servo_3.write(145 + SensorTemp_1);
  } else if (SensorUmid_1 <= 74) {
    servo_3.write(90 + SensorTemp_1);
    digitalWrite(6, HIGH);
  } else {
    servo_3.write(0);
    digitalWrite(6, LOW);
  }

  //Segundo sensor de umidade
  if (SensorUmid_2 <= 30) {
    servo_4.write(225 + SensorTemp_2);
  } else if (SensorUmid_2 <= 50) {
    servo_4.write(145 + SensorTemp_2);
  } else if (SensorUmid_2 <= 80) {
    servo_4.write(90 + SensorTemp_2);
    digitalWrite(7, HIGH);
  } else {
    servo_4.write(0);
    digitalWrite(7, LOW);
  }

  //terceiro sensor de umidade
  if (SensorUmid_3 <= 50) {
    servo_5.write(225 + SensorTemp_2);
  } else if (SensorUmid_3 <= 60) {
    servo_5.write(145 + SensorTemp_2);
  } else if (SensorUmid_3 <= 74) {
    servo_5.write(90 + SensorTemp_2);
    digitalWrite(8, HIGH);
  } else {
    servo_5.write(0);
    digitalWrite(8, LOW);
  }

  delay(10); // Delay a little bit to improve simulation performance
}