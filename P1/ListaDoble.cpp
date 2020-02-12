#include <iostream>
#include <string.h>



using namespace std;

class nodo {
public:
	char letra;
	nodo* sig;
	nodo* ant;
	
	nodo(char letra) {
		this->letra = letra;
		this->ant = 0;
		this->sig = 0;
		
	};
};
class ListaDoble {
public:
	nodo* ultimo;
	nodo* primero;
	int tam;
	ListaDoble() {
		this->ultimo = 0;
		this->primero = 0;
		
	}
	bool vacia() {
		return primero == 0;
	}
	
	void insertar(char letra) {
		nodo* nuevo = new nodo(letra);
		if (vacia()) {
			primero = nuevo;
			ultimo = nuevo;
			tam = 0;
		}
		else {
			ultimo->sig = nuevo;
			nuevo->ant = ultimo;
			ultimo = nuevo;
			tam++;
		}
	}
	//insertar a partir de una posición
	void insertarPorPosicion(char letra, int posicion) {
		nodo* nuevo = new nodo(letra);
		nodo* aux = primero;
		for (int i = 0; i < posicion; i++) {
			if (i == posicion) {
				aux->ant->sig = nuevo;
				nuevo->sig = aux;
				nuevo->ant = aux->ant;
				aux->ant = nuevo;
				tam++;
				}
			else {
				aux = aux->sig;
			}
		}

		

	}
	void print() {
		if (vacia())
			cout << "Lista Vacia";
		else {
			nodo* aux = primero;

			while (aux->sig != 0) {
				cout << aux->letra << endl;
				aux = aux->sig;
			}
		}
		
	}
	int posinicio = -1;
	int posfinal = -1;
	nodo* buscar(string s, nodo* aux1, int cont) {
		bool var = true;
		nodo* aux = aux1;
		int cont1 = cont;
		while (var) {
			for (auto x : s) {
				if (aux->letra == x) {
					cont1++;
					if (posinicio < 0)
						posinicio = cont1;
					if (aux->sig == 0 || aux->sig->letra == ' ')
						posfinal = cont1;
					aux = aux->sig;
				}
				else {
					while (aux->sig != 0) {
						if (aux->letra != ' ') {
							aux = aux->sig;
							cont1++;
						}
						else {
							aux = aux->sig;
							buscar(s, aux, cont1);
							break;
						}
					}
					if (aux->sig == 0) {
						var = false;
					}
				}
			}
			var = false;
			aux = primero;
			for (int i = 0; i < tam + 1; i++) {
				if (posinicio == i) {
					return aux;
				}
				else {
					if (aux->sig != 0)
						aux = aux->sig;
				}
			}
		}
	}
	void r(string buscar, string reemplazar, int inicio, int final, nodo*aux) {
		if (buscar.length() < reemplazar.length()) {
			cout << "1";
		}
		else if (buscar.length() > reemplazar.length()) {
			cout << "2";
		}
		else {
			cout << "3";
		}
	}
	void reemplazar(string s, nodo* aux1, int cont) {

		nodo* s1 = buscar(s, aux1, cont);
		if (posinicio >= 0) {
			cout << "Valor encontrado: ";
			cout << s1->letra << endl;
		}
		else {
			cout << "No se encuentra coincidencia ";
		}

	}
	nodo* buscarpos(int pos) {
		nodo* aux = primero;
		/*int p;
		while (p != pos) {
			aux = aux->sig;
		}*/
		
		return aux;
	}
};