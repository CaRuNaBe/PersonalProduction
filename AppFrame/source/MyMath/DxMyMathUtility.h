/*****************************************************************//**
 * \file   DxMyMathUtility.h
 * \brief  自分が使っている行列と3次元ベクトルをdxlibで使えるように変換
 * 　　　　する関数群を集めたファイル(定義)
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#pragma once
#include <DxLib.h>
namespace DxLib
{
  struct tagVECTOR;
  struct tagMATRIX;
}


namespace mymath
{
  class Vector4;
  class Matrix44;
}

namespace mymath
{
  /** Vector4からdxlibで使われるVECTORに変換 */
  DxLib::VECTOR ToDX(const mymath::Vector4& vector);
  /** VECTORからVector4にへんかん */
  mymath::Vector4 ToMyMath(const DxLib::VECTOR& vector);
  /** matrix44からdxlib用のMATRIXに変換 */
  DxLib::MATRIX ToDX(const mymath::Matrix44& matrix);
  /** MATRIXからmatrix44に変換 */
  mymath::Matrix44 ToMyMath(const DxLib::MATRIX& matrix);
}