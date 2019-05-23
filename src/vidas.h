#pragma once
#include "iostream"
using namespace std;
class Vidas
{
	int numvidas;
public:
	Vidas(void);
	~Vidas(void);
	void setVidas(int numerovidas) {numvidas=numerovidas;}
	int getVidas(){return numvidas;}
	void incrementaVidas() 
	{
		numvidas++;
		cout<< "Has perdido una vida, has gastado: " <<getVidas()<< " de 3" << endl;
	}
};

