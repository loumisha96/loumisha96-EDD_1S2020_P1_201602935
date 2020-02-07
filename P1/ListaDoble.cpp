#include <iostream>
#include <string>


using namespace std;

class nodo {
public:
	char letra;
	nodo* sig;
	nodo* ant;
	int pos;
	nodo(char letra) {
		this->letra = letra;
		this->ant = 0;
		this->sig = 0;
		pos++;
	};
};
class ListaDoble {
	nodo* ultimo;
	nodo* primero;

	ListaDoble() {
		this->ultimo = 0;
		this->primero = 0;
	}
	bool vacia() {
		primero = 0;
	}
	void insertar(char letra) {
		nodo* nuevo = new nodo(letra);
		if (vacia()) {
			primero = nuevo;
			ultimo = nuevo;

		}
		else {
			nuevo->sig = primero;
			primero->ant = nuevo;
			primero = nuevo;

		}

	}
	void buscar(string buscar, string reemplaza) {
		string word;

		for (auto x : buscar) {
			nodo* aux = primero;
			if (aux->letra = x) {
				word = word + x;
			}
			else {
				word = "";
			}
		}
	}
};