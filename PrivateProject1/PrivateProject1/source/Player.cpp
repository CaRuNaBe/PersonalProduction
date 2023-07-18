/*****************************************************************//**
 * \file   Player.cpp
 * \brief  �v���C���[�N���X(�錾)
 * \author ���������Y
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
  /** �J�����̌��� */
  mymath::Vector4 camera_dir = game.GetCamera().GetFromCameraDirection();
  camera_dir.SetY(0.0f);//�����𖳎�
  /** ���͂̌��� */
  mymath::Vector4 lstick_dir = { static_cast<float>(game.GetInput().GetLstickX()),0.0f,static_cast<float>(game.GetInput().GetLstickY()) };
  /** �J�����̌����x�N�g���Ɠ��͂̌����x�N�g�����l�����āA�v���C���[�̐i�s�����x�N�g�����v�Z */
  mymath::Vector4 player_forward = camera_dir * lstick_dir.GetZ();
  mymath::Vector4 player_right = mymath::Vector4::Cross(mymath::VECTOR4_UP,camera_dir) * lstick_dir.GetX();
  mymath::Vector4 player_velocity = player_forward + player_right;
  player_velocity.Normalized();
  float player_speed = lstick_dir.Lenght() / 10.0f;
  /** �f���^�^�C���𑬂��ɂ����σt���[�����[�g�� */
  player_velocity *= (player_speed * game.GetDeltaTime());

  position += player_velocity;

  /** �v���C���[�𓮂��� */
  mymath::Matrix44 transform;
  transform.Scale(0.5f,0.5f,0.5f);
  mymath::Vector4 vRot = { 0,0,0 };
  vRot.SetY(atan2(player_velocity.GetX() * -1,player_velocity.GetZ() * -1));// ���f�����W���łǂ���������Ă��邩�Ŏ����ς��(�����-z�������Ă���ꍇ)
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
  /** �ɍ��W�ŃJ�����𓮂��� */
  mymath::Vector4 rstick_dir = { static_cast<float>(game.GetInput().GetRstickX()),0.0f,static_cast<float>(game.GetInput().GetRstickY()) };
  /** �ɍ��W���� */
  mymath::Polar3D came_pol = { game.GetCamera().GetFromTargetDirection() };
  float camera_speed = mymath::MyMathUtility::DegreeToRadian((rstick_dir.Lenght() * 0.005f) * game.GetDeltaTime());
  /** ���E */
  if( game.GetInput().GetRstickX() < -50 )
  {
    came_pol.PhiIncrement(camera_speed);
  }
  if( game.GetInput().GetRstickX() > 50 )
  {
    came_pol.PhiDecrement(camera_speed);
  }
  /** �㉺ */
  if( game.GetInput().GetRstickY() < -50 )
  {
    came_pol.ThetaIncrement(camera_speed);
  }
  if( game.GetInput().GetRstickY() > 50 )
  {
    came_pol.ThetaDecrement(camera_speed);
  }
  /** theta���N�����v���� */
  float theta = std::clamp(came_pol.GetTheta(),0.5f,3.0f);
  came_pol.SetTheta(theta);

  /** �J�����ɃZ�b�g */
  mymath::Vector4 pos = { 0.0f,100.0f,0.0f };//�v���C���[�̏�����Ƀ^�[�Q�b�g��u��
  mymath::Vector4 camera_target = position + pos;
  mymath::Vector4 camera_posi = came_pol.ToVector4() + camera_target;
  game.GetCamera().SetPosition(camera_posi);
  game.GetCamera().SetTarget(camera_target);
};
