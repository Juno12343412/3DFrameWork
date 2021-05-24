#include "DXUT.h"
#include "LoadingScene.h"

void LoadingScene::Init()
{
	CAMERA->Reset();
	ImageLoad(L"VayneIdle", L"Vayne/Idle", Type::LTHREE ,29);
	ImageLoad(L"Map", L"Map/TftMap/TftMap", Type::LTHREE);
	ImageLoad(L"Sky", L"Map/TftSky/SkyBox", Type::LTHREE);
}

void LoadingScene::Update()
{
	if (!imageList.empty())
	{
		auto info = imageList.front();
		IMAGE->AddImage(info.key, info.path);
		imageList.pop_front();
		imageCount++;
	}
	if (!aniList.empty())
	{
		auto info = aniList.front();
		IMAGE->ADDVECIMAGE(info.key, info.path, info.size);
		aniList.pop_front();
		imageCount++;
	}
	if (!meshList.empty())
	{
		auto info = meshList.front();
		IMAGE->AddMesh(info.key, info.path);
		meshList.pop_front();
		imageCount++;
	}
	if (!meshAniList.empty())
	{
		auto info = meshAniList.front();
		IMAGE->ADDVECMESH(info.key, info.path, info.size);
		meshAniList.pop_front();
		imageCount++;
	}
	if (!soundList.empty())
	{
		auto info = soundList.front();
		soundList.pop_front();
		SOUND->AddSound(info.key, info.path);
		imageCount++;
	}
	if (imageList.empty() && aniList.empty() && meshList.empty() && meshAniList.empty())
	{
		DEBUG_LOG("로딩끝");
		SCENE->ChangeScene("stage1");
	}
}

void LoadingScene::Render()
{
	IMAGE->ReBegin(true, false);
	WCHAR a[12];
	wsprintf(a, L"로딩중..%d/%d", imageCount, maxImageCount);
	IMAGE->TextDraw(a, Vector3(WINSIZEX / 2 - 20, WINSIZEY / 2, 0), 200, D3DCOLOR_XRGB(255, 255, 255), true);
	IMAGE->ReBegin(false, false);
}

void LoadingScene::Release()
{
}

void LoadingScene::ImageLoad(const wstring& key, const wstring& path, Type tp, int size)
{
	if (tp == Type::LTWO) {
		if (size == 0)
		{
			imageList.push_back(Load(key, path));
			maxImageCount++;
		}
		else
		{
			aniList.push_back(Load(key, path, size));
			maxImageCount++;
		}
	}
	else if(tp == Type::LTHREE)
	{
		if (size == 0)
		{
			meshList.push_back(Load(key, path));
			maxImageCount++;
		}
		else
		{
			meshAniList.push_back(Load(key, path, size));
			maxImageCount++;
		}
	}
	else
	{
		soundList.push_back(Load(key, path));
		maxImageCount++;
	}
}
