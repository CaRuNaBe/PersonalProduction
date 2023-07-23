/*****************************************************************//**
 * \file   Mv1Model.h
 * \brief  dx���C�u������MV1���f���̏������܂Ƃ߂��N���X��`
 * \author ���������Y
 * \date   July 2023
 *********************************************************************/
#pragma once
#include <string>
#include <vector>
#include <tuple>
#include <map>
namespace mymath
{
  class Vector4;
  class Matrix44;
}
namespace model
{
  class Mv1Model
  {
  public:
    /** �R���X�g���N�^ */
    Mv1Model(std::string filename);
    /** �R�s�[�R���X�g���N�^ */
    Mv1Model(const Mv1Model&) = delete;
    /** ���[�u�R���X�g���N�^ */
    Mv1Model(Mv1Model&&) = default;

    /** �f�X�g���N�^ */
    virtual ~Mv1Model();

    /** �R�s�[��� */
    Mv1Model& operator =(const Mv1Model&) = delete;
    /** ���[�u��� */
    Mv1Model& operator =(Mv1Model&&) = default;

    /** MV1���f���`��֐� */
    void Draw();
    /** ���f���̍��W���Z�b�g���� */
    bool SetPosition(const mymath::Vector4& position);
    /** ���f���̊g��l���Z�b�g���� */
    bool SetSetScale(const mymath::Vector4& scale);
    /** ���f���̉�]�l���Z�b�g���� x����]  y����]  z����] �̏��ŉ�]*/
    bool SetRotation(const mymath::Vector4& rotation);
    /** ���f���̍��W�ϊ��p�s����Z�b�g���� */
    bool SetMatrix(const mymath::Matrix44& parameter);
    /** ���f���̍��W�ϊ��p�s����擾���� */
    mymath::Matrix44 GetMatrix()const;
    /** ���f���̂��ׂẴt���[���ɑ΂��R���W���������\�z���� */
    bool SetupAllCollInfo();

    /** �A�j���[�V�������A�^�b�`���� */
    int AttachAnim(int anim_index,int anim_src_mhandle = -1,int name_check = 1);
    /** �A�j���[�V�������f�^�b�`���� */
    int DetachAnim(int attach_index);
    /** �A�^�b�`���Ă���A�j���[�V�����̍Đ����Ԃ�ݒ肷�� */
    int SetAttachAnimTime(int attach_index,float time);
    /** �A�^�b�`���Ă���A�j���[�V�����̑����Ԃ��擾���� */
    float GetAttachAnimTotalTime(int attach_index);
  private:
    int mv1_model;
    std::map<std::string,int> collision_flame;
  };
}
