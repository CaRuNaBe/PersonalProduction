/*****************************************************************//**
 * \file   Camera.cpp
 * \brief  �J�����N���X(�錾)
 * \author ���������Y
 * \date   July 2023
 *********************************************************************/
#include <DxLib.h>
#include "Camera.h"
#include "MyMath/DxMyMathUtility.h"
#include "MyMath/Matrix44.h"
#include "MyMath/MyMathUtility.h"
namespace
{
  constexpr auto DEFAULT_POSITION_Z = -300.0f;
  constexpr auto DEFAULT_POSITION_Y = 100.0f;
  constexpr auto DEFAULT_UP_Y = 1.0f;
#undef DEFAULT_NEAR
  constexpr auto DEFAULT_NEAR = 1.0f;
#undef DEFAULT_FAR
  constexpr auto DEFAULT_FAR = 100000000.0f;
  constexpr auto DEFAULT_FOV_ANGLE = 60.0f;
}
Camera::Camera(int screen_width,int screen_height)
  :near_value { DEFAULT_NEAR }
  ,far_value { DEFAULT_FAR }
  ,fov { mymath::MyMathUtility::DegreeToRadian(DEFAULT_FOV_ANGLE) }
  ,aspect { static_cast<float>(screen_height) / static_cast<float>(screen_width) }
  ,position { 0.0f,DEFAULT_POSITION_Y,DEFAULT_POSITION_Z }
  ,target { 0.0f,0.0f,0.0f }
  ,up { 0.0f,1.0f,0.0f }
{};

bool Camera::Update()
{
  auto view_matrix = GetViewMatrix();

  SetCameraViewMatrix(ToDX(view_matrix));

  auto projection_matrix = GetProjectionMatrix();

  SetupCamera_ProjectionMatrix(ToDX(projection_matrix));
  return true;
}

const mymath::Matrix44 Camera::GetViewMatrix() const
{
  mymath::Matrix44 camera_matrix = mymath::Matrix44();

  camera_matrix.LookAt(position,target,up);

  return camera_matrix;
}

const mymath::Matrix44 Camera::GetProjectionMatrix() const
{
  mymath::Matrix44 projection_matrix = mymath::Matrix44();

  projection_matrix.Perspective(fov,aspect,near_value,far_value);

  return projection_matrix;
}

const mymath::Matrix44 Camera::GetBillboardMatrix() const
{
  auto view_matrix = GetViewMatrix();
  auto inverse_matrix = view_matrix.GetInverse();

  // ���s�ړ������̓J�b�g����
  inverse_matrix.SetValue(3,0,0.0f);
  inverse_matrix.SetValue(3,1,0.0f);
  inverse_matrix.SetValue(3,2,0.0f);

  return inverse_matrix;
}
