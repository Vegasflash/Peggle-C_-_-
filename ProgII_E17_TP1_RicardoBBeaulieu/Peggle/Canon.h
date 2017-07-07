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

	void RotateCanon(float rotation);
	void SetRotation();

private:
	// Sprite
	D3DXVECTOR3 rotEuler;
	D3DXMATRIX rotMatrix;
	IDirect3DTexture9* texture;
	D3DXIMAGE_INFO info;
	D3DXVECTOR3 position;
	D3DXVECTOR3 center;
};

