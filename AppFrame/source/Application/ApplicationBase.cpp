/*****************************************************************//**
 * \file   ApplicationBase.cpp
 * \brief  アプリフレームの基底クラスの宣言
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#include "ApplicationBase.h"
#include "DxLib.h"
ApplicationBase* ApplicationBase::lp_instance = NULL;

namespace
{
  static constexpr int Z_BUFFER_BIT_DEPTH = 32;
  static constexpr int COLOR_BIT_DEPTH = 32;
  /** システムが開始して経過した時間(1000で割ると秒になる) */
  int now_time = 0;
  /** 前の経過時間 */
  int time = 0;

  /** 今のリフレッシュレート */
  int fps = 0;
  /* 1フレームに1増加しディスプレイの設定したフレーム数になるととまりそれを描画する  */
  int fps_counter = 0;
  /** fpsを計測するときに使う前の経過時間 */
  int fps_check_time = 0;
}

ApplicationBase::ApplicationBase()
  : camera { DispSizeW(),DispSizeH() }
{
  lp_instance = this;
  is_game_end = false;
}

ApplicationBase::~ApplicationBase()
{}

bool ApplicationBase::Initialize()
{
#if _DEBUG
  /** デバッグモード時解放忘れがないか確認 */
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  /** DXライブラリの初期化 */
  if( AppWindowed() )
  {
    ChangeWindowMode(TRUE);/** ウィンドウモードに指定する */
  }
  /** zバッファのbit深度を変更 */
  SetZBufferBitDepth(Z_BUFFER_BIT_DEPTH);
  /** 画面サイズセット */
  SetGraphMode(DispSizeW(),DispSizeH(),COLOR_BIT_DEPTH);


  if( DxLib_Init() == -1 )
  {
    /** エラーが起きたら直ちに終了 */
    return false;
  }
  /** 描画先画面を裏画面にセット */
  SetDrawScreen(DX_SCREEN_BACK);

  /** Ｚバッファを有効にする */
  SetUseZBuffer3D(TRUE);

  /** Ｚバッファへの書き込みを有効にする */
  SetWriteZBuffer3D(TRUE);

  /** モードサーバの初期化 */
  base_server = std::make_shared<GameServerShared<GameBase>>();

  is_game_end = false;

  /** システム時間を取得しておく */
  time = GetNowCount();

  /** 最初の経過時間は仮に 0.00000f 秒にしておく */
  delta_time = 0.00000f;

  /** FPS計測関係の初期化 */
  fps_check_time = GetNowCount();
  fps = 0;
  fps_counter = 0;

  camera.SetAspect(DispSizeW(),DispSizeH());
  return true;
}

bool ApplicationBase::Terminate()
{
  /** DXライブラリ開放 */
  DxLib_End();
  return true;
}

bool ApplicationBase::Input()
{
  input.Update();
  return true;
}

bool ApplicationBase::Update()
{
  base_server->Update();
  camera.Update();
  return true;
}

bool ApplicationBase::Draw()
{
  /** フォグ設定 */
  SetFogEnable(TRUE);
  SetFogColor(255,255,205);
  SetFogStartEnd(5000.f,800000.f);
  /** 画面を初期化する */
  ClearDrawScreen();
  base_server->Draw();
  /** 0,0,0を中心に線を引く */
  {
    float linelength = 1000000.f;
    VECTOR v = { 0, 0, 0 };
    DrawLine3D(VAdd(v,VGet(-linelength,0,0)),VAdd(v,VGet(linelength,0,0)),GetColor(255,0,0));
    DrawLine3D(VAdd(v,VGet(0,-linelength,0)),VAdd(v,VGet(0,linelength,0)),GetColor(0,255,0));
    DrawLine3D(VAdd(v,VGet(0,0,-linelength)),VAdd(v,VGet(0,0,linelength)),GetColor(0,0,255));
  }
  FpsDraw();
  /** 裏画面の内容を表画面に反映させる */
  ScreenFlip();
  return true;
}

void ApplicationBase::DeltaTimeAndFpsMeasure()
{
  /** 現在のシステム時間を取得 */
  now_time = GetNowCount();

  /** 前回取得した時間からの経過時間を秒に変換してセット */
  /** (GetNowCount で取得できる値はマイクロ秒単位なので 1000 で割ることで秒単位になる) */
  delta_time = (now_time - time) / 1000.0f;

  /** 今回取得した時間を保存 */
  time = now_time;

  /** FPS関係の処理(1秒経過する間に実行されたメインループの回数を FPS とする) */
  fps_counter++;
  if( now_time - fps_check_time > 1000 )
  {
    fps = fps_counter;
    fps_counter = 0;
    fps_check_time = now_time;
  }
}

void ApplicationBase::FpsDraw()
{
  DrawFormatString(0,0,GetColor(255,255,255),"fps:%d",fps);
};

bool ApplicationBase::AppWindowed()
{
  return true;
}

int ApplicationBase::DispSizeW()
{
  return 640;
}

int ApplicationBase::DispSizeH()
{
  return 480;
}