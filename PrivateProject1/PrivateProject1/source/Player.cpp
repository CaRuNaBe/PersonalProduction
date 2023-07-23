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
  constexpr float JUMP_INITIAL_SPEED = 1000.0f;
  constexpr float GRAVITY = 10;
  constexpr float ANIME_SPEED = 100;
  float player_speed = 0;

}

Player::Player(ApplicationBase& game,int layer,ModeGame& mode,std::string filename)
  :GameObject(game,layer,mode,filename)
  ,is_stand(false)
  ,velocity_y(0.0f)
  ,anim_state(AnimState::kNone)
  ,anime_total_time(0.0f)
  ,anime_play_time(0.0f)
  ,anime_attach_index(-1)
{};

Player::~Player()
{};

bool Player::Update()
{
  /** 処理前のステータスを保存しておく */
  AnimState old_status = anim_state;
  /** 何もしてなければアイドル */
  anim_state = AnimState::kIdle;
  PlayerMoves();
  GravityFalling();
  Jump();

  /** プレイヤーを動かす */
  mymath::Matrix44 transform;
  transform.Scale(0.5f,0.5f,0.5f);
  mymath::Vector4 vRot = { 0,0,0 };
  vRot.SetY(std::atan2(now_player_velocity.GetX() * -1,now_player_velocity.GetZ() * -1));// モデルが標準でどちらを向いているかで式が変わる(これは-zを向いている場合)
  if( player_speed > 0 )
  {
    now_direction = vRot;
  }

  transform.RotateX(now_direction.GetX());
  transform.RotateY(now_direction.GetY());
  transform.RotateZ(now_direction.GetZ());
  transform.Transfer(position);

  modele.SetMatrix(transform);

  CameraMoves();

  AnimeBranch(old_status);
  return true;
};

bool Player::Draw()
{
  DxLib::SetUseLighting(TRUE);
  modele.Draw();
  DxLib::SetUseLighting(FALSE);
  return true;
};

bool Player::DebugDraw()
{

  return true;
};

void Player::AnimeBranch(AnimState old_status)
{
  /** ステータスが変わっていないか？ */
  if( old_status == anim_state )
  {
    // 再生時間を進める
    anime_play_time += ANIME_SPEED * game.GetDeltaTime();
  }
  else
  {
    /** アニメーションがアタッチされていたら、デタッチする */
    if( anime_attach_index != -1 )
    {
      modele.DetachAnim(anime_attach_index);
      anime_attach_index = -1;
    }
    /** ステータスに合わせてアニメーションのアタッチ */
    switch( anim_state )
    {
      case AnimState::kIdle:
        anime_attach_index = modele.AttachAnim(static_cast<int>(AnimState::kIdle),-1,FALSE);
        break;
      case AnimState::kRun:
        anime_attach_index = modele.AttachAnim(static_cast<int>(AnimState::kRun),-1,FALSE);
        break;
      case AnimState::kAttack:
        anime_attach_index = modele.AttachAnim(static_cast<int>(AnimState::kAttack),-1,FALSE);
        break;
      case AnimState::kJumpStart:
        anime_attach_index = modele.AttachAnim(static_cast<int>(AnimState::kJumpStart),-1,FALSE);
        break;
      case AnimState::kJumpLoop:
        anime_attach_index = modele.AttachAnim(static_cast<int>(AnimState::kJumpLoop),-1,FALSE);
        break;
      case AnimState::kJumpEnd:
        anime_attach_index = modele.AttachAnim(static_cast<int>(AnimState::kJumpEnd),-1,FALSE);
        break;
      default:

        break;
    }
    /** アタッチしたアニメーションの総再生時間を取得する */
    anime_total_time = modele.GetAttachAnimTotalTime(anime_attach_index);
    /** 再生時間を初期化 */
    anime_play_time = 0.0f;
  }

  /** 再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す */
  if( anime_play_time >= anime_total_time )
  {
    anime_play_time = 0.0f;
  }

  modele.SetAttachAnimTime(anime_attach_index,anime_play_time);
};

void Player::PlayerMoves()
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

  /** デルタタイムを速さにかけ可変フレームレート化 */
  player_speed = (lstick_dir.Lenght() / 50.0f) * game.GetDeltaTime();
  player_velocity *= player_speed;
  if( is_stand )
  {
    /** 空中で進行方向を変えられないように */
    now_player_velocity = player_velocity;
  }

  if( now_player_velocity.Lenght() > 0 && is_stand )
  {
    /** 入力があり地面に立っていたら走る */
    anim_state = AnimState::kRun;
  }

  position += now_player_velocity;
}

void Player::CameraMoves()
{
  /** 極座標でカメラを動かす */
  /** 右スティックの情報 */
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

void Player::GravityFalling()
{
  float player_position_y = position.GetY();
  /** 地面についていない前提 */
  player_position_y += velocity_y * game.GetDeltaTime();
  velocity_y -= GRAVITY + (JUMP_INITIAL_SPEED * game.GetDeltaTime());
  is_stand = false;

  if( player_position_y <= 0 )
  {
    /** 地面についていた */
    is_stand = true;
    player_position_y = 0;
    velocity_y = 0.0f;
  }

  bool is_rising = velocity_y > 700;
  if( is_rising )
  {
    anim_state = AnimState::kJumpStart;
  }
  bool is_falling = velocity_y < -600;
  if( is_falling )
  {
    anim_state = AnimState::kJumpEnd;
  }
  if( !is_rising && !is_falling && !is_stand )
  {
    anim_state = AnimState::kJumpLoop;
  }

  position.SetY(player_position_y);
}

void Player::Jump()
{
  if( game.GetInput().GetTrgXinput(XinputButton::A) )
  {
    /** 地面に立っていなかったらジャンプしない */
    if( is_stand )
    {
      velocity_y = JUMP_INITIAL_SPEED;
    }
  }
};