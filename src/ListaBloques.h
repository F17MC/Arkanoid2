#pragma once
#define MAX_BLOQUES 52
#include "Bloque.h"
#include "Esfera.h"
class ListaBloques
{
	friend class Interaccion;
public:
	ListaBloques(void);
	~ListaBloques(void);
	Bloque * lista[MAX_BLOQUES];
	Bloque * rebota(Esfera &e);
	void rebote(Esfera &e);
	bool agregar (Bloque *b);
	void dibuja();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Bloque *b);
private:
	int numero;
};

