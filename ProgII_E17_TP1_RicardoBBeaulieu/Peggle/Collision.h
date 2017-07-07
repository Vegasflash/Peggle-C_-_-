#pragma once

#include "stdafx.h"

class Collision
{
public:
	Collision(const float x, const float y, const float radius);
	Collision(const D3DXVECTOR3* center, const  float radius);
	~Collision();

	bool Contains(const float x, const float y) const;
	bool Contains(const D3DXVECTOR3* point) const;
	float GetX() const;
	float GetY() const;
	float GetRadiusSq() const;
	float GetRadius() const;
	void SetPosition(const D3DXVECTOR3* vect);
	void SetPosition(const float x, const float y);


private:
	D3DXVECTOR3 position;
	float radius;
};

