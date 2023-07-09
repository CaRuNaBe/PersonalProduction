#include "SkySphere.h"

SkySphere::SkySphere(ApplicationBase& game,int layer)
  :GameBase(game,layer)
  ,modele("res/skysphere_morning/cg_stageSkymap_1.mv1")
{};
SkySphere::~SkySphere()
{};
bool SkySphere::Update()
{
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