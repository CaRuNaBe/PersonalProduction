/*****************************************************************//**
 * \file   ModeGame.h
 * \brief  ゲーム画面(定義)
 * \author 阿部健太郎
 * \date   July 2023
 *********************************************************************/
#pragma once
#include "AppFrame.h"
#include "GameObject.h"

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
  /** このモードで使われるオブジェクトのサーバーを取得 */
  GameServerShared<GameObject>& GetGameObjectServer()
  {
    return game_object;
  }
private:
  GameServerShared<GameObject> game_object;
};

