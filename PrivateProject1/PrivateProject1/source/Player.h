/*****************************************************************//**
 * \file   Player.h
 * \brief  プレイヤークラス(定義)
 * \author 阿部健太郎
 * \date   July 2023
 *********************************************************************/
#pragma once
#include "AppFrame.h"
#include "string"
#include "ObjectBase3d.h"
#include "ModeGame.h"
class Player : public ObjectBase3d
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
  enum class Status
  {
    WAIT,
    MOVE
  };
  /** このプレイヤーの状態 */
  Status status;
  /** カメラ動かすための関数 */
  void CameraMoves();
};




