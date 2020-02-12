#include <curses.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <string>

#include "ListaDoble.cpp"

using namespace std;
ListaDoble* listaTexto = new ListaDoble();
void pintar(int x, int y) {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;

	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hCon, pos);

	printf("^w(Buscar y Reemplazar!)      ^c(Reportes)      ^s(Guardar)");

	
	
}
void insert() {
	char entrada = ' ';
	while (entrada != KEY_ENTER) {
		cin >> entrada;
		listaTexto->insertar(entrada);
	}
}
void pintarLimites() {
	for (int i = 2; i < 78; i++) {
		pintar(i, 3);
		printf("%c", 205);
		pintar(i, 30);
		printf("%c", 205);

	}
	for (int i = 4; i < 33; i++) {
		pintar(2, i);
		printf("%c", 186);
		pintar(77, i);
		printf("%c", 186);
	}
}


int main()
{

	//listaTexto->insert
	char entrada=' ';
	cout << "UNIVERSIDAD DE SAN CARLOS DE GUATEMALA" <<endl;
	cout << "FACULTAD DE INGENIERIA "<<endl;
	cout << "ESTRUCTURA DE DATOS " << endl;
	cout << "PRACTICA 1 " << endl;
	cout << "LOURDES MISHEL LORENZANA OCHOA" << endl;
	cout << "201602935" << endl;
	cout << " " << endl;
	cout << "MENU " << endl;
	cout << "1. Crear archivo" << endl;
	cout << "2. Abrir Archivo " << endl;
	cout << "3. Archivos Recientes " << endl;
	cout << "4. Salir " << endl;
	cin >> entrada;
	cout << entrada;
	switch (entrada) {
		case '1':
			pintar(2, 14);
			HANDLE hCon;
			hCon = GetStdHandle(STD_OUTPUT_HANDLE);
			COORD posCursor;
			posCursor.X = 2;
			posCursor.Y = 15;
			SetConsoleCursorPosition(hCon, posCursor);
			while (entrada == KEY_DOWN) {
				cin >> entrada;
				listaTexto->insertar(entrada);
				
			}
			listaTexto->print();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
	}
	//return 0;
	/*ListaSimple *lista = new ListaSimple();
	lista->insertarOrdenadaBuscar("b", "r");
	lista->insertarOrdenadaBuscar("a", "r");
	lista->insertarOrdenadaBuscar("z", "r");
	lista->print();
     */
}




