#include "DXUT.h"
#include "Stage1.h"
#include "Map.h"
#include "Sky.h"

void Stage1::Init()
{
	CAMERA->Reset();
	DEBUG_LOG("asdfsadfsa");
	OBJECT->AddObject(L"Map", new Map, Vector3(0, 0, 0), RenderType::THREE);
	OBJECT->AddObject(L"Sky", new Sky, Vector3(0, 0, 0), RenderType::THREE);
}

void Stage1::Update()
{
}

void Stage1::Render()
{
}

void Stage1::Release()
{
}
