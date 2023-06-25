#include "AppFrame.h"
#include "ApplicationMain.h"
#include "ApplicationGlobal.h"
// ����
ApplicationMain g_oApplicationMain;

bool ApplicationMain::Initialize()
{
  /** ��b�I�ȏ����� */
  if( !ApplicationBase::Initialize() )
  {
    return false;
  }
  /** ���̃Q�[���̏����� */
  gGlobal.Initialize();
  return true;
}

bool ApplicationMain::Terminate()
{
  /** ��b�I�ȏI���֐� */
  ApplicationBase::Terminate();
  /** ���̃Q�[���̏I������ */

  return true;
}


bool ApplicationMain::Input()
{
  ApplicationBase::Input();
  return true;
}

bool ApplicationMain::Update()
{
  ApplicationBase::Update();
  if( is_game_end )
  {
    return false;
  }

  return true;
}

bool ApplicationMain::Draw()
{
  ApplicationBase::Draw();
  return true;
}

bool ApplicationMain::AppWindowed()
{
  return true;
}
int ApplicationMain::DispSizeW()
{
  return 1920;
}
int ApplicationMain::DispSizeH()
{
  return 1080;
}