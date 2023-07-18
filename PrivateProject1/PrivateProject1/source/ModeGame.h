/*****************************************************************//**
 * \file   ModeGame.h
 * \brief  �Q�[�����(��`)
 * \author ���������Y
 * \date   July 2023
 *********************************************************************/
#pragma once
#include "AppFrame.h"
#include "ObjectBase3d.h"

class ModeGame :public GameBase
{
public:
  /** �R���X�g���N�^ */
  ModeGame(ApplicationBase& game,int layer);
  /** �f�X�g���N�^ */
  virtual ~ModeGame();
  /** �X�V�֐� */
  virtual bool Update();
  /** �`��֐� */
  virtual bool Draw();
  /** �f�o�b�O�p�`��֐� */
  virtual bool DebugDraw();
  GameServerShared<ObjectBase3d>& GetObjectBase3dServer()
  {
    return game_object;
  }
private:
  GameServerShared<ObjectBase3d> game_object;
};

