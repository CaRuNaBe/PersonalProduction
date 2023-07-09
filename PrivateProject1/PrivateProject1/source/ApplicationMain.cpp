#include "AppFrame.h"
#include "ApplicationMain.h"
#include "ApplicationGlobal.h"
#include "GameStage.h"
#include "SkySphere.h"
// ����
ApplicationMain g_oapplicationmain;

bool ApplicationMain::Initialize()
{
  /** ��b�I�ȏ����� */
  if( !ApplicationBase::Initialize() )
  {
    return false;
  }
  /** ���̃Q�[���̏����� */
  global.Initialize();
  auto stage = std::make_shared<GameStage>(*this,0);
  this->base_server->Add(stage);
  auto sky_sphere = std::make_shared<SkySphere>(*this,0);
  this->base_server->Add(sky_sphere);

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