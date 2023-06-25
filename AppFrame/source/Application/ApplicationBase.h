/*****************************************************************//**
 * \file   ApplicationBase.h
 * \brief  �A�v���t���[���̊��N���X�̒�`
 * \author ���������Y
 * \date   June 2023
 *********************************************************************/
#pragma once
#include "Dxlib.h"
#include <memory>
#include "../Base/GameBase.h"
#include "../Base/GameServerShared.h"
#include "InputManager.h"

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
  /** �ÓI�C���X�^���X���Q�b�g�֐� */
  static ApplicationBase* GetInstance()
  {
    return lp_Instance;
  }
  /** �Q�[�����[�h�Ǘ��N���X�擾 */
  std::shared_ptr<GameServerShared<GameBase>> GetModeServer()
  {
    return base_server;
  }

  /** ���͎擾 */
  const InputManager& GetInput()
  {
    return input;
  }
  /** �Q�[�����I��点��Ƃ��ɌĂԊ֐� */
  void IsGameEnd()
  {
    is_game_end = true;
  }
protected:
  /** ���̃N���X�̓A�v���P�[�V�����N���X�̊��N���X�Ȃ̂ŃC���X�^���X��static�ɂ����Ƃŏ㏑�������悤�ɂ��� */
  static ApplicationBase* lp_Instance;
  /** �I�u�W�F�N�g�ǉ��Ǘ�����N���X�̃C���X�^���X */
  std::shared_ptr<GameServerShared<GameBase>> base_server;
  /** input�N���X�C���X�^�X */
  InputManager input;
  /** �Q�[�����I���Ƃ�true */
  bool is_game_end;
};
