/*****************************************************************//**
 * \file   ApplicationMain.cpp
 * \brief  ApplicationBaseを派生したクラス(宣言)
 * \author 阿部健太郎
 * \date   July 2023
 *********************************************************************/
#include "AppFrame.h"
#include "ApplicationMain.h"
#include "ApplicationGlobal.h"
#include "ModeGame.h"
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

  auto game = std::make_shared<ModeGame>(*this,0);
  this->base_server->Add(game);

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