#pragma once

#include "stdafx.h"
#include "ILevelObject.h"
#include <string.h>
#include <vector>


class Orb :
	public ILevelObject
{
public:
	Orb();
	Orb(D3DXVECTOR3* position);
	~Orb();

	void Draw(ID3DXSprite* spriteBatch) override;
	void Draw(ID3DXSprite* spriteBatch, D3DXVECTOR3* position) override;
	void Update() override;

	int GetRandomColor();
	int PointCounter();

private:

	Collision* collision;
	D3DXVECTOR3 orbPosition;
	D3DXVECTOR3 center;

	float radius;
	int colorKey;
};

