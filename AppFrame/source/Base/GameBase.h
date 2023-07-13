/*****************************************************************//**
 * \file   GameBase.h
 * \brief  �Q�[���ɓo�ꂷ����̂̊��N���X���Ƃ���������h������
 *         �Ȃ���΂Ȃ�Ȃ�
 * \author ���������Y
 * \date   June 2023
 *********************************************************************/
#pragma once
class ApplicationBase;
namespace mymath
{
  class Matrix44;
}

class GameBase
{
public:
  /** �R���X�g���N�^ */
  GameBase(ApplicationBase& _game,int layer)
    : game(_game)
    ,is_dead(false)
    ,is_update_skip(false)
    ,is_draw_skip(false)
    ,layer(layer)
    ,cnt(0)
  {}
  /** �f�X�g���N�^ */
  virtual ~GameBase()
  {};
  /** �X�V�֐� */
  virtual bool Update() = 0;
  /** �`��֐� */
  virtual bool Draw() = 0;
  /** �f�o�b�O�p�`��֐� */
  virtual bool DebugDraw() = 0;
  /** ���񂾂��擾 */
  virtual bool IsDead()
  {
    return is_dead;
  }
  /** ���� */
  virtual void Dead()
  {
    is_dead = true;
  }
  /** �A�b�v�f�[�g�X�L�b�v�擾 */
  virtual bool GetUpdateSkip()
  {
    return is_update_skip;
  }
  /** �Z�b�g�A�b�v�f�[�g�X�L�b�v */
  virtual void SetUpdateSkip(bool update_skip)
  {
    is_update_skip = update_skip;
  }
  /** �`��X�L�b�v�ϐ��擾 */
  virtual bool GetDrawSkip()
  {
    return is_draw_skip;
  }
  /** �Z�b�g�`��X�L�b�v */
  virtual void SetDrawSkip(bool draw_skip)
  {
    is_draw_skip = draw_skip;
  }
  /** ���C���[�Q�b�g */
  virtual int GetLayer()
  {
    return layer;
  }

protected:
  /** ApplicationBase�̎Q�� */
  ApplicationBase& game;
  /** ���̃I�u�W�F�N�g�����񂾂�true */
  bool is_dead;
  /** �X�V�������Ȃ��Ƃ�true */
  bool is_update_skip;
  /** �`�悵�����Ȃ��Ƃ�true */
  bool is_draw_skip;
  /** �X�V,�`�揇�̎w�萔�����Ȃ��Ɛ�ɍX�V����� */
  int layer;
  /** �J�E���g�ϐ� */
  int cnt;
};

