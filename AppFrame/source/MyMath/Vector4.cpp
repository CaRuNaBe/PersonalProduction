/*****************************************************************//**
 * \file   Vector4.cpp
 * \brief  四次元ベクトル宣言
 * \author 阿部健太郎
 * \date   June 2023
 *********************************************************************/
#include <limits>
#include <cmath>

#include "Vector4.h"
#include "Matrix44.h"
#include "Polar3D.h"
namespace mymath
{
  Vector4::Vector4()
    : x(0.0f)
    ,y(0.0f)
    ,z(0.0f)
    ,w(1.0f)
  {}
  Vector4::Vector4(float x,float y,float z)
    : x(x)
    ,y(y)
    ,z(z)
    ,w(1.0f)
  {}
  Vector4::Vector4(float x,float y,float z,float w)
    : x(x)
    ,y(y)
    ,z(z)
    ,w(w)
  {}
  Vector4::Vector4(int x,int y,int z)
    : x(static_cast<float>(x))
    ,y(static_cast<float>(y))
    ,z(static_cast<float>(z))
    ,w(1.0f)
  {}
  Vector4::Vector4(int x,int y,int z,int w)
    : x(static_cast<float>(x))
    ,y(static_cast<float>(y))
    ,z(static_cast<float>(z))
    ,w(static_cast<float>(w))
  {}
  Vector4::Vector4(const Polar3D& pol)
    : x((pol.GetRadius()* std::sin(pol.GetTheta()))* std::cos(pol.GetPhi()))
    ,y(pol.GetRadius()* std::cos(pol.GetTheta()))
    ,z((pol.GetRadius()* std::sin(pol.GetTheta()))* std::sin(pol.GetPhi()))
    ,w(1.0f)
  {};

  float Vector4::Lenght(const Vector4& second) const
  {
    return sqrt((x - second.GetX()) * (x - second.GetX()) + (y - second.GetY()) * (y - second.GetY()) + (z - second.GetZ()) * (z - second.GetZ()));
  }

  void Vector4::Normalized()
  {
    auto len = Lenght();
    /** 誤差未満ならゼロとみなす */
    if( std::abs(len) < std::numeric_limits<float>::epsilon() )
    {
      x = 0.0f;
      y = 0.0f;
      z = 0.0f;
    } else
    {
      x /= len;
      y /= len;
      z /= len;
    }
  }
  Vector4 Vector4::GetNormalize() const
  {
    auto len = Lenght();
    auto nx = 0.0f;
    auto ny = 0.0f;
    auto nz = 0.0f;
    /** 誤差未満ならゼロとみなす */
    if( std::abs(len) < std::numeric_limits<float>::epsilon() )
    {
      nx = 0.0f;
      ny = 0.0f;
      nz = 0.0f;
    } else
    {
      nx = x / len;
      ny = y / len;
      nz = z / len;
    }
    return Vector4(nx,ny,nz);
  }

  float Vector4::Dot(const Vector4& rhs) const
  {
    return x * rhs.x + y * rhs.y + z * rhs.z;
  }

  Vector4 Vector4::Cross(const Vector4& rhs) const
  {
    auto cx = y * rhs.z - z * rhs.y;
    auto cy = z * rhs.x - x * rhs.z;
    auto cz = x * rhs.y - y * rhs.x;

    return Vector4(cx,cy,cz);
  }

  Vector4 Vector4::Lerp(const Vector4& start,const Vector4& end,float amount)
  {
    if( amount < 0.0f )
    {
      amount = 0.0f;
    }
    return start + ((end - start) * amount);
  };

  Vector4 Vector4::operator+(const Vector4& rhs) const
  {
    return Vector4(x + rhs.x,y + rhs.y,z + rhs.z);
  }

  Vector4 Vector4::operator-(const Vector4& rhs) const
  {
    return Vector4(x - rhs.x,y - rhs.y,z - rhs.z);
  }

  Vector4 Vector4::operator*(const Vector4& rhs) const
  {
    return Vector4(x * rhs.x,y * rhs.y,z * rhs.z);
  }

  Vector4 Vector4::operator*(const float& rhs) const
  {
    return Vector4(x * rhs,y * rhs,z * rhs);
  }

  Vector4 Vector4::operator/(const float& rhs) const
  {
    return Vector4(x / rhs,y / rhs,z / rhs);
  }

  Vector4& Vector4::operator+=(const Vector4& right)
  {
    x += right.x;
    y += right.y;
    z += right.z;
    return *this;
  };

  Vector4& Vector4::operator-=(const Vector4& right)
  {
    x -= right.x;
    y -= right.y;
    z -= right.z;
    return *this;
  }

  Vector4& Vector4::operator*=(float scalar)
  {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
  }

  Vector4 Vector4::operator *(const Matrix44 rhs) const
  {
    auto mx = x * rhs.GetValue(0,0)
      + y * rhs.GetValue(1,0)
      + z * rhs.GetValue(2,0)
      + rhs.GetValue(3,0);

    auto my = x * rhs.GetValue(0,1)
      + y * rhs.GetValue(1,1)
      + z * rhs.GetValue(2,1)
      + rhs.GetValue(3,1);

    auto mz = x * rhs.GetValue(0,2)
      + y * rhs.GetValue(1,2)
      + z * rhs.GetValue(2,2)
      + rhs.GetValue(3,2);

    auto mw = x * rhs.GetValue(0,3)
      + y * rhs.GetValue(1,3)
      + z * rhs.GetValue(2,3)
      + rhs.GetValue(3,3);

    return Vector4(mx,my,mz,mw);
  }

} // mymath