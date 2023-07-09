/*****************************************************************//**
 * \file   Mv1Model.cpp
 * \brief  dx���C�u������MV!���f���̏������܂Ƃ߂��N���X�錾
 * \author ���������Y
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