#include <iostream>
#include <conio.h>
#include <windows.h>  
#include <stdio.h>
#include <random>
#define ARRIBA 72
#define IZQUIERDA 75
#define	DERECHA 77
#define ABAJO 80
#define ESPACIO 32
#define ESCAPE 27

using namespace std;

#define MAXFILAS 35
#define MAXCOLS 36
void gotoxy(int x, int y) {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;

	SetConsoleCursorPosition(hCon, dwPos);

}
void Ocultarcursor() {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 100;
	cci.bVisible = FALSE;

	SetConsoleCursorInfo(hCon, &cci);
}
char mapa[MAXFILAS][MAXCOLS] = {
	"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
	"x                  111            x", //19,1
	"x                  111            x",
	"x                  111            x",
	"x   yyy111yyy   yyy   yyy   yyy   x",//7,4
	"x   yyy111yyy   yyy   yyy   yyy   x",
	"x   yyy111yyy   yyy   yyy   yyy   x",
	"x            111                  x",//13,7
	"x            111                  x",
	"x            111                  x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x               111               x",//16,13
	"x               111               x",
	"x               111               x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x                        111      x",//25,19
	"x                        111      x",
	"x                        111      x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x      111                        x",//7,25
	"x      111                        x",
	"x      111                        x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x111                     111      x",//1,31  //25,31
	"x111                     111      x",
	"x111                     111      x",
	"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
};

void dibujarmapa() {
	int x, y;
	
	for (x = 0;x < MAXFILAS;x++) {
		
		for (y = 0;y < MAXCOLS;y++) {
			if (mapa[x][y] == 'x') {
				printf("%c", 205);
			}
			if (mapa[x][y] == ' ') {
				cout << " ";
			}
			
			if (mapa[x][y] == 'y') {
				printf("%c", 178);
			}
			if (mapa[x][y] == '1') {
				cout << " ";

			}
		}
		printf("\n");
	}
	
	
}
class Jugador {
private:
	int x, y;
	int corazones;
	int life;

public:
	Jugador(int _x, int _y, int _corazones, int _life);
	void pintararriba();
	void pintarabajo();
	void pintarizquierda();
	void pintarderecha();
	void borrar();
	virtual void mover();
	void pintar_corazones();
	void morir();
};
Jugador::Jugador(int _x, int _y, int _corazones, int _life) {
	x = _x;
	y = _y;
	corazones = _corazones;
	life = _life;
}

void Jugador::pintararriba() {
	gotoxy(x, y); printf(" %c ", 223);
	gotoxy(x, y + 1); printf("%c%c%c", 47, 219, 92);
	gotoxy(x, y + 2); printf("%c %c", 215, 215);
}
void Jugador::pintarabajo() {
	gotoxy(x, y); printf("%c%c%c", 39, 223, 39);
	gotoxy(x, y + 1); printf("%c%c%c", 47, 178, 92);
	gotoxy(x, y + 2); printf("%c %c", 215, 215);
}
void Jugador::pintarizquierda() {
	gotoxy(x, y); printf("%c  ", 223);
	gotoxy(x, y + 1); printf("%c%c ", 47, 219);
	gotoxy(x, y + 2); printf("%c%c ", 214, 214);
}
void Jugador::pintarderecha() {
	gotoxy(x, y); printf("  %c", 223);
	gotoxy(x, y + 1); printf(" %c%c", 219, 92);
	gotoxy(x, y + 2); printf(" %c%c", 222, 222);
}
void Jugador::borrar() {
	gotoxy(x, y); printf("   ");
	gotoxy(x, y + 1); printf("   ");
	gotoxy(x, y + 2); printf("   ");
}
void Jugador::mover() {
	if (_kbhit()) {
		char tecla = _getch();
		borrar();
		if (tecla == 'e') {
			if (life >0)
				life--;
			else
				morir();
		}
		if (tecla == IZQUIERDA) {
			pintarizquierda();
		
			if (tecla == IZQUIERDA &&x > 1 && mapa[x - 1][y] != 'y'&&mapa[x - 1][y + 1] != 'y' &&mapa[x - 1][y + 2] != 'y') {
				x--;
				pintarizquierda();

			}
		}
		if (tecla == DERECHA) {
			pintarderecha();
			if (tecla == DERECHA&&x + 3 < 34 && mapa[x + 4][y] != 'y'&&mapa[x + 4][y + 1] != 'y' &&mapa[x + 4][y + 2] != 'y') {
				x++;
				pintarderecha();
			}
		}
		if (tecla == ARRIBA) {
			pintararriba();
			if (tecla == ARRIBA&&y > 1 && mapa[x][y - 1] != 'y'&&mapa[x + 1][y - 1] != 'y' &&mapa[x + 2][y - 1] != 'y') {
				borrar();
				y--;
				pintararriba();
			}
		}
		if (tecla == ABAJO) {
			pintarabajo();

			if (tecla == ABAJO&&y + 3 < 34 && mapa[x][y + 4] != 'y'&&mapa[x + 1][y + 4] != 'y' &&mapa[x + 2][y + 4] != 'y') {
				borrar();
				y++;
				pintarabajo();
			}

		}
		pintar_corazones();
	}






}
void Jugador::pintar_corazones() {
	gotoxy(50, 2); printf("VIDAS %d", life);
	gotoxy(64, 2); printf("Vidas");
	gotoxy(70, 2); printf("     ");
	for (int i = 0;i < corazones;i++) {
		gotoxy(70 + i, 2); printf("%c", 3);


	}
}
void Jugador::morir() {
	if (life == 0) {
		borrar();
		gotoxy(x, y);printf(" * ");
		gotoxy(x, y + 1);printf("***");
		gotoxy(x, y + 2);printf(" * ");
		Sleep(200);

		borrar();
		gotoxy(x, y);printf("* *");
		gotoxy(x, y + 1);printf("***");
		gotoxy(x, y + 2);printf("* *");

		borrar();
		Sleep(200);
		corazones--;
		life = 3;
		pintar_corazones();
		x = 4 + rand() % (32, 4);
		y = 4 + rand() % (34, 4);
		pintararriba();
	}




}


class Bomba {
private:
	int m;
	int n;
public:
	Bomba(int, int);
	void colorear();
	int X1() { return m; }
	int Y1() { return n; }
	//void agarrar();
	//void explotar();
	//void eliminar();
};
Bomba::Bomba(int _x, int _y) {
	m = _x;
	n = _y;
}
void Bomba::colorear() {
	gotoxy(m, n); printf(" %c ", 190);
	gotoxy(m, n + 1); printf("%c%c%c", 40, 178, 41);
	gotoxy(m, n + 2); printf(" %c ", 223);
}


int main() {
	Ocultarcursor();
	dibujarmapa();
	Jugador j1(1, 1, 3, 3);
	Jugador j2(10, 5, 3, 3);
	j2.pintararriba();
	
	j1.pintarderecha();
	j1.pintar_corazones();

	Bomba b1(19, 1);
	b1.colorear();
	Bomba b2(7, 4);
	b2.colorear();
	Bomba b3(13, 7);
	b3.colorear();
	Bomba b4(16, 13);
	b4.colorear();
	Bomba b5(25, 19);
	b5.colorear();
	Bomba b6(7, 25);
	b6.colorear();
	Bomba b7(1, 31);
	b7.colorear();
	Bomba b8(25, 31);
	b8.colorear();

	bool game_over = false;
	while (!game_over) {

		j1.morir();
		j1.mover();

		Sleep(30);

	}
	system("pause");
	return 0;
}