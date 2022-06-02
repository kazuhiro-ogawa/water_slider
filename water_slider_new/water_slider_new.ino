#include <MsTimer2.h>

#include "water_slider.h"
#include "Lcd.h"
#include "Gate.h"
#include "Button.h"
#include "Sensor.h"

/* 表示文字列 */
String countdown_print[7] =
{
  "GO!",
  "1",
  "2",
  "3",
  "4",
  "5",
  "WAIT"
};

/* 各クラスをインスタンス化 */
Lcd lcd;
Gate gate = Gate(SERVO_PIN);
Sensor sensor = Sensor(ECHO, TRIG);
Button button = Button(BTN_PIN, D_READ, NULL);

MODE g_mode = INIT;
ACTION_STATE action = ENTRY;
volatile int g_count = 6;

void change_mode(MODE mode){
  g_mode = mode;
}

void cdTimer(){
  g_count--;
}

void setup() {
  //インスタンスがクラスの関数を使うには インスタンス名.クラスの関数名() 
  lcd.init();
  gate.init();
  lcd.lcd_print(countdown_print[g_count]);
  MsTimer2::set(1000, cdTimer);
  Serial.begin(9600);
}

void loop(){
  
    switch(g_mode){
      
      case INIT:
        switch(action){
          case ENTRY:
            action = DO;
            break;
          case DO :
            if(!button.Read()){
              action = EXIT;
            }
            break;
          case EXIT:
            change_mode(COUNTDOWN);
            action = ENTRY;
            break;
        }
        break;
  
      case COUNTDOWN :
        switch(action){
          case ENTRY:
            MsTimer2::start();
            action = DO;
            break;
          case DO:
            lcd.lcd_print(countdown_print[g_count]);
            if(g_count < 0){
              MsTimer2::stop();     
              action = EXIT;
            }
            break;
          case EXIT:
            change_mode(GATE);
            action = ENTRY;
            g_count = 6;
            break;
        }
        break;

      case GATE :
        switch(action){
          case ENTRY:
            gate.gate_opn();
            action = DO;
            break;
          case DO:
            delay(3000);
            action = EXIT;
            break;
          case EXIT:
            gate.gate_cls();
            change_mode(WAIT);
            action = ENTRY;
            break;
        }
        break;

      case WAIT :
        switch(action){
          case ENTRY:
            lcd.lcd_print(countdown_print[g_count]);
            action = DO;
            break;
          case DO :
            if(sensor.check_passing() || !button.Read()){
              action = EXIT;
            }
            break;
          case EXIT:
            change_mode(COUNTDOWN);
            action = ENTRY;
            break;
        }
        break; 
    }
    Serial.print("g_mode = ");
    Serial.println(g_mode);
    Serial.print("action = ");
    Serial.println(action);
}
