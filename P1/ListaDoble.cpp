#include <iostream>
#include <string.h>
#include <fstream>


using namespace std;
static int posinicio = -1;
static int posfinal = -1;

class Nodo {
public:
	char letra;
	Nodo* sig;
	Nodo* ant;

	Nodo(char letra) {
		this->letra = letra;
		this->ant = 0;
		this->sig = 0;

	}
};
class ListaDoble {
public:
	Nodo* ultimo;
	Nodo* primero;
	int tam;
	ListaDoble() {
		this->ultimo = 0;
		this->primero = 0;

	};

	bool vacia() {
		return primero == 0;
	}

	void insertar(char letra) {
		Nodo* nuevo = new Nodo(letra);
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
		Nodo* nuevo = new Nodo(letra);
		Nodo* aux = primero;
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
	Nodo* buscarLD(char s, int cont){
		Nodo * retornar = 0;
		char f = 'u';
		bool encontrado = true;
		int i = 0;
		Nodo *aux = primero;
		for(int j =0; j<tam+1; j++){
			if(j==cont){
				j=tam;
			}
			else{
				aux = aux->sig;
			}
		}
		while(i<tam && encontrado){
			if( aux->letra== s){
				if(posinicio<0)
					posinicio = cont;
				if(aux->sig == 0)
					posfinal = cont;
				retornar = aux;
				aux = aux->sig;	
				
				i= tam;
			}else{
				while(aux->sig != 0 || aux->letra == ' '){
					aux = aux->sig;
					
				}
				aux = aux->sig;
			}
			
		}
		return retornar;
	}
	void print() {
		if (vacia())
			cout << "Lista Vacia";
		else {
			Nodo* aux = primero;

			while (aux->sig != 0) {
				cout << aux->letra << endl;
				aux = aux->sig;
			}
			cout << aux->letra << endl;
		}

	}

	void reemplazar(string buscada, char reemplazar) {
		int b = buscada.size();
		
		Nodo *aux = primero;
		
			for(int i =0; i<tam; i++){
				if(i== posinicio && i<=posfinal){
					aux->letra = reemplazar;
					aux = aux->sig;
					i= tam;
					
				}
			}
			posinicio++;
		
	}
	
	void reporte() {
		ofstream reporte;
		reporte.open("Reporte.dot", ios::out);
		if (reporte.fail()) {
			cout << "No se creo el reporte" << endl;
			exit(1);
		}
		else {
			reporte << "digraph G{" << endl;
			reporte << "rankdir = LR;" << endl;
			reporte << "node[shape = record]; " << endl;
			Nodo* aux = primero;
			for (int i = 0; i < tam + 1; i++) {
				reporte << i + "[label=\"{<ref>|<data>" << aux->letra + "|}\"] ";
				reporte << i + "->" << i + 1 << endl;

			}
			reporte << "}" << endl;
			reporte.close();
			string str = "gcc";
			str = str + "-o reporte.out imagen.jpg";
			const char* command = str.c_str();
			system(command);
			system("./ reporte.out");
			//ios.system("dot-Tjpg Reporte.dot -o imagen.jpg");
			//system("imagen.jpg");
		}

	}
};



/*int cont = -1;
int main(){

	ListaDoble *prueba= new ListaDoble();
prueba->insertar('u');
prueba->insertar('o');
prueba->insertar('L');
prueba->buscar('uoL',cont);
prueba->reemplazar('u', posinicio, posfinal);
prueba->print();
	return 0;
}*/
