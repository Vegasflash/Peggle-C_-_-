#pragma once

#include "stdafx.h"
#include "D3DApp.h"
#include "Sprite.h"

class Canon : Sprite
{
public:
	Canon();
	~Canon();

	void Update();
	void Draw(ID3DXSprite * spriteBatch);

	void CheckRotation();
	void SetRotation();

private:
	// Sprite
	HWND hwnd;
	RECT windowRect;

	IDirect3DTexture9* texture;
	D3DXIMAGE_INFO info;
	D3DXVECTOR3 position;
	D3DXVECTOR3 center;
};

