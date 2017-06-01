#include "Persona.h"
#include "Cumple.h"
#include <string>
#include <cstring>
Persona::Persona(string _nombre, int _dni,Cumple _cumple) {
	cumple = _cumple;
	nombre = _nombre;
	dni = _dni;

}
Persona::Persona() {
	//cumple = 0;
	nombre = " ";
	dni = 0;

}
const string Persona::mostrarDatos() {
	return nombre + " con el numero de DNI : " + to_string(dni)+ " y su edad es : "+to_string(cumple.mostrarEdad());
	
}
const string Persona::mostrarNombre() {
	return nombre;
}
const int Persona::mostrardni() {
	return dni;
}