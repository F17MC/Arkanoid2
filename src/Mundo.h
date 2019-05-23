#include "Caja.h"	
#include "Ficha.h"	
#include "Esfera.h"	
#include "Bloque.h"
#include "ListaBloques.h"
#include "Vidas.h"
#include "Puntos.h"

class Mundo
{
	Esfera esfera;
	Ficha ficha;
	Caja caja;
	Bloque bloque; 
	ListaBloques bloques;
	Vidas vds;
	Puntos punto;

	float x_ojo;
	float y_ojo;
	float z_ojo;
public: 
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
	~Mundo();
};
