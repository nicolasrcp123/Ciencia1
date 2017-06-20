#include <iostream>
using namespace std;
//creamos la clase base
class Base
{
	//funciones que imprimen en pantalla algunos mensajes
	void a()
	{
		cout << "aprendi  ";
	}
	void c()
	{
		cout << "c++  ";
	}
	void e()
	{
		cout << "My hero  ";
	}

	virtual void ph1() = 0;
	virtual void ph2() = 0;

public:
	//Funcion que llama a otras funciones privadas para imprimir los valores de estas funciones
	void execute()
	{
		a();
		ph1();
		c();
		ph2();
		e();
	}
};

class One : public Base {
	//Funciones que heredan de la clase base(virtual puro) 
	void ph1() {
		cout << "bastante  ";
	}

	void ph2()
	{
		cout << "Gracias  ";
	}

};

class Two : public Base {
	//Funciones que heredan de la clase base(virtual puro) 
	void ph1() {
		cout << "pero mucho molestabas cuando te preguntaba de ";
	}

	void ph2() {
		cout << "MrMusculos ";
	}
};

int main() {
	//creamos un arreglo de punteros que contiene a la clase one y two  
	Base *array[] = { &One(), &Two() };
	//hacemos un bucle para llamar sus funciones de cada elemento de mi arreglo
	for (int i = 0; i < 2; i++) {
		array[i]->execute();
		cout << '\n';
	}
	system("pause");

}