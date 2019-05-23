#pragma once
#include "Pared.h"

class Caja  
{
	friend class Interaccion;
public:
	void dibuja();
	Caja(); //Constructor de caja
	virtual ~Caja(); //Destructor virtual de caja
	Pared suelo;
	Pared techo;
	Pared pared_izq;
	Pared pared_dcha;
};

