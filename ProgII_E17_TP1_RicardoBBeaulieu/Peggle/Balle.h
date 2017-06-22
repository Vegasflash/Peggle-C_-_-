#pragma once

#include "stdafx.h"
#include "Sprite.h"


#define LEFT 1
#define RIGHT 2

class Balle : Sprite
{
public:
	Balle();
	~Balle();

	void Update();
	void UpdatePosition();
	void Draw(ID3DXSprite* spriteBatch);
	void CheckPosition();
	void SetDirection(int direction);
	


private:	
	// Sprite
	int newDirection;

	IDirect3DTexture9* texture;
	D3DXIMAGE_INFO info;
	D3DXVECTOR3 position;
	D3DXVECTOR3 center;
};

