/*****************************************************************//**
 * \file   ApplicationGlobal.h
 * \brief  �O���[�o���ϐ���֐����܂Ƃ߂Ă����N���X�̒�`
 * \author ���������Y
 * \date   June 2023
 *********************************************************************/
#include "AppFrame.h"
class ApplicationGlobal
{
public:
  /** �R���X�g���N�^ */
  ApplicationGlobal();
  /** �f�X�g���N�^ */
  virtual ~ApplicationGlobal();
  /** �����֐� */
  bool Initialize();
private:
};
/** ���̃\�[�X��gGlobal���g����悤�� */
extern ApplicationGlobal gGlobal;