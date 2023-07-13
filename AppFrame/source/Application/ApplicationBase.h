/*****************************************************************//**
 * \file   ApplicationBase.h
 * \brief  �A�v���t���[���̊��N���X�̒�`
 * \author ���������Y
 * \date   June 2023
 *********************************************************************/
#pragma once

#include <memory>
#include "../Base/GameBase.h"
#include "../Base/GameServerShared.h"
#include "InputManager.h"
 // �J����
class Camera
{
public:
  VECTOR _vPos;// �ʒu
  VECTOR _vTarget; // ����
  float _clipNear,_clipFar;// �N���b�v
};

class ApplicationBase
{
public:
  /** �R���X�g���N�^ */
  ApplicationBase();
  /** �f�X�g���N�^ */
  virtual ~ApplicationBase();
  /** �������֐� */
  virtual bool Initialize();
  /** �I���֐� */
  virtual bool Terminate();
  /** �C���v�b�g�̃A�b�v�f�[�g�֐� */
  virtual bool Input();
  /** �Q�[���̃A�b�v�f�[�g�֐� */
  virtual bool Update();
  /** �`��֐� */
  virtual bool Draw();
  /** �E�B���h�E���J���Ă������m�F����֐� */
  virtual bool AppWindowed();
  /** �f�B�X�v���C���̉�f�����w�肷��֐� */
  virtual int DispSizeW();
  /** �f�B�X�v���C�c��f�����w�肷��֐� */
  virtual int DispSizeH();
  /** delta_time��fps�̌v���֐� */
  void DeltaTimeAndFpsMeasure();
  /** ���t���b�V�����[�g�𕶎��`�� */
  void FpsDraw();
  /** �ÓI�C���X�^���X���Q�b�g�֐� */
  static ApplicationBase* GetInstance()
  {
    return lp_instance;
  }
  /** �Q�[�����[�h�Ǘ��N���X�擾 */
  std::shared_ptr<GameServerShared<GameBase>> GetModeServer()
  {
    return base_server;
  }

  /** ���͎擾 */
  InputManager& GetInput()
  {
    return input;
  }
  /** �Q�[�����I��点��Ƃ��ɌĂԊ֐� */
  void IsGameEnd()
  {
    is_game_end = true;
  }
  /** �f���^�^�C�����擾(�ύX�s��) */
  const float& GetDeltaTime()const
  {
    return delta_time;
  }
protected:
  /** ���̃N���X�̓A�v���P�[�V�����N���X�̊��N���X�Ȃ̂ŃC���X�^���X��static�ɂ����Ƃŏ㏑�������悤�ɂ��� */
  static ApplicationBase* lp_instance;
  /** �I�u�W�F�N�g�ǉ��Ǘ�����N���X�̃C���X�^���X */
  std::shared_ptr<GameServerShared<GameBase>> base_server;
  /** input�N���X�C���X�^�X */
  InputManager input;
  /** �Q�[�����I���Ƃ�true */
  bool is_game_end;
  /** �σt���[�����[�g�O��̃t���[�����牽�b�������� */
  float delta_time;
  // �J����
  Camera _cam;

};
