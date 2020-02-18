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
	
};
class ListaCircular {
public: 
	nodoLC* ultimo;
	nodoLC* primero;
	//ultimo.sig = primero
	int tamLC;
	ListaCircular() {
		this->ultimo = 0;
		this->primero = 0;
	};
	void insertar(string nombre, string ruta) {
		nodoLC* nuevo = new nodoLC(nombre, ruta);
		if(primero==0){
			primero = nuevo;
			ultimo = nuevo;
			ultimo->sig= primero;
			tamLC=0;
		}else{
			ultimo->sig= nuevo;
			nuevo->sig = primero;
			ultimo = nuevo;
			tamLC++;
		}
		
	}
	void print(){
		nodoLC *aux=primero;
		while(aux!=ultimo){
			cout<<aux->nombre;
			aux = aux->sig;
		}
		cout<<aux->nombre;
	}
	void reporte(){
		ofstream reporte;
		reporte.open("reporteArchRec.dot", ios::out);
		if (reporte.fail()) {
			cout << "No se creo el reporte" << endl;
			exit(1);
		}
		else {
			reporte << "digraph G{\n";
			reporte << "rankdir = LR;\n";
			reporte << "node[shape = record]; \n";
			nodoLC* aux = ultimo->sig;
			for (int i = 0; i < tamLC + 1; i++) {
				reporte<<i;
				reporte<<" [label = \"{<ref> | <data>" ;
				reporte<<aux->nombre;
				reporte<<" | }\"]\n";
				if(i==tamLC){
					reporte<<i;
					reporte<<"->";
					reporte<<0;
					reporte<<"\n";
				}
				else if(i+1 > tamLC){
					reporte<<i;
					reporte<<"->";
					reporte<<(i+1);
					reporte<<"\n";
				}
				else{
					
					reporte<<i;
					reporte<<"->";
					reporte<<(i+1);
					reporte<<"\n";
				}
				aux = aux->sig;
			}	
			reporte << "}";
			reporte.close();
			string str = "dot -o imagen.out reporte.dot" ;
			system("dot -Tpng reporteArchRec.dot -o reporteArchRec.png");
			system("reporteArchRec.png &");
		}
	}
};
