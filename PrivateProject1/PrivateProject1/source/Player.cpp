/*****************************************************************//**
 * \file   Player.cpp
 * \brief  プレイヤークラス(宣言)
 * \author 阿部健太郎
 * \date   July 2023
 *********************************************************************/
#include "Player.h"
#include <algorithm>
namespace
{
  /** プレイヤーが1秒間に動く距離 */
  const float SPEED = 200;

  const float CAMERA_SPEED = 120.f;
}
Player::Player(ApplicationBase& game,int layer)
  :GameBase(game,layer)
  ,modele("res/player/SDChar.mv1")
{
  transform.Scale(0.5f,0.5f,0.5f,false);
};

Player::~Player()
{};

bool Player::Update()
{
  /** 入力をベクトル化 */
  mymath::Vector4 player_dir = { static_cast<float>(game.GetInput().GetLstickX()),0.0f,static_cast<float>(game.GetInput().GetLstickY()) };
  player_dir.Normalized();
  /** デルタタイムを速さにかけ可変フレームレート化 */
  player_dir *= (SPEED * game.GetDeltaTime());
  /** プレイヤーを動かす */
  transform.Transfer(player_dir);

  modele.SetMatrix(transform);

  /** 極座標でカメラを動かす */
  mymath::Polar3D came_pol = { game.GetCamera().GetPosition() - game.GetCamera().GetTarget() };

  if( game.GetInput().GetRstickX() < -50 )
  {
    came_pol.PhiDecrement(mymath::MyMathUtility::DegreeToRadian(CAMERA_SPEED) * game.GetDeltaTime());
  }
  if( game.GetInput().GetRstickX() > 50 )
  {
    came_pol.PhiIncrement(mymath::MyMathUtility::DegreeToRadian(CAMERA_SPEED) * game.GetDeltaTime());
  }

  if( game.GetInput().GetRstickY() < -50 )
  {
    came_pol.ThetaIncrement(mymath::MyMathUtility::DegreeToRadian(CAMERA_SPEED) * game.GetDeltaTime());
  }
  if( game.GetInput().GetRstickY() > 50 )
  {
    came_pol.ThetaDecrement(mymath::MyMathUtility::DegreeToRadian(CAMERA_SPEED) * game.GetDeltaTime());
  }
  /** 制限する */
  float radius = came_pol.GetRadius();
  float theta = std::clamp(came_pol.GetTheta(),0.5f,3.0f);
  float phi = came_pol.GetPhi();  
  came_pol.Set(radius,theta,phi);
  /** カメラにセット */
  mymath::Vector4 pos = { 0.0f,100.0f,0.0f };//プレイヤーの少し上にターゲットを置く
  mymath::Vector4 camera_target_posi = transform.GetTransfer() + pos;
  mymath::Vector4 camera_posi = came_pol.ToVector4() + camera_target_posi;
  game.GetCamera().SetPosition(camera_posi);
  game.GetCamera().SetTarget(camera_target_posi);


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