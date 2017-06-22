#pragma once
#include "stdafx.h"
#include "Sprite.h"

class Background : Sprite
{
public:
	Background();
	~Background();

	void Draw(ID3DXSprite* spriteBatch);

private:
	IDirect3DTexture9* texture;
	D3DXIMAGE_INFO info;
	D3DXVECTOR3 position;
	D3DXVECTOR3 center;
};

