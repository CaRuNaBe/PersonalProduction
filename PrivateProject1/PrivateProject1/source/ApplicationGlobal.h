/*****************************************************************//**
 * \file   ApplicationGlobal.h
 * \brief  グローバル変数や関数をまとめておくクラスの定義
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#include "AppFrame.h"
class ApplicationGlobal
{
public:
  /** コンストラクタ */
  ApplicationGlobal();
  /** デストラクタ */
  virtual ~ApplicationGlobal();
  /** 初期関数 */
  bool Initialize();
private:
};
/** 他のソースでgGlobalを使えるように */
extern ApplicationGlobal gGlobal;