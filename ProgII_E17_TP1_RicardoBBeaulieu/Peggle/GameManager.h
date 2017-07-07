#pragma once

#include "stdafx.h"
#include "ILevelObject.h"
#include "Canon.h"
#include "Balle.h"
#include <vector>
#include "Background.h"
#include "Orb.h"
#include "Constant.h"
#include "Net.h"
#include "Score.h"


class GameManager
{
public:
	GameManager();
	void CreateOrbVector();
	~GameManager();

	void Update();
	void ScoreBoard();
	void SetOrbList();
	void InitializeOrbPositions();
	D3DXVECTOR3 GetOrbPosition(int i, int j);
	void DrawLevel(ID3DXSprite* spriteBatch);

	

	//Circle Methods
	bool Contains(float x, float y) const;
	bool Contains(const D3DXVECTOR2* const point) const;
	float GetX();
	float GetY();
	float GetRadiusSq();
	float GetRadius();
	void SetPosition(D3DXVECTOR2* vect);
	void SetPosition(float x, float y);
	void MoveBy(const D3DXVECTOR2* const vect);
	void MoveBy(const float x, const float y);

private:
	

	// Circle Collision Variables
	float x, y, radius;
	float orbListSize;
	D3DXVECTOR2 center;

	std::vector<Orb*> orbVector;

	// Objets
	Canon canon;
	Balle balle;
	Background backGround;
	Orb orb;
	Net net;
	Score score;

	// Object Positions
	D3DXVECTOR3 spawnPointsPos[9][4];
	D3DXVECTOR3 greenOrbPos;
	D3DXVECTOR3 redOrbPos;
	D3DXVECTOR3 blueOrbPos;
	D3DXVECTOR3 netPos;
};

