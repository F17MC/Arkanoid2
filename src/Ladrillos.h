#pragma once
#include "Vector2D.h"

class Ladrillos
{
public:
	Ladrillos(void);
	~Ladrillos(void);
	void dibuja();
	void setPos(float ix,float iy);
	float distancia(Vector2D punto, Vector2D *direccion);
private:
	float lado;
	Vector2D posicion;
	Vector2D limite1;
	Vector2D limite2;
};

