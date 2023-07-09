/*****************************************************************//**
 * \file   InputManager.cpp
 * \brief  input�Ǘ��N���X�錾
 * \author ���������Y
 * \date   June 2023
 *********************************************************************/
#include "InputManager.h"
#include <DxLib.h>
namespace
{
  /** XINPUT_STATE�������֐� */
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
  /** XINPUT_STATE���m��or */
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
  /** XINPUT_STATE���m��and */
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
  /** XINPUT_STATE���m��not */
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
  gx_key = InitializeXinput();
  gx_trg = InitializeXinput();
  gx_rel = InitializeXinput();
}

InputManager::~InputManager()
{};

bool InputManager::Update()
{
  SetJoypadDeadZone(DX_INPUT_PAD1,0.50);
  auto xkeyold = gx_key;
  GetJoypadXInputState(DX_INPUT_PAD1,&gx_key);
  gx_trg = (gx_key ^ xkeyold) & gx_key;
  gx_rel = (gx_key ^ xkeyold) & ~gx_key;

  return true;
};

const bool InputManager::GetKeyXinput(const int button)
{
  return gx_key.Buttons[button] == TRUE;
};

const bool InputManager::GetTrgXinput(const int button)
{
  return gx_trg.Buttons[button] == TRUE;
};

const bool InputManager::GetRelXinput(const int button)
{
  return gx_rel.Buttons[button] == TRUE;
};

const unsigned char& InputManager::GetLeftTrigger()
{
  return gx_key.LeftTrigger;
};

const unsigned char& InputManager::GetRightTrigger()
{
  return gx_key.RightTrigger;
};

const short& InputManager::GetLstickX()
{
  return gx_key.ThumbLX;
};

const short& InputManager::GetLstickY()
{
  return gx_key.ThumbLY;
};

const short& InputManager::GetRstickX()
{
  return gx_key.ThumbRX;
};

const short& InputManager::GetRstickY()
{
  return gx_key.ThumbRY;
};

const bool& InputManager::XinputEveryOtherKey(const int button,const int frequency_frame)
{
  is_click_on_key = true;
  if( gx_key.Buttons[button] >= 1 && (key_skip_count == 0) )
  {
    /** key_skip_count��0�J�E���g�̎��̏��� */
    key_skip_count++;
    return is_click_on_key;
  }
  if( gx_key.Buttons[button] >= 1 )
  {
    /** ������Ă����� */
    key_skip_count++;
    if( 0 == key_skip_count % frequency_frame )
    {
      /** key_skip_count��frequency_frame�Ŋ���؂ꂽ�Ƃ�true�ɂ��� */
      is_click_on_key = true;
    } else
    {
      is_click_on_key = false;
    }
  } else
  {
    /** ����ȊO��false */
    is_click_on_key = false;
    key_skip_count = 0;
  }
  return is_click_on_key;
};

const bool& InputManager::XinputEveryOtherRightTrigger(const int frequency_frame)
{
  is_click_on_r_trigger = true;
  if( gx_key.RightTrigger >= 10 && (righttrigger_skip_count == 0) )
  {
    /** righttrigger_skip_count��0�J�E���g�̎��̏��� */
    righttrigger_skip_count++;
    return is_click_on_r_trigger;
  }
  if( gx_key.RightTrigger >= 10 )
  {
    /** ������Ă����� */
    righttrigger_skip_count++;
    if( 0 == righttrigger_skip_count % frequency_frame )
    {
      /** righttrigger_skip_count��frequency_frame�Ŋ���؂ꂽ�Ƃ�true�ɂ��� */
      is_click_on_r_trigger = true;
    } else
    {
      /** ����ȊO��false */
      is_click_on_r_trigger = false;
    }
  } else
  {
    /** ������Ă��Ȃ��Ƃ� */
    is_click_on_r_trigger = false;
    righttrigger_skip_count = 0;
  }
  return is_click_on_r_trigger;
};

const bool& InputManager::XinputEveryOtherLeftTrigger(const int frequency_frame)
{
  is_click_on_l_trigger = true;
  if( gx_key.LeftTrigger >= 10 && (lefttrigger_skip_count == 0) )
  {
    /** lefttrigger_skip_count��0�J�E���g�̎��̏��� */
    lefttrigger_skip_count++;
    return is_click_on_l_trigger;
  }
  if( gx_key.LeftTrigger >= 10 )
  {
    /** ������Ă����� */
    lefttrigger_skip_count++;
    if( 0 == lefttrigger_skip_count % frequency_frame )
    {
      /** lefttrigger_skip_countga��frequency_frame�Ŋ���؂ꂽ�Ƃ�true�ɂ��� */
      is_click_on_l_trigger = true;
    } else
    {
      /** ����ȊO��false */
      is_click_on_l_trigger = false;
    }
  } else
  {
    /** ������Ă��Ȃ��Ƃ� */
    is_click_on_l_trigger = false;
    lefttrigger_skip_count = 0;
  }
  return is_click_on_l_trigger;
};
