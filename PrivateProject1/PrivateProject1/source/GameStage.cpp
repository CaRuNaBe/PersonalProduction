/*****************************************************************//**
 * \file   GameStage.cpp
 * \brief
 *
 * \author ˆ¢•”Œ’‘¾˜Y
 * \date   July 2023
 *********************************************************************/
#include "GameStage.h"

GameStage::GameStage(ApplicationBase& game,int layer)
  :GameBase(game,layer)
  ,modele("res/stage2_New/Stage2Floor.mv1")
{};
GameStage::~GameStage()
{};
bool GameStage::Update()
{
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