#include "stdafx.h"
#include "Background.h"


Background::Background()
	: center(.0f, .0f, .0f)
	, position(-(1260.0f / 2), -(970.0f / 2), .0f)
{
	HR(D3DXCreateTextureFromFileEx(gD3DDevice, L"Background.png", 0, 0, 1, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255), &info, NULL, &texture));
	
}

Background::~Background()
{
	ReleaseCOM(texture);
}

void Background::Draw(ID3DXSprite * spriteBatch)
{
	HR(spriteBatch->Draw(texture, 0, &center, &position, D3DCOLOR_XRGB(255, 255, 255)));
	HR(spriteBatch->Flush());
}
