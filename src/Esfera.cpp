#include "Esfera.h"
#include "glut.h"
#include "Interaccion.h"

Esfera::Esfera() //Constructor por defecto de la esfera	
{
}

Esfera::~Esfera() //Destructor por defecto de la esfera
{
}

void Esfera::dibuja() //Dibujo de la esfera
{
	color.ponColor();
	glTranslatef(posicion.x,posicion.y,0);
	glutSolidSphere(radio,90,90);
	glTranslatef(-posicion.x,-posicion.y,0);
}

void Esfera::mueve(float t) //Movimiento de la esfera
{
	posicion=posicion+velocidad*t+aceleracion*(0.5f*t*t);
	velocidad=velocidad+aceleracion*t;
}

void Esfera::setColor( Byte r,Byte v, Byte a) //Color de la esfera
{
	color.set(r,v,a);
}

void Esfera::setRadio(float r) //Radio
{
	radio=r;
}	

void Esfera::setPos(float ix,float iy) //Posición 
{
	posicion.x=ix;
	posicion.y=iy;
}

void Esfera::setVel(float vx, float vy) //Velocidad
{
	velocidad.x=vx;
	velocidad.y=vy;
}

