#pragma once

#include "stdafx.h"
#include "D3DApp.h"
#include "Constant.h"

class Sprite
{
public:
	Sprite();
	~Sprite();

	// Must overrie the following functions
	virtual void Update() = 0;
	virtual void Draw(ID3DXSprite * spriteBatch) = 0;

private:
	// Sprite
};

