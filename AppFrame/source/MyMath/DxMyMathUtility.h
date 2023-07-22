/*****************************************************************//**
 * \file   DxMyMathUtility.h
 * \brief  �������g���Ă���s���3�����x�N�g����dxlib�Ŏg����悤�ɕϊ�
 * �@�@�@�@����֐��Q���W�߂��t�@�C��(��`)
 * \author ���������Y
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
  /** Vector4����dxlib�Ŏg����VECTOR�ɕϊ� */
  DxLib::VECTOR ToDX(const mymath::Vector4& vector);
  /** VECTOR����Vector4�ɂւ񂩂� */
  mymath::Vector4 ToMyMath(const DxLib::VECTOR& vector);
  /** matrix44����dxlib�p��MATRIX�ɕϊ� */
  DxLib::MATRIX ToDX(const mymath::Matrix44& matrix);
  /** MATRIX����matrix44�ɕϊ� */
  mymath::Matrix44 ToMyMath(const DxLib::MATRIX& matrix);
}