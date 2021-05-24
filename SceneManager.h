#pragma once
#include "singleton.h"

#include "Scene.h"
class SceneManager :
    public singleton<SceneManager>
{
private:
    Scene* nowScene;
    Scene* nextScene;
    map<string, Scene*> scenes;

    void Release();

public:
    SceneManager();
    virtual ~SceneManager();

    Scene* AddScene(const string& key, Scene* scenePtr);
    Scene* ChangeScene(const string& key);

    void Update();
    void Render();
};

#define SCENE SceneManager::GetInstance()