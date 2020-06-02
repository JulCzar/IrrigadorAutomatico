#include <Servo.h>

int SensorHum_1 = 0;
int SensorHum_2 = 0;
int SensorHum_3 = 0;
int SensorTemp_1 = 0;
int SensorTemp_2 = 0;
int SensorTemp_3 = 0;

//Instância dos servo-motor;
Servo servo_3;
Servo servo_4;
Servo servo_5;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  
  //Instância dos servo-motor;
  servo_3.attach(3);
  servo_4.attach(4);
  servo_5.attach(5);
}

void loop()
{
  //Leitura dos sensores de humidade
  SensorHum_1 = analogRead(A3);
  SensorHum_2 = analogRead(A4);
  SensorHum_3 = analogRead(A5);
  //Leituras dos sensores de temperatura
  SensorTemp_1 = (-40 + 0.488155 * (analogRead(A2) - 20) + 1);
  SensorTemp_2 = (-40 + 0.488155 * (analogRead(A1) - 20) + 1);
  SensorTemp_3 = (-40 + 0.488155 * (analogRead(A0) - 20) + 1);

  //Modulo do primeiro sensor de umidade
  if (SensorHum_1 >= 800) {
    servo_3.write(240);
    digitalWrite(6, HIGH);
  } else if (SensorHum_1 >= 500) {
    servo_3.write(150);
    digitalWrite(6, HIGH);
  } else if (SensorHum_1 >= 300) {
    servo_3.write(90);
    digitalWrite(6, HIGH);
  } else {
    servo_3.write(0);
    digitalWrite(6, LOW);
  }

  //Segundo sensor de umidade
  if (SensorHum_2 >= 800) {
    servo_4.write(240);
    digitalWrite(7, HIGH);
  } else if (SensorHum_2 >= 500) {
    servo_4.write(90);
    digitalWrite(7, HIGH);
  } else if (SensorHum_2 >= 300) {
    servo_4.write(90);
    digitalWrite(7, HIGH);
  } else {
    servo_4.write(0);
    digitalWrite(7, LOW);
  }

  //terceiro sensor de umidade
  if (SensorHum_3 >= 800) {
    servo_5.write(240);
    digitalWrite(8, HIGH);
  } else if (SensorHum_3 >= 500) {
    servo_5.write(90);
    digitalWrite(8, HIGH);
  } else if (SensorHum_3 >= 300) {
    servo_5.write(90);
    digitalWrite(8, HIGH);
  } else {
    servo_5.write(0);
    digitalWrite(8, LOW);
  }

  delay(10); // Delay a little bit to improve simulation performance
}