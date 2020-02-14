
#include <Windows.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#ifndef CTRL
#define CTRL(s)((c) & 037)
#endif
#include "ListaDoble.cpp"
#include "ListaSimple.cpp"

using namespace std;
int cont_ = 0;
ListaDoble* listaTexto = new ListaDoble();
ListaSimple* lis = new ListaSimple();

void pintarCrear(int x, int y) {
	system("cls");
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;

	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hCon, pos);

	printf("^w(Buscar y Reemplazar!)      ^c(Reportes)      ^s(Guardar)");
}
void pintarCursor(int x, int y) {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD posCursor;
	posCursor.X = 2;
	posCursor.Y = 4;
	SetConsoleCursorPosition(hCon, posCursor);

}
void pintarLista() {
	Nodo* aux = listaTexto->primero;
	while (aux->sig != 0) {
		cout << aux->letra;
		aux = aux->sig;
	}
	cout << aux->letra << endl;
	pintarCursor(2, 2);
}
void pintarTexto(int x, int y) {
	system("cls");
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;

	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hCon, pos);

	printf("^w(Buscar y Reemplazar!)      ^c(Reportes)      ^s(Guardar)");
	pos.X = x;
	pos.Y = y + 1;
	SetConsoleCursorPosition(hCon, pos);
	pintarLista();
}

int main()
{
	char entrada = ' ';
	cout << "UNIVERSIDAD DE SAN CARLOS DE GUATEMALA" << endl;
	cout << "FACULTAD DE INGENIERIA " << endl;
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

	bool c = true;
	bool d = true;
	switch (entrada) {
		case '1'://  \023
			pintarCrear(2, 2);
			pintarCursor(2, 4);
			char tecla = getch();
			string word = "";
			//entrada = getch();
			//buscar y reemplazar = '\x17' ctrlw
			//reportes '1'
			//guardar = '\x13'
			
			while (c) {
				cin >> tecla;
				if (tecla == '\x13') {//guarda
					pintarTexto(2, 2);
				}//guardar
				else if (tecla == '1')//
					cout << "f";
				else if (tecla == '\x17') {
					pintarCrear(2, 2);
					pintarCursor(2, 4);
					printf("Buscar y reemplazar: ");
					char busqueda= ' ';
					string buscada;
					string reemplazar= "";
					char bandera = ' ';
					while (d) {
						cin >> busqueda;
						if(busqueda != ';' && bandera != ';') {
							if(listaTexto->buscarLD(busqueda, cont_)){
								word = word + busqueda;
								cont_++;
								d = true;
							}else{
								
								d = false;
							}
							
						}
						else if(bandera != ';'){
							bandera = busqueda;
							buscada = word;
							
							d = true;
							
						}
						else{
							reemplazar = reemplazar + busqueda;
							listaTexto->reemplazar(buscada, busqueda);
							pintarTexto(2,2);
							
						}
						pintarTexto(2,2);
						//d = false;
					}
				}
				else
					listaTexto->insertar(tecla);
			}
			pintarTexto(2,2);
			c = false;
			break;
	}

};




