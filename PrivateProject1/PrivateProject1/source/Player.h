/*****************************************************************//**
 * \file   Player.h
 * \brief  �v���C���[�N���X(��`)
 * \author ���������Y
 * \date   July 2023
 *********************************************************************/
#pragma once
#include "AppFrame.h"
class Player : public GameBase
{
public:
  /** �R���X�g���N�^ */
  Player(ApplicationBase& game,int layer);
  /** �f�X�g���N�^ */
  virtual ~Player();
  /** �X�V�֐� */
  virtual bool Update();
  /** �`��֐� */
  virtual bool Draw();
  /** �f�o�b�O�p�`��֐� */
  virtual bool DebugDraw();
private:
  /** �v���C���[��3d���f�� */
  model::Mv1Model modele;
  /** �v���C���[�̈ʒu�A��]�A�X�P�[�� */
  mymath::Matrix44 transform;
  /** �L�[�{�[�h�̏�񂪓����Ă�o�b�t�@�[ */
  char keyboard[256];
};



