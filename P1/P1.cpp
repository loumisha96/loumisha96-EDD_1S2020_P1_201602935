
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
#include "PilaCambios.cpp"

using namespace std;
int cont_ = 0;
ListaDoble* listaTexto = new ListaDoble();
ListaSimple* lis = new ListaSimple();
Pila *pilacambios = new Pila();
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

void Case1(char tecla){
	bool c = true;
			bool d = true;
			char busqueda= ' ';
			string word = "";
			while (c) {
				cin >> tecla;
				if (tecla == '\x13') {//guarda
					pintarTexto(2, 2);
				}//guardar
				else if (tecla == '\022'){//reportes
					pintarCrear(2, 2);
					pintarCursor(2,4);
					printf("Reportes: 1)Lista   2)Palabras Buscadas  3)Palabras Ordenadas ");
					cin>>busqueda;
					switch (busqueda){
						
						case '1':
							listaTexto->reporte();
							break;
					}
						
					
				}
				else if (tecla == '\x17') {//ctrlw
					pintarCrear(2, 2);
					pintarCursor(2,4);
					printf("Buscar y reemplazar: ");
					
					
					string buscada;
					string reemplazar= "";
					char bandera = ' ';
					int tamReemplazar =0;
					while (d) {
						cin >> busqueda;
						cin.ignore();
						
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
							tamReemplazar++;
							int i =0;
							
							int tamBuscada= buscada.size();
							if(tamReemplazar< tamBuscada){
								reemplazar = reemplazar + busqueda;
								Nodo *aux = listaTexto->primero;
								if(listaTexto->BuscarPos(tamReemplazar)->letra != ' '){
									listaTexto->reemplazar(buscada, busqueda, tamBuscada);
								}
								else{
									listaTexto->eliminarporPosicion(tamReemplazar);
								}
								
							}
							else if(tamReemplazar>tamBuscada){
								reemplazar = reemplazar + busqueda;
								listaTexto->insertarPorPosicion(busqueda, i);
								i++;
							}
							else{
								reemplazar = reemplazar + busqueda;
								
								listaTexto->reemplazar(buscada, busqueda, tamBuscada);
								pintarTexto(2,2);
							}
							
							
						}
						
						pintarTexto(2,2);
						//d = false;
					}
					pilacambios->pushSearch(buscada, reemplazar);
				}
				else
					listaTexto->insertar(tecla);
			}
			pintarTexto(2,2);
			c = false;
	
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

	switch (entrada) {
		case '1'://  \023
			pintarCrear(2, 2);
			pintarCursor(2, 4);
//			puts("Escriba");
			char tecla = getch();
			Case1(tecla);
			
			break;
		
	}

};




