/*****************************************************************//**
 * @file   Polar3D.h
 * @brief  �O�����ɍ��W��`
 *
 * @author ���������Y
 * @date   June 2023
 *********************************************************************/
#pragma once
namespace mymath
{
  class Vector4;
  class Polar3D
  {
  public:
    /** �R���X�g���N�^�Q */
    Polar3D();
    Polar3D(float radius,float theta,float phi);
    Polar3D(int radius,int theta,int phi);
    /** �R���X�g���N�^��Vector4����ɍ��W�ɕϊ� */
    Polar3D(const Vector4& vec);
    /** �R�s�[�R���X�g���N�^ */
    Polar3D(const Polar3D&) = default;
    /** ���[�u�R���X�g���N�^ */
    Polar3D(Polar3D&&) = default;
    /** �f�X�g���N�^ */
    virtual ~Polar3D() = default;

    /** �R�s�[��� */
    Polar3D& operator =(const Polar3D&) = default;
    /** ���[�u��� */
    Polar3D& operator =(Polar3D&&) = default;
    /** Vector4�ɕϊ� */
    Vector4 ToVector4();
    /** �ɍ��W�ɂ����锼�a���C���N�������g */
    void RadiusIncrement(const float& radius);
    /** �ɍ��W�ɂ����锼�a���f�N�������g������0�ȉ��ɂ͂Ȃ�Ȃ� */
    void RadiusDecrement(const float& radius);
    /** �ɍ��W�ɂ�����ܓx(���W�A��)���C���N�������g */
    void ThetaIncrement(const float& theta);
    /** �ɍ��W�ɂ�����ܓx(���W�A��)���f�N�������g */
    void ThetaDecrement(const float& theta);
    /** �ɍ��W�ɂ�����o�x(���W�A��)���C���N�������g */
    void PhiIncrement(const float& phi);
    /** �ɍ��W�ɂ�����o�x(���W�A��)���f�N�������g */
    void PhiDecrement(const float& phi);

    /** ���a�Z�b�g */
    void SetRadius(const float& radius)
    {
      this->radius = radius;
    }
    /** �ܓx(���W�A��)�Z�b�g */
    void SetTheta(const float& theta)
    {
      this->theta = theta;
    }
    /** �o�x(���W�A��)�Z�b�g */
    void SetPhi(const float& phi)
    {
      this->phi = phi;
    }
    /** Polar3D����Z�b�g */
    void Set(const Polar3D& pol)
    {
      radius = pol.GetRadius();
      theta = pol.GetTheta();
      phi = pol.GetPhi();
    }
    /** 3�̒l�𓯎��ɃZ�b�g */
    void Set(const float& radius,const float& theta,const float& phi)
    {
      this->radius = radius;
      this->theta = theta;
      this->phi = phi;
    }
    /** ���a�Q�b�g */
    float GetRadius()const
    {
      return radius;
    }
    /** �ܓx(���W�A�����Q�b�g */
    float GetTheta()const
    {
      return theta;
    }
    /** �o�x(���W�A��)���Q�b�g */
    float GetPhi()const
    {
      return phi;
    }
  private:
    /** ���a */
    float radius;
    /** �ܓx(���W�A��) */
    float theta;
    /** �o�x(���W�A��) */
    float phi;
  };
}
