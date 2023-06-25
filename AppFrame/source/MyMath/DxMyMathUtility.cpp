/*****************************************************************//**
 * \file   DxMyMathUtility.cpp
 * \brief  自分が使っている行列と3次元ベクトルをdxlibで使えるように変換
 * 　　　　する関数群を集めたファイル(宣言)
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#include "DxMyMathUtility.h"
#include "Vector4.h"
#include "Matrix44.h"

namespace mymath
{
  VECTOR ToDX(mymath::Vector4& vector)
  {
    return VGet(static_cast<float>(vector.GetX()),static_cast<float>(vector.GetY()),static_cast<float>(vector.GetZ()));
  }

  mymath::Vector4 ToMyMath(VECTOR& vector)
  {
    return mymath::Vector4(static_cast<float>(vector.x),static_cast<float>(vector.y),static_cast<float>(vector.z));
  }

  MATRIX ToDX(mymath::Matrix44& matrix)
  {
    MATRIX ret;

    for( auto i = 0; i < mymath::row_max; ++i )
    {
      for( auto j = 0; j < mymath::column_max; ++j )
      {
        ret.m[i][j] = static_cast<float>(matrix.GetValue(i,j));
      }
    }

    return ret;
  }

  mymath::Matrix44 ToMyMath(MATRIX& matrix)
  {
    mymath::Matrix44 ret;

    for( auto i = 0; i < mymath::row_max; ++i )
    {
      for( auto j = 0; j < mymath::column_max; ++j )
      {
        ret.SetValue(i,j,static_cast<float>(matrix.m[i][j]));
      }
    }

    return ret;
  }

}