/*****************************************************************//**
 * \file   ModeGame.cpp
 * \brief  ƒQ[ƒ€‰æ–Ê(éŒ¾)
 * \author ˆ¢•”Œ’‘¾˜Y
 * \date   July 2023
 *********************************************************************/
#include "ModeGame.h"
#include "GameStage.h"
#include "SkySphere.h"
#include "Player.h"

ModeGame::ModeGame(ApplicationBase& game,int layer)
  :GameBase(game,layer)
{
  auto sky_sphere = std::make_shared<SkySphere>(game,1,*this,"res/skysphere_morning/cg_stageSkymap_1.mv1");
  game_object.Add(sky_sphere);
  auto stage = std::make_shared<GameStage>(game,1,*this,"res/stage2_sample/cg_stage2.mv1");
  game_object.Add(stage);
  auto player = std::make_shared<Player>(game,3,*this,"res/player/SDChar.mv1");
  game_object.Add(player);
};

ModeGame::~ModeGame()
{};

bool ModeGame::Update()
{
  game_object.Update();
  return true;
};

bool ModeGame::Draw()
{
  game_object.Draw();
  return true;
};

bool ModeGame::DebugDraw()
{
  return true;
};