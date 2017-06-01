#pragma once
#include "Persona.h"
#include <string>
#include <cstring>
class Gerente :public Persona {
private:
	string area;
	int codigo;

public:
	Gerente(string, int,Cumple,string,int);
	const string mostrarDatos();
	const string mostrarArea();
	const int mostrarCodigo();


};
