#include <Arduino.h>

//Board 1
const int AIN1 = 13;
const int AIN2 = 12;
const int PWM1 = 11;

const int BIN1 = 8;
const int BIN2 = 9;
const int PWM2 = 10;

//Board 2
const int AIN1_B = 2;
const int AIN2_B = 1;
const int PWM3 = 3;

const int BIN1_B = 4;
const int BIN2_B = 5;
const int PWM4 = 6;

const int STBY = 7;

int value;

void setup() {
  // put your setup code here, to run once:
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWM1, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWM2, OUTPUT);

  pinMode(AIN1_B, OUTPUT);
  pinMode(AIN2_B, OUTPUT);
  pinMode(PWM3, OUTPUT);

  pinMode(BIN1_B, OUTPUT);
  pinMode(BIN2_B, OUTPUT);
  pinMode(PWM4, OUTPUT);

  digitalWrite(STBY, HIGH);
}

void forward() {
  

  for(value = 60; value < 150; value = value + 1) {
    //***** Board 1 *****
    //Motor 1 - Front Driver's Side
    analogWrite(PWM1, value);
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);

    //Motor 2 - Front Passenger Side
    analogWrite(PWM2, value);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);

    //****** Board 2 *****
    //Motor 3 - Rear Driver's Side
    analogWrite(PWM3, value);
    digitalWrite(AIN1_B, HIGH);
    digitalWrite(AIN2_B, LOW);

    //Motor 4 - Rear Passenger Side
    analogWrite(PWM4, value);
    digitalWrite(BIN1_B, LOW);
    digitalWrite(BIN2_B, HIGH);
    
    delay(20);
  }
}

void tank_turn() {
  for(value = 60; value < 120; value = value + 1) {
    //***** Board 1 *****
    //Motor 1 - Front Driver's Side
    analogWrite(PWM1, value);
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);

    //Motor 2 - Front Passenger Side
    analogWrite(PWM2, value);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);

    //****** Board 2 *****
    //Motor 3 - Rear Driver's Side
    analogWrite(PWM3, value);
    digitalWrite(AIN1_B, HIGH);
    digitalWrite(AIN2_B, LOW);

    //Motor 4 - Rear Passenger Side
    analogWrite(PWM4, value);
    digitalWrite(BIN1_B, HIGH);
    digitalWrite(BIN2_B, LOW);
    
    delay(20);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  forward();
  tank_turn();
}

//TRUTH TABLE
//AIN1|0  |0   |1
//AIN2|0  |1   |0
//   STOP |REV |FWD
