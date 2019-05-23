#include "Ficha.h"
#include "glut.h"

Ficha::Ficha() //Constructor por defecto de la ficha
{
}

Ficha::~Ficha() //Destructor de la ficha
{
}

void Ficha::dibuja() //Codigo para dibujar la ficha 
{
	glPushMatrix();
	glTranslatef(posicion.x,posicion.y,0);
	glDisable(GL_LIGHTING);
	glColor3d(255,0,0);
	glBegin(GL_POLYGON);
		glVertex3d(limite1.x,limite1.y,3);
		glVertex3d(limite2.x,limite2.y,3);
		glVertex3d(limite2.x,limite2.y,-3);
		glVertex3d(limite1.x,limite1.y,-3);
	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

void Ficha::mueve(float t) //Movimiento de la ficha
{
	posicion=posicion+velocidad*t+aceleracion*(0.5f*t*t);
	velocidad=velocidad+aceleracion*t;
}

void Ficha::setVel(float vx, float vy) //Velocidad 
{
	velocidad.x=vx;
	velocidad.y=vy;
}

void Ficha::setPos(float x1, float y1, float x2, float y2) //Posición de los 4 puntos del plano
{
	limite1.x=x1;
	limite1.y=y1;
	limite2.x=x2;
	limite2.y=y2;
}

float Ficha::distancia(Vector2D punto, Vector2D *direccion) //AÑADIDO +POSICION PARA QUE FUNCIONE!!!
{
	Vector2D u=(punto-(limite1+posicion));
	Vector2D v=(limite2-limite1).unitario();
	float longitud=(limite1-limite2).modulo();
	Vector2D dir;
	float valor=u*v;
	float distancia=0;

	if(valor<0)
		dir=u;
	else if(valor>longitud)
		dir=(punto-limite2);
	else
		dir=u-v*valor;

	distancia=dir.modulo();
	if(direccion!=0)
		*direccion=dir.unitario();
	return distancia;
}
