#include <Arduino.h>
#include "water_slider.h"
#include "Sensor.h"

Sensor::Sensor(int echo_pin, int trig_pin){
  echo = echo_pin;
  trig = trig_pin;
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
}

float Sensor::measure_distance(){
  float t; //ｔはμ秒単位
  float distance = 0;
  
  /*超音波の発生*/
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);

  /*返ってくるまでの時間測定*/
  t = pulseIn(ECHO,HIGH); //ECHOピンのパルスがHIGHになった時間を変数tに格納
  if(t >= 0){
    distance = (float)t * 340*(0.000001)*0.5*100;//m→cmなので100倍する
  }

  return distance;
}

bool Sensor::check_passing(){
  float distance;
  distance = measure_distance();
  if( 0 < distance && distance < 10){
    return true;
  }
  return false;
}
