/*****************************************************************//**
 * \file   Vector4.h
 * \brief  四次元ベクトル定義
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#pragma once
namespace mymath
{
  class Matrix44;
  class Polar3D;

  class Vector4
  {
  public:
    /** コンストラクタ群 */
    Vector4();
    Vector4(float x,float y,float z);
    Vector4(float x,float y,float z,float w);
    Vector4(int x,int y,int z);
    Vector4(int x,int y,int z,int w);
    /** 三次元極座標からコンストラクタで変換 */
    Vector4(const Polar3D& pol);

    /** コピーコンストラクタ */
    Vector4(const Vector4&) = default;
    /** ムーブコンストラクタ */
    Vector4(Vector4&&) = default;

    /** デストラクタ */
    virtual ~Vector4() = default;

    /** コピー代入 */
    Vector4& operator =(const Vector4&) = default;
    /** ムーブ代入 */
    Vector4& operator =(Vector4&&) = default;

    /** ベクトルの加算 a + b */
    Vector4 operator +(const Vector4& rhs) const;
    /** ベクトルの減算 a - b */
    Vector4 operator -(const Vector4& rhs) const;
    /** ベクトルのかけ算 a * b */
    Vector4 operator *(const Vector4& rhs) const;
    /** ベクトルのスカラー倍 v * scalar */
    Vector4 operator *(const float& rhs) const;
    /** ベクトルのスカラー割 v / scalar */
    Vector4 operator /(const float& rhs) const;
    /** ベクトル加算代入 */
    Vector4& operator+=(const Vector4& right);
    /** ベクトル減算代入 */
    Vector4& operator-=(const Vector4& right);
    /** ベクトルのスカラ乗算代入 */
    Vector4& operator*=(float scalar);

    /** ベクトルの行列変換 オペレータ */
    Vector4 operator *(const Matrix44 rhs) const;
    /** ベクトルの大きさをゲット */
    float Lenght(const Vector4& second = { 0,0,0 }) const;
    /** このベクトルを正規化 */
    void Normalized();
    /** 正規化したベクトルをゲット */
    Vector4 GetNormalize() const;
    /** ベクトルの内積(Dot product) a・b */
    float Dot(const Vector4& rhs) const;
    /** ベクトルの外積(Cross product) a×b */
    Vector4 Cross(const Vector4& rhs) const;
    /** 線形補間(静的関数) */
    static Vector4 Lerp(const Vector4& start,const Vector4& end,float amount);
    /** xをゲット */
    float GetX()const
    {
      return x;
    }
    /** yをゲット */
    float GetY()const
    {
      return y;
    }
    /** zをゲット */
    float GetZ()const
    {
      return z;
    }
    /** wをゲット */
    float GetW()const
    {
      return w;
    }
    /** xセット */
    void SetX(const float& x)
    {
      this->x = x;
    }
    /** yセット */
    void SetY(const float& y)
    {
      this->y = y;
    }
    /** zセット */
    void SetZ(const float& z)
    {
      this->z = z;
    }
    /** wセット */
    void SetW(const float& w)
    {
      this->w = w;
    }
  private:
    /* 成分 */
    /** +x右側 */
    float x;
    /** +yで上側 */
    float y;
    /** +zで奥 */
    float z;
    float w;
  };
} // mymath
