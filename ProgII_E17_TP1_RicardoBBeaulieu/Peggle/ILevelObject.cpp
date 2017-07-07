#include "stdafx.h"
#include "ILevelObject.h"

ILevelObject::ILevelObject()
{
	
}

ILevelObject::~ILevelObject()
{
	ReleaseCOM(texture);
}

void ILevelObject::Update()
{

}

void ILevelObject::Draw(ID3DXSprite* spriteBatch)
{
	HR(spriteBatch->Draw(texture, 0, &center, &defaultPosition, D3DCOLOR_XRGB(255, 255, 255)));
	HR(spriteBatch->Flush());
}


