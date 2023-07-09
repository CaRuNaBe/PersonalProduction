/*****************************************************************//**
 * \file   InputManager.h
 * \brief  input管理クラス定義
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#pragma once
#include <DxLib.h>
struct tagXINPUT_STATE;
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
  XINPUT_STATE gx_key;
  /** 押したときだけ反応するものを格納する構造体 */
  XINPUT_STATE gx_trg;
  /** 離したとき反応反応するものを格納する構造体 */
  XINPUT_STATE gx_rel;
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
