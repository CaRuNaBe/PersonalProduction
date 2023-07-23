/*****************************************************************//**
 * \file   Player.h
 * \brief  プレイヤークラス(定義)
 * \author 阿部健太郎
 * \date   July 2023
 *********************************************************************/
#pragma once
#include "AppFrame.h"
#include "string"
#include "GameObject.h"
#include "ModeGame.h"
class Player : public GameObject
{
public:
  /** コンストラクタ */
  Player(ApplicationBase& game,int layer,ModeGame& mode,std::string filename);
  /** デストラクタ */
  virtual ~Player();
  /** 更新関数 */
  virtual bool Update();
  /** 描画関数 */
  virtual bool Draw();
  /** デバッグ用描画関数 */
  virtual bool DebugDraw();
private:
  /** アニメーションの番号一覧 */
  enum class AnimState
  {
    kIdle,      //待機
    kRun,       //走り
    kAttack,    //攻撃
    kJumpStart, //ジャンプのはじめ
    kJumpLoop,  //ジャンプ中
    kJumpEnd,   //ジャンプ終わり
    kNone       //なし
  };
  /** アニメーションステート */
  AnimState anim_state;
  /** 床の上に立っていたらtrue */
  bool is_stand;
  /** プレイヤーのyの向き */
  float velocity_y;
  /** アニメーション遷移 */
  void AnimeBranch(AnimState old_status);
  /** カメラ動かすための関数 */
  void CameraMoves();
  /** プレイヤーを動かす関数 */
  void PlayerMoves();
  /** ジャンプ処理 */
  void Jump();
  /** 重力処理 */
  void GravityFalling();
  /** 今の進行方向 */
  mymath::Vector4 now_player_velocity;
  /** アニメの総再生時間 */
  float anime_total_time;
  /** アニメの再生時間 */
  float anime_play_time;
  /** アタッチされているアニメ */
  int anime_attach_index;
};




