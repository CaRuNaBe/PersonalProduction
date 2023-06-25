/*****************************************************************//**
 * \file   MyMathUtility.h
 * \brief  自分が使う計算クラスのユーティリティの定義
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#pragma once
namespace mymath
{
  class Vector4;

  class MyMathUtility
  {
  public:
    /** ディグリー値ゼロ度 */
    static constexpr float DEGREES_ZERO = 0.0f;
    /** ディグリー値180度 */
    static constexpr float DEGREES_180 = 180.0f;
    /** ディグリー値360度 */
    static constexpr float DEGREES_360 = DEGREES_180 * 2.0f;
    /** 円周率 */
    static constexpr float PI = 3.14159265358979f;
    /** ラジアン値ゼロ */
    static constexpr float RADIANS_ZERO = 0.0f;
    /** ディグリー値360度の時のラジアン値 */
    static constexpr float TWOPI = PI * 2.0f;
    /** ディグリー値90度の時のラジアン値 */
    static constexpr float PIOVER2 = PI / 2.0f;
    /** ディグリー値からラジアン値に変換する関数 */
    static float DegreeToRadian(float degree);
    /** ラジアン値からディグリー値に変換する関数 */
    static float RadianToDegree(float radion);
    /** minからmaxのランダム値獲得関数(離散一様分布) */
    static int GetRandom(const int min,const int max);
    /** trueかfalseをランダム獲得(離散一様分布) */
    static bool get_random()
    {
      return GetRandom(1,2) == 1 ? true : false;
    }


  private:
    MyMathUtility() = default;
  };

  /** 二つの値の大きい値を取得 */
  template <typename T>
  T Max(const T& a,const T& b)
  {
    return (a < b ? b : a);
  }
  /** 二つの値の小さい値を取得 */
  template <typename T>
  T Min(const T& a,const T& b)
  {
    return (a < b ? a : b);
  }
  /** 二つの値の間でクランプする */
  template <typename T>
  T Clamp(const T& value,const T& lower,const T& upper)
  {
    return Min(upper,Max(lower,value));
  }
  /** 符号獲得関数 */
  template <typename T>
  T Sign(const T& num)
  {
    return static_cast<T>((num > 0) - (num < 0));
  }
  /** ステップ関数 */
  template <typename T>
  T Step(const T& num,const T& threshold)
  {
    return (num >= threshold);
  }
}
