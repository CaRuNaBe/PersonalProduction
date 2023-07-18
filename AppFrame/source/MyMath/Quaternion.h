#pragma once
class Quaternion
{
private:
  float w;  // �X�J���[����
  float x;  // x����
  float y;  // y����
  float z;  // z����

public:
  // �R���X�g���N�^
  Quaternion(float scalar = 0.0f,float xComp = 0.0f,float yComp = 0.0f,float zComp = 0.0f) : w(scalar),x(xComp),y(yComp),z(zComp)
  {}

  // �f�X�g���N�^
  ~Quaternion()
  {
    // �f�X�g���N�^�̏���
  }

  // �e�����̎擾
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

  // �e�����̐ݒ�
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