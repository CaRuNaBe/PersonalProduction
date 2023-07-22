/*****************************************************************//**
 * \file   InputManager.h
 * \brief  input�Ǘ��N���X��`
 * \author ���������Y
 * \date   June 2023
 *********************************************************************/
#pragma once
#include <DxLib.h>

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
  DxLib::XINPUT_STATE gx_key;
  /** �������Ƃ���������������̂��i�[����\���� */
  DxLib::XINPUT_STATE gx_trg;
  /** �������Ƃ���������������̂��i�[����\���� */
  DxLib::XINPUT_STATE gx_rel;
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

/** xinput�̃{�^�����͍Ē�` */
struct XinputButton
{
  static const int DPAD_UP = XINPUT_BUTTON_DPAD_UP;// �f�W�^�������{�^����
  static const int DPAD_DOWN = XINPUT_BUTTON_DPAD_DOWN;// �f�W�^�������{�^����
  static const int DPAD_LEFT = XINPUT_BUTTON_DPAD_LEFT;// �f�W�^�������{�^����
  static const int DPAD_RIGHT = XINPUT_BUTTON_DPAD_RIGHT;// �f�W�^�������{�^���E
  static const int START = XINPUT_BUTTON_START;// START�{�^��
  static const int BACK = XINPUT_BUTTON_BACK;// BACK�{�^��
  static const int LEFT_THUMB = XINPUT_BUTTON_LEFT_THUMB;// ���X�e�B�b�N��������
  static const int RIGHT_THUMB = XINPUT_BUTTON_RIGHT_THUMB;// �E�X�e�B�b�N��������
  static const int LEFT_SHOULDER = XINPUT_BUTTON_LEFT_SHOULDER;// LB�{�^��
  static const int RIGHT_SHOULDER = XINPUT_BUTTON_RIGHT_SHOULDER;// RB�{�^��
  static const int A = XINPUT_BUTTON_A;// A�{�^��
  static const int B = XINPUT_BUTTON_B;// B�{�^��
  static const int X = XINPUT_BUTTON_X;// X�{�^��
  static const int Y = XINPUT_BUTTON_Y;// Y�{�^��
};