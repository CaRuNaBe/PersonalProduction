/*****************************************************************//**
 * \file   MyMathUtility.h
 * \brief  �������g���v�Z�N���X�̃��[�e�B���e�B�̒�`
 * \author ���������Y
 * \date   June 2023
 *********************************************************************/
#pragma once
namespace mymath
{
  class Vector4;

  class MyMathUtility
  {
  public:
    /** �f�B�O���[�l�[���x */
    static constexpr float DEGREES_ZERO = 0.0f;
    /** �f�B�O���[�l180�x */
    static constexpr float DEGREES_180 = 180.0f;
    /** �f�B�O���[�l360�x */
    static constexpr float DEGREES_360 = DEGREES_180 * 2.0f;
    /** �~���� */
    static constexpr float PI = 3.14159265358979f;
    /** ���W�A���l�[�� */
    static constexpr float RADIANS_ZERO = 0.0f;
    /** �f�B�O���[�l360�x�̎��̃��W�A���l */
    static constexpr float TWOPI = PI * 2.0f;
    /** �f�B�O���[�l90�x�̎��̃��W�A���l */
    static constexpr float PIOVER2 = PI / 2.0f;
    /** �f�B�O���[�l���烉�W�A���l�ɕϊ�����֐� */
    static float DegreeToRadian(float degree);
    /** ���W�A���l����f�B�O���[�l�ɕϊ�����֐� */
    static float RadianToDegree(float radion);
    /** min����max�̃����_���l�l���֐�(���U��l���z) */
    static int GetRandom(const int min,const int max);
    /** true��false�������_���l��(���U��l���z) */
    static bool get_random()
    {
      return GetRandom(1,2) == 1 ? true : false;
    }


  private:
    MyMathUtility() = default;
  };

  /** ��̒l�̑傫���l���擾 */
  template <typename T>
  T Max(const T& a,const T& b)
  {
    return (a < b ? b : a);
  }
  /** ��̒l�̏������l���擾 */
  template <typename T>
  T Min(const T& a,const T& b)
  {
    return (a < b ? a : b);
  }
  /** ��̒l�̊ԂŃN�����v���� */
  template <typename T>
  T Clamp(const T& value,const T& lower,const T& upper)
  {
    return Min(upper,Max(lower,value));
  }
  /** �����l���֐� */
  template <typename T>
  T Sign(const T& num)
  {
    return static_cast<T>((num > 0) - (num < 0));
  }
  /** �X�e�b�v�֐� */
  template <typename T>
  T Step(const T& num,const T& threshold)
  {
    return (num >= threshold);
  }
}
