/*****************************************************************//**
 * \file   SkySphere.cpp
 * \brief  スカイスフィアクラス(宣言)
 * \author 阿部健太郎
 * \date   July 2023
 *********************************************************************/
#include "SkySphere.h"

SkySphere::SkySphere(ApplicationBase& game,int layer,ModeGame& mode,std::string filename)
  :ObjectBase3d(game,layer,mode,filename)
{};

SkySphere::~SkySphere()
{};

bool SkySphere::Update()
{
  mymath::Matrix44 transform;
  modele.SetMatrix(transform);
  return true;
};

bool SkySphere::Draw()
{
  modele.Draw();
  return true;
};

bool SkySphere::DebugDraw()
{
  return true;
};