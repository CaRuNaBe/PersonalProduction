/*****************************************************************//**
 * \file   Mv1Model.cpp
 * \brief  dxライブラリのMV1モデルの処理をまとめたクラス宣言
 * \author 阿部健太郎
 * \date   July 2023
 *********************************************************************/
#include "Mv1Model.h"
#include "DxLib.h"
#include "MyMath/Vector4.h"
#include "MyMath/DxMyMathUtility.h"
#include "MyMath/Matrix44.h"
#include "mymath/DxMyMathUtility.h"
namespace model
{
  Mv1Model::Mv1Model(std::string filename)
  {
    mv1_model = DxLib::MV1LoadModel(filename.c_str());
  }

  Mv1Model::~Mv1Model()
  {
    DxLib::MV1DeleteModel(mv1_model);

    for( auto&& map : collision_flame )
    {
      DxLib::MV1TerminateCollInfo(mv1_model,map.second);
    }
  }

  void Mv1Model::Draw()
  {
    // Z バッファを有効化
    DxLib::MV1SetUseZBuffer(mv1_model,TRUE);
    DxLib::MV1SetWriteZBuffer(mv1_model,TRUE);
    DxLib::MV1DrawModel(mv1_model);
  }

  bool Mv1Model::SetPosition(const mymath::Vector4& position)
  {
    return MV1SetPosition(mv1_model,mymath::ToDX(position));
  }

  bool Mv1Model::SetSetScale(const mymath::Vector4& scale)
  {
    return MV1SetScale(mv1_model,mymath::ToDX(scale));
  }

  bool Mv1Model::SetRotation(const mymath::Vector4& rotation)
  {
    return MV1SetRotationXYZ(mv1_model,mymath::ToDX(rotation));
  }

  bool Mv1Model::SetMatrix(const mymath::Matrix44& parameter)
  {
    return MV1SetMatrix(mv1_model,mymath::ToDX(parameter));
  }

  mymath::Matrix44  Mv1Model::GetMatrix()const
  {
    return mymath::ToMyMath(DxLib::MV1GetMatrix(mv1_model));
  };

  bool Mv1Model::SetupAllCollInfo()
  {
    int frame_num_max = DxLib::MV1GetFrameNum(mv1_model);
    for( int i = 0; i < frame_num_max; i++ )
    {
      DxLib::MV1SetupCollInfo(mv1_model,i);
      std::string frame_name = DxLib::MV1GetFrameName(mv1_model,i);
      collision_flame.insert(std::make_pair(frame_name,i));
    }

    return true;
  };

  int Mv1Model::AttachAnim(int anim_index,int anim_src_mhandle,int name_check)
  {
    return DxLib::MV1AttachAnim(mv1_model,anim_index,anim_src_mhandle,name_check);
  }

  int Mv1Model::DetachAnim(int attach_index)
  {
    return DxLib::MV1DetachAnim(mv1_model,attach_index);
  };

  int Mv1Model::SetAttachAnimTime(int attach_index,float time)
  {
    return DxLib::MV1SetAttachAnimTime(mv1_model,attach_index,time);
  };

  float Mv1Model::GetAttachAnimTotalTime(int attach_index)
  {
    return DxLib::MV1GetAttachAnimTotalTime(mv1_model,attach_index);
  };
}