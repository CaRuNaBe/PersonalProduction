/*****************************************************************//**
 * \file   WinMain.cpp
 * \brief  �G���g���[�|�C���g
 * \author ���������Y
 * \date   June 2023
 *********************************************************************/
#include "AppFrame.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR lpCmdLine,_In_ int nShowCmd)
{
  /** Log�o�͂��s��Ȃ� */
  DxLib::SetOutApplicationLogValidFlag(FALSE);
  /** �A�v���P�[�V�����̃C���X�^�����Q�b�g */
  auto app_base = ApplicationBase::GetInstance();
  /** null�ł���ΏI�� */
  if( !app_base )
  {
    return 0;
  }
  /** ������ ���s�����ꍇ�I�� */
  if( !app_base->Initialize() )
  {
    return 0;
  }

  /** 1�t���[�����[�v��g�� */
  while( DxLib::ProcessMessage() == 0 )// �v���O�������I������܂Ń��[�v
  {
    app_base->Input();

    if( !app_base->Update() )
    {
      break;
    };
    app_base->Draw();
    app_base->DeltaTimeAndFpsMeasure();
#if _DEBUG
    /** esc�L�[�������ꂽ��Q�[���I�� */
    if( DxLib::CheckHitKey(KEY_INPUT_ESCAPE) )
    {
      break;
    }
#endif
  }

  app_base->Terminate();

  return 0;
}
