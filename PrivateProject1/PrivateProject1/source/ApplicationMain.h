/*****************************************************************//**
 * \file   ApplicationMain.h
 * \brief  ApplicationBase��h�������N���X(��`)
 *         �����ɃQ�[���̒��g�������Ă�
 * \author ���������Y
 * \date   June 2023
 *********************************************************************/
#include "AppFrame.h"
class ApplicationMain : public ApplicationBase
{
public:
  /** �������֐� */
  virtual bool Initialize()override;
  /** �E�B���h�E���J���Ă������m�F����֐� */
  virtual bool AppWindowed()override;
  /** �f�B�X�v���C���̉�f�����w�肷��֐� */
  virtual int DispSizeW()override;
  /** �f�B�X�v���C�c��f�����w�肷��֐� */
  virtual int DispSizeH()override;
private:
};