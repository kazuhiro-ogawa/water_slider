/* インクルードガード */
#pragma once

/* pin管理 */
#define SERVO_PIN 4
#define ECHO 13 
#define TRIG 12
#define BTN_PIN 2

/* mode */
typedef enum{
  INIT,         // 初期状態
  COUNTDOWN,    // カウントダウン状態
  GATE,         // ゲート開閉状態
  WAIT,         // 待機状態
}MODE;

typedef enum{
  ENTRY,        // エントリー
  DO,           // ドゥー
  EXIT,         // イグジット
}ACTION_STATE;
