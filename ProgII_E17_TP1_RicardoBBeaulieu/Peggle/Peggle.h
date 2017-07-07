
#include "stdafx.h"
#include "D3DApp.h"

#include "GameManager.h"


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

	GameManager gameManager;

	// Camera
	D3DXMATRIX view;
	D3DXMATRIX ortho;
	D3DXVECTOR3 eyePos;
	D3DXVECTOR3 target;
	D3DXVECTOR3 up;




};
