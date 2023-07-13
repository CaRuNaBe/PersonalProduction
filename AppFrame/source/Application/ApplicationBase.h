/*****************************************************************//**
 * \file   ApplicationBase.h
 * \brief  アプリフレームの基底クラスの定義
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#pragma once

#include <memory>
#include "../Base/GameBase.h"
#include "../Base/GameServerShared.h"
#include "InputManager.h"
 // カメラ
class Camera
{
public:
  VECTOR _vPos;// 位置
  VECTOR _vTarget; // 距離
  float _clipNear,_clipFar;// クリップ
};

class ApplicationBase
{
public:
  /** コンストラクタ */
  ApplicationBase();
  /** デストラクタ */
  virtual ~ApplicationBase();
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
  /** delta_timeとfpsの計測関数 */
  void DeltaTimeAndFpsMeasure();
  /** リフレッシュレートを文字描画 */
  void FpsDraw();
  /** 静的インスタンスをゲット関数 */
  static ApplicationBase* GetInstance()
  {
    return lp_instance;
  }
  /** ゲームモード管理クラス取得 */
  std::shared_ptr<GameServerShared<GameBase>> GetModeServer()
  {
    return base_server;
  }

  /** 入力取得 */
  InputManager& GetInput()
  {
    return input;
  }
  /** ゲームを終わらせるときに呼ぶ関数 */
  void IsGameEnd()
  {
    is_game_end = true;
  }
  /** デルタタイムを取得(変更不可) */
  const float& GetDeltaTime()const
  {
    return delta_time;
  }
protected:
  /** このクラスはアプリケーションクラスの基底クラスなのでインスタンスをstaticにしあとで上書きされるようにする */
  static ApplicationBase* lp_instance;
  /** オブジェクト追加管理するクラスのインスタンス */
  std::shared_ptr<GameServerShared<GameBase>> base_server;
  /** inputクラスインスタス */
  InputManager input;
  /** ゲームが終わるときtrue */
  bool is_game_end;
  /** 可変フレームレート前回のフレームから何秒立ったか */
  float delta_time;
  // カメラ
  Camera _cam;

};
