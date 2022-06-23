#include <Servo.h>
#include <Arduino.h>
#include "water_slider.h"
#include "Gate.h"

Servo servo; //Servoクラスから インスタンスservoを生成

Gate::Gate(int servo_pin){
  m_servo_pin = servo_pin;
}

void Gate::init(){
  servo.attach(m_servo_pin);  //サーボモータで使用するピンを設定
  servo.write(0);           //サーボモータの角度を0度に設定
}

void Gate::cls(){
  servo.write(0);          //サーボモータの角度を0度に設定
}

void Gate::opn(){
  servo.write(90);          //サーボモータの角度を90度に設定
}
