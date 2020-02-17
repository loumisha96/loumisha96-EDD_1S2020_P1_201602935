#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class nodoLC {
public:
	string nombre;
	string ruta;
	nodoLC* sig;
	nodoLC(string nombre, string ruta) {
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
	public: 
	nodoLC* ultimo;
	//ultimo.sig = primero
	int tam;
	ListaCircular() {
		this->ultimo = 0;
	}
	void insertar(string nombre, string ruta) {
		nodoLC* nuevo = new nodoLC(nombre, ruta);
		ultimo->sig = nuevo;
		nuevo->sig = ultimo->sig;
		ultimo = nuevo;
	};
	void reporte(){
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
			nodoLC* aux = ultimo->sig;
			for (int i = 0; i < tam + 1; i++) {
				reporte<<i;
				reporte<<" [label = \"{<ref> | <data>" ;
				reporte<<aux->nombre;
				reporte<<" | }\"]\n";
				if(i+1 > tam){
					reporte<<(i+1);
					reporte<<"[label=\"{<data>";
					reporte<<aux->sig->nombre;
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
		
		}
	}
};
