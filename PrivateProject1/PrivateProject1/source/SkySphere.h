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
  Mv1Model modele;
};

