/*****************************************************************//**
 * \file   Canera.h
 * \brief  �J�����N���X(��`)
 * \author ���������Y
 * \date   July 2023
 *********************************************************************/
#pragma once
#include "MyMath/Vector4.h"
namespace mymath
{
  class Matrix44;
}

class Camera
{
public:
  /** �R���X�g���N�^ */
  Camera(int screen_width,int screen_height);
  /** �R�s�[�R���X�g���N�^ */
  Camera(const Camera&) = default;
  /** ���[�u�R���X�g���N�^ */
  Camera(Camera&&) = default;

  /** �f�X�g���N�^ */
  ~Camera() = default;
  /** �X�V */
  bool Update();


  /** �j�A�[���Z�b�g */
  void SetNear(const float near_value)
  {
    this->near_value = near_value;
  }
  /** �t�@�[���Z�b�g */
  void SetFar(const float far_value)
  {
    this->far_value = far_value;
  }
  /** fov���Z�b�g */
  void SetFov(const float fov)
  {
    this->fov = fov;
  }
  /** �J�����̈ʒu���Z�b�g */
  void SetPosition(const mymath::Vector4& position)
  {
    this->position = position;
  }
  /** �����_���Z�b�g */
  void SetTarget(const mymath::Vector4& target)
  {
    this->target = target;
  }
  /** �J�����̏�x�N�g�����Z�b�g */
  void SetUp(const mymath::Vector4& up)
  {
    this->up = up;
  }
  /** �A�X�y�N�g��X�N���[���T�C�Y�̎w��ŃZ�b�g */
  void SetAspect(int screen_width,int screen_height)
  {
    aspect = static_cast<float>(screen_height) / static_cast<float>(screen_width);
  }
  /** �J�����̈ʒu���擾 */
  const mymath::Vector4 GetPosition() const
  {
    return position;
  }
  /** �J�����̒����_���擾 */
  const mymath::Vector4 GetTarget() const
  {
    return target;
  }
  /** �J�����̏�x�N�g���擾 */
  const mymath::Vector4 GetUp() const
  {
    return up;
  }

  /** �r���[�A�}�g���N�X���擾 */
  const mymath::Matrix44 GetViewMatrix() const;
  /** �v���W�F�N�V�����}�g���N�X���擾 */
  const mymath::Matrix44 GetProjectionMatrix() const;
  /** ���̃J�����ɑ΂���r���{�[�h�}�g���N�X���擾 */
  const mymath::Matrix44 GetBillboardMatrix() const;

private:
  /** �J�����̎�O�N���b�v���� */
  float near_value;
  /** �J�����̉��N���b�v���� */
  float far_value;
  /** ��p */
  float fov;
  /** �A�X�y�N�g��(��ʂ̍���/����) */
  float aspect;

  /** �J�����̈ʒu */
  mymath::Vector4 position;
  /** �J�����̒����_ */
  mymath::Vector4 target;
  /** �J�����̏�x�N�g�� */
  mymath::Vector4 up;
};