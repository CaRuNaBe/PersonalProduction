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

}

Player::Player(ApplicationBase& game,int layer,ModeGame& mode,std::string filename)
  :ObjectBase3d(game,layer,mode,filename)
  ,status(Status::WAIT)
{};

Player::~Player()
{};

bool Player::Update()
{
  /** カメラの向き */
  mymath::Vector4 camera_dir = game.GetCamera().GetFromCameraDirection();
  camera_dir.SetY(0.0f);//高さを無視
  /** 入力の向き */
  mymath::Vector4 lstick_dir = { static_cast<float>(game.GetInput().GetLstickX()),0.0f,static_cast<float>(game.GetInput().GetLstickY()) };
  /** カメラの向きベクトルと入力の向きベクトルを考慮して、プレイヤーの進行方向ベクトルを計算 */
  mymath::Vector4 player_forward = camera_dir * lstick_dir.GetZ();
  mymath::Vector4 player_right = mymath::Vector4::Cross(mymath::VECTOR4_UP,camera_dir) * lstick_dir.GetX();
  mymath::Vector4 player_velocity = player_forward + player_right;
  player_velocity.Normalized();
  float player_speed = lstick_dir.Lenght() / 10.0f;
  /** デルタタイムを速さにかけ可変フレームレート化 */
  player_velocity *= (player_speed * game.GetDeltaTime());

  position += player_velocity;

  /** プレイヤーを動かす */
  mymath::Matrix44 transform;
  transform.Scale(0.5f,0.5f,0.5f);
  mymath::Vector4 vRot = { 0,0,0 };
  vRot.SetY(atan2(player_velocity.GetX() * -1,player_velocity.GetZ() * -1));// モデルが標準でどちらを向いているかで式が変わる(これは-zを向いている場合)
  if( player_speed > 0 )
  {
    old_direction = vRot;
  }

  transform.RotateX(old_direction.GetX());
  transform.RotateY(old_direction.GetY());
  transform.RotateZ(old_direction.GetZ());
  transform.Transfer(position);

  modele.SetMatrix(transform);


  CameraMoves();


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

void Player::CameraMoves()
{
  /** 極座標でカメラを動かす */
  mymath::Vector4 rstick_dir = { static_cast<float>(game.GetInput().GetRstickX()),0.0f,static_cast<float>(game.GetInput().GetRstickY()) };
  /** 極座標生成 */
  mymath::Polar3D came_pol = { game.GetCamera().GetFromTargetDirection() };
  float camera_speed = mymath::MyMathUtility::DegreeToRadian((rstick_dir.Lenght() * 0.005f) * game.GetDeltaTime());
  /** 左右 */
  if( game.GetInput().GetRstickX() < -50 )
  {
    came_pol.PhiIncrement(camera_speed);
  }
  if( game.GetInput().GetRstickX() > 50 )
  {
    came_pol.PhiDecrement(camera_speed);
  }
  /** 上下 */
  if( game.GetInput().GetRstickY() < -50 )
  {
    came_pol.ThetaIncrement(camera_speed);
  }
  if( game.GetInput().GetRstickY() > 50 )
  {
    came_pol.ThetaDecrement(camera_speed);
  }
  /** thetaをクランプする */
  float theta = std::clamp(came_pol.GetTheta(),0.5f,3.0f);
  came_pol.SetTheta(theta);

  /** カメラにセット */
  mymath::Vector4 pos = { 0.0f,100.0f,0.0f };//プレイヤーの少し上にターゲットを置く
  mymath::Vector4 camera_target = position + pos;
  mymath::Vector4 camera_posi = came_pol.ToVector4() + camera_target;
  game.GetCamera().SetPosition(camera_posi);
  game.GetCamera().SetTarget(camera_target);
};
