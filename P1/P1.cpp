
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
#include "ListaCircular.cpp"

using namespace std;
int cont_ = 0;
ListaDoble* listaTexto = new ListaDoble();
ListaSimple* lis = new ListaSimple();
Pila *pilacambios = new Pila();
ListaCircular *listaArchRec = new ListaCircular();

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
	listaTexto->print();
}

void rem1(string var){
	int v = var.size();
	string b;
	string r;
	bool bandera=false;
	for(int i=0; i<v; i++){
		if( var[i] !=';' && bandera== false){
			b= b+var[i];
			
				
		}else{
			
			if(var[i]== ';'){
				bandera =true;
			}
			else{
				r= r+var[i];
			}
			
		}
			
	}
	listaTexto->buscarReemplazar(b,r);
	listaTexto->print();
} 
void Case1(char tecla){
	

			bool c = true;
			
			char busqueda;
			
			while (c) {
				cin >> tecla;
				if (tecla == '\023') {//guarda
					pintarCrear(2, 2);
					pintarCursor(2,4);
					printf("Guardar: ");
					string g;
					cin.ignore();
					getline(cin,g);
					ofstream file;
					g = g+".txt";
					file.open(g.c_str(), ios::out);
					if (listaTexto->vacia())
						cout << "Lista Vacia";
					else {
						Nodo* aux = listaTexto->primero;
		
						while (aux->sig != 0) {
							file << aux->letra;
							aux = aux->sig;
						}
					file<< aux->letra;
					}
					file.close();
				//	ifstream 
					
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
						case '2':
							pilacambios->reporte();
							break;
						
					}
						
					
				}
				else if (tecla == '\027') {//ctrlw
					pintarCrear(2, 2);
					pintarCursor(2,4);
					printf("Buscar y reemplazar: ");
					string var;
					cin.ignore();
					getline(cin, var);
					rem1(var);
					//cin.ignore();
					cin>>tecla;
					Case1(tecla);
					//rem(busqueda);
					
				}
				else if(tecla== '\030'){
					
				}
				
			}
		//	pilacambios->pushSearch(buscada, reemplazar);
		//	pilacambios->print();
		  //  pilacambios->reporte();
			pintarTexto(2,2);
			c = false;
	
}

void Case2(string g){
	
	char cadena[128];
	ifstream file(g.c_str(), ios::app);
	
		listaArchRec->insertar(g,"rut");
		if(!file.fail()){
			file.getline(cadena,128,'\n');
		}
		while(!file.eof()){
			cout<<cadena<<endl;
			file.getline(cadena,128, '\n');
			
		}
		
		file.close();
}


int main()
{

		system("cls");
		int entrada=0;
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
		int c ;
		char opcion;
		string tecla;
		string g="";
		
		switch (entrada) {
			case 1:
			
				
				pintarCrear(2, 2);
				pintarCursor(2, 4);
				
				cin.ignore();
				getline(cin, tecla);
				if(tecla == "\030")
					main();
				else{
					c = tecla.size();
					for(int i=0; i<=c; i++){
						listaTexto->insertar(tecla[i]);
						//pintarTexto(2,1);
					}
				}
				
				opcion = getch();
				if(opcion == '\030')
					main();
				else
					Case1(opcion);
			
				pintarTexto(2,1);
				break;
			case 2:
				pintarCrear(2, 2);
				pintarCursor(2,4);
				printf("Abrir archivo: ");
				
				cin.ignore();
				getline(cin,tecla);
				if(tecla == "\030"){
					main();
				}else{
						
					g = tecla+".txt";
					Case2(g);
				}
				break;
			case 3:
				pintarCrear(2, 2);
				pintarCursor(2,4);
				printf("X: Generar reporte de archivos ");
				cin.ignore();
				getline(cin, tecla);
				if(tecla == "x")
					
					listaArchRec->reporte();
					
				else if(tecla == "\030"){
					main();
				}
				break;
			case 4:
				cout<<"EL PROGRAMA SE HA CERRADO"<<endl;
				exit(1);
				break;
		
		}
	
	
	return 0;
};




