
#pragma once

#include "Vector2D.h"

class Hombre
{
	friend class Interaccion;
public:
	void mueve(float t);
	void dibuja();
	Hombre();
	virtual ~Hombre();
	void setVel(float vx, float vy);
private:
	float altura;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

};

