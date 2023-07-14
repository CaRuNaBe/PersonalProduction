/*****************************************************************//**
 * \file   Canera.h
 * \brief  カメラクラス(定義)
 * \author 阿部健太郎
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
  /** コンストラクタ */
  Camera(int screen_width,int screen_height);
  /** コピーコンストラクタ */
  Camera(const Camera&) = default;
  /** ムーブコンストラクタ */
  Camera(Camera&&) = default;

  /** デストラクタ */
  ~Camera() = default;
  /** 更新 */
  bool Update();


  /** ニアーをセット */
  void SetNear(const float near_value)
  {
    this->near_value = near_value;
  }
  /** ファーをセット */
  void SetFar(const float far_value)
  {
    this->far_value = far_value;
  }
  /** fovをセット */
  void SetFov(const float fov)
  {
    this->fov = fov;
  }
  /** カメラの位置をセット */
  void SetPosition(const mymath::Vector4& position)
  {
    this->position = position;
  }
  /** 注視点をセット */
  void SetTarget(const mymath::Vector4& target)
  {
    this->target = target;
  }
  /** カメラの上ベクトルをセット */
  void SetUp(const mymath::Vector4& up)
  {
    this->up = up;
  }
  /** アスペクト比スクリーンサイズの指定でセット */
  void SetAspect(int screen_width,int screen_height)
  {
    aspect = static_cast<float>(screen_height) / static_cast<float>(screen_width);
  }
  /** カメラの位置を取得 */
  const mymath::Vector4 GetPosition() const
  {
    return position;
  }
  /** カメラの注視点を取得 */
  const mymath::Vector4 GetTarget() const
  {
    return target;
  }
  /** カメラの上ベクトル取得 */
  const mymath::Vector4 GetUp() const
  {
    return up;
  }

  /** ビュー、マトリクスを取得 */
  const mymath::Matrix44 GetViewMatrix() const;
  /** プロジェクションマトリクスを取得 */
  const mymath::Matrix44 GetProjectionMatrix() const;
  /** このカメラに対するビルボードマトリクスを取得 */
  const mymath::Matrix44 GetBillboardMatrix() const;

private:
  /** カメラの手前クリップ距離 */
  float near_value;
  /** カメラの奥クリップ距離 */
  float far_value;
  /** 画角 */
  float fov;
  /** アスペクト比(画面の高さ/横幅) */
  float aspect;

  /** カメラの位置 */
  mymath::Vector4 position;
  /** カメラの注視点 */
  mymath::Vector4 target;
  /** カメラの上ベクトル */
  mymath::Vector4 up;
};