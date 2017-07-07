#include "stdafx.h"
#include "Net.h"


Net::Net()
	: center(117.5f, 57.5f, .0f)
	, position(0, 250, 0)
{
	HR(D3DXCreateTextureFromFileEx(gD3DDevice, NET_IMAGE, 0, 0, 1, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255), &info, NULL, &texture));
}


Net::~Net()
{
}

void Net::Update()
{
}

void Net::Draw(ID3DXSprite* spriteBatch)
{
	HR(spriteBatch->Draw(texture, 0, &center, &position, D3DCOLOR_XRGB(255, 255, 255)));
	HR(spriteBatch->Flush());
}

void Net::Draw(ID3DXSprite* spriteBatch, D3DXVECTOR3* position)
{
	HR(spriteBatch->Draw(texture, 0, &center, position, D3DCOLOR_XRGB(255, 255, 255)));
	HR(spriteBatch->Flush());
}

int Net::PointCounter()
{
	// Does not give points, nor is it part of it functionality, but regardless it is a LevelObject which REQUIRES a PointCounter
	return 0;
}
