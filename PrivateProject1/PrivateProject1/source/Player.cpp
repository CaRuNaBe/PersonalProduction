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
  /** �v���C���[��1�b�Ԃɓ������� */
  const float SPEED = 200;
  /** �J�����̃X�s�[�h */
  const float CAMERA_SPEED = 180.f;
}
Player::Player(ApplicationBase& game,int layer)
  :GameBase(game,layer)
  ,modele("res/player/SDChar.mv1")
{};

Player::~Player()
{};

bool Player::Update()
{
  /** �J�����̌��� */
  mymath::Vector4 camera_dir = game.GetCamera().GetFromCameraDirection();
  camera_dir.SetY(0.0f);//�����𖳎�
  /** ���͂̌��� */
  mymath::Vector4 controller_dir = { static_cast<float>(game.GetInput().GetLstickX()),0.0f,static_cast<float>(game.GetInput().GetLstickY()) };

  /** �J�����̌����x�N�g���Ɠ��͂̌����x�N�g�����l�����āA�v���C���[�̐i�s�����x�N�g�����v�Z */
  mymath::Vector4 player_forward = camera_dir * controller_dir.GetZ();
  mymath::Vector4 player_right = mymath::Vector4::Cross(mymath::VECTOR4_UP,camera_dir) * controller_dir.GetX();
  mymath::Vector4 player_velocity = player_forward + player_right;
  player_velocity.Normalized();

  /** �f���^�^�C���𑬂��ɂ����σt���[�����[�g�� */
  player_velocity *= (SPEED * game.GetDeltaTime());
  position += player_velocity;
  /** �v���C���[�𓮂��� */
  mymath::Matrix44 transform;
  transform.Scale(0.5f,0.5f,0.5f);
  mymath::Vector4 vRot = { 0,0,0 };
  vRot.SetY(atan2(player_velocity.GetX() * -1,player_velocity.GetZ() * -1));// ���f�����W���łǂ���������Ă��邩�Ŏ����ς��(�����-z�������Ă���ꍇ)
  transform.RotateX(vRot.GetX());
  transform.RotateY(vRot.GetY());
  transform.RotateZ(vRot.GetZ());
  transform.Transfer(position);

  modele.SetMatrix(transform);


  /** �ɍ��W�ŃJ�����𓮂��� */
  {
    /** �ɍ��W���� */
    mymath::Polar3D came_pol = { game.GetCamera().GetFromTargetDirection() };

    /** ���E */
    if( game.GetInput().GetRstickX() < -50 )
    {
      came_pol.PhiIncrement(mymath::MyMathUtility::DegreeToRadian(CAMERA_SPEED) * game.GetDeltaTime());
    }
    if( game.GetInput().GetRstickX() > 50 )
    {
      came_pol.PhiDecrement(mymath::MyMathUtility::DegreeToRadian(CAMERA_SPEED) * game.GetDeltaTime());
    }
    /** �㉺ */
    if( game.GetInput().GetRstickY() < -50 )
    {
      came_pol.ThetaIncrement(mymath::MyMathUtility::DegreeToRadian(CAMERA_SPEED) * game.GetDeltaTime());
    }
    if( game.GetInput().GetRstickY() > 50 )
    {
      came_pol.ThetaDecrement(mymath::MyMathUtility::DegreeToRadian(CAMERA_SPEED) * game.GetDeltaTime());
    }
    /** theta���N�����v���� */
    float theta = std::clamp(came_pol.GetTheta(),0.5f,3.0f);
    came_pol.SetTheta(theta);

    /** �J�����ɃZ�b�g */
    mymath::Vector4 pos = { 0.0f,100.0f,0.0f };//�v���C���[�̏�����Ƀ^�[�Q�b�g��u��
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