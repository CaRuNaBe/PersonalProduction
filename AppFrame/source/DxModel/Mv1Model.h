/*****************************************************************//**
 * \file   Mv1Model.h
 * \brief  dxライブラリのMV1モデルの処理をまとめたクラス定義
 * \author 阿部健太郎
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
    /** コンストラクタ */
    Mv1Model(std::string filename);
    /** コピーコンストラクタ */
    Mv1Model(const Mv1Model&) = delete;
    /** ムーブコンストラクタ */
    Mv1Model(Mv1Model&&) = default;

    /** デストラクタ */
    virtual ~Mv1Model();

    /** コピー代入 */
    Mv1Model& operator =(const Mv1Model&) = delete;
    /** ムーブ代入 */
    Mv1Model& operator =(Mv1Model&&) = default;

    /** MV1モデル描画関数 */
    void Draw();
    /** モデルの座標をセットする */
    bool SetPosition(const mymath::Vector4& position);
    /** モデルの拡大値をセットする */
    bool SetSetScale(const mymath::Vector4& scale);
    /** モデルの回転値をセットする x軸回転  y軸回転  z軸回転 の順で回転*/
    bool SetRotation(const mymath::Vector4& rotation);
    /** モデルの座標変換用行列をセットする */
    bool SetMatrix(const mymath::Matrix44& parameter);
    /** モデルの座標変換用行列を取得する */
    mymath::Matrix44 GetMatrix()const;
    /** モデルのすべてのフレームに対しコリジョン情報を構築する */
    bool SetupAllCollInfo();

    /** アニメーションをアタッチする */
    int AttachAnim(int anim_index,int anim_src_mhandle = -1,int name_check = 1);
    /** アニメーションをデタッチする */
    int DetachAnim(int attach_index);
    /** アタッチしているアニメーションの再生時間を設定する */
    int SetAttachAnimTime(int attach_index,float time);
    /** アタッチしているアニメーションの総時間を取得する */
    float GetAttachAnimTotalTime(int attach_index);
  private:
    int mv1_model;
    std::map<std::string,int> collision_flame;
  };
}
