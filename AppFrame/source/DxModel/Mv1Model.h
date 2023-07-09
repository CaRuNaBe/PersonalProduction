/*****************************************************************//**
 * \file   Mv1Model.h
 * \brief  dx���C�u������MV!���f���̏������܂Ƃ߂��N���X��`
 * \author ���������Y
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
  /** MV1���f���`��֐� */
  void Draw();
private:
  int mv1_model;
};