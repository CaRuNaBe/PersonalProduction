/*****************************************************************//**
 * \file   Easing.cpp
 * \brief  �C�[�W���O�N���X�錾
 * \author ���������Y
 * \date   June 2023
 *********************************************************************/
#include "Easing.h"
namespace mymath
{
  /** 
   * �C�[�W���O�֐������_���e�[�u��
   * @param t �o�ߎ���
   * @param b �J�n�l
   * @param c �I���l
   * @param d ��������
   * @return  �v�Z����
   */
  const EasingMap Easing::_modes = {
    { "Linear",[] (float t, float b, float c, float d) { return (c - b) * t / d + b; }},

    { "InQuad",[] (float t, float b, float c, float d) { t /= d; return (c - b) * t * t + b; }},

    { "OutQuad",[] (float t, float b, float c, float d) { t /= d; return -(c - b) * t * (t - 2.0f) + b; }},

    { "InOutQuad",[] (float t, float b, float c, float d) { t /= d / 2.0f; if(t < 1.0f) { return (c - b) / 2.0f * t * t + b; }t--; return -(c - b) / 2.0f * (t * (t - 2.0f) - 1.0f) + b; }},

    { "InCubic",[] (float t, float b, float c, float d) { t /= d; return (c - b) * t * t * t + b; }},

    { "OutCubic",[] (float t, float b, float c, float d) { t /= d; t--; return (c - b) * (t * t * t + 1.0f) + b; }},

    { "InOutCubic",[] (float t, float b, float c, float d) { t /= d / 2.0f; if(t < 1.0f) { return (c - b) / 2.0f * t * t * t + b; }t -= 2.0f; return (c - b) / 2.0f * (t * t * t + 2.0f) + b; }},

    { "InQuart",[] (float t, float b, float c, float d) { t /= d; return (c - b) * t * t * t * t + b; }},

    { "OutQuart",[] (float t, float b, float c, float d) { t /= d; t--; return -(c - b) * (t * t * t * t - 1.0f) + b; }},

    { "InOutQuart",[] (float t, float b, float c, float d) { t /= d / 2.0f; if(t < 1.0f) { return (c - b) / 2.0f * t * t * t * t + b; }t -= 2.0f; return -(c - b) / 2.0f * (t * t * t * t - 2.0f) + b; }},

    { "InQuint",[] (float t, float b, float c, float d) { t /= d; return (c - b) * t * t * t * t * t + b; }},

    { "OutQuint",[] (float t, float b, float c, float d) { t /= d; t--; return (c - b) * (t * t * t * t * t + 1.0f) + b; }},

    { "InOutQuint",[] (float t, float b, float c, float d) { t /= d / 2.0f; if(t < 1.0f) { return (c - b) / 2.0f * t * t * t * t * t + b; }t -= 2.0f; return (c - b) / 2.0f * (t * t * t * t * t + 2.0f) + b; }},

    { "InSine",[] (float t, float b, float c, float d) { return -(c - b) * std::cos(t / d * (MyMathUtility::PIOVER2)) + c + b; }},

    { "OutSine",[] (float t, float b, float c, float d) { return (c - b) * std::sin(t / d * MyMathUtility::PIOVER2) + b; }},

    { "InOutSine",[] (float t, float b, float c, float d) { return -(c - b) / 2.0f * (std::cos(MyMathUtility::PI * t / d) - 1.0f) + b; }},

    { "InExpo",[] (float t, float b, float c, float d) { return (c - b) * std::pow(2.0f, 10.0f * (t / d - 1.0f)) + b; }},

    { "OutExpo",[] (float t, float b, float c, float d) { return (c - b) * (-std::pow(2.0f, -10.0f * t / d) + 1.0f) + b; }},

    { "InOutExpo",[] (float t, float b, float c, float d) { t /= d / 2.0f; if(t < 1.0f) { return (c - b) / 2.0f * std::pow(2.0f, 10.0f * (t - 1.0f)) + b; }t--; return (c - b) / 2.0f * (-std::pow(2.0f, -10.0f * t) + 2.0f) + b; }},

    { "InCirc",[] (float t, float b, float c, float d) { t /= d; return -(c - b) * (std::sqrt(1.0f - t * t) - 1.0f) + b; }},

    { "OutCirc",[] (float t, float b, float c, float d) { t /= d; t--; return (c - b) * std::sqrt(1.0f - t * t) + b; }},

    { "InOutCirc",[] (float t, float b, float c, float d) { t /= d / 2.0f; if(t < 1.0f) { return -(c - b) / 2.0f * (std::sqrt(1.0f - t * t) - 1.0f) + b; }t -= 2.0f; return (c - b) / 2.0f * (std::sqrt(1.0f - t * t) + 1.0f) + b; }}
  };
}