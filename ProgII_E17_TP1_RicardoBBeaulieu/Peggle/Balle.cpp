#include "stdafx.h"
#include "Balle.h"

Balle::Balle()
	: center(.0f, .0f, .0f)
	, position(.0f, .0f, .0f)
	,  newDirection(2)
{
	HR(D3DXCreateTextureFromFileEx(gD3DDevice, L"Pokeball.png", 0, 0, 1, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255), &info, NULL, &texture));
	
	//center = D3DXVECTOR3(info.Width / 2, info.Height / 2, 0.f);
}

Balle::~Balle()
{
	ReleaseCOM(texture);
}

void Balle::UpdatePosition()
{
	//std::cout << position.x << std::endl;
	std::cout << (gD3DApp->GetSize().right - gD3DApp->GetSize().left) << std::endl;
	std::cout << (gD3DApp->GetSize().bottom) << std::endl;

	CheckPosition();
	switch (newDirection)
	{
	case 1:
		position += D3DXVECTOR3(-50.f, 0.f, 0.f) * gD3DApp->GetTimer()->GetDeltaTime();
		break;
	case 2:
		position += D3DXVECTOR3(50.f, 0.f, 0.f) * gD3DApp->GetTimer()->GetDeltaTime();
		break;
	}
}

void Balle::SetDirection(int direction)
{
	switch (direction)
	{
	case 1:
		newDirection = direction;
		break;
	case 2:
		newDirection = direction;
		break;
	}
}

void Balle::CheckPosition()
{
	if (position.x >= (gD3DApp->GetSize().right - gD3DApp->GetSize().left) / 2)
	{
		SetDirection(LEFT);
		
	}
	if (position.x <= gD3DApp->GetSize().right)
	{
		//SetDirection(RIGHT);
	}
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
