#include "stdafx.h"
#include "Collision.h"


Collision::Collision(const float x, const float y, const float radius)
{
	position.x = x;
	position.y = y;
	this->radius = radius;
}

Collision::Collision(const D3DXVECTOR3 * center, const float radius)
{
	position.x = center->x;
	position.y = center->y;
	this->radius = radius;
}

Collision::~Collision()
{
}

bool Collision::Contains(const float x, const float y) const
{
	float length;
	float heigth;

	if (position.x > x)
		length = position.x - x;
	else
		length = x - position.x;

	if (position.y > y)
		heigth = position.y - y;
	else
		heigth = y - position.y;


	if (((length * length) + (heigth * heigth)) < (this->radius * this->radius))
		return true;
	else
		return false;
}

bool Collision::Contains(const D3DXVECTOR3 * point) const
{
	float length;
	float heigth;

	// affecte la difference positive
	length = position.x > point->x
		?
		position.x - point->x
		:
		point->x - position.x;

	// affecte la difference positive
	heigth = position.y > point->y
		?
		position.y - point->y
		:
		heigth = point->y - position.y;

	// a² + b² = c²
	//pas besoin de faire la racine pour comparer des distance:
	// si c² < r², alors c < r
	if (((length * length) + (heigth * heigth)) <= GetRadiusSq())
		return true;
	else
		return false;
}

float Collision::GetX() const
{
	return this->position.x;
}

float Collision::GetY() const
{
	return this->position.y;
}

float Collision::GetRadiusSq() const
{
	return (this->radius * this->radius);
}

float Collision::GetRadius() const
{
	return this->radius;
}

void Collision::SetPosition(const D3DXVECTOR3 * vect)
{
	position.x = vect->x;
	position.y = vect->y;
}

void Collision::SetPosition(const float x, const float y)
{
	position.x = x;
	position.y = y;
}
