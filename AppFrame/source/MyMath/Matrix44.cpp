/*****************************************************************//**
 * \file   Matrix44.cpp
 * \brief  行列クラス宣言
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#include <cmath>
#include "MyMathUtility.h"
#include "Matrix44.h"
#include "Vector4.h"

namespace mymath
{
  Matrix44::Matrix44()
  {
    Unit();
  }

  Matrix44::Matrix44(const MatrixArray values)
  {
    this->row_column = values;
  }

  void Matrix44::Zero(MatrixArray& target) const
  {
    for( auto i = 0; i < column_max; ++i )
    {
      target[i].fill(0.0f);
    }
  }

  void Matrix44::Unit()
  {
    Zero(row_column);
    /** 単位化 */
    for( auto i = 0; i < column_max; ++i )
    {
      row_column[i][i] = 1.0;
    }
  }

  float Matrix44::Determinant() const
  {
    /** 上三角行列を作成して行列式を求める */
    MatrixArray upper_triangular = row_column;

    for( auto i = 0; i < column_max; ++i )
    {
      for( auto j = 0; j < row_max; ++j )
      {
        if( i >= j )
        {
          continue;
        }

        auto coefficient = upper_triangular[j][i] / upper_triangular[i][i];

        for( auto k = 0; k < row_max; ++k )
        {
          upper_triangular[j][k] -= upper_triangular[i][k] * coefficient;
        }
      }
    }

    auto determinant = 1.0f;

    for( auto i = 0; i < column_max; ++i )
    {
      determinant *= upper_triangular[i][i];
    }

    return determinant;
  }

  Matrix44 Matrix44::GetInverse() const
  {
    /** 掃き出し法による逆行列の計算 */
    MatrixArray inverse { {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}} };
    MatrixArray temporary = row_column;

    for( auto i = 0; i < column_max; ++i )
    {
      auto coefficient = 1.0f / temporary[i][i];

      for( auto j = 0; j < row_max; ++j )
      {
        temporary[i][j] *= coefficient;
        inverse[i][j] *= coefficient;
      }

      for( auto j = 0; j < row_max; ++j )
      {
        if( i == j )
        {
          continue;
        }

        coefficient = temporary[j][i];

        for( auto k = 0; k < row_max; ++k )
        {
          temporary[j][k] -= temporary[i][k] * coefficient;
          inverse[j][k] -= inverse[i][k] * coefficient;
        }
      }
    }

    return Matrix44(inverse);
  }

  void Matrix44::LookAt(const Vector4& position,const Vector4& target,const Vector4& up)
  {
    auto axis_z = target - position;
    auto axis_x = up.Cross(axis_z);
    auto axis_y = axis_z.Cross(axis_x);

    axis_x.Normalized();
    axis_y.Normalized();
    axis_z.Normalized();

    row_column[0][0] = axis_x.GetX();
    row_column[0][1] = axis_y.GetX();
    row_column[0][2] = axis_z.GetX();
    row_column[0][3] = 0.0;

    row_column[1][0] = axis_x.GetY();
    row_column[1][1] = axis_y.GetY();
    row_column[1][2] = axis_z.GetY();
    row_column[1][3] = 0.0;

    row_column[2][0] = axis_x.GetZ();
    row_column[2][1] = axis_y.GetZ();
    row_column[2][2] = axis_z.GetZ();
    row_column[2][3] = 0.0;

    row_column[3][0] = -axis_x.Dot(position);
    row_column[3][1] = -axis_y.Dot(position);
    row_column[3][2] = -axis_z.Dot(position);
    row_column[3][3] = 1.0;
  }

  void Matrix44::Perspective(const float fov_y,const float aspect,const float near_z,const float far_z)
  {
    auto cot = 1.0f / tan(fov_y * 0.5f);
    auto range = far_z - near_z;
    auto temp = far_z / range;

    Zero(row_column);

    row_column[0][0] = cot * aspect;
    row_column[1][1] = cot;
    row_column[2][2] = temp;
    row_column[2][3] = 1.0f;
    row_column[3][2] = -near_z * temp;
  }

  void Matrix44::Viewport(const float width,const float height)
  {
    auto w = width * 0.5f;
    auto h = height * 0.5f;

    Unit();

    row_column[0][0] = w;
    row_column[1][1] = -h;
    row_column[3][0] = w;
    row_column[3][1] = h;
  }

  const Matrix44 Matrix44::operator *(const Matrix44& rhs) const
  {
    MatrixArray result { {{0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}} };

    for( auto i = 0; i < column_max; ++i )
    {
      for( auto j = 0; j < row_max; ++j )
      {
        auto m = 0.0f;

        for( auto k = 0; k < 4; ++k )
        {
          m += row_column[i][k] * rhs.GetValue(k,j);
        }

        result[i][j] = m;
      }
    }

    return Matrix44(result);
  }

  const Matrix44 Matrix44::operator +(const Vector4& rhs) const
  {
    MatrixArray result = row_column;

    result[3][0] += rhs.GetX();
    result[3][1] += rhs.GetY();
    result[3][2] += rhs.GetZ();

    return Matrix44(result);
  }

  void Matrix44::Transfer(const float x,const float y,const float z,bool is_remake)
  {
    if( is_remake )
    {
      Unit();
    }

    row_column[3][0] += x;
    row_column[3][1] += y;
    row_column[3][2] += z;
  }

  void Matrix44::Transfer(const mymath::Vector4& transfer,bool is_remake)
  {
    if( is_remake )
    {
      Unit();
    }

    row_column[3][0] += transfer.GetX();
    row_column[3][1] += transfer.GetY();
    row_column[3][2] += transfer.GetZ();
  };

  void Matrix44::Scale(const float x,const float y,const float z,bool is_remake)
  {
    if( is_remake )
    {
      Unit();
    }

    row_column[0][0] *= x;
    row_column[1][1] *= y;
    row_column[2][2] *= z;
  }

  void Matrix44::RotateX(const float radians,bool is_remake)
  {
    auto [sin,cos] = GetSinCos(radians);

    if( is_remake )
    {
      Unit();

      row_column[1][1] = cos;
      row_column[1][2] = sin;
      row_column[2][1] = -sin;
      row_column[2][2] = cos;
    } else
    {
      MatrixArray array { {{1, 0, 0, 0}, {0, cos, sin, 0}, {0, -sin, cos, 0}, {0, 0, 0, 1}} };
      Matrix44 rot_x(array);

      *this = *this * rot_x;
    }
  }

  void Matrix44::RotateY(const float radians,bool is_remake)
  {
    auto [sin,cos] = GetSinCos(radians);

    if( is_remake )
    {
      Unit();

      row_column[0][0] = cos;
      row_column[0][2] = -sin;
      row_column[2][0] = sin;
      row_column[2][2] = cos;
    } else
    {
      MatrixArray array { {{cos, 0, -sin, 0}, {0, 1, 0, 0}, {sin, 0, cos, 0}, {0, 0, 0, 1}} };
      Matrix44 rot_y(array);

      *this = *this * rot_y;
    }
  }

  void Matrix44::RotateZ(const float radians,bool is_remake)
  {
    auto [sin,cos] = GetSinCos(radians);

    if( is_remake )
    {
      Unit();

      row_column[0][0] = cos;
      row_column[0][1] = sin;
      row_column[1][0] = -sin;
      row_column[1][1] = cos;
    } else
    {
      MatrixArray array { {{cos, sin, 0, 0}, {-sin, cos, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}} };
      Matrix44 rot_z(array);

      *this = *this * rot_z;
    }
  }

  Matrix44 Matrix44::GetRotate() const
  {
    MatrixArray none_transfer = row_column;

    none_transfer[3][0] = 0.0;
    none_transfer[3][1] = 0.0;
    none_transfer[3][2] = 0.0;

    return Matrix44(none_transfer);
  }

  std::tuple<float,float> Matrix44::GetSinCos(const float radians) const
  {
    return { std::sin(radians),std::cos(radians) };
  }

}
