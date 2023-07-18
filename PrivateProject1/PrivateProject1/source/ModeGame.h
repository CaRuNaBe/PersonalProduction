/*****************************************************************//**
 * \file   ModeGame.h
 * \brief  ゲーム画面(定義)
 * \author 阿部健太郎
 * \date   July 2023
 *********************************************************************/
#pragma once
#include "AppFrame.h"
#include "ObjectBase3d.h"

class ModeGame :public GameBase
{
public:
  /** コンストラクタ */
  ModeGame(ApplicationBase& game,int layer);
  /** デストラクタ */
  virtual ~ModeGame();
  /** 更新関数 */
  virtual bool Update();
  /** 描画関数 */
  virtual bool Draw();
  /** デバッグ用描画関数 */
  virtual bool DebugDraw();
  GameServerShared<ObjectBase3d>& GetObjectBase3dServer()
  {
    return game_object;
  }
private:
  GameServerShared<ObjectBase3d> game_object;
};

