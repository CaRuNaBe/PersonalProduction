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
  /** �A�j���[�V�����̔ԍ��ꗗ */
  enum class AnimState
  {
    kIdle,      //�ҋ@
    kRun,       //����
    kAttack,    //�U��
    kJumpStart, //�W�����v�̂͂���
    kJumpLoop,  //�W�����v��
    kJumpEnd,   //�W�����v�I���
    kNone       //�Ȃ�
  };
  /** �A�j���[�V�����X�e�[�g */
  AnimState anim_state;
  /** ���̏�ɗ����Ă�����true */
  bool is_stand;
  /** �v���C���[��y�̌��� */
  float velocity_y;
  /** �A�j���[�V�����J�� */
  void AnimeBranch(AnimState old_status);
  /** �J�������������߂̊֐� */
  void CameraMoves();
  /** �v���C���[�𓮂����֐� */
  void PlayerMoves();
  /** �W�����v���� */
  void Jump();
  /** �d�͏��� */
  void GravityFalling();
  /** ���̐i�s���� */
  mymath::Vector4 now_player_velocity;
  /** �A�j���̑��Đ����� */
  float anime_total_time;
  /** �A�j���̍Đ����� */
  float anime_play_time;
  /** �A�^�b�`����Ă���A�j�� */
  int anime_attach_index;
};




