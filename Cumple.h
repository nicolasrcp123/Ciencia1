#pragma once
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
class Cumple {
protected:
	int dia;
	int mes;
	int year;
public:
	Cumple(int, int, int);
	Cumple();
	const int mostrarEdad();
	const int mostrardia();
	const int mostrarmes();
	const int mostraryear();
};