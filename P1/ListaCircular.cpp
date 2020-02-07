#include <iostream>
#include <string>

using namespace std;

class nodo {
public:
	string nombre;
	string ruta;
	nodo* sig;
	nodo() {
		this->nombre = "";
		this->ruta = "";
		this->sig = 0;
	};
	void setNombreArchivo(string nombre, string archivo) {
		this->nombre = nombre;
		this->ruta = archivo;
	}
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
		nodo* nuevo = new nodo();
		ultimo->sig = nuevo;
		nuevo->sig = ultimo->sig;
		ultimo = nuevo;
		ultimo->setNombreArchivo(nombre, ruta);

	};
};