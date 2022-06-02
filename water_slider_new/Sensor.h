/* インクルードガード */
#pragma once

class Sensor     // classの定義
{
  private :               // privateはクラス内からしかアクセスできない
    int echo;
    int trig;
    
  public :                // publicはどこからでもアクセス可能
    Sensor(int echo_pin, int trig_pin);   // コンストラクター
    float measure_distance();             // 距離測定関数
    bool check_passing();                 // 人通過チェック
    
};
