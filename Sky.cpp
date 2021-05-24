#include "DXUT.h"
#include "Sky.h"

void Sky::Init()
{
	mesh = IMAGE->FindMesh(L"Sky");
	
}

void Sky::Update()
{
	RotatePos(Vector3(0,D_TIME * 100,0));
}

void Sky::Render()
{
	IMAGE->MeshRender(mesh, matWorld, CullMode::NONECULL);

}

void Sky::Release()
{
}

void Sky::onCollisionEnter(Collider* col1, Collider* col2)
{
}

void Sky::onCollisionStay(Collider* col1, Collider* col2)
{
}

void Sky::onCollisionExit(Collider* col1, Collider* col)
{
}
