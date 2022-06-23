/* インクルードガード */
#pragma once

class Gate     // classの定義
{
  private :               // privateはクラス内からしかアクセスできない
    int m_servo_pin;      // サーボピンのメンバ変数
    
  public :                // publicはどこからでもアクセス可能
    Gate(int servo_pin);  // コンストラクター、サーボで使用するピンを受け取りメンバ変数に格納
    void opn();           // ゲートのオープン
    void cls();           // ゲートのクローズ
    void init();          // 初期化処理
};
