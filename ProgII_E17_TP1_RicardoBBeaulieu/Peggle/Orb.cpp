#include "stdafx.h"
#include "Orb.h"


Orb::Orb()
	: center( 10.0f, 10.0f, .0f)
	, radius(10.0f)
{
	colorKey = GetRandomColor();
	collision = new Collision(&center, radius);
}

Orb::Orb(D3DXVECTOR3* position)
	: center ( 10.0f, 10.0f, .0f)
	, radius(10.0f)
{
	
	collision = new Collision(&center, radius);
	collision->SetPosition(position);
	orbPosition = *position;
	colorKey = GetRandomColor();
}


Orb::~Orb()
{
}

void Orb::Draw(ID3DXSprite * spriteBatch, D3DXVECTOR3 * position)
{
	// Default Orb Type is Green
	HR(D3DXCreateTextureFromFileEx(gD3DDevice, GREEN_ORB_IMAGE, 0, 0, 1, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255), &info, NULL, &texture));
}

void Orb::Draw(ID3DXSprite* spriteBatch)
{
	switch (colorKey)
	{
	case 0:
		HR(D3DXCreateTextureFromFileEx(gD3DDevice, GREEN_ORB_IMAGE, 0, 0, 1, 0,
			D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_DEFAULT,
			D3DCOLOR_XRGB(255, 255, 255), &info, NULL, &texture));	
		break;
	case 1:
		HR(D3DXCreateTextureFromFileEx(gD3DDevice, RED_ORB_IMAGE, 0, 0, 1, 0,
			D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_DEFAULT,
			D3DCOLOR_XRGB(255, 255, 255), &info, NULL, &texture));
		break;
	case 2:
		HR(D3DXCreateTextureFromFileEx(gD3DDevice, BLUE_ORB_IMAGE, 0, 0, 1, 0,
			D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_DEFAULT,
			D3DCOLOR_XRGB(255, 255, 255), &info, NULL, &texture));
		break;
	}
	HR(spriteBatch->Draw(texture, 0, &center, &orbPosition, D3DCOLOR_XRGB(255, 255, 255)));
	HR(spriteBatch->Flush());
}

void Orb::Update()
{
}

int Orb::GetRandomColor()
{
	int tempRandom;
	
	tempRandom = rand() % 3;
	return tempRandom;
}

int Orb::PointCounter()
{
	return 10;
}


