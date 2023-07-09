/*****************************************************************//**
 * \file   InputManager.h
 * \brief  input�Ǘ��N���X��`
 * \author ���������Y
 * \date   June 2023
 *********************************************************************/
#pragma once
#include <DxLib.h>
struct tagXINPUT_STATE;
class InputManager
{
public:
  /** �R���X�g���N�^ */
  InputManager();
  /** �f�X�g���N�^ */
  ~InputManager();
  /** �X�V */
  bool Update();
  /** �A������ */
  const bool GetKeyXinput(const int button);
  /** �������Ƃ��������� */
  const bool GetTrgXinput(const int button);
  /** �������Ƃ����� */
  const bool GetRelXinput(const int button);
  /** ���g���K�[�̓��͏�Ԃ��擾 */
  const unsigned char& GetLeftTrigger();
  /** �E�g���K�[�̓��͏�Ԃ��擾 */
  const unsigned char& GetRightTrigger();
  /** ���X�e�B�b�N��x���̓��͏�Ԃ��擾 */
  const short& GetLstickX();
  /** ���X�e�B�b�N��y���̓��͏�Ԃ��擾 */
  const short& GetLstickY();
  /** �E�X�e�B�b�N��x���̓��͏�Ԃ��擾 */
  const short& GetRstickX();
  /** �E�X�e�B�b�N��y���̓��͏�Ԃ��擾 */
  const short& GetRstickY();
  /** �{�^���̊u�t���[�����͂��擾 */
  const bool& XinputEveryOtherKey(int button,const int frequency_frame);
  /** �E�g���K�[�̊u�t���[�����͂��擾 */
  const bool& XinputEveryOtherLeftTrigger(const int frequency_frame);
  /** ���g���K�[�̊u�t���[�����͂��擾 */
  const bool& XinputEveryOtherRightTrigger(const int frequency_frame);
private:
  /** xinput�R���g���[���[��� */
  /** �A�����͂̊i�[����\���� */
  XINPUT_STATE gx_key;
  /** �������Ƃ���������������̂��i�[����\���� */
  XINPUT_STATE gx_trg;
  /** �������Ƃ���������������̂��i�[����\���� */
  XINPUT_STATE gx_rel;
  /** �������������Ƃ��J�E���g����Ă����ϐ� */
  int key_skip_count;
  /** ���g���K�[��������Ă�����J�E���g����Ă����ϐ� */
  int lefttrigger_skip_count;
  /** �E�g���K�[��������Ă�����J�E���g����Ă����ϐ� */
  int righttrigger_skip_count;
  /** �{�^���̊u�t���[�����͗p�̐^�U�ϐ�true�̎�������Ă� */
  bool is_click_on_key;
  /** �E�g���K�[�̊u�t���[�����͗p�̐^�U�ϐ�true�̎�������Ă� */
  bool is_click_on_r_trigger;
  /** ���g���K�[�̊u�t���[�����͗p�̐^�U�ϐ�true�̎�������Ă� */
  bool is_click_on_l_trigger;
};
