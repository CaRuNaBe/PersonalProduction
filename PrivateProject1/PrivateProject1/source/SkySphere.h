/*****************************************************************//**
 * \file   SkySphere.h
 * \brief  スカイスフィアクラス(定義)
 * \author 阿部健太郎
 * \date   July 2023
 *********************************************************************/
#pragma once
#include "AppFrame.h"
class SkySphere : public GameBase
{
public:
  /** コンストラクタ */
  SkySphere(ApplicationBase& game,int layer);
  /** デストラクタ */
  virtual ~SkySphere();
  /** 更新関数 */
  virtual bool Update();
  /** 描画関数 */
  virtual bool Draw();
  /** デバッグ用描画関数 */
  virtual bool DebugDraw();
private:
  model::Mv1Model modele;
  /** 位置、回転、スケール */
  mymath::Matrix44 transform;
};

