/*****************************************************************//**
 * \file   ApplicationMain.h
 * \brief  ApplicationBase��h�������N���X
 *         �����ɃQ�[���̒��g�������Ă�
 * \author ���������Y
 * \date   June 2023
 *********************************************************************/
#include "AppFrame.h"



class ApplicationMain : public ApplicationBase
{
public:
  /** �������֐� */
  virtual bool Initialize();
  /** �I���֐� */
  virtual bool Terminate();
  /** �C���v�b�g�̃A�b�v�f�[�g�֐� */
  virtual bool Input();
  /** �Q�[���̃A�b�v�f�[�g�֐� */
  virtual bool Update();
  /** �`��֐� */
  virtual bool Draw();
  /** �E�B���h�E���J���Ă������m�F����֐� */
  virtual bool AppWindowed();
  /** �f�B�X�v���C���̉�f�����w�肷��֐� */
  virtual int DispSizeW();
  /** �f�B�X�v���C�c��f�����w�肷��֐� */
  virtual int DispSizeH();

private:

};
