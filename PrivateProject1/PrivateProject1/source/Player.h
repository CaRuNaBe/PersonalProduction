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
  /** 床の上に立っていたらtrue */
  bool is_stand;
  /** プレイヤーのyの向き */
  float velocity_y;
  /** カメラ動かすための関数 */
  void CameraMoves();
  /** ジャンプと重力処理 */
  void Jump();
  /** 今の進行方向 */
  mymath::Vector4 now_player_velocity;
};




