/*****************************************************************//**
 * \file   SkySphere.cpp
 * \brief  �X�J�C�X�t�B�A�N���X(�錾)
 * \author ���������Y
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