/*****************************************************************//**
 * \file   ApplicationGlobal.cpp
 * \brief  グローバル変数や関数をまとめておくクラスの宣言
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#include "AppFrame.h"
#include "ApplicationGlobal.h"
/** 実体 */
ApplicationGlobal gGlobal;

ApplicationGlobal::ApplicationGlobal()
{}

ApplicationGlobal::~ApplicationGlobal()
{}

bool ApplicationGlobal::Initialize()
{
  return true;
}