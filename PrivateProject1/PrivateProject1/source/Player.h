/*****************************************************************//**
 * \file   Player.h
 * \brief  �v���C���[�N���X(��`)
 * \author ���������Y
 * \date   July 2023
 *********************************************************************/
#pragma once
#include "AppFrame.h"
#include "string"
#include "ObjectBase3d.h"
#include "ModeGame.h"
class Player : public ObjectBase3d
{
public:
  /** �R���X�g���N�^ */
  Player(ApplicationBase& game,int layer,ModeGame& mode,std::string filename);
  /** �f�X�g���N�^ */
  virtual ~Player();
  /** �X�V�֐� */
  virtual bool Update();
  /** �`��֐� */
  virtual bool Draw();
  /** �f�o�b�O�p�`��֐� */
  virtual bool DebugDraw();
private:
  enum class Status
  {
    WAIT,
    MOVE
  };
  /** ���̃v���C���[�̏�� */
  Status status;
  /** �J�������������߂̊֐� */
  void CameraMoves();
};




