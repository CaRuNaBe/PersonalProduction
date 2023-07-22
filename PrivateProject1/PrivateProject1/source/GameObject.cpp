/*****************************************************************//**
 * \file   GameObject.cpp
 * \brief  3dオブジェクトの基底クラス(宣言)
 * \author 阿部健太郎
 * \date   July 2023
 *********************************************************************/
#include "GameObject.h"
#include "ModeGame.h"
GameObject::GameObject(ApplicationBase& game,int layer,ModeGame& mode,std::string filename)
  :GameBase(game,layer)
  ,mode_game(mode)
  ,modele(filename)
{};

GameObject::~GameObject()
{};

bool GameObject::Update()
{
  return true;
};
bool GameObject::Draw()
{
  return true;
};

bool GameObject::DebugDraw()
{
  return true;
};