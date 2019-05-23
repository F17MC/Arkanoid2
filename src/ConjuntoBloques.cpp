#include "ConjuntoBloques.h"


ConjuntoBloques::ConjuntoBloques(void)
{
	numero=0;
	for (int i=0; i<MAX_LADRILLOS;i++)
		lista[i]=0;
}


ConjuntoBloques::~ConjuntoBloques(void)
{
}

bool ConjuntoBloques::agregar (Ladrillos *e)
{
	if (numero<MAX_LADRILLOS)
		lista[numero++]=e;
	else
		return false;
	return true;
}

void ConjuntoBloques::dibuja()
{
	for (int i=0;i<numero;i++)
			lista[i]->dibuja();
}

/*
void ConjuntoBloques::rebote (Esfera esfera)
{
	for (int i=0; i<numero; i++)
		Interaccion::rebote(*(lista[i]), esfera);
}*/