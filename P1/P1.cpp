#include <curses.h>
#include <iostream>
#include "ListaSimple.cpp"
int main()
{
	int entrada;
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
	
	switch (entrada) {
	case 1:
		//initscr();
		//WINDOW *win = newwin(20, 60, 0, 0);
	
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	}


	return 0;
	/*ListaSimple *lista = new ListaSimple();
	lista->insertarOrdenadaBuscar("b", "r");
	lista->insertarOrdenadaBuscar("a", "r");
	lista->insertarOrdenadaBuscar("z", "r");
	lista->print();
    std::cout << "Hello World!\n"; */

}


