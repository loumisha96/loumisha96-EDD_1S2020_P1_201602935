#include <iostream>
#include <string>


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
	nodo* ultimo;
	nodo* primero;
	int tam;
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
	void buscar(string buscar, string reemplaza) {
		string word;
		bool var=true;
		nodo* aux = primero;
		int posinicio=-1;
		int posfinal=-1;
		int cont;
		while (var) {
			for (auto x : buscar) {
				
				if (aux->letra = x) {
					cont++;
					if(posinicio <0)
						posinicio = cont;
					
					aux = aux->sig;
				}
				else {
					while (aux->sig != 0) {
						if (aux->letra != ' ') {
							aux = aux->sig;
							cont++;
						}
							
						else {
							aux = aux->sig;
							cont++;
							break;
						}
							
					}
					
					if (aux = 0) {
						var = false;
					
					}
					break;
				}
			}
			if (aux != 0 || aux->letra == ' ')
				posfinal = cont;
			var = false;
		}
		
	}
};