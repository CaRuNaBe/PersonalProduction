/*****************************************************************//**
 * \file   ApplicationBase.cpp
 * \brief  �A�v���t���[���̊��N���X�̐錾
 * \author ���������Y
 * \date   June 2023
 *********************************************************************/
#include "ApplicationBase.h"
#include "DxLib.h"
ApplicationBase* ApplicationBase::lp_instance = NULL;

namespace
{
  static constexpr int Z_BUFFER_BIT_DEPTH = 32;
  static constexpr int COLOR_BIT_DEPTH = 32;
  /** �V�X�e�����J�n���Čo�߂�������(1000�Ŋ���ƕb�ɂȂ�) */
  int now_time = 0;
  /** �O�̌o�ߎ��� */
  int time = 0;

  /** ���̃��t���b�V�����[�g */
  int fps = 0;
  /* 1�t���[����1�������f�B�X�v���C�̐ݒ肵���t���[�����ɂȂ�ƂƂ܂肻���`�悷��  */
  int fps_counter = 0;
  /** fps���v������Ƃ��Ɏg���O�̌o�ߎ��� */
  int fps_check_time = 0;
}

ApplicationBase::ApplicationBase()
  : camera { DispSizeW(),DispSizeH() }
{
  lp_instance = this;
  is_game_end = false;
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
    DxLib::ChangeWindowMode(TRUE);/** �E�B���h�E���[�h�Ɏw�肷�� */
  }
  /** z�o�b�t�@��bit�[�x��ύX */
  DxLib::SetZBufferBitDepth(Z_BUFFER_BIT_DEPTH);
  /** ��ʃT�C�Y�Z�b�g */
  DxLib::SetGraphMode(DispSizeW(),DispSizeH(),COLOR_BIT_DEPTH);

  DxLib::SetWaitVSyncFlag(TRUE);
 // SetAlwaysRunFlag(TRUE);
  DxLib::SetUseLighting(FALSE);
  if( DxLib::DxLib_Init() == -1 )
  {
    /** �G���[���N�����璼���ɏI�� */
    return false;
  }

  /** �`����ʂ𗠉�ʂɃZ�b�g */
  DxLib::SetDrawScreen(DX_SCREEN_BACK);

  /** �y�o�b�t�@��L���ɂ��� */
  DxLib::SetUseZBuffer3D(TRUE);

  /** �y�o�b�t�@�ւ̏������݂�L���ɂ��� */
  DxLib::SetWriteZBuffer3D(TRUE);
  /** ���̉�ʂ���ۂ����� */
  DxLib::SetBackgroundColor(0,192,255);
  /** ���[�h�T�[�o�̏����� */
  base_server = std::make_shared<GameServerShared<GameBase>>();

  is_game_end = false;

  /** �V�X�e�����Ԃ��擾���Ă��� */
  time = DxLib::GetNowCount();

  /** �ŏ��̌o�ߎ��Ԃ�0.00000f �b�ɂ��Ă��� */
  delta_time = 0.00000f;

  /** FPS�v���֌W�̏����� */
  fps_check_time = DxLib::GetNowCount();
  fps = 0;
  fps_counter = 0;

  camera.SetAspect(DispSizeW(),DispSizeH());
  return true;
}

bool ApplicationBase::Terminate()
{
  /** DX���C�u�����J�� */
  DxLib::DxLib_End();
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
  camera.Update();
  return true;
}

bool ApplicationBase::Draw()
{
  /** �t�H�O�ݒ� */
  //SetFogEnable(TRUE);
  //SetFogColor(255,255,255);
  //SetFogStartEnd(1000.f,800.f);
  /** ��ʂ����������� */
  DxLib::ClearDrawScreen();
  base_server->Draw();
  /** 0,0,0�𒆐S�ɐ������� */
  {
    float linelength = 1000000.f;
    DxLib::VECTOR v = { 0, 0, 0 };
    DxLib::DrawLine3D(VAdd(v,DxLib::VGet(-linelength,0,0)),DxLib::VAdd(v,DxLib::VGet(linelength,0,0)),DxLib::GetColor(255,0,0));
    DxLib::DrawLine3D(VAdd(v,DxLib::VGet(0,-linelength,0)),DxLib::VAdd(v,DxLib::VGet(0,linelength,0)),DxLib::GetColor(0,255,0));
    DxLib::DrawLine3D(VAdd(v,DxLib::VGet(0,0,-linelength)),DxLib::VAdd(v,DxLib::VGet(0,0,linelength)),DxLib::GetColor(0,0,255));
  }
  FpsDraw();
  /** ����ʂ̓��e��\��ʂɔ��f������ */
  DxLib::ScreenFlip();
  return true;
}

void ApplicationBase::DeltaTimeAndFpsMeasure()
{
  /** ���݂̃V�X�e�����Ԃ��擾 */
  now_time = DxLib::GetNowCount();

  /** �O��擾�������Ԃ���̌o�ߎ��Ԃ�b�ɕϊ����ăZ�b�g */
  /** (GetNowCount �Ŏ擾�ł���l�̓}�C�N���b�P�ʂȂ̂� 1000 �Ŋ��邱�Ƃŕb�P�ʂɂȂ�) */
  delta_time = (now_time - time) / 1000.0f;

  /** ����擾�������Ԃ�ۑ� */
  time = now_time;

  /** FPS�֌W�̏���(1�b�o�߂���ԂɎ��s���ꂽ���C�����[�v�̉񐔂� FPS �Ƃ���) */
  fps_counter++;
  if( now_time - fps_check_time > 1000 )
  {
    fps = fps_counter;
    fps_counter = 0;
    fps_check_time = now_time;
  }
}

void ApplicationBase::FpsDraw()
{
  DxLib::DrawFormatString(0,0,DxLib::GetColor(255,255,255),"fps:%d",fps);
};

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