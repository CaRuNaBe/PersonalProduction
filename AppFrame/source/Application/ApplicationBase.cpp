/*****************************************************************//**
 * \file   ApplicationBase.cpp
 * \brief  �A�v���t���[���̊��N���X�̐錾
 * \author ���������Y
 * \date   June 2023
 *********************************************************************/
#include "ApplicationBase.h"
ApplicationBase* ApplicationBase::lp_Instance = NULL;

namespace
{
  static constexpr int z_buffer_bit_depth = 32;
  static constexpr int color_bit_depth = 32;
}

ApplicationBase::ApplicationBase()
{
  lp_Instance = this;
}

ApplicationBase::~ApplicationBase()
{}

bool ApplicationBase::Initialize()
{
#if _DEBUG
  /** �f�o�b�O���[�h������Y�ꂪ�Ȃ����m�F */
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  /** DX���C�u�����̏����� */
  if( AppWindowed() )
  {
    ChangeWindowMode(TRUE);/** �E�B���h�E���[�h�Ɏw�肷�� */
  }
  /** z�o�b�t�@��bit�[�x��ύX */
  SetZBufferBitDepth(z_buffer_bit_depth);
  /** ��ʃT�C�Y�Z�b�g */
  SetGraphMode(DispSizeW(),DispSizeH(),color_bit_depth);


  if( DxLib_Init() == -1 )
  {
    /** �G���[���N�����璼���ɏI�� */
    return false;
  }
  /** �`����ʂ𗠉�ʂɃZ�b�g */
  SetDrawScreen(DX_SCREEN_BACK);

  /** �y�o�b�t�@��L���ɂ��� */
  SetUseZBuffer3D(TRUE);

  /** �y�o�b�t�@�ւ̏������݂�L���ɂ��� */
  SetWriteZBuffer3D(TRUE);

  /** ���[�h�T�[�o�̏����� */
  base_server = std::make_shared<GameServerShared<GameBase>>();

  is_game_end = false;
  return true;
}

bool ApplicationBase::Terminate()
{
  /** DX���C�u�����J�� */
  DxLib_End();
  return true;
}

bool ApplicationBase::Input()
{
  input.Update();
  return true;
}

bool ApplicationBase::Update()
{
  base_server->Update();
  return true;
}

bool ApplicationBase::Draw()
{
  /** ��ʂ����������� */
  ClearDrawScreen();
  base_server->Draw();
  /** ����ʂ̓��e��\��ʂɔ��f������ */
  ScreenFlip();
  return true;
}

bool ApplicationBase::AppWindowed()
{
  return true;
}

int ApplicationBase::DispSizeW()
{
  return 640;
}

int ApplicationBase::DispSizeH()
{
  return 480;
}