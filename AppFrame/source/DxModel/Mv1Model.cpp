/*****************************************************************//**
 * \file   Mv1Model.cpp
 * \brief  dxライブラリのMV!モデルの処理をまとめたクラス宣言
 * \author 阿部健太郎
 * \date   July 2023
 *********************************************************************/
#include "Mv1Model.h"
#include "DxLib.h"
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