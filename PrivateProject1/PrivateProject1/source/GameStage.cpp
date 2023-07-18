/*****************************************************************//**
 * \file   GameStage.cpp
 * \brief  �X�e�[�W�y��̃N���X(�錾)
 *
 * \author ���������Y
 * \date   July 2023
 *********************************************************************/
#include "GameStage.h"

GameStage::GameStage(ApplicationBase& game,int layer,ModeGame& mode,std::string filename)
  :ObjectBase3d(game,layer,mode,filename)
{};

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