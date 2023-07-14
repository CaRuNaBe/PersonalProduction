/*****************************************************************//**
 * \file   Matrix44.h
 * \brief  行列クラス定義
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#pragma once

#include <array>
#include <tuple>

namespace mymath
{
  class Vector4;
  /** 行数の最大値 */
  constexpr auto row_max = 4;
  /** 列数の最大値 */
  constexpr auto column_max = 4;
  /** std::arrayを二次元配列として別名定義 */
  using MatrixArray = std::array<std::array<float,row_max>,column_max>;

  class Matrix44
  {
  public:
    /** Matrix44単位行列にして初期化 */
    Matrix44();
    /** Matrix44をMatrixArrayをいれて初期化 */
    Matrix44(const MatrixArray values);
    /** コピーコンストラクタ */
    Matrix44(const Matrix44&) = default;
    /** ムーブコンストラクタ */
    Matrix44(Matrix44&&) = default; 

    /** デストラクタ */
    virtual ~Matrix44() = default;
    /** コピー代入 */
    Matrix44& operator =(const Matrix44&) = default;
    /** ムーブ代入 */
    Matrix44& operator =(Matrix44&&) = default; 
    /** 行列の掛け算 */
    const Matrix44 operator *(const Matrix44& rhs) const;
    /** 行列とベクトルのかけ算 */
    const Matrix44 operator +(const Vector4& rhs) const;
    /** 行列から指定の値を入手ただし配列なので0から3で指定する */
    float GetValue(const int row,const int column) const
    {
      return row_column[row][column];
    }
    /** 行列の指定の場所に値を入れるただし配列なので0から3で指定する */
    void SetValue(const int row,const int column,const float value)
    {
      row_column[row][column] = value;
    }
    /** すべての値を0.0f初期化 */
    void Zero(MatrixArray& target) const;
    /** すべての値を0.0f初期化にしたうえで単位ベクトル化 */
    void Unit();
    /** 行列式を行う */
    float Determinant() const;
    /** 正則行列を得る */
    Matrix44 GetInverse() const;

    /** targetに向くベクトルと姿勢回転の行列を作る */
    void LookAt(const Vector4& position,const Vector4& target,const Vector4& up);
    /** 初期化してから射影変換行列を作成 */
    void Perspective(const float fov_y,const float aspect,const float near_z,const float far_z);
    /** 初期化し単位化させてからビューポート行列を作成 */
    void Viewport(const float width,const float height);

    /** それぞれ値に移動した並行移動行列にするis_remakeがtrueの時初期化し単位化させてから並行行列にする */
    void Transfer(const float x,const float y,const float z,bool is_remake = false);
    /** Vector4のxyzの値をいれ並行移動行列にするis_remakeがtrueの時初期化し単位化させてから並行行列にする */
    void Transfer(const mymath::Vector4& transfer,bool is_remake = false);
    /** それぞれの拡大した行列にするis_remakeがtrueの時初期化し単位化させてから拡大行列にする */
    void Scale(const float x,const float y,const float z,bool is_remake = false);
    /** x軸で回転した行列にするis_remakeがtrueの時初期化し単位化させてからx軸回転する */
    void RotateX(const float radians,bool is_remake = false);
    /** y軸で回転した行列にするis_remakeがtrueの時初期化し単位化させてからy軸回転する */
    void RotateY(const float radians,bool is_remake = false);
    /** z軸で回転した行列にするis_remakeがtrueの時初期化し単位化させてからz軸回転する */
    void RotateZ(const float radians,bool is_remake = false);
    /** 回転行列を取得 */
    Matrix44 GetRotate() const;
    /** 行列の並行移動をつかさどる部分からVector4で取得 */
    mymath::Vector4 GetTransfer()const;
  private:
    /** tupleでsinとcosの値を取得 */
    std::tuple<float,float> GetSinCos(const float radians) const;
    /** 4*4の配列 */
    MatrixArray row_column;
  };
}
