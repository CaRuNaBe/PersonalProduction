/*****************************************************************//**
 * \file   Player.h
 * \brief  �v���C���[�N���X(��`)
 * \author ���������Y
 * \date   July 2023
 *********************************************************************/
#pragma once
#include "AppFrame.h"
#include "string"
#include "GameObject.h"
#include "ModeGame.h"
class Player : public GameObject
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
  /** ���̏�ɗ����Ă�����true */
  bool is_stand;
  /** �v���C���[��y�̌��� */
  float velocity_y;
  /** �J�������������߂̊֐� */
  void CameraMoves();
  /** �W�����v�Əd�͏��� */
  void Jump();
  /** ���̐i�s���� */
  mymath::Vector4 now_player_velocity;
};




