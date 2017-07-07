#pragma once
#include "stdafx.h"
#include "Sprite.h"
#include "Collision.h"
#include <time.h>

class ILevelObject :
	public Sprite
{
public:
	ILevelObject();
	~ILevelObject();
	virtual void Update() override;
	virtual void Draw(ID3DXSprite* spriteBatch) override;
	virtual void Draw(ID3DXSprite* spriteBatch, D3DXVECTOR3* position) = 0;

	//virtual void CollisionTest() = 0;
	virtual int PointCounter() = 0;

protected:
	IDirect3DTexture9* texture;
	D3DXIMAGE_INFO info;
	D3DXVECTOR3 defaultPosition;
	D3DXVECTOR3 center;

private:

	
};

