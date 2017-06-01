#pragma once
#include "Persona.h"
#include "Gerente.h"
#include <string>
#include "Cumple.h"
using namespace std;

class Conserje :public Persona {
private:
	string edificio;
	int llaves;

public:
	Conserje(string, int,Cumple, string, int);
	const string mostrarDatos();	
	const int  mostrarllaves();
	const string mostraredificio();

};