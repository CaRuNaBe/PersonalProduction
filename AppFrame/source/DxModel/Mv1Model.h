/*****************************************************************//**
 * \file   Mv1Model.h
 * \brief  dxライブラリのMV!モデルの処理をまとめたクラス定義
 * \author 阿部健太郎
 * \date   July 2023
 *********************************************************************/
#pragma once
#include <string>

namespace mymath
{
  class Vector4;
}
 
class Mv1Model
{
public:
  Mv1Model(std::string&& filename);
  ~Mv1Model();
  /** MV1モデル描画関数 */
  void Draw();
private:
  int mv1_model;
};