/*****************************************************************//**
 * \file   ModeGame.h
 * \brief  �Q�[�����(��`)
 * \author ���������Y
 * \date   July 2023
 *********************************************************************/
#pragma once
#include "AppFrame.h"
#include "GameObject.h"

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
  /** ���̃��[�h�Ŏg����I�u�W�F�N�g�̃T�[�o�[���擾 */
  GameServerShared<GameObject>& GetGameObjectServer()
  {
    return game_object;
  }
private:
  GameServerShared<GameObject> game_object;
};

