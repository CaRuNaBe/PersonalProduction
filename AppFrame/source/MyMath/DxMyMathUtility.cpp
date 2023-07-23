/*****************************************************************//**
 * \file   DxMyMathUtility.cpp
 * \brief  �������g���Ă���s���3�����x�N�g����dxlib�Ŏg����悤�ɕϊ�
 *         ����֐��Q���W�߂��t�@�C��(�錾)
 * \author ���������Y
 * \date   June 2023
 *********************************************************************/
#include "DxMyMathUtility.h"
#include "Vector4.h"
#include "Matrix44.h"
namespace mymath
{
  DxLib::VECTOR ToDX(const mymath::Vector4& vector)
  {
    return DxLib::VGet(static_cast<float>(vector.GetX()),static_cast<float>(vector.GetY()),static_cast<float>(vector.GetZ()));
  }

  mymath::Vector4 ToMyMath(const DxLib::VECTOR& vector)
  {
    return mymath::Vector4(static_cast<float>(vector.x),static_cast<float>(vector.y),static_cast<float>(vector.z));
  }

  DxLib::MATRIX ToDX(const mymath::Matrix44& matrix)
  {
    DxLib::MATRIX ret;

    for( auto i = 0; i < mymath::row_max; ++i )
    {
      for( auto j = 0; j < mymath::column_max; ++j )
      {
        ret.m[i][j] = static_cast<float>(matrix.GetValue(i,j));
      }
    }

    return ret;
  }

  mymath::Matrix44 ToMyMath(const DxLib::MATRIX& matrix)
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