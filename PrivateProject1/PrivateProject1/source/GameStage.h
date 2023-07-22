/*****************************************************************//**
 * \file   GameStage.h
 * \brief  �X�e�[�W�y��̃N���X�̒�`
 *
 * \author ���������Y
 * \date   July 2023
 *********************************************************************/
#pragma once
#include "AppFrame.h"
#include "string"
#include "GameObject.h"
#include "ModeGame.h"
class GameStage : public GameObject
{
public:
  /** �R���X�g���N�^ */
  GameStage(ApplicationBase& game,int layer,ModeGame& mode,std::string filename);
  /** �f�X�g���N�^ */
  virtual ~GameStage();
  /** �X�V�֐� */
  virtual bool Update();
  /** �`��֐� */
  virtual bool Draw();
  /** �f�o�b�O�p�`��֐� */
  virtual bool DebugDraw();
private:
};

