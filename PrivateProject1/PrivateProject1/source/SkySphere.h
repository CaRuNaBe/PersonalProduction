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
  Mv1Model modele;
};

