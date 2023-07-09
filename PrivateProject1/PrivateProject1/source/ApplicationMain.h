/*****************************************************************//**
 * \file   ApplicationMain.h
 * \brief  ApplicationBaseを派生したクラス
 *         ここにゲームの中身を書いてく
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#include "AppFrame.h"



class ApplicationMain : public ApplicationBase
{
public:
  /** 初期化関数 */
  virtual bool Initialize();
  /** 終了関数 */
  virtual bool Terminate();
  /** インプットのアップデート関数 */
  virtual bool Input();
  /** ゲームのアップデート関数 */
  virtual bool Update();
  /** 描画関数 */
  virtual bool Draw();
  /** ウィンドウを開いていいか確認する関数 */
  virtual bool AppWindowed();
  /** ディスプレイ横の画素数を指定する関数 */
  virtual int DispSizeW();
  /** ディスプレイ縦画素数を指定する関数 */
  virtual int DispSizeH();

private:

};
