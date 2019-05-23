#include "Ladrillos.h"
#include "glut.h"

Ladrillos::Ladrillos(void) //constructor por defecto
{
	lado=0.9f;
}

Ladrillos::~Ladrillos(void)
{
}

void Ladrillos::setPos(float ix,float iy)
{
	posicion.x=ix;
	posicion.y=iy;
}

void Ladrillos::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x,posicion.y,0);
	glDisable(GL_LIGHTING);
	glColor3d(50,100,200);
	glutSolidCube(lado);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

float Ladrillos::distancia(Vector2D punto, Vector2D *direccion)
{
	Vector2D u=(punto-limite1);
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
	if(direccion!=0) //si nos dan un vector…
		*direccion=dir.unitario();
	return distancia;
}

