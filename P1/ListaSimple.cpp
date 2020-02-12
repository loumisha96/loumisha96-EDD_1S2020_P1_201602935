#include <iostream>
#include <string>

using namespace std;

class nodo {
public:
	string buscar;
	string reemplazar;
	nodo *sig;
	nodo() {
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
	nodo* primero;
	ListaSimple() {
		primero = 0;
	}
	bool vacia() {
		return primero == 0;
	}
	void insertarOrdenadaBuscar(char buscar, string reemplazar) {
		/*nodo* nuevo = new nodo();
		if (vacia()) {
			primero = nuevo;
		}
		else
		{
			nodo* aux = primero;
			
			int c = buscar.length();
			int d = c + 1;
			//char* a = buscar;
			const char* a = "hsd";
			cout << a[1]<<endl;
			//strcpy(a, buscar.c_str());
			
			
			while (aux->sig != 0) {
				char b[aux->buscar.size];
				for (int i = 0; i < buscar.size; i++) {
					if (strcoll(a[i], b[i]) < 0) {//a b inserta
						nuevo->sig = primero;
						primero = nuevo;
						primero->setBuscarReemplazar(buscar, reemplazar);
						aux->sig = 0;
					}if (strcoll(a[i], b[i]) > 0) {//b a cambia de nodo
						aux = aux->sig;
						i = buscar.size;
					}
					else {
						//sigue recorriendo el string
					}
				}
				
			}
			
			
		
		}*/
	}
	void print() {
		nodo* aux = primero;
		while (aux->sig != 0) {
			cout << aux->buscar << endl;
			aux = aux->sig;
		}


	}
};