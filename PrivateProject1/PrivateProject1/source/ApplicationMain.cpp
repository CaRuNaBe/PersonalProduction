#include "AppFrame.h"
#include "ApplicationMain.h"
#include "ApplicationGlobal.h"
// 実体
ApplicationMain g_oApplicationMain;

bool ApplicationMain::Initialize()
{
  /** 基礎的な初期化 */
  if( !ApplicationBase::Initialize() )
  {
    return false;
  }
  /** このゲームの初期化 */
  gGlobal.Initialize();
  return true;
}

bool ApplicationMain::Terminate()
{
  /** 基礎的な終了関数 */
  ApplicationBase::Terminate();
  /** このゲームの終了処理 */

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