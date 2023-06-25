/*****************************************************************//**
 * \file   Easing.h
 * \brief  �C�[�W���O�֐����܂Ƃ߂��N���X��`
 * \author ���������Y
 * \date   June 2023
 *********************************************************************/
#pragma once
#include <string>
#include <unordered_map>
#include <functional>
#include "MyMathUtility.h"
namespace mymath
{
  using EasingMode = std::function<float( float,float,float,float )>;
  using EasingMap = std::unordered_map<std::string,EasingMode>;

  class Easing
  {
  public:
    /** �C�[�W���O�֐��̃����_���擾���� */
    static EasingMode GetMode( const std::string& mode )
    {
      return _modes.at( mode );
    }
  private:
    static const EasingMap _modes;
  };
}
