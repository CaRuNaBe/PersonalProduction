/*****************************************************************//**
 * \file   ApplicationMain.cpp
 * \brief  ApplicationBase��h�������N���X(�錾)
 * \author ���������Y
 * \date   July 2023
 *********************************************************************/
#include "AppFrame.h"
#include "ApplicationMain.h"
#include "ApplicationGlobal.h"
#include "GameStage.h"
#include "SkySphere.h"
#include "Player.h"
 /** ���� */ 
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
  auto sky_sphere = std::make_shared<SkySphere>(*this,0);
  this->base_server->Add(sky_sphere);
  auto stage = std::make_shared<GameStage>(*this,1);
  this->base_server->Add(stage);

  auto player = std::make_shared<Player>(*this,2);
  this->base_server->Add(player);
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