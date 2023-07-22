/*****************************************************************//**
 * \file   Mv1Model.h
 * \brief  dxライブラリのMV!モデルの処理をまとめたクラス定義
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
    /** 	アニメーションをアタッチする */
    int AttachAnim(int anim_index,int anim_src_mhandle = -1,int name_check = 1);
  private:
    /** モデルのアニメーションの名前と総再生時間をvectorに入れる */
    void SetVectorAnimationNameAndTime();
    int mv1_model;
    std::vector<std::tuple<std::string,float>> animation_name_and_time_vector;
    std::map<std::string,int> collision_flame;
  };
}
