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
  /** カメラのスピード */
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
  /** カメラの向き */
  auto cammera_dir = game.GetCamera().GetFromCameraDirection();
  cammera_dir.SetY(0.0f);//高さを無視
  cammera_dir.Normalized();
  /** 入力の向き */
  mymath::Vector4 controller_dir = { static_cast<float>(game.GetInput().GetLstickX()),0.0f,static_cast<float>(game.GetInput().GetLstickY()) };
  controller_dir.Normalized();

  /** カメラの向きベクトルと入力の向きベクトルを考慮して、プレイヤーの進行方向ベクトルを計算 */
  mymath::Vector4 player_forward = cammera_dir * controller_dir.GetZ();
  mymath::Vector4 player_right = mymath::Vector4::Cross(mymath::UP,cammera_dir) * controller_dir.GetX();
  mymath::Vector4 player_movement = player_forward + player_right;
  player_movement.Normalized();  // プレイヤーの進行方向ベクトルを正規化（長さを1にする）

  /** デルタタイムを速さにかけ可変フレームレート化 */
  player_movement *= (SPEED * game.GetDeltaTime());
  /** プレイヤーを動かす */
  transform.Transfer(player_movement);

  modele.SetMatrix(transform);
  /** 極座標でカメラを動かす */
  {
    /** 極座標生成 */
    mymath::Polar3D came_pol = { game.GetCamera().GetFromTargetDirection() };

    /** 左右 */
    if( game.GetInput().GetRstickX() < -50 )
    {
      came_pol.PhiIncrement(mymath::MyMathUtility::DegreeToRadian(CAMERA_SPEED) * game.GetDeltaTime());
    }
    if( game.GetInput().GetRstickX() > 50 )
    {
      came_pol.PhiDecrement(mymath::MyMathUtility::DegreeToRadian(CAMERA_SPEED) * game.GetDeltaTime());
    }
    /** 上下 */
    if( game.GetInput().GetRstickY() < -50 )
    {
      came_pol.ThetaIncrement(mymath::MyMathUtility::DegreeToRadian(CAMERA_SPEED) * game.GetDeltaTime());
    }
    if( game.GetInput().GetRstickY() > 50 )
    {
      came_pol.ThetaDecrement(mymath::MyMathUtility::DegreeToRadian(CAMERA_SPEED) * game.GetDeltaTime());
    }
    /** thetaをクランプする */
    float theta = std::clamp(came_pol.GetTheta(),0.5f,3.0f);
    came_pol.SetTheta(theta);

    /** カメラにセット */
    mymath::Vector4 pos = { 0.0f,100.0f,0.0f };//プレイヤーの少し上にターゲットを置く
    mymath::Vector4 camera_target_posi = transform.GetTransfer() + pos;
    mymath::Vector4 camera_posi = came_pol.ToVector4() + camera_target_posi;
    game.GetCamera().SetPosition(camera_posi);
    game.GetCamera().SetTarget(camera_target_posi);
  }

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