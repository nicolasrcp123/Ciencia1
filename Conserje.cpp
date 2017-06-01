#include "Persona.h"
#include "Conserje.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cstring>
#include "Cumple.h"

using namespace std;

Conserje::Conserje(string nombre, int dni,Cumple cumple, string _edificio, int _llaves) :Persona(nombre, dni,cumple), edificio(_edificio), llaves(_llaves) {}
const string Conserje::mostrarDatos() {
	return "El conserje " + nombre + " del edificio de " + edificio + " con numero de llaves :"+to_string(llaves) + " su numero de dni es :" + to_string(dni)+ " con la edad de :"+ to_string(cumple.mostrarEdad());
}
const int  Conserje::mostrarllaves() {
	return llaves;

}
const string Conserje::mostraredificio() {
	return edificio;
}