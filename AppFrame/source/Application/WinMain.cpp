/*****************************************************************//**
 * \file   WinMain.cpp
 * \brief  エントリーポイント
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#include "AppFrame.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR lpCmdLine,_In_ int nShowCmd)
{
  /** Log出力を行わない */
  DxLib::SetOutApplicationLogValidFlag(FALSE);
  /** アプリケーションのインスタンをゲット */
  auto app_base = ApplicationBase::GetInstance();
  /** nullであれば終了 */
  if( !app_base )
  {
    return 0;
  }
  /** 初期化 失敗した場合終了 */
  if( !app_base->Initialize() )
  {
    return 0;
  }

  /** 1フレームループを組む */
  while( DxLib::ProcessMessage() == 0 )// プログラムが終了するまでループ
  {
    app_base->Input();

    if( !app_base->Update() )
    {
      break;
    };
    app_base->Draw();
    app_base->DeltaTimeAndFpsMeasure();
#if _DEBUG
    /** escキーが押されたらゲーム終了 */
    if( DxLib::CheckHitKey(KEY_INPUT_ESCAPE) )
    {
      break;
    }
#endif
  }

  app_base->Terminate();

  return 0;
}
