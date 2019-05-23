#include "Mundo.h"
#include "glut.h"

Mundo mundo; //Creación del objeto mundo que contine todo lo demás.

void onDraw(void); //esta funcion sera llamada para dibujar
void onTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void onKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void onSpecialKeyboardDown(int key, int x, int y); //cuando se pulse una tecla especial	

int main(int argc,char* argv[])
{

	glutInit(&argc, argv);
	glutInitWindowSize(900,600); //Tamaño de la ventana que queremos abrir
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Arkanoid ETSIDI"); //Título de la ventana 

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 35.0, 900/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(onDraw);
	glutTimerFunc(25,onTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(onKeyboardDown);
	glutSpecialFunc(onSpecialKeyboardDown);

	mundo.inicializa(); //Inicializamos el mundo
		
	glutMainLoop();	

	return 0;   
}

void onDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	mundo.dibuja(); //Dibujamos el mundo

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void onKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	mundo.tecla(key);

	glutPostRedisplay();
}
void onSpecialKeyboardDown(int key, int x, int y)
{
	mundo.teclaEspecial(key);
}

void onTimer(int value)
{
//poner aqui el código de animacion
	mundo.mueve();

	//no borrar estas lineas
	glutTimerFunc(25,onTimer,0);
	glutPostRedisplay();
}
