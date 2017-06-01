#pragma once
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include "Cumple.h"

using namespace std;

class Persona {
protected:
	string nombre;
	int dni;
	Cumple cumple;
public:
	Persona(string, int,Cumple);
	Persona();
	virtual const string mostrarDatos();
	virtual const string mostrarNombre();
	const int mostrardni();


};