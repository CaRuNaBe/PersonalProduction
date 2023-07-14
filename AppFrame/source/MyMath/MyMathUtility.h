/*****************************************************************//**
 * \file   MyMathUtility.h
 * \brief  �������g���v�Z�N���X�̃��[�e�B���e�B�̒�`
 * \author ���������Y
 * \date   June 2023
 *********************************************************************/
#pragma once
namespace mymath
{
  /** �f�B�O���[�l�[���x */
  constexpr float DEGREES_ZERO = 0.0f;
  /** �f�B�O���[�l180�x */
  constexpr float DEGREES_180 = 180.0f;
  /** �f�B�O���[�l360�x */
  constexpr float DEGREES_360 = DEGREES_180 * 2.0f;
  /** �~���� */
  constexpr float PI = 3.14159265358979f;
  /** ���W�A���l�[�� */
  constexpr float RADIANS_ZERO = 0.0f;
  /** �f�B�O���[�l360�x�̎��̃��W�A���l */
  constexpr float TWOPI = PI * 2.0f;
  /** �f�B�O���[�l90�x�̎��̃��W�A���l */
  constexpr float PIOVER2 = PI / 2.0f;

  /** �����l���֐� */
  template <typename T>
  T Sign(const T& num)
  {
    auto zero = static_cast<T>(0);
    return static_cast<T>((num > zero) - (num < zero));
  }
  /** �X�e�b�v�֐� */
  template <typename T>
  bool Step(const T& num,const T& edge)
  {
    return (num >= edge);
  }
  class MyMathUtility
  {
  public:
    /** �f�B�O���[�l���烉�W�A���l�ɕϊ�����֐� */
    static float DegreeToRadian(float degree);
    /** ���W�A���l����f�B�O���[�l�ɕϊ�����֐� */
    static float RadianToDegree(float radion);
    /** min����max�̃����_���l�l���֐�(���U��l���z) */
    static int GetRandom(const int min,const int max);
    /** true��false�������_���l��(���U��l���z) */
    static bool GetRandom();
  private:
    MyMathUtility() = default;
  };
}
