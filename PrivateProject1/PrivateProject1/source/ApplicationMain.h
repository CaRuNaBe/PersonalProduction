/*****************************************************************//**
 * \file   ApplicationMain.h
 * \brief  ApplicationBaseを派生したクラス(定義)
 *         ここにゲームの中身を書いてく
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#include "AppFrame.h"
class ApplicationMain : public ApplicationBase
{
public:
  /** 初期化関数 */
  virtual bool Initialize()override;
  /** ウィンドウを開いていいか確認する関数 */
  virtual bool AppWindowed()override;
  /** ディスプレイ横の画素数を指定する関数 */
  virtual int DispSizeW()override;
  /** ディスプレイ縦画素数を指定する関数 */
  virtual int DispSizeH()override;
private:
};