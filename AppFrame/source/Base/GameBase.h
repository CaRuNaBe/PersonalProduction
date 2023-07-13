/*****************************************************************//**
 * \file   GameBase.h
 * \brief  ゲームに登場するものの基底クラス作るときここから派生させ
 *         なければならない
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#pragma once
class ApplicationBase;
namespace mymath
{
  class Matrix44;
}

class GameBase
{
public:
  /** コンストラクタ */
  GameBase(ApplicationBase& _game,int layer)
    : game(_game)
    ,is_dead(false)
    ,is_update_skip(false)
    ,is_draw_skip(false)
    ,layer(layer)
    ,cnt(0)
  {}
  /** デストラクタ */
  virtual ~GameBase()
  {};
  /** 更新関数 */
  virtual bool Update() = 0;
  /** 描画関数 */
  virtual bool Draw() = 0;
  /** デバッグ用描画関数 */
  virtual bool DebugDraw() = 0;
  /** 死んだか取得 */
  virtual bool IsDead()
  {
    return is_dead;
  }
  /** 死んだ */
  virtual void Dead()
  {
    is_dead = true;
  }
  /** アップデートスキップ取得 */
  virtual bool GetUpdateSkip()
  {
    return is_update_skip;
  }
  /** セットアップデートスキップ */
  virtual void SetUpdateSkip(bool update_skip)
  {
    is_update_skip = update_skip;
  }
  /** 描画スキップ変数取得 */
  virtual bool GetDrawSkip()
  {
    return is_draw_skip;
  }
  /** セット描画スキップ */
  virtual void SetDrawSkip(bool draw_skip)
  {
    is_draw_skip = draw_skip;
  }
  /** レイヤーゲット */
  virtual int GetLayer()
  {
    return layer;
  }

protected:
  /** ApplicationBaseの参照 */
  ApplicationBase& game;
  /** このオブジェクトが死んだらtrue */
  bool is_dead;
  /** 更新したくないときtrue */
  bool is_update_skip;
  /** 描画したくないときtrue */
  bool is_draw_skip;
  /** 更新,描画順の指定数が少ないと先に更新される */
  int layer;
  /** カウント変数 */
  int cnt;
};

