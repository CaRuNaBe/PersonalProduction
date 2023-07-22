/*****************************************************************//**
 * \file   GameObject.h
 * \brief  3d�I�u�W�F�N�g�̊��N���X(��`)
 * \author ���������Y
 * \date   July 2023
 *********************************************************************/
#pragma once
#include "AppFrame.h"
#include "string"
class ModeGame;

class GameObject :public GameBase
{
public:
  /** �R���X�g���N�^ */
  GameObject(ApplicationBase& game,int layer,ModeGame& mode,std::string filename);
  /** �f�X�g���N�^ */
  virtual ~GameObject();
  /** �X�V�֐� */
  virtual bool Update() ;
  /** �`��֐� */
  virtual bool Draw() ;
  /** �f�o�b�O�p�`��֐� */
  virtual bool DebugDraw() ;
protected:
  ModeGame& mode_game;
  /** �v���C���[��3d���f�� */
  model::Mv1Model modele;
  /** �ʒu */
  mymath::Vector4 position;
  /** �������Ă�������̕ۑ��ꏊ */
  mymath::Vector4 now_direction;
};

