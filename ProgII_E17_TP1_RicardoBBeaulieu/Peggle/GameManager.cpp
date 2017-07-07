#include "stdafx.h"
#include "GameManager.h"


GameManager::GameManager()
	: x(0.0f)
	, y(0.0f)
	, radius(0.0f)
	, center(0.0f, 0.0f)
{
	InitializeOrbPositions();
	CreateOrbVector();
}

void GameManager::CreateOrbVector()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			orbVector.push_back(new Orb(&GetOrbPosition(i, j)));
		}
	}
}


GameManager::~GameManager()
{
	for (int i = 0; i < 10; i++)
	{
		delete orbVector.at(i);
	}
}

void GameManager::Update()
{
	canon.Update();
	balle.Update();
}

void GameManager::ScoreBoard()
{
}

void GameManager::SetOrbList()
{

}

void GameManager::InitializeOrbPositions()
{
	D3DXVECTOR3 initialSpawnPos = D3DXVECTOR3(-450, 250, 0);
	D3DXVECTOR3 nextSpawnPos = initialSpawnPos;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			spawnPointsPos[i][j] = D3DXVECTOR3(0,0,0);
		}
	}

	for (int i = 0; i < 10; i++)
	{			
		if(i != 0)
			nextSpawnPos.x += 100;
		for (int j = 0; j < 5; j++)
		{
			nextSpawnPos.y -= 100;
			spawnPointsPos[i][j] = nextSpawnPos;
		}
		nextSpawnPos.y = initialSpawnPos.y;
	}
}

D3DXVECTOR3 GameManager::GetOrbPosition(int i, int j)
{
	return spawnPointsPos[i][j];
}


void GameManager::DrawLevel(ID3DXSprite* spriteBatch)
{

	backGround.Draw(spriteBatch);
	balle.Draw(spriteBatch);

	for (int i = 0; i < orbVector.size(); i++)
	{
		orbVector.at(i)->Draw(spriteBatch);
	}

	net.Draw(spriteBatch);
	canon.Draw(spriteBatch);
}



