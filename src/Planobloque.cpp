#include "Planobloque.h"
#include "glut.h"

Planobloque::Planobloque(void)
{
}

Planobloque::~Planobloque(void)
{
}

void Planobloque::dibuja() //Dibuja los planos que pueden chocar con las bolas. No dibuja el frontal
{
	glDisable(GL_LIGHTING);
	color.ponColor(); //Es de ColorRGB
	glBegin(GL_POLYGON);
		glVertex3d(limite1.x,limite1.y,0.3);
		glVertex3d(limite2.x,limite2.y,0.3);
		glVertex3d(limite2.x,limite2.y,-0.3);
		glVertex3d(limite1.x,limite1.y,-0.3);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Planobloque::setColor( Byte r,Byte v, Byte a)
{
	color.set(r,v,a);
}

void Planobloque::setPos(float x1, float y1, float x2, float y2) //Los puntos de referencia para crear los planos
{
	limite1.x=x1;
	limite1.y=y1;
	limite2.x=x2;
	limite2.y=y2;
}

float Planobloque::distancia(Vector2D punto, Vector2D *direccion) //No tocar, funciona
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
	if(direccion!=0)
		*direccion=dir.unitario();
	return distancia;
}

