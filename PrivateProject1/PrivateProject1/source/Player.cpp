/*****************************************************************//**
 * \file   Player.cpp
 * \brief  プレイヤークラス(宣言)
 * \author 阿部健太郎
 * \date   July 2023
 *********************************************************************/
#include "Player.h"
namespace
{
  /** プレイヤーが1秒間に動く距離 */
  const float SPEED = 60;
}
Player::Player(ApplicationBase& game,int layer)
  :GameBase(game,layer)
  ,modele("res/player/SDChar.mv1")
{
  transform.Scale(0.1f,0.1f,0.1f,false);
};

Player::~Player()
{};

bool Player::Update()
{
  /** 入力をベクトル化 */
  mymath::Vector4 player_dir = { static_cast<float>(game.GetInput().GetLstickX()),0.0f,static_cast<float>(game.GetInput().GetLstickY()) };
  player_dir.Normalized();
  player_dir *= (SPEED * game.GetDeltaTime());
  /** プレイヤーを動かす */
  transform.Transfer(player_dir);

  modele.SetMatrix(transform);
  return true;
};

bool Player::Draw()
{
  modele.Draw();
  return true;
};

bool Player::DebugDraw()
{
  return true;
};