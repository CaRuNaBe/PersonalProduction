/*****************************************************************//**
 * \file   GameStage.cpp
 * \brief  �X�e�[�W�y��̃N���X(�錾)
 *
 * \author ���������Y
 * \date   July 2023
 *********************************************************************/
#include "GameStage.h"

GameStage::GameStage(ApplicationBase& game,int layer)
  :GameBase(game,layer)
  ,modele("res/stage2_sample/cg_stage2.mv1")
{};

GameStage::~GameStage()
{};

bool GameStage::Update()
{
  auto pos = mymath::Vector4(0,0,0);
  modele.SetPosition(pos);
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