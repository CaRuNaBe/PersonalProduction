/*****************************************************************//**
 * \file   ApplicationBase.cpp
 * \brief  アプリフレームの基底クラスの宣言
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#include "ApplicationBase.h"
ApplicationBase* ApplicationBase::lp_Instance = NULL;

namespace
{
  static constexpr int z_buffer_bit_depth = 32;
  static constexpr int color_bit_depth = 32;
}

ApplicationBase::ApplicationBase()
{
  lp_Instance = this;
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
  SetZBufferBitDepth(z_buffer_bit_depth);
  /** 画面サイズセット */
  SetGraphMode(DispSizeW(),DispSizeH(),color_bit_depth);


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
  return true;
}

bool ApplicationBase::Draw()
{
  /** 画面を初期化する */
  ClearDrawScreen();
  base_server->Draw();
  /** 裏画面の内容を表画面に反映させる */
  ScreenFlip();
  return true;
}

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