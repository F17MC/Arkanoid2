#pragma once
#include "Ladrillos.h"
#include "Esfera.h"
#include "Interaccion.h"

#define MAX_LADRILLOS 80

class ConjuntoBloques
{
public:
	ConjuntoBloques(void);
	virtual ~ConjuntoBloques(void);
	bool agregar (Ladrillos *e);
	void dibuja();
	//void rebote (Esfera esfera);
private:
	Ladrillos * lista[MAX_LADRILLOS];
	int numero;
};

