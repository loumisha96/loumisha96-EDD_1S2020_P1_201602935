#include <iostream>
#include <string>

using namespace std;
class nodo {
public:
	string wordsearch;//palabra buscada
	string wordreplace;//palabra reemplazada
	bool estado;
	string palabra;
	int posicion;
	nodo* sig;
	nodo() {
		this->wordsearch = "Null";
		this->wordreplace = "Null";
		this->posicion = 0;
		this->palabra = "Null";
		this->sig = 0;
		this->estado = false;

	};
	void setBuscarReemplazar(string buscar, string reemplazar) {
		this->wordsearch = buscar;
		this->wordreplace = reemplazar;
	}
	void setPosicionPalabra(string palabra, int pos) {
		this->palabra = palabra;
		this->posicion = pos;
	}
	void setEstado(bool estado) {
		this->estado = estado;
	}

};
class Pila {
public:
	nodo* primero;
	Pila() {
		primero = 0;
	}
	bool vacia() {
		return primero = 0;
	}
	//insertar para buscar y reemplazar
	void pushSearch(string wordsearch, string wordreplace) {
		nodo* aux = new nodo();
		aux->sig = primero;
		primero = aux;
		primero->setBuscarReemplazar(wordsearch, wordreplace);
		primero->setEstado(false);//preguntar

	}
	void pop() {
		nodo* aux = primero;
		primero = aux->sig;
		aux->sig = 0;
	}
	void pushEditar(string wordsearch, string wordreplace) {
		nodo* aux = new nodo();
		aux->sig = primero;
		primero = aux;
		//primero->setPosicionPalabra()


	}
};