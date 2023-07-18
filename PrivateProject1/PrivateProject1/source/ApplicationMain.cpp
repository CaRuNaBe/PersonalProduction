/*****************************************************************//**
 * \file   ApplicationMain.cpp
 * \brief  ApplicationBase��h�������N���X(�錾)
 * \author ���������Y
 * \date   July 2023
 *********************************************************************/
#include "AppFrame.h"
#include "ApplicationMain.h"
#include "ApplicationGlobal.h"
#include "ModeGame.h"
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