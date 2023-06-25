/*****************************************************************//**
 * \file   MyMathUtility.cpp
 * \brief  自分が使う計算クラスのユーティリティの宣言
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#include <random>
#include <cmath>
#include "Vector4.h"
#include "MyMathUtility.h"

namespace
{
  /** ランダムの種 */
  std::random_device seed_gen;
  /** 64ビット版のメルセンヌ・ツイスター法で使用 */
  std::mt19937_64 random(seed_gen());
}

namespace mymath
{
  int MyMathUtility::GetRandom(const int min,const int max)
  {
    std::uniform_int_distribution<int>  distr(min,max);
    return distr(random);
  }

  float MyMathUtility::DegreeToRadian(float degree)
  {
    return degree * PI / DEGREES_180;
  }

  float MyMathUtility::RadianToDegree(float radion)
  {
    return radion * DEGREES_180 / PI;
  }
}
