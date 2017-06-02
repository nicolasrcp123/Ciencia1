#include <iostream>
#include <vector>
#include <stdlib.h>


using namespace std;
class Avion {
public:
	virtual void Mensaje() = 0;
};
class Avioneta :public Avion
{
public:
	void Mensaje() { cout << "Nos atacan" << endl; }
};
class Avionchorro :public Avion
{
public:
	void Mensaje() { cout << "No hay mar para aterrizar" << endl; }
};
class Torre {
public:
	vector <Avion *> aviones;
	Torre() {}
	void add(Avioneta elemento) {
		aviones.push_back(&elemento);
		elemento.Mensaje();
	}
	void add(Avionchorro elemento) {
		aviones.push_back(&elemento);
		elemento.Mensaje();
	}


};


int main()
{
	Avioneta a;
	Avionchorro b;
	Torre t;
	t.add(a);
	t.add(b);

	system("pause");

	return 0;
}