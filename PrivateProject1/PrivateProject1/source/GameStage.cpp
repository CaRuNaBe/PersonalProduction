/*****************************************************************//**
 * \file   GameStage.cpp
 * \brief  ステージ土台のクラス(宣言)
 *
 * \author 阿部健太郎
 * \date   July 2023
 *********************************************************************/
#include "GameStage.h"

GameStage::GameStage(ApplicationBase& game,int layer,ModeGame& mode,std::string filename)
  :GameObject(game,layer,mode,filename)
{
  modele.SetupAllCollInfo();
};

GameStage::~GameStage()
{};

bool GameStage::Update()
{
  mymath::Matrix44 transform;
  modele.SetMatrix(transform);
  return true;
};

bool GameStage::Draw()
{
  modele.Draw();
  return true;
};

bool GameStage::DebugDraw()
{
  return true;
};