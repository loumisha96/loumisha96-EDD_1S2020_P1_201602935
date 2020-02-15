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
	void eliminarporPosicion(int pos){
		Nodo *aux = BuscarPos(pos);
		while(aux->sig->letra != ' '|| aux->sig != 0){
			aux->sig = aux->sig->sig;
			aux->sig->sig->ant = aux;
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

	void reemplazar(string buscada, char reemplazar, int tambuscada) {
		int b = buscada.size();
		
		Nodo *aux = primero;
		
			for(int i =0; i<tam; i++){
				if(i== posinicio && i<=posfinal){
					aux->letra = reemplazar;
					aux = aux->sig;
					i= tam;
				}
				else{
					aux = aux->sig;
				}
			}
			posinicio++;
		
	}
	Nodo* BuscarPos(int pos){
		Nodo *aux = primero;
		
		for(int i=0;i<=tam; i++){
			if(i==pos){
				return aux;
			}
			else
				aux = aux->sig;
		}
	}
	
	
	void reporte() {
		ofstream reporte;
		reporte.open("Reporte.dot", ios::out);
		if (reporte.fail()) {
			cout << "No se creo el reporte" << endl;
			exit(1);
		}
		else {
			reporte << "digraph G{\n";
			reporte << "rankdir = LR;\n";
			reporte << "node[shape = record]; \n";
			Nodo* aux = primero;
			for (int i = 0; i < tam + 1; i++) {
				reporte<<i;
				reporte<<" [label = \"{<ref> | <data>" ;
				reporte<<aux->letra;
				reporte<<" | }\"]\n";
				if(i+1 > tam){
					
					
					reporte<<(i+1);
					reporte<<"[label=\"{<data>";
					reporte<<"null";
					reporte<<" }\"]\n";
					reporte<<i;
					reporte<<"->";
					reporte<<(i+1);
					reporte<<"\n";
					reporte<<(i+1);
					reporte<<"->";
					reporte<<i;
					reporte<<"\n";
					
					
				}
				else{
					
					reporte<<i;
					reporte<<"->";
					reporte<<(i+1);
					reporte<<"\n";
					reporte<<(i+1);
					reporte<<"->";
					reporte<<i;
					reporte<<"\n";
					
				}
				
				
				aux = aux->sig;

			}
			reporte << "}";
			reporte.close();
			string str = "dot -o imagen.out reporte.dot" ;
			system("dot -Tpng Reporte.dot -o reporte.png");
			system(" reporte.png &");
		}

	}
};


/*
int cont = -1;
int main(){

	ListaDoble *prueba= new ListaDoble();
prueba->insertar('u');
prueba->insertar('o');
prueba->insertar('L');
//prueba->buscarLD('uoL',cont);

prueba->print();
prueba->reporte();
	return 0;
}*/
