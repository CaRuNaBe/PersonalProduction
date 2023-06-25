#include "AppFrame.h"
#include "ApplicationMain.h"
#include "ApplicationGlobal.h"
// À‘Ì
ApplicationMain g_oApplicationMain;

bool ApplicationMain::Initialize()
{
  /** Šî‘b“I‚È‰Šú‰» */
  if( !ApplicationBase::Initialize() )
  {
    return false;
  }
  /** ‚±‚ÌƒQ[ƒ€‚Ì‰Šú‰» */
  gGlobal.Initialize();
  return true;
}

bool ApplicationMain::Terminate()
{
  /** Šî‘b“I‚ÈI—¹ŠÖ” */
  ApplicationBase::Terminate();
  /** ‚±‚ÌƒQ[ƒ€‚ÌI—¹ˆ— */

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