#include "Bloque.h"
#include "Interaccion.h"

Bloque::Bloque(void) //Creación por defecto
{
}


Bloque::~Bloque(void) //Destruye todas las paredes con su destructor 
{
	suelo.~Planobloque();
	techo.~Planobloque();
	pared_dcha.~Planobloque();
	pared_izq.~Planobloque();

}

void Bloque::dibuja() //Dibuja las 5 caras (salvo la trasera) de un cubo
{
	suelo.dibuja();
	techo.dibuja();
	pared_izq.dibuja();
	pared_dcha.dibuja();
}

bool Bloque::rebota(Esfera &e) //devuelve si choca o no.
{
	if ((Interaccion::rebote(e,suelo))||(Interaccion::rebote(e,techo))||(Interaccion::rebote(e,pared_dcha))||(Interaccion::rebote(e,pared_izq)))
		return true; 
	else 
		return false;
}
