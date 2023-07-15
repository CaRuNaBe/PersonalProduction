/*****************************************************************//**
 * \file   Player.h
 * \brief  プレイヤークラス(定義)
 * \author 阿部健太郎
 * \date   July 2023
 *********************************************************************/
#pragma once
#include "AppFrame.h"
class Player : public GameBase
{
public:
  /** コンストラクタ */
  Player(ApplicationBase& game,int layer);
  /** デストラクタ */
  virtual ~Player();
  /** 更新関数 */
  virtual bool Update();
  /** 描画関数 */
  virtual bool Draw();
  /** デバッグ用描画関数 */
  virtual bool DebugDraw();
private:
  /** プレイヤーの3dモデル */
  model::Mv1Model modele;
  /** プレイヤーの位置 */
  mymath::Vector4 position;
};




