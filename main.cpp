#include "Persona.h"
#include "Gerente.h"
#include "Conserje.h"
#include <cstring>
#include <iostream>
#include <math.h>
#include <string>
#include <conio.h>

using namespace std;

int main() {
	Cumple c1(12, 12, 1999);
	Cumple c2(11, 6, 2015);
	Cumple c3(10, 2, 1990);
	Persona p1("Mauricio Paquito",7123933, c1);
	Gerente g1("Mauricio Paquito", 71602324,c2,"Licenciado", 78123);
	Conserje d1("Mauricio Paquito", 71602354,c3,"UCSP", 100);
	Persona *arr = new Persona[3];
	arr[0] = p1;
	arr[1] =g1;
	arr[2] = d1;
	for (int i = 0;i < 3;i++) {
		cout << arr[i].mostrarDatos() << endl;
	}
	//cout << g1.mostrarDatos() << endl;
	//cout << c1.mostrarDatos() << endl;


	system("pause");
	return 0;
}