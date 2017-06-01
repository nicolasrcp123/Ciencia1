#include "Persona.h"
#include "Gerente.h"
#include <fstream>
#include <conio.h>
#include <cstring>
#include <iostream>
#include <string>
#include "Cumple.h"
using namespace std;


Gerente::Gerente(string nombre, int dni,Cumple cumple,string _area,int _codigo):Persona(nombre,dni,cumple),area(_area),codigo(_codigo){}
const string Gerente::mostrarDatos() {
	return "El gerente " + nombre + " del area de " + area + " con codigo :"+to_string(codigo) + " su numero de dni es :"+ to_string(dni)+" con la edad de :" + to_string(cumple.mostrarEdad());

}
const string Gerente::mostrarArea() {
	return area;
}
const int Gerente::mostrarCodigo() {
	return codigo;
}