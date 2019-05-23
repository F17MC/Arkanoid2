#pragma once
#include "Planobloque.h"
#include "Esfera.h"

class Bloque
{
	friend class Interaccion; 
public:
	Bloque(); //Constructor de bloques
	virtual ~Bloque(); //Destructor virtual de bloques
	void dibuja();
	bool rebota (Esfera &e); //rebote con la esfera
	Planobloque suelo;
	Planobloque techo;
	Planobloque pared_izq;
	Planobloque pared_dcha;
};


