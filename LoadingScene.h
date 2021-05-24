#pragma once
#include "Scene.h"
enum Type
{
	LTWO,
	LTHREE,
	LSOUND
};

struct Load
{
public:
	Load(const wstring& key, const wstring& path, int size = 0) : key(key), path(path), size(size) { }
	~Load() {}
public:
	wstring key;
	wstring path;
	int size = 0;
};

class LoadingScene :
	public Scene
{
public:
	virtual void Init()			override;
	virtual void Update()		override;
	virtual void Render()		override;
	virtual void Release()		override;
	void ImageLoad(const wstring& key, const wstring& path, Type tp, int size = 0);
	int imageCount = 0;
	int maxImageCount = 0;
	list<Load> imageList;
	list<Load> aniList;
	list<Load> meshList;
	list<Load> meshAniList;
	list<Load> soundList;
	texture* loadingBar;
};

