/*****************************************************************//**
 * \file   SkySphere.h
 * \brief  �X�J�C�X�t�B�A�N���X(��`)
 * \author ���������Y
 * \date   July 2023
 *********************************************************************/
#pragma once
#include "AppFrame.h"
class SkySphere : public GameBase
{
public:
  /** �R���X�g���N�^ */
  SkySphere(ApplicationBase& game,int layer);
  /** �f�X�g���N�^ */
  virtual ~SkySphere();
  /** �X�V�֐� */
  virtual bool Update();
  /** �`��֐� */
  virtual bool Draw();
  /** �f�o�b�O�p�`��֐� */
  virtual bool DebugDraw();
private:
  model::Mv1Model modele;
  /** �ʒu�A��]�A�X�P�[�� */
  mymath::Matrix44 transform;
};

