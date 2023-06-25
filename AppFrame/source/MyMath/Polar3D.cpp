/*****************************************************************//**
 * \file   Polar3D.cpp
 * \brief  OŸŒ³‹ÉÀ•WéŒ¾
 * \author ˆ¢•”Œ’‘¾˜Y
 * \date   June 2023
 *********************************************************************/
#include "Polar3D.h"
#include <cmath>
namespace mymath
{
  Polar3D::Polar3D()
    :radius(0.0f)
    ,theta(0.0f)
    ,phi(0.0f)
  {};

  Polar3D::Polar3D(float radius,float theta,float phi)
    :radius(radius)
    ,theta(theta)
    ,phi(phi)
  {};

  Polar3D::Polar3D(int radius,int theta,int phi)
    :radius(static_cast<float> (radius))
    ,theta(static_cast<float> (theta))
    ,phi(static_cast<float> (phi))
  {};

  Polar3D::Polar3D(const Vector4& vec)
    :radius(vec.Lenght())
    ,theta(std::acos(vec.GetZ() / radius))
    ,phi(mymath::Sign(vec.GetY())* std::acos(vec.GetX() / (std::sqrt((vec.GetX() * vec.GetX()) + (vec.GetY() * vec.GetY())))))
  {};

  Vector4 Polar3D::ToVector4()
  {
    auto fnum = radius * std::sin(theta);
    return { fnum * std::cos(phi),radius * std::cos(theta),fnum * std::sin(phi) };
  };

  void Polar3D::RadiusIncrement(const float& radius)
  {
    this->radius += radius;
  };

  void Polar3D::RadiusDecrement(const float& radius)
  {
    this->radius -= radius;
    if( this->radius < 0.0f )
    {
      this->radius = 0.0f;
    }
  };

  void Polar3D::ThetaIncrement(const float& theta)
  {
    this->theta += theta;
  };

  void Polar3D::ThetaDecrement(const float& theta)
  {
    this->theta -= theta;
  };

  void Polar3D::PhiIncrement(const float& phi)
  {
    this->phi += phi;
  };

  void Polar3D::PhiDecrement(const float& phi)
  {
    this->phi -= phi;
  };
}