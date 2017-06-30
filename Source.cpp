#include <iostream>
#include <conio.h>
#include <windows.h>  
#include <stdio.h>
#include <random>
#include <list>
#include <vector>
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
	"x q                111            x", //19,1   2,1
	"x                  111            x",//33,2
	"x                  111            x",
	"x   yyy111yyy   yyy   yyy   yyy   x",//7,4
	"x   yyy111yyy   yyy   yyy   yyy   x",
	"x   yyy111yyy   yyy   yyy   yyy   x",
	"x       q    111                  x",//13,7     8,7
	"x            111                  x",//26,8
	"x            111                  x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x             q 111               x",//16,13
	"x               111               x",//20,14
	"x               111               x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x                   q    111      x",//25,19
	"x                        111      x",//14,20
	"x                        111      x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x                         q       x",//7,25
	"x                                 x",//8,26
	"x                                 x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x   yyy   yyy   yyy   yyy   yyy   x",
	"x                        111    q x",//1,31  //25,31
	"x                        111      x",//2,32
	"x                        111      x",
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
			
			if (mapa[x][y] == 'q') {
	
				printf(" ");

			}
			
		}
		printf("\n");
	}
	
	
}
void dibujar_O(int &ex,int &ey,int dx) {		
	gotoxy(ex, ey); printf(" ");
	ex = ex + dx;
	if (ex == 3 || ex > 20) {
		dx = dx*(-1);
	}
	
	
	gotoxy(ex, ey);printf("%c", 220);
}

class Jugador {
private:
	int x, y, n;
	int bombas;
	int corazones;
	int life;

public:
	Jugador(int _x, int _y, int _corazones, int _life);
	void pintararriba();
	void pintarabajo();
	int darX();
	int darY();
	int dar_vidas() { return life; }
	int darN() { return n; }
	void pintarizquierda();
	void pintarderecha();
	virtual void borrar();
	virtual void mover();
	void quitar_corazones() { corazones--; }
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

int Jugador::darX() {
	return x;
}
int Jugador::darY() {
	return y;
}
void Jugador::mover() {
	if (_kbhit()) {
		char tecla = _getch();
		borrar();
		
		if (tecla == 'e') {
			if (life > 0)

				corazones--;
			else
				morir();
		}
		if (tecla == IZQUIERDA) {
			n = 1;
			pintarizquierda();

			if (tecla == IZQUIERDA &&x > 1 && mapa[x - 1][y] != 'y'&&mapa[x - 1][y + 1] != 'y' &&mapa[x - 1][y + 2] != 'y') {
				x--;
				pintarizquierda();

			}
		}
		if (tecla == DERECHA) {
			n = 2;
			pintarderecha();

			if (tecla == DERECHA&&x + 3 < 34 && mapa[x + 4][y] != 'y'&&mapa[x + 4][y + 1] != 'y' &&mapa[x + 4][y + 2] != 'y') {
				x++;
				pintarderecha();
			
			}
		}
		if (tecla == ARRIBA) {
			n = 3;
			pintararriba();
			if (tecla == ARRIBA &&y > 1 && mapa[x][y - 1] != 'y'&&mapa[x + 1][y - 1] != 'y' &&mapa[x + 2][y - 1] != 'y') {
				borrar();
				y--;
				pintararriba();
			}
		}
		if (tecla == ABAJO) {
			n = 4;
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
	if (corazones == 0) {
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
		life--; 
		corazones = 3;
		pintar_corazones();
		x = 4;
		y = 7;
		pintararriba();
	}


}
/*class Enemigo {
private:
	int x, y, life;
public:
	Enemigo(int _x, int _y, int _life);
	void pintar();
	void borrar();
	int X() { return x; }
	int Y() { return y; }
	int Life() { return life; }

};
Enemigo::Enemigo(int _x, int _y, int _life) {
	x = _x;
	y = _y;
	life = _life;

}
void Enemigo::pintar() {
	gotoxy(x, y); printf("%c%c", 201, 187);
	gotoxy(x, y + 1); printf("%c%c", 200, 188);

}
void Enemigo::borrar() {
	gotoxy(x, y); printf("  ");
	gotoxy(x, y + 1); printf("  ");

}
*/


class Obst1 {
private:
	int q, w, dx, dy;
public:
	Obst1(int _q, int _w,int _dx,int _dy) :q(_q), w(_w),dx(1),dy(1) {}
	void pintar();
	void mover();
	void mover2();
	void borrar();
	void colision(Jugador &N);
	int darQ() { return q; }
	int darW() { return w; }
};
void Obst1::pintar() {

	gotoxy(q, w); printf("*");
}
void Obst1::borrar() {
	gotoxy(q, w); printf(" ");
}
void Obst1::colision(Jugador &N) {
	if (q >= N.darX() && q < N.darX() + 4&& w >= N.darY() && w < N.darY() + 4){
		N.quitar_corazones();
		N.borrar();
		N.pintar_corazones();
		N.pintararriba();
		
	}
	

}
void Obst1::mover() {
	borrar();
	q += dx; 
	pintar();
	if (q==1||q==33) {
		dx = -dx;
	}
	

}
void Obst1::mover2() {
	borrar();
	w += dy;
	pintar();
	//Sleep(15);
	if (w == 1 || w == 33 ) {
		dy = -dy;
	}
	
}

class Bala {
private:
	int q, w;
public:
	Bala(int _q, int _w):q(_q),w(_w){}
	bool fin_bala();
	void mover_derecha();
	void mover_izquierda();
	void mover_arriba();
	void mover_abajo();
	int darQ() { return q; }
	int darW() { return w; }

};
bool Bala::fin_bala() {
	if (q == 1|| q == 33 ||w == 1 ||  w == 33||mapa[q+1][w]=='y'||mapa[q-1][w]=='y'||mapa[q][w+1]=='y'||mapa[q][w-1]=='y')//||mapa[q][w]=='y')
		return true;
	return false;



}
void Bala::mover_derecha() {

	gotoxy(q, w); printf(" ");
	if (q > 2&& q<33 && mapa[q+1][w]!='y') q++;
	gotoxy(q, w); printf("%c",207);
}
void Bala::mover_izquierda() {
	gotoxy(q, w); printf(" ");
	if (q > 1 && q<33&&mapa[q-1][w]!='y') q--;
	gotoxy(q, w); printf("%c", 207);
}
void Bala::mover_arriba() {
	gotoxy(q, w); printf(" ");
	if (w > 1 && w<33&&mapa[q][w-1]!='y') w--;
	gotoxy(q, w); printf("%c", 207);
}
void Bala::mover_abajo() {
	gotoxy(q, w); printf(" ");
	if (w > 1 && w<33 &&mapa[q][w+1]!= 'y') w++;
	gotoxy(q, w); printf("%c", 207);
}
int main() {
	Ocultarcursor();
	dibujarmapa();
	
	Obst1 o1(32,2,1,1);
	Obst1 o2(26, 8, 1, 1);
	Obst1 o3(20, 14, 1, 1);
	Obst1 o4(14, 20, 1, 1);
	Obst1 o5(8, 26, 1, 1);
	Obst1 o6(2, 32, 1, 1);
	//diferente movimiento
	Obst1 o7(2, 1, 1, 1);
	Obst1 o8(8, 7, 1, 1);
	Obst1 o9(14, 13, 1, 1);
	Obst1 o10(20, 19, 1, 1);
	Obst1 o11(26, 25, 1, 1);
	Obst1 o12(32, 31, 1, 1);
	o1.pintar();
	
	o3.pintar();
	
	o5.pintar();
	
	Jugador j1(4, 7, 3, 3);
	
	j1.pintarderecha();
	j1.pintar_corazones();

	int X = j1.darX();
	int Y = j1.darY();

	int m = 1;
	int n = 1;
	int life = 3;
	
	gotoxy(52, 4); printf("VIDAS ENEMIGO %d", 9);


	gotoxy(m, n); printf("%c%c", 201, 187);
	gotoxy(m, n + 1); printf("%c%c", 200, 188);

	//Enemigo j2(7, 7, 10);
	list<Bala *> B;
	list<Bala *>::iterator it;
	bool game_over = false;
	while (!game_over) {
		
	
		o1.mover(); o1.colision(j1);
	
		o3.mover(); o3.colision(j1);
		
		o5.mover(); o5.colision(j1);
		
		o7.mover2(); o7.colision(j1);
		
		o9.mover2(); o9.colision(j1);
		
		o11.mover2(); o11.colision(j1);
	
		
		int N = j1.darN();
		if (_kbhit()) {
			

			
			char tecla = _getch();
			if (N == 1) {
				if (tecla == '.')
					B.push_back(new Bala(j1.darX(), j1.darY() + 1));
			}
			if (N==2) {
				if (tecla == '.')
					B.push_back(new Bala(j1.darX() + 2, j1.darY() + 1));
			}
			if (N == 3) {
				if (tecla == '.')
					B.push_back(new Bala(j1.darX() +1, j1.darY()-1 ));
			}
			if (N == 4) {
				if (tecla == '.')
					B.push_back(new Bala(j1.darX()+1 , j1.darY() + 2));
			}
			///////////////////////////////////////
		

			if (tecla == 'a') {
				gotoxy(m, n); printf("%c%c", 201, 187);
				gotoxy(m, n + 1); printf("%c%c", 200, 188);
				if (tecla == 'a' &&m > 1 && mapa[m - 1][n] != 'y'&&mapa[m - 1][n + 1] != 'y' ){
					gotoxy(m, n); printf("  ");
					gotoxy(m, n + 1); printf("  ");
					m--;
					gotoxy(m, n); printf("%c%c", 201, 187);
					gotoxy(m, n + 1); printf("%c%c", 200, 188);
				}
			}
			if (tecla == 'd') {
				gotoxy(m, n); printf("%c%c", 201, 187);
				gotoxy(m, n + 1); printf("%c%c", 200, 188);
				if (tecla == 'd' &&m+2 < 34 && mapa[m + 2][n] != 'y'&&mapa[m +2 ][n + 1] != 'y') {
					gotoxy(m, n); printf("  ");
					gotoxy(m, n + 1); printf("  ");
					m++;
					gotoxy(m, n); printf("%c%c", 201, 187);
					gotoxy(m, n + 1); printf("%c%c", 200, 188);
				}
			}
			if (tecla == 'w') {
				gotoxy(m, n); printf("%c%c", 201, 187);
				gotoxy(m, n + 1); printf("%c%c", 200, 188);
				if (tecla == 'w' &&n > 1 && mapa[m][n-1] != 'y'&&mapa[m +1][n - 1] != 'y') {
					gotoxy(m, n); printf("  ");
					gotoxy(m, n + 1); printf("  ");
					n--;
					gotoxy(m, n); printf("%c%c", 201, 187);
					gotoxy(m, n + 1); printf("%c%c", 200, 188);
				}
			}
			if (tecla == 's') {
				gotoxy(m, n); printf("%c%c", 201, 187);
				gotoxy(m, n + 1); printf("%c%c", 200, 188);
				if (tecla == 's' &&n +2<34 && mapa[m][n + 2] != 'y'&&mapa[m + 1][n + 2] != 'y') {
					gotoxy(m, n); printf("  ");
					gotoxy(m, n + 1); printf("  ");
					n++;
					gotoxy(m, n); printf("%c%c", 201, 187);
					gotoxy(m, n + 1); printf("%c%c", 200, 188);
				}
			}
			if (m >= j1.darX() && m < j1.darX() + 2 && n >= j1.darY() && n < j1.darY() + 2) {
				gotoxy(m, n); printf("  ");
				gotoxy(m, n + 1); printf("  ");
				j1.quitar_corazones();
				j1.borrar();
				j1.pintar_corazones();
				j1.pintararriba();
				gotoxy(m, n); printf("%c%c", 201, 187);
				gotoxy(m, n+1); printf("%c%c", 200, 188);
			}
			
			gotoxy(m, n); printf("%c%c", 201, 187);
			gotoxy(m, n + 1); printf("%c%c", 200, 188);
			gotoxy(52, 4); printf("VIDAS ENEMIGO %d", life);
		  ///////////////////7
			
			
			/////////////////////7
		}
			

	
			if (N == 1) {
				for (it = B.begin();it != B.end();) {
					(*it)->mover_izquierda();
					if ((*it)->fin_bala()==true) {
						gotoxy((*it)->darQ(), (*it)->darW()); printf(" ");
						//if (m >= (*it)->darQ() && m < (*it)->darQ() + 1 && n >= (*it)->darW() && n < (*it)->darW() + 1) {
						if(m == (*it)->darQ() && n == (*it)->darW() || n+1==(*it)->darW()){
							gotoxy(m, n); printf("  ");
							gotoxy(m, n + 1); printf("  ");
							life--;
							gotoxy(m, n); printf("%c%c", 201, 187);
							gotoxy(m, n + 1); printf("%c%c", 200, 188);
						}
						delete (*it);
						it = B.erase(it);
						
					}
				
					else it++;
				}

			}
			
			if (N == 2) {
				for (it = B.begin();it != B.end();) {
					(*it)->mover_derecha();
					if ((*it)->fin_bala() == true) {
						gotoxy((*it)->darQ(), (*it)->darW()); printf(" ");
						if (m == (*it)->darQ() && n == (*it)->darW() || n + 1 == (*it)->darW()) {
							gotoxy(m, n); printf("  ");
							gotoxy(m, n + 1); printf("  ");
							life--;
							gotoxy(m, n); printf("%c%c", 201, 187);
							gotoxy(m, n + 1); printf("%c%c", 200, 188);
						}
						delete (*it);
						it = B.erase(it);

					}
					else it++;
				}
			}
			if (N == 3) {
				for (it = B.begin();it != B.end();) {
					(*it)->mover_arriba();
					if ((*it)->fin_bala() == true) {
						if (mapa[(*it)->darQ()][(*it)->darW()] != 'y') {
							gotoxy((*it)->darQ(), (*it)->darW()); printf(" ");
						}
						if (mapa[(*it)->darQ()][(*it)->darW()] == 'y') {
							gotoxy((*it)->darQ(), (*it)->darW()); printf("%c", 178);
						}
						if (n == (*it)->darW() && m == (*it)->darQ() || m + 1 == (*it)->darQ()) {
							gotoxy(m, n); printf("  ");
							gotoxy(m, n + 1); printf("  ");
							life--;
							gotoxy(m, n); printf("%c%c", 201, 187);
							gotoxy(m, n + 1); printf("%c%c", 200, 188);
						}
						delete (*it);
						it = B.erase(it);

					}
					
					else it++;
				}
				
			}

			if (N == 4) {
				for (it = B.begin();it != B.end();) {
					(*it)->mover_abajo();
					if ((*it)->fin_bala() == true) {
						gotoxy((*it)->darQ(), (*it)->darW()); printf(" ");
						if (n == (*it)->darW() && m == (*it)->darQ()-1 || m +1 == (*it)->darQ()) {
							gotoxy(m, n); printf("  ");
							gotoxy(m, n + 1); printf("  ");
							life--;
							gotoxy(m, n); printf("%c%c", 201, 187);
							gotoxy(m, n + 1); printf("%c%c", 200, 188);
						}
						delete (*it);
						it = B.erase(it);

					}
					else it++;;
				}
			}





			if (j1.dar_vidas() == 0 || life==0) game_over = true;
			
			j1.morir();
			j1.mover();
			Sleep(100);//30	
		
	}
	if (j1.dar_vidas() > life) {
		cout << "Gano el PLAYER 1" << endl;
	}
	else
		cout << "Gano el ENEMIGO " << endl;
	system("pause");
	return 0;
}