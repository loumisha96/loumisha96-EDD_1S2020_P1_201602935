#include <iostream>
#include <string>

using namespace std;

class nodoP {
public:
	string buscar;
	string reemplazar;
	nodoP *sig;
	nodoP() {
		this->buscar = "";
		this->reemplazar = "";
		this->sig = 0;
	}
	void setBuscarReemplazar(string buscar, string reemplazar) {
		this->buscar = buscar;
		this->reemplazar = reemplazar;
	}


};
class ListaSimple {
public:
	nodoP* primero;
	ListaSimple() {
		primero = 0;
	}
	bool vacia() {
		return primero == 0;
	}
	void insertarOrdenadaBuscar(char buscar, string reemplazar) {
		nodoP* nuevo = new nodoP();
		//cout<< buscar.length();
		if (vacia()) {
			primero = nuevo;
		}
		else
		{
			nodoP* aux = primero;
			
		/*	while (aux->sig != 0) {
				char b[aux->buscar.size];
				for (int i = 0; i < buscar.size; i++) {
					if (strcoll(a[i], b[i]) < 0) {//a b inserta
						nuevo->sig = primero;
						primero = nuevo;
						primero->setBuscarReemplazar(buscar, reemplazar);
						aux->sig = 0;
					}if (strcoll(a[i], b[i]) > 0) {//b a cambia de nodoP
						aux = aux->sig;
						i = buscar.size;
					}
					else {
						//sigue recorriendo el string
					}
				}
				
			}*/
			
			
		
		}
	}
	void print() {
		nodoP* aux = primero;
		while (aux->sig != 0) {
			cout << aux->buscar << endl;
			aux = aux->sig;
		}


	}
};
