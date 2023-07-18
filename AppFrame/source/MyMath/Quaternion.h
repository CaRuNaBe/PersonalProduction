#pragma once
class Quaternion
{
private:
  float w;  // スカラー部分
  float x;  // x成分
  float y;  // y成分
  float z;  // z成分

public:
  // コンストラクタ
  Quaternion(float scalar = 0.0f,float xComp = 0.0f,float yComp = 0.0f,float zComp = 0.0f) : w(scalar),x(xComp),y(yComp),z(zComp)
  {}

  // デストラクタ
  ~Quaternion()
  {
    // デストラクタの処理
  }

  // 各成分の取得
  float GetScalar() const
  {
    return w;
  }
  float GetXComponent() const
  {
    return x;
  }
  float GetYComponent() const
  {
    return y;
  }
  float GetZComponent() const
  {
    return z;
  }

  // 各成分の設定
  void SetScalar(float scalar)
  {
    w = scalar;
  }
  void SetXComponent(float xComp)
  {
    x = xComp;
  }
  void SetYComponent(float yComp)
  {
    y = yComp;
  }
  void SetZComponent(float zComp)
  {
    z = zComp;
  }
};