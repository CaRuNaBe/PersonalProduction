/*****************************************************************//**
 * \file   ObjectBase3d.cpp
 * \brief  3d�I�u�W�F�N�g�̊��N���X(�錾)
 * \author ���������Y
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