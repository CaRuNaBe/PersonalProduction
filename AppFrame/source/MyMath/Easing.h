/*****************************************************************//**
 * \file   Easing.h
 * \brief  イージング関数をまとめたクラス定義
 * \author 阿部健太郎
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
    /** イージング関数のラムダを取得する */
    static EasingMode GetMode( const std::string& mode )
    {
      return _modes.at( mode );
    }
  private:
    static const EasingMap _modes;
  };
}
