#include "stdafx.h"
#include "D3DApp.h"

#include "Canon.h"
#include "Balle.h"
#include "Background.h"

class Peggle 
	: public D3DApp
{
public:
	Peggle();
	Peggle(HINSTANCE hInstance, int nCmdShow);
	~Peggle();

	void Update();
	void Draw();

private:
	ID3DXSprite* spriteBatch;

	// Objets
	Canon canon;
	Balle balle;
	Background backGround;

	// Camera
	D3DXMATRIX view;
	D3DXMATRIX ortho;
	D3DXVECTOR3 eyePos;
	D3DXVECTOR3 target;
	D3DXVECTOR3 up;
};
