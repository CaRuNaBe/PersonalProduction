/*****************************************************************//**
 * \file   GameObject.cpp
 * \brief  3d�I�u�W�F�N�g�̊��N���X(�錾)
 * \author ���������Y
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