/*****************************************************************//**
 * @file   Polar3D.h
 * @brief  三次元極座標定義
 *
 * @author 阿部健太郎
 * @date   June 2023
 *********************************************************************/
#pragma once
namespace mymath
{
  class Vector4;
  class Polar3D
  {
  public:
    /** コンストラクタ群 */
    Polar3D();
    Polar3D(float radius,float theta,float phi);
    Polar3D(int radius,int theta,int phi);
    /** コンストラクタでVector4から極座標に変換 */
    Polar3D(const Vector4& vec);
    /** コピーコンストラクタ */
    Polar3D(const Polar3D&) = default;
    /** ムーブコンストラクタ */
    Polar3D(Polar3D&&) = default;
    /** デストラクタ */
    virtual ~Polar3D() = default;

    /** コピー代入 */
    Polar3D& operator =(const Polar3D&) = default;
    /** ムーブ代入 */
    Polar3D& operator =(Polar3D&&) = default;
    /** Vector4に変換 */
    Vector4 ToVector4();
    /** 極座標における半径をインクリメント */
    void RadiusIncrement(const float& radius);
    /** 極座標における半径をデクリメントただし0以下にはならない */
    void RadiusDecrement(const float& radius);
    /** 極座標における緯度(ラジアン)をインクリメント */
    void ThetaIncrement(const float& theta);
    /** 極座標における緯度(ラジアン)をデクリメント */
    void ThetaDecrement(const float& theta);
    /** 極座標における経度(ラジアン)をインクリメント */
    void PhiIncrement(const float& phi);
    /** 極座標における経度(ラジアン)をデクリメント */
    void PhiDecrement(const float& phi);

    /** 半径セット */
    void SetRadius(const float& radius)
    {
      this->radius = radius;
    }
    /** 緯度(ラジアン)セット */
    void SetTheta(const float& theta)
    {
      this->theta = theta;
    }
    /** 経度(ラジアン)セット */
    void SetPhi(const float& phi)
    {
      this->phi = phi;
    }
    /** Polar3Dからセット */
    void Set(const Polar3D& pol)
    {
      radius = pol.GetRadius();
      theta = pol.GetTheta();
      phi = pol.GetPhi();
    }
    /** 3個の値を同時にセット */
    void Set(const float& radius,const float& theta,const float& phi)
    {
      this->radius = radius;
      this->theta = theta;
      this->phi = phi;
    }
    /** 半径ゲット */
    float GetRadius()const
    {
      return radius;
    }
    /** 緯度(ラジアンをゲット */
    float GetTheta()const
    {
      return theta;
    }
    /** 経度(ラジアン)をゲット */
    float GetPhi()const
    {
      return phi;
    }
  private:
    /** 半径 */
    float radius;
    /** 緯度(ラジアン) */
    float theta;
    /** 経度(ラジアン) */
    float phi;
  };
}
