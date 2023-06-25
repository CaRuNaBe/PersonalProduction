/*****************************************************************//**
 * \file   MyMathUtility.cpp
 * \brief  �������g���v�Z�N���X�̃��[�e�B���e�B�̐錾
 * \author ���������Y
 * \date   June 2023
 *********************************************************************/
#include <random>
#include <cmath>
#include "Vector4.h"
#include "MyMathUtility.h"

namespace
{
  /** �����_���̎� */
  std::random_device seed_gen;
  /** 64�r�b�g�ł̃����Z���k�E�c�C�X�^�[�@�Ŏg�p */
  std::mt19937_64 random(seed_gen());
}

namespace mymath
{
  int MyMathUtility::GetRandom(const int min,const int max)
  {
    std::uniform_int_distribution<int>  distr(min,max);
    return distr(random);
  }

  float MyMathUtility::DegreeToRadian(float degree)
  {
    return degree * PI / DEGREES_180;
  }

  float MyMathUtility::RadianToDegree(float radion)
  {
    return radion * DEGREES_180 / PI;
  }
}
