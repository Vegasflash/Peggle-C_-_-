#pragma once

#include "stdafx.h"
#include "Sprite.h"

class Score :
	public Sprite
{
public:
	Score();
	~Score();

	void Update()override;
	void Draw(ID3DXSprite * spriteBatch)override;
};

