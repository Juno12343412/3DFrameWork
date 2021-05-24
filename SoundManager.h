#pragma once
#include "singleton.h"
class SoundManager :
    public singleton<SoundManager>
{
private:
    map<wstring, CSound*> sounds;
    CSoundManager* manager;
public:
    SoundManager();
    virtual ~SoundManager();

    void AddSound(wstring key, wstring path);
    void Play(wstring key, BOOL isLoop);
    void Copy(wstring key, long volume = -1000);
    void Stop(wstring key);
};

#define SOUND SoundManager::GetInstance()