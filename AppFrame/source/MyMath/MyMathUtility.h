/*****************************************************************//**
 * \file   MyMathUtility.h
 * \brief  自分が使う計算クラスのユーティリティの定義
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#pragma once
namespace mymath
{
  /** ディグリー値ゼロ度 */
  constexpr float DEGREES_ZERO = 0.0f;
  /** ディグリー値180度 */
  constexpr float DEGREES_180 = 180.0f;
  /** ディグリー値360度 */
  constexpr float DEGREES_360 = DEGREES_180 * 2.0f;
  /** 円周率 */
  constexpr float PI = 3.14159265358979f;
  /** ラジアン値ゼロ */
  constexpr float RADIANS_ZERO = 0.0f;
  /** ディグリー値360度の時のラジアン値 */
  constexpr float TWOPI = PI * 2.0f;
  /** ディグリー値90度の時のラジアン値 */
  constexpr float PIOVER2 = PI / 2.0f;

  /** 符号獲得関数 */
  template <typename T>
  T Sign(const T& num)
  {
    auto zero = static_cast<T>(0);
    return static_cast<T>((num > zero) - (num < zero));
  }
  /** ステップ関数 */
  template <typename T>
  bool Step(const T& num,const T& edge)
  {
    return (num >= edge);
  }
  class MyMathUtility
  {
  public:
    /** ディグリー値からラジアン値に変換する関数 */
    static float DegreeToRadian(float degree);
    /** ラジアン値からディグリー値に変換する関数 */
    static float RadianToDegree(float radion);
    /** minからmaxのランダム値獲得関数(離散一様分布) */
    static int GetRandom(const int min,const int max);
    /** trueかfalseをランダム獲得(離散一様分布) */
    static bool GetRandom();
  private:
    MyMathUtility() = default;
  };
}
