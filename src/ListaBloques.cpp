#include "ListaBloques.h"
#include "Interaccion.h"
#include "Esfera.h"
#include "iostream"
#include "Puntos.h"
using namespace std;
Puntos punto; //Creamos aquí el objeto punto para poder incrementar los puntos cuando un bloque sea destruido.


ListaBloques::ListaBloques(void) //Ponemos todo a 0 inicialmente
{
	numero=0;
	for (int i=0; i<MAX_BLOQUES; i++)
		lista[i]=00000000;
}

ListaBloques::~ListaBloques(void) //Destructor por defecto. No lo utilizamos.
{
}

bool ListaBloques::agregar (Bloque *b)
{
	if (numero<MAX_BLOQUES) //Mientras no cumplamos el cupo de bloques
	{
		lista[numero++]=b; //Añadimos el bloque a la lista
		return true;
	}
	else
		return false;
}

void ListaBloques::dibuja()
{
	for (int i =0; i<numero;i++) //Dibujamos todos los bloques que existan en la lista
		lista[i]->dibuja(); 
}

Bloque * ListaBloques::rebota(Esfera &e) //Si una esfera choca con un bloque, devuelve con qué bloque ha chocado
{ 
	for(int i=0;i<numero;i++)
		if(Interaccion::rebote(e,*(lista[i])))//REBOTE DE LA ESFERA CON EL BLOQUE CONCRETO
			return lista[i]; //Devuelve el bloque concreto
} 

void ListaBloques::destruirContenido() //Destruir todos los bloques de la lista
{
	for(int i=0;i<numero;i++)   
		delete lista[i];  
	numero=0;
}

void ListaBloques::eliminar(int index) 
{
	if ((index<0)||(index>=numero)) //Si está fuera de rango, error. Simple comprobación 
		return;
	delete lista[index]; //Destruímos el bloque que hemos tocado con Delete
	numero--; //Decrementamos el número de bloques
	for (int i=index;i<numero;i++) //Volvemos a ordenar los bloques en la lista
		lista[i]=lista[i+1];
	lista[numero]=00000000; //La ultima posicion ocupada la ponemos a 0.
}

void ListaBloques::eliminar(Bloque *b) //Pasamos el bloque que queremos eliminar //ESTA ES LA FUNCIÓN QUE SE EJECUTA PARA ELIMINAR UN BLOQUE QUE CHOCA CON LA PELOTA
{  
	for(int i=0;i<numero;i++)     
		if(lista[i]==b)        //Lo encontramos en su posición en la lista
		{
			eliminar(i); //Esta función llama a a de arriba, pasándolo el índice de la lista
			cout << "Eliminado el bloque: " << lista[i]<<endl;
			punto.incrementaPuntos();
			punto.imprimePuntos();
		}
} 

