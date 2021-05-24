#include "DXUT.h"
#include "Map.h"

void Map::Init()
{
	mesh = IMAGE->FindMesh(L"Map");
	SetRotate(Vector3(0, 0, 0));
}

void Map::Update()
{
}

void Map::Render()
{
	IMAGE->MeshRender(mesh, matWorld, CullMode::CCW, true);
}

void Map::Release()
{
}

void Map::onCollisionEnter(Collider* col1, Collider* col2)
{
}

void Map::onCollisionStay(Collider* col1, Collider* col2)
{
}

void Map::onCollisionExit(Collider* col1, Collider* col)
{
}
