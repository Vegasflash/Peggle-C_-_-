#pragma once

#include "stdafx.h"
#include "Canon.h"
#include "Balle.h"
#include "Background.h"

#define GREEN_ORB = "Green_Orb.png"
#define BLUE_ORB = "Blue_Orb.png"
#define RED_ORB = "Red_Orb.png"


class GameManager
{
public:
	GameManager();
	~GameManager();

private:

	// ball variables
	D3DXVECTOR3 ballPosition;
	D3DXVECTOR3 cannonPosition;
};

