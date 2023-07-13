/*****************************************************************//**
 * \file   GameStage.h
 * \brief  �X�e�[�W�y��̃N���X�̒�`
 *
 * \author ���������Y
 * \date   July 2023
 *********************************************************************/
#pragma once
#include "AppFrame.h"
class GameStage : public GameBase
{
public:
  /** �R���X�g���N�^ */
  GameStage(ApplicationBase& game,int layer);
  /** �f�X�g���N�^ */
  virtual ~GameStage();
  /** �X�V�֐� */
  virtual bool Update();
  /** �`��֐� */
  virtual bool Draw();
  /** �f�o�b�O�p�`��֐� */
  virtual bool DebugDraw();
private:
  model::Mv1Model modele;
};

