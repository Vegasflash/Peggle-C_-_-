#pragma once
#include "stdafx.h"
#include "ILevelObject.h"

class Net :
	public ILevelObject
{
public:
	Net();
	~Net();

	virtual void Update() override;
	virtual void Draw(ID3DXSprite* spriteBatch) override;
	void Draw(ID3DXSprite* spriteBatch, D3DXVECTOR3* position)override;

	int PointCounter()override;

private:
	D3DXVECTOR3 center;
	D3DXVECTOR3 position;
};

