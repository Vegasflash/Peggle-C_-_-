#include "stdafx.h"
#include "Balle.h"

Balle::Balle()
	: center(10.0f, 10.0f, .0f)
	, position(.0f, .0f, .0f)
	, newDirection(.0f, .0f, .0f)
	, speed (200.0f)
	, gravity (100.0f)
	, dx(0.5)
	, dy(0.5)
{
	HR(D3DXCreateTextureFromFileEx(gD3DDevice, BALL_IMAGE, 0, 0, 1, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255), &info, NULL, &texture));
}

Balle::Balle(D3DXVECTOR3 * position)
	: center(10.0f, 10.0f, .0f)
	, position(.0f, .0f, .0f)
	, newDirection(.0f, .0f, .0f)
	, speed(200.0f)
	, gravity(100.0f)
	, dx(0.5)
	, dy(0.5)
{
	HR(D3DXCreateTextureFromFileEx(gD3DDevice, BALL_IMAGE, 0, 0, 1, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255), &info, NULL, &texture));
}

Balle::~Balle()
{
	ReleaseCOM(texture);
}

void Balle::UpdatePosition()
{

	CheckCollision();
	//GRAVITY
	//std::cout << position.x << "," << position.y << std::endl;

	position += D3DXVECTOR3(dx, dy, 0.f) * speed * gD3DApp->GetTimer()->GetDeltaTime();
	

	if (position.x >= ((gD3DApp->GetSize().right - gD3DApp->GetSize().left) / 2) - 20.0f)
	{
		dx = -dx;
	}

	if (position.x <= -((gD3DApp->GetSize().right + gD3DApp->GetSize().left) / 2) + 20.0f)
	{
		dx = -dx;
	}
	if (position.y >= ((gD3DApp->GetSize().bottom - gD3DApp->GetSize().top) / 2) - 20.0f)
	{
		dy = -dy;
	}
	if (position.y <= -((gD3DApp->GetSize().bottom + gD3DApp->GetSize().top) / 2) + 20.0f)
	{
		dy = -dy;
	}
}

void Balle::CheckCollision()
{
}

void Balle::Update()
{	
	UpdatePosition();	
}


void Balle::Draw(ID3DXSprite* spriteBatch)
{
	HR(spriteBatch->Draw(texture, 0, &center, &position, D3DCOLOR_XRGB(255, 255, 255)));
	HR(spriteBatch->Flush());
}
