/*****************************************************************//**
 * \file   InputManager.cpp
 * \brief  input管理クラス宣言
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#include "InputManager.h"
namespace
{
  /** XINPUT_STATE初期化関数 */
  const XINPUT_STATE InitializeXinput()
  {
    XINPUT_STATE input;
    for( int i = 0; i < 16; i++ )
    {
      input.Buttons[i] = 0;
    }
    input.LeftTrigger = 0;
    input.RightTrigger = 0;
    input.ThumbLX = 0;
    input.ThumbLY = 0;
    input.ThumbRX = 0;
    input.ThumbRY = 0;

    return input;
  };
  /** XINPUT_STATE同士のor */
  const XINPUT_STATE operator^(const XINPUT_STATE& left,const XINPUT_STATE& right)
  {
    XINPUT_STATE input = InitializeXinput();
    for( int i = 0; i < 16; i++ )
    {
      input.Buttons[i] = left.Buttons[i] ^ right.Buttons[i];
    }
    input.LeftTrigger = left.LeftTrigger ^ right.LeftTrigger;
    input.RightTrigger = left.RightTrigger ^ right.RightTrigger;
    input.ThumbLX = left.ThumbLX ^ right.ThumbLX;
    input.ThumbLY = left.ThumbLY ^ right.ThumbLY;
    input.ThumbRX = left.ThumbRX ^ right.ThumbRX;
    input.ThumbRY = left.ThumbRY ^ right.ThumbRY;
    return input;
  };
  /** XINPUT_STATE同士のand */
  const XINPUT_STATE operator&(const XINPUT_STATE& left,const XINPUT_STATE& right)
  {
    XINPUT_STATE input = InitializeXinput();
    for( int i = 0; i < 16; i++ )
    {
      input.Buttons[i] = left.Buttons[i] & right.Buttons[i];
    }
    input.LeftTrigger = left.LeftTrigger & right.LeftTrigger;
    input.ThumbLX = left.ThumbLX & right.ThumbLX;
    input.ThumbLY = left.ThumbLY & right.ThumbLY;
    input.ThumbRX = left.ThumbRX & right.ThumbRX;
    input.ThumbRY = left.ThumbRY & right.ThumbRY;
    return input;
  };
  /** XINPUT_STATE同士のnot */
  const XINPUT_STATE operator~(const XINPUT_STATE& right)
  {
    XINPUT_STATE input = InitializeXinput();
    for( int i = 0; i < 16; i++ )
    {
      input.Buttons[i] = ~right.Buttons[i];
    }
    input.LeftTrigger = ~right.LeftTrigger;
    input.RightTrigger = ~right.RightTrigger;
    input.ThumbLX = ~right.ThumbLX;
    input.ThumbLY = ~right.ThumbLY;
    input.ThumbRX = ~right.ThumbRX;
    input.ThumbRY = ~right.ThumbRY;
    return input;
  };
}

InputManager::InputManager()
{
  key_skip_count = 0;
  lefttrigger_skip_count = 0;
  righttrigger_skip_count = 0;
  is_click_on_key = false;
  is_click_on_r_trigger = false;
  is_click_on_l_trigger = false;
  _gxKey = InitializeXinput();
  _gxTrg = InitializeXinput();
  _gxRel = InitializeXinput();
}

InputManager::~InputManager()
{};

bool InputManager::Update()
{
  SetJoypadDeadZone(DX_INPUT_PAD1,0.50);
  auto xkeyold = _gxKey;
  GetJoypadXInputState(DX_INPUT_PAD1,&_gxKey);
  _gxTrg = (_gxKey ^ xkeyold) & _gxKey;
  _gxRel = (_gxKey ^ xkeyold) & ~_gxKey;

  return true;
};

const bool InputManager::GetKeyXinput(const int button)
{
  return _gxKey.Buttons[button] == true;
};

const bool InputManager::GetTrgXinput(const int button)
{
  return _gxTrg.Buttons[button] == true;
};

const bool InputManager::GetRelXinput(const int button)
{
  return _gxRel.Buttons[button] == true;
};

const unsigned char& InputManager::GetLeftTrigger()
{
  return _gxKey.LeftTrigger;
};

const unsigned char& InputManager::GetRightTrigger()
{
  return _gxKey.RightTrigger;
};

const short& InputManager::GetLstickX()
{
  return _gxKey.ThumbLX;
};

const short& InputManager::GetLstickY()
{
  return _gxKey.ThumbLY;
};

const short& InputManager::GetRstickX()
{
  return _gxKey.ThumbRX;
};

const short& InputManager::GetRstickY()
{
  return _gxKey.ThumbRY;
};

const bool& InputManager::XinputEveryOtherKey(const int button,const int frequency_frame)
{
  is_click_on_key = true;
  if( _gxKey.Buttons[button] >= 1 && (key_skip_count == 0) )
  {
    /** key_skip_countが0カウントの時の処理 */
    key_skip_count++;
    return is_click_on_key;
  }
  if( _gxKey.Buttons[button] >= 1 )
  {
    /** 押されていた時 */
    key_skip_count++;
    if( 0 == key_skip_count % frequency_frame )
    {
      /** key_skip_countがfrequency_frameで割り切れたときtrueにする */
      is_click_on_key = true;
    } else
    {
      is_click_on_key = false;
    }
  } else
  {
    /** それ以外はfalse */
    is_click_on_key = false;
    key_skip_count = 0;
  }
  return is_click_on_key;
};

const bool& InputManager::XinputEveryOtherRightTrigger(const int frequency_frame)
{
  is_click_on_r_trigger = true;
  if( _gxKey.RightTrigger >= 10 && (righttrigger_skip_count == 0) )
  {
    /** righttrigger_skip_countが0カウントの時の処理 */
    righttrigger_skip_count++;
    return is_click_on_r_trigger;
  }
  if( _gxKey.RightTrigger >= 10 )
  {
    /** 押されていた時 */
    righttrigger_skip_count++;
    if( 0 == righttrigger_skip_count % frequency_frame )
    {
      /** righttrigger_skip_countがfrequency_frameで割り切れたときtrueにする */
      is_click_on_r_trigger = true;
    } else
    {
      /** それ以外はfalse */
      is_click_on_r_trigger = false;
    }
  } else
  {
    /** 押されていないとき */
    is_click_on_r_trigger = false;
    righttrigger_skip_count = 0;
  }
  return is_click_on_r_trigger;
};

const bool& InputManager::XinputEveryOtherLeftTrigger(const int frequency_frame)
{
  is_click_on_l_trigger = true;
  if( _gxKey.LeftTrigger >= 10 && (lefttrigger_skip_count == 0) )
  {
    /** lefttrigger_skip_countが0カウントの時の処理 */
    lefttrigger_skip_count++;
    return is_click_on_l_trigger;
  }
  if( _gxKey.LeftTrigger >= 10 )
  {
    /** 押されていた時 */
    lefttrigger_skip_count++;
    if( 0 == lefttrigger_skip_count % frequency_frame )
    {
      /** lefttrigger_skip_countgaがfrequency_frameで割り切れたときtrueにする */
      is_click_on_l_trigger = true;
    } else
    {
      /** それ以外はfalse */
      is_click_on_l_trigger = false;
    }
  } else
  {
    /** 押されていないとき */
    is_click_on_l_trigger = false;
    lefttrigger_skip_count = 0;
  }
  return is_click_on_l_trigger;
};
