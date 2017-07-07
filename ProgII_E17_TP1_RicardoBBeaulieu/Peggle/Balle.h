#pragma once

#include "stdafx.h"
#include "Sprite.h"

class Balle : public Sprite
{
public:
	Balle();
	Balle(D3DXVECTOR3* position);
	~Balle();

	void Update() override;
	void Draw(ID3DXSprite* spriteBatch) override;

	void UpdatePosition();

	void CheckCollision();
	


private:	
	// Sprite
	float speed;
	float dx, dy;
	float gravity;
	bool isColliding;

	D3DXVECTOR3 newDirection;

	D3DXVECTOR3 center;
	D3DXIMAGE_INFO info;
	D3DXVECTOR3 position;
	IDirect3DTexture9* texture;
};

