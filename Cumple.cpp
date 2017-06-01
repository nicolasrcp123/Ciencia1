#include "Cumple.h"

Cumple::Cumple(int _dia, int _mes, int _year) {
	dia = _dia;
	mes = _mes;
	year = _year;
}
Cumple::Cumple() {
	dia = 0;
	mes = 0;
	year = 0;

}
const int Cumple::mostrarEdad() {
	return 2017 - year;
}
const int Cumple::mostrardia() {
	return dia;
}
const int Cumple::mostrarmes() {
	return mes;
}
const int Cumple::mostraryear() {
	return year;
}