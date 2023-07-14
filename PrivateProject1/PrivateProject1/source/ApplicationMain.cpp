/*****************************************************************//**
 * \file   ApplicationMain.cpp
 * \brief  ApplicationBaseを派生したクラス(宣言)
 * \author 阿部健太郎
 * \date   July 2023
 *********************************************************************/
#include "AppFrame.h"
#include "ApplicationMain.h"
#include "ApplicationGlobal.h"
#include "GameStage.h"
#include "SkySphere.h"
#include "Player.h"
 /** 実体 */ 
ApplicationMain g_oapplicationmain;

bool ApplicationMain::Initialize()
{
  /** 基礎的な初期化 */
  if( !ApplicationBase::Initialize() )
  {
    return false;
  }
  /** このゲームの初期化 */
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