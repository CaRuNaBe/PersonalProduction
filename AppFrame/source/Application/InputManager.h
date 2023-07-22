/*****************************************************************//**
 * \file   InputManager.h
 * \brief  input管理クラス定義
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#pragma once
#include <DxLib.h>

class InputManager
{
public:
  /** コンストラクタ */
  InputManager();
  /** デストラクタ */
  ~InputManager();
  /** 更新 */
  bool Update();
  /** 連続入力 */
  const bool GetKeyXinput(const int button);
  /** 押したときだけ反応 */
  const bool GetTrgXinput(const int button);
  /** 離したとき反応 */
  const bool GetRelXinput(const int button);
  /** 左トリガーの入力状態を取得 */
  const unsigned char& GetLeftTrigger();
  /** 右トリガーの入力状態を取得 */
  const unsigned char& GetRightTrigger();
  /** 左スティックのx軸の入力状態を取得 */
  const short& GetLstickX();
  /** 左スティックのy軸の入力状態を取得 */
  const short& GetLstickY();
  /** 右スティックのx軸の入力状態を取得 */
  const short& GetRstickX();
  /** 右スティックのy軸の入力状態を取得 */
  const short& GetRstickY();
  /** ボタンの隔フレーム入力を取得 */
  const bool& XinputEveryOtherKey(int button,const int frequency_frame);
  /** 右トリガーの隔フレーム入力を取得 */
  const bool& XinputEveryOtherLeftTrigger(const int frequency_frame);
  /** 左トリガーの隔フレーム入力を取得 */
  const bool& XinputEveryOtherRightTrigger(const int frequency_frame);
private:
  /** xinputコントローラー情報 */
  /** 連続入力の格納する構造体 */
  DxLib::XINPUT_STATE gx_key;
  /** 押したときだけ反応するものを格納する構造体 */
  DxLib::XINPUT_STATE gx_trg;
  /** 離したとき反応反応するものを格納する構造体 */
  DxLib::XINPUT_STATE gx_rel;
  /** 何かを押したときカウントされていく変数 */
  int key_skip_count;
  /** 左トリガーが押されていたらカウントされていく変数 */
  int lefttrigger_skip_count;
  /** 右トリガーが押されていたらカウントされていく変数 */
  int righttrigger_skip_count;
  /** ボタンの隔フレーム入力用の真偽変数trueの時押されてる */
  bool is_click_on_key;
  /** 右トリガーの隔フレーム入力用の真偽変数trueの時押されてる */
  bool is_click_on_r_trigger;
  /** 左トリガーの隔フレーム入力用の真偽変数trueの時押されてる */
  bool is_click_on_l_trigger;
};

/** xinputのボタン入力再定義 */
struct XinputButton
{
  static const int DPAD_UP = XINPUT_BUTTON_DPAD_UP;// デジタル方向ボタン上
  static const int DPAD_DOWN = XINPUT_BUTTON_DPAD_DOWN;// デジタル方向ボタン下
  static const int DPAD_LEFT = XINPUT_BUTTON_DPAD_LEFT;// デジタル方向ボタン左
  static const int DPAD_RIGHT = XINPUT_BUTTON_DPAD_RIGHT;// デジタル方向ボタン右
  static const int START = XINPUT_BUTTON_START;// STARTボタン
  static const int BACK = XINPUT_BUTTON_BACK;// BACKボタン
  static const int LEFT_THUMB = XINPUT_BUTTON_LEFT_THUMB;// 左スティック押し込み
  static const int RIGHT_THUMB = XINPUT_BUTTON_RIGHT_THUMB;// 右スティック押し込み
  static const int LEFT_SHOULDER = XINPUT_BUTTON_LEFT_SHOULDER;// LBボタン
  static const int RIGHT_SHOULDER = XINPUT_BUTTON_RIGHT_SHOULDER;// RBボタン
  static const int A = XINPUT_BUTTON_A;// Aボタン
  static const int B = XINPUT_BUTTON_B;// Bボタン
  static const int X = XINPUT_BUTTON_X;// Xボタン
  static const int Y = XINPUT_BUTTON_Y;// Yボタン
};