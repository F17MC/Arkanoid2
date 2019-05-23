#include "Caja.h"


Caja::Caja() //Configuramos los colores y la posición de cada plano de la caja
{
	suelo.setColor(0,0,0);
	suelo.setPos(-13.0f,0,13.0f,0);

	techo.setColor(153,255,0);
	techo.setPos(-13.0f,15.0f,13.0f,15.0f);
	
	pared_dcha.setColor(100,220,0);
	pared_dcha.setPos(-13.0f,0,-13.0f,15.0f);

	pared_izq.setColor(100,220,0);
	pared_izq.setPos(13.0f,0,13.0f,15.0f);
}

Caja::~Caja() //Destructores de cada plano individual
{
	pared_dcha.~Pared();
	pared_izq.~Pared();
	techo.~Pared();
	suelo.~Pared();
}

void Caja::dibuja() //Dibuja cada plano 
{
	suelo.dibuja();
	techo.dibuja();
	pared_izq.dibuja();
	pared_dcha.dibuja();
}
