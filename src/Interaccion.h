#pragma once

#include "Ficha.h"
#include "Caja.h"
#include "Esfera.h"
#include "Bloque.h"
#include "ListaBloques.h"
class Interaccion  
{
public:
	Interaccion();
	virtual ~Interaccion();	
	static bool rebote(Esfera &e, Pared p);
	static void rebote(Esfera &e, Caja c);
	static void rebote(Ficha &h, Caja c);
	static bool rebote(Esfera &e, Ficha h);
	static bool rebote(Esfera &e, Planobloque pb);
	static bool rebote(Esfera &e, Bloque b);
	static bool rebote(Esfera &e, ListaBloques *lb);
};



