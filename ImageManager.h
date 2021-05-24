#pragma once
#include "singleton.h"
#include "MeshLoader.h"

enum CullMode
{
    CW,
    CCW,
    NONECULL,
};

struct texture
{
    LPDIRECT3DTEXTURE9 texturePtr;
    D3DXIMAGE_INFO info;

    texture(LPDIRECT3DTEXTURE9 texturePtr, D3DXIMAGE_INFO info)
        :texturePtr(texturePtr), info(info)
    {

    }

    void CenterRender(Vector3 pos, Vector3 rot = { 0,0,0 }, Vector3 size = { 1,1,1 }, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
    void Render(Vector3 pos, Vector3 rot = { 0,0,0 }, Vector3 size = { 1,1,1 }, RECT rect = { 0,0,0,0 }, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));

    void Release();
};

struct VECtexture
{
    vector<texture*> vecTex;
public:
    VECtexture();
    virtual ~VECtexture();
    void ADDIMAGE(texture* tempImage);
    texture* FINDIMAGE(int count = -1);
};

struct VECMesh {
    vector<CMeshLoader*> vecMesh;
public:
    VECMesh();
    ~VECMesh();

    void ADDMESH(CMeshLoader* tempImage);
    CMeshLoader* FINDMESH(int count = -1);
};

class ImageManager :
    public singleton<ImageManager>
{
public:
    LPD3DXSPRITE sprite;
    map<wstring, texture*> imageMap;
    map<wstring, VECtexture*> vecImageMap;
    map<wstring, CMeshLoader*> meshMap;
    map<wstring, VECMesh*> vecMeshes;

    LPD3DXFONT lpFont;

    void Init();
    void Release();

    ImageManager();
    virtual ~ImageManager();

    texture* AddImage(wstring key, wstring path, bool isMapping = false);
    texture* FindImage(wstring key);

    VECtexture* ADDVECIMAGE(wstring key, wstring path, int max);
    VECtexture* FINDVECIMAGE(wstring key);

    CMeshLoader* AddMesh(wstring key, wstring path);
    CMeshLoader* FindMesh(wstring key);

    VECMesh* ADDVECMESH(wstring key, wstring path, int max);
    VECMesh* FINDVECMESH(wstring key);

    void Begin(bool isUi, bool isBill);
    void ReBegin(bool isUi, bool isBill);
    void End();

    void CenterRender(texture* texturePtr, Vector3 pos, Vector3 rot = { 0,0,0 }, Vector3 size = { 1,1,1 }, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
    void Render(texture* texturePtr, Vector3 pos, Vector3 rot = { 0,0,0 }, Vector3 size = { 1,1,1 }, RECT rect = { 0,0,0,0 }, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));

    void MeshRender(CMeshLoader* meshPtr, Matrix matWorld, CullMode cullMode, bool alphaTest = false);

    void TextDraw(wstring str, Vector3 pos, float size, D3DCOLOR color, bool center, bool isBill = false);

    void LostDevice();
    void ResetDevice();
};

#define IMAGE ImageManager::GetInstance()