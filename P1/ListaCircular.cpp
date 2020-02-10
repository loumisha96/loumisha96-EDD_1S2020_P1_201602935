#include <iostream>
#include <string>

using namespace std;

class nodo {
public:
	string nombre;
	string ruta;
	nodo* sig;
	nodo(string nombre, string ruta) {
		this->nombre = nombre;
		this->ruta = ruta;
		this->sig = 0;
	};
	
	string getNombre() {
		return this->nombre;
	}
	string getRuta() {
		return this->ruta;
	}
};
class ListaCircular {
	nodo* ultimo;
	//ultimo.sig = primero
	ListaCircular() {
		this->ultimo = 0;
	}
	void insertar(string nombre, string ruta) {
		nodo* nuevo = new nodo(nombre, ruta);
		ultimo->sig = nuevo;
		nuevo->sig = ultimo->sig;
		ultimo = nuevo;
	

	};
};