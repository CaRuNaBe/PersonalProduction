/*****************************************************************//**
 * \file   ObjectBase3d.h
 * \brief  3dオブジェクトの基底クラス(定義)
 * \author 阿部健太郎
 * \date   July 2023
 *********************************************************************/
#pragma once
#include "AppFrame.h"
#include "string"
class ModeGame;

class ObjectBase3d :public GameBase
{
public:
  /** コンストラクタ */
  ObjectBase3d(ApplicationBase& game,int layer,ModeGame& mode,std::string filename);
  /** デストラクタ */
  virtual ~ObjectBase3d();
  /** 更新関数 */
  virtual bool Update() ;
  /** 描画関数 */
  virtual bool Draw() ;
  /** デバッグ用描画関数 */
  virtual bool DebugDraw() ;
protected:
  ModeGame& mode_game;
  /** プレイヤーの3dモデル */
  model::Mv1Model modele;
  /** 位置 */
  mymath::Vector4 position;
  /** 今向いている方向の保存場所 */
  mymath::Vector4 old_direction;
};

