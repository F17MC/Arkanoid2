
#pragma once

#include "Vector2D.h"

class Ficha
{
	friend class Interaccion;
public:
	void mueve(float t);
	void dibuja();
	Ficha();
	virtual ~Ficha();
	void setVel(float vx, float vy); //para moverse
	float distancia(Vector2D punto, Vector2D *direccion);//para rebote
	void setPos(float x1, float y1, float x2, float y2);//para rebote

private:
	float altura;
	Vector2D posicion;
	Vector2D velocidad;	
	Vector2D aceleracion;

	Vector2D limite1;
	Vector2D limite2;
};

