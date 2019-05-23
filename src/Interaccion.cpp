#include "Interaccion.h"
#include <cmath>

Interaccion::Interaccion(void)
{
}


Interaccion::~Interaccion(void)
{
}

void Interaccion::rebote(Ficha &h, Caja c)
{
	float xmax=c.suelo.limite2.x-h.limite1.x; //calculamos las posiciones máximas de la ficha para no salirse de la caja
	float xmin=c.suelo.limite1.x-h.limite2.x;
	if(h.posicion.x>xmax) //Cuando se vaya a salir de la caja, la posición máxima es max.
		h.posicion.x=xmax;
	if(h.posicion.x<xmin)
		h.posicion.x=xmin;
}

void Interaccion::rebote(Esfera &e, Caja c)
{
	rebote(e,c.techo); //llama al rebote de la esfera con cada pared 
	rebote(e,c.pared_dcha);
	rebote(e,c.pared_izq);
	rebote(e,c.suelo);
}

bool Interaccion::rebote(Esfera &e, Pared p) //Funciona, no tocar.
{
	Vector2D dir; 
	float dif=p.distancia(e.posicion,&dir)-e.radio;
	if(dif<=0.0f) //si la distancia entre la esfera y la pared es 0 o menos, cambia de dirección y velocidad
		{
		Vector2D v_inicial=e.velocidad;
		e.velocidad=v_inicial-dir*2.0*(v_inicial*dir);
		e.posicion=e.posicion-dir*dif;
		return true;
		}
	return false;
}


bool Interaccion::rebote(Esfera &e, Ficha h) //Funciona, no tocar
{
	Vector2D dir;
	float dif=h.distancia(e.posicion,&dir)-e.radio;
	if(dif<=0.0f)
		{
		Vector2D v_inicial=e.velocidad;
		e.velocidad=v_inicial-dir*2.0*(v_inicial*dir);
		e.posicion=e.posicion-dir*dif;
		return true;
		}
	return false;	
}

bool Interaccion::rebote(Esfera &e, ListaBloques *lb) //bool, es true si rebota con un bloque de a lista
{
	if (Interaccion::rebote (e, lb))
		return true;
	else 
		return false;
}

bool Interaccion::rebote(Esfera &e, Bloque b) //bool, es true si rebota alguna superficie del bloque con la pelota
{
	if (rebote(e,b.suelo)||rebote(e,b.techo)||rebote(e,b.pared_dcha)||rebote(e,b.pared_izq)) 
		return true;
	else
		return false;
}

bool Interaccion::rebote(Esfera &e, Planobloque pb)
{
	Vector2D dir; 
	float dif=pb.distancia(e.posicion,&dir)-e.radio;
	if(dif<=0.0f) //si la distancia entre la esfera y la pared es 0 o menos, cambia de dirección y velocidad
		{
		Vector2D v_inicial=e.velocidad;
		e.velocidad=v_inicial-dir*2.0*(v_inicial*dir);
		e.posicion=e.posicion-dir*dif;
		return true;
		}
	return false;
}


