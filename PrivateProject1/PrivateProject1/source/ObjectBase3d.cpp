/*****************************************************************//**
 * \file   ObjectBase3d.cpp
 * \brief  3dオブジェクトの基底クラス(宣言)
 * \author 阿部健太郎
 * \date   July 2023
 *********************************************************************/
#include "ObjectBase3d.h"
#include "ModeGame.h"
ObjectBase3d::ObjectBase3d(ApplicationBase& game,int layer,ModeGame& mode,std::string filename)
  :GameBase(game,layer)
  ,mode_game(mode)
  ,modele(filename)
{};

ObjectBase3d::~ObjectBase3d()
{};

bool ObjectBase3d::Update()
{
  return true;
};
bool ObjectBase3d::Draw()
{
  return true;
};

bool ObjectBase3d::DebugDraw()
{
  return true;
};