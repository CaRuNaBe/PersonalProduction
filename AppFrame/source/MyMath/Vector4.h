/*****************************************************************//**
 * \file   Vector4.h
 * \brief  �l�����x�N�g����`
 * \author ���������Y
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
    /** �R���X�g���N�^�Q */
    Vector4();
    Vector4(float x,float y,float z);
    Vector4(float x,float y,float z,float w);
    Vector4(int x,int y,int z);
    Vector4(int x,int y,int z,int w);
    /** �O�����ɍ��W����R���X�g���N�^�ŕϊ� */
    Vector4(const Polar3D& pol);

    /** �R�s�[�R���X�g���N�^ */
    Vector4(const Vector4&) = default;
    /** ���[�u�R���X�g���N�^ */
    Vector4(Vector4&&) = default;

    /** �f�X�g���N�^ */
    virtual ~Vector4() = default;

    /** �R�s�[��� */
    Vector4& operator =(const Vector4&) = default;
    /** ���[�u��� */
    Vector4& operator =(Vector4&&) = default;

    /** �x�N�g���̉��Z a + b */
    Vector4 operator +(const Vector4& rhs) const;
    /** �x�N�g���̌��Z a - b */
    Vector4 operator -(const Vector4& rhs) const;
    /** �x�N�g���̂����Z a * b */
    Vector4 operator *(const Vector4& rhs) const;
    /** �x�N�g���̃X�J���[�{ v * scalar */
    Vector4 operator *(const float& rhs) const;
    /** �x�N�g���̃X�J���[�� v / scalar */
    Vector4 operator /(const float& rhs) const;
    /** �x�N�g�����Z��� */
    Vector4& operator+=(const Vector4& right);
    /** �x�N�g�����Z��� */
    Vector4& operator-=(const Vector4& right);
    /** �x�N�g���̃X�J����Z��� */
    Vector4& operator*=(float scalar);

    /** �x�N�g���̍s��ϊ� �I�y���[�^ */
    Vector4 operator *(const Matrix44 rhs) const;
    /** �x�N�g���̑傫�����Q�b�g */
    float Lenght() const;
    /** ���̃x�N�g���𐳋K�� */
    void Normalized();
    /** ���K�������x�N�g�����Q�b�g */
    Vector4 GetNormalize() const;
    /** �x�N�g���̓���(Dot product) a�Eb */
    float Dot(const Vector4& rhs) const;
    /** �x�N�g���̓���(Dot product) a�Eb(�ÓI�֐�) */
    static float Dot(const Vector4& v1,const Vector4& v2);
    /** �x�N�g���̊O��(Cross product) a�~b */
    Vector4 Cross(const Vector4& rhs) const;
    /** �O�� (�ÓI�֐�) */
    static Vector4 Cross(const Vector4& v1,const Vector4& v2);
    /** ���`���(�ÓI�֐�) */
    static Vector4 Lerp(const Vector4& start,const Vector4& end,float amount);

    /** x���Q�b�g */
    float GetX()const
    {
      return x;
    }
    /** y���Q�b�g */
    float GetY()const
    {
      return y;
    }
    /** z���Q�b�g */
    float GetZ()const
    {
      return z;
    }
    /** w���Q�b�g */
    float GetW()const
    {
      return w;
    }
    /** x�Z�b�g */
    void SetX(const float& x)
    {
      this->x = x;
    }
    /** y�Z�b�g */
    void SetY(const float& y)
    {
      this->y = y;
    }
    /** z�Z�b�g */
    void SetZ(const float& z)
    {
      this->z = z;
    }
    /** w�Z�b�g */
    void SetW(const float& w)
    {
      this->w = w;
    }
  private:
    /* ���� */
    /** +x�E�� */
    float x;
    /** +y�ŏ㑤 */
    float y;
    /** +z�ŉ� */
    float z;
    float w;
  };
  static const mymath::Vector4 VECTOR4_RIGHT = { 1.0f,0.0f,0.0f };
  static const mymath::Vector4 VECTOR4_UP = { 0.0f,1.0f,0.0f };
  static const mymath::Vector4 VECTOR4_FRONT = { 0.0f,0.0f,1.0f };
} // mymath
