/*****************************************************************//**
 * \file   Mv1Model.cpp
 * \brief  dxライブラリのMV!モデルの処理をまとめたクラス宣言
 * \author 阿部健太郎
 * \date   July 2023
 *********************************************************************/
#include "Mv1Model.h"
#include "DxLib.h"
#include "MyMath/Vector4.h"
#include "MyMath/DxMyMathUtility.h"
#include "MyMath/Matrix44.h"
namespace model
{
  Mv1Model::Mv1Model(std::string&& filename)
  {
    mv1_model = MV1LoadModel(filename.c_str());
  }


  Mv1Model::~Mv1Model()
  {
    MV1DeleteModel(mv1_model);
  }

  void Mv1Model::Draw()
  {
    MV1DrawModel(mv1_model);
  }

  bool Mv1Model::SetPosition(const mymath::Vector4& position)
  {
    return MV1SetPosition(mv1_model,mymath::ToDX(position));
  }

  bool Mv1Model::SetSetScale(const mymath::Vector4& scale)
  {
    return MV1SetScale(mv1_model,mymath::ToDX(scale));
  }

  bool Mv1Model::SetRotation(const mymath::Vector4& rotation)
  {
    return MV1SetRotationXYZ(mv1_model,mymath::ToDX(rotation));
  }

  bool Mv1Model::SetMatrix(const mymath::Matrix44& parameter)
  {
    return MV1SetMatrix(mv1_model,mymath::ToDX(parameter));
  }
}