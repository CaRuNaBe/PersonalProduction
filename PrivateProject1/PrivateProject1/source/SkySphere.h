/*****************************************************************//**
 * \file   SkySphere.h
 * \brief  �X�J�C�X�t�B�A�N���X(��`)
 * \author ���������Y
 * \date   July 2023
 *********************************************************************/
#pragma once
#include "AppFrame.h"
#include "string"
#include "GameObject.h"
#include "ModeGame.h"
class SkySphere : public GameObject
{
public:
  /** �R���X�g���N�^ */
  SkySphere(ApplicationBase& game,int layer,ModeGame& mode,std::string filename);
  /** �f�X�g���N�^ */
  virtual ~SkySphere();
  /** �X�V�֐� */
  virtual bool Update();
  /** �`��֐� */
  virtual bool Draw();
  /** �f�o�b�O�p�`��֐� */
  virtual bool DebugDraw();
private:
};

