#include "stdafx.h"
#include "Canon.h"

Canon::Canon()
	: center((256/2) + 80, 128/2, .0f)
	, position(0, -300, 0.f)
{
	HR(D3DXCreateTextureFromFileEx(gD3DDevice, CANNON_IMAGE, 0, 0, 1, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255), &info, NULL, &texture));

	//center = D3DXVECTOR3(info.Width / 2, info.Height / 2, 0.f);
}

Canon::~Canon()
{
	ReleaseCOM(texture);
}

void Canon::Update()
{
	if (gD3DApp->GetInput()->KeyDown(DIK_LEFT))
	{
		position = D3DXVECTOR3(0, 0, 0);
		RotateCanon(10.0f);
	}
	else
	{
		position = D3DXVECTOR3(0, -300, 0.f);
	}
	if (gD3DApp->GetInput()->KeyDown(DIK_RIGHT))
	{
		position = D3DXVECTOR3(0, 0, 0);
		RotateCanon(-10.0f);
	}
	else 
	{
		position = D3DXVECTOR3(0, -300, 0.f);
	}
}

void Canon::Draw(ID3DXSprite * spriteBatch)
{
	D3DXMatrixIdentity(&rotMatrix);
	spriteBatch->SetTransform(&rotMatrix);
	HR(spriteBatch->Draw(texture, 0, &center, &position, D3DCOLOR_XRGB(255, 255, 255)));
	HR(spriteBatch->Flush());
}


void Canon::RotateCanon(float rotation)
{
	D3DXMatrixRotationYawPitchRoll(&rotMatrix, rotEuler.x, rotEuler.y, rotEuler.z);
	rotEuler += D3DXVECTOR3(0.f, 0.f, rotation) * gD3DApp->GetTimer()->GetDeltaTime();
}
