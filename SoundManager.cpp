#include "DXUT.h"
#include "SoundManager.h"

SoundManager::SoundManager()
{
	manager = new CSoundManager;
	manager->Initialize(DXUTGetHWND(), 2);
}

SoundManager::~SoundManager()
{
	for (auto iter : sounds) SAFE_DELETE(iter.second);
	sounds.clear();

	SAFE_DELETE(manager);
}

void SoundManager::AddSound(wstring key, wstring path)
{
	auto find = sounds.find(key);
	if (find != sounds.end()) return;
	CSound* sound;
	manager->Create(&sound, (LPWSTR)path.c_str(), DSBCAPS_CTRLVOLUME);
	sounds[key] = sound;
}

void SoundManager::Play(wstring key, BOOL isLoop)
{
	auto find = sounds.find(key);
	if (find == sounds.end()) return;
	find->second->Play(0, isLoop);
}

void SoundManager::Copy(wstring key, long volume)
{
	auto find = sounds.find(key);
	if (find == sounds.end()) return;
	LPDIRECTSOUNDBUFFER buff;
	manager->GetDirectSound()->DuplicateSoundBuffer(find->second->GetBuffer(0), &buff);
	buff->SetCurrentPosition(0);
	buff->SetVolume(volume);
	buff->Play(0, 0, 0);
}

void SoundManager::Stop(wstring key)
{
	auto find = sounds.find(key);
	if (find == sounds.end()) return;
	find->second->Stop();
}
