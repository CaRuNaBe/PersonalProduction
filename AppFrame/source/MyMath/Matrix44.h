/*****************************************************************//**
 * \file   Matrix44.h
 * \brief  �s��N���X��`
 * \author ���������Y
 * \date   June 2023
 *********************************************************************/
#pragma once

#include <array>
#include <tuple>

namespace mymath
{
  class Vector4;
  /** �s���̍ő�l */
  constexpr auto row_max = 4;
  /** �񐔂̍ő�l */
  constexpr auto column_max = 4;
  /** std::array��񎟌��z��Ƃ��ĕʖ���` */
  using MatrixArray = std::array<std::array<float,row_max>,column_max>;

  class Matrix44
  {
  public:
    /** Matrix44�P�ʍs��ɂ��ď����� */
    Matrix44();
    /** Matrix44��MatrixArray������ď����� */
    Matrix44(const MatrixArray values);
    /** �R�s�[�R���X�g���N�^ */
    Matrix44(const Matrix44&) = default;
    /** ���[�u�R���X�g���N�^ */
    Matrix44(Matrix44&&) = default; 

    /** �f�X�g���N�^ */
    virtual ~Matrix44() = default;
    /** �R�s�[��� */
    Matrix44& operator =(const Matrix44&) = default;
    /** ���[�u��� */
    Matrix44& operator =(Matrix44&&) = default; 
    /** �s��̊|���Z */
    const Matrix44 operator *(const Matrix44& rhs) const;
    /** �s��ƃx�N�g���̂����Z */
    const Matrix44 operator +(const Vector4& rhs) const;
    /** �s�񂩂�w��̒l����肽�����z��Ȃ̂�0����3�Ŏw�肷�� */
    float GetValue(const int row,const int column) const
    {
      return row_column[row][column];
    }
    /** �s��̎w��̏ꏊ�ɒl�����邽�����z��Ȃ̂�0����3�Ŏw�肷�� */
    void SetValue(const int row,const int column,const float value)
    {
      row_column[row][column] = value;
    }
    /** ���ׂĂ̒l��0.0f������ */
    void Zero(MatrixArray& target) const;
    /** ���ׂĂ̒l��0.0f�������ɂ��������ŒP�ʃx�N�g���� */
    void Unit();
    /** �s�񎮂��s�� */
    float Determinant() const;
    /** �����s��𓾂� */
    Matrix44 GetInverse() const;

    /** target�Ɍ����x�N�g���Ǝp����]�̍s������ */
    void LookAt(const Vector4& position,const Vector4& target,const Vector4& up);
    /** ���������Ă���ˉe�ϊ��s����쐬 */
    void Perspective(const float fov_y,const float aspect,const float near_z,const float far_z);
    /** ���������P�ʉ������Ă���r���[�|�[�g�s����쐬 */
    void Viewport(const float width,const float height);

    /** ���ꂼ��l�Ɉړ��������s�ړ��s��ɂ���is_remake��true�̎����������P�ʉ������Ă�����s�s��ɂ��� */
    void Transfer(const float x,const float y,const float z,bool is_remake = false);
    /** Vector4��xyz�̒l��������s�ړ��s��ɂ���is_remake��true�̎����������P�ʉ������Ă�����s�s��ɂ��� */
    void Transfer(const mymath::Vector4& transfer,bool is_remake = false);
    /** ���ꂼ��̊g�債���s��ɂ���is_remake��true�̎����������P�ʉ������Ă���g��s��ɂ��� */
    void Scale(const float x,const float y,const float z,bool is_remake = false);
    /** x���ŉ�]�����s��ɂ���is_remake��true�̎����������P�ʉ������Ă���x����]���� */
    void RotateX(const float radians,bool is_remake = false);
    /** y���ŉ�]�����s��ɂ���is_remake��true�̎����������P�ʉ������Ă���y����]���� */
    void RotateY(const float radians,bool is_remake = false);
    /** z���ŉ�]�����s��ɂ���is_remake��true�̎����������P�ʉ������Ă���z����]���� */
    void RotateZ(const float radians,bool is_remake = false);
    /** ��]�s����擾 */
    Matrix44 GetRotate() const;
    /** �s��̕��s�ړ��������ǂ镔������Vector4�Ŏ擾 */
    mymath::Vector4 GetTransfer()const;
  private:
    /** tuple��sin��cos�̒l���擾 */
    std::tuple<float,float> GetSinCos(const float radians) const;
    /** 4*4�̔z�� */
    MatrixArray row_column;
  };
}
