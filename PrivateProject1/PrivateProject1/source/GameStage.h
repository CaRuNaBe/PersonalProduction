/*****************************************************************//**
 * \file   GameStage.h
 * \brief  ステージ土台のクラスの定義
 *
 * \author 阿部健太郎
 * \date   July 2023
 *********************************************************************/
#pragma once
#include "AppFrame.h"
#include "string"
#include "GameObject.h"
#include "ModeGame.h"
class GameStage : public GameObject
{
public:
  /** コンストラクタ */
  GameStage(ApplicationBase& game,int layer,ModeGame& mode,std::string filename);
  /** デストラクタ */
  virtual ~GameStage();
  /** 更新関数 */
  virtual bool Update();
  /** 描画関数 */
  virtual bool Draw();
  /** デバッグ用描画関数 */
  virtual bool DebugDraw();
private:
};

