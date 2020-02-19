#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h> 
using namespace std;

class nodoP {
public:
	string buscar;
	string reemplazar;
	nodoP *sig;
	nodoP() {
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
	nodoP* primero;
	int tam;
	ListaSimple() {
		primero = 0;
	}
	bool vacia() {
		return primero == 0;
	}
/*	void insertarOrdenadaBuscar(string buscar, string reemplazo) {
		
		nodoP* nuevo = new nodoP();
		nuevo->buscar = buscar;
		char str[10];
		
		if(vacia()){
			primero = nuevo;
			tam =0;
		}else{
			nodoP* aux = primero;
			while(aux->sig != 0 && (strcmp(nuevo->buscar, aux->buscar)>0)){
				aux= aux->sig;
			}
		}
		
		
	}*/
	void print() {
		nodoP* aux = primero;
		while (aux->sig != 0) {
			cout << aux->buscar << endl;
			aux = aux->sig;
		}


	}
	/*void reporte(){
		ofstream report;
		report.open("reportPalabrasOrdenadas.dot", ios::out);
		if (report.fail()) {
			cout << "No se creo el report" << endl;
			exit(1);
		}
		else {
			report << "digraph G{\n";
			report << "rankdir = LR;\n";
			report << "node[shape = record]; \n";
			nodoPC* aux = primero;
			for (int i = 0; i <= tamPC + 1; i++) {
				report<<i;
				report<<" [label = \"{<ref> | <data>" ;
				report<<"Palabra Buscada: ";
				report<<aux->wordsearch;
				report<<"\\n Palabra Remplazada: ";
				report<<aux->wordreplace;
				report<<"\\n Estado: ";
				report<<aux->estado;
				report<<"\\n Palabra: ";
				report<<aux->palabra;
				report<<"\\n Posicion: ";
				report<<aux->posicion;
				report<<" | }\"]\n";
				if(i+1 >= tamPC){
					report<<(i+1);
					report<<"[label=\"{<data>";
					report<<"null";
					report<<" }\"]\n";
					report<<i;
					report<<"->";
					report<<(i+1);
					report<<"\n";
				}
				else{
					
					report<<i;
					report<<"->";
					report<<(i+1);
					report<<"\n";
				}
				aux = aux->sig;
			}
			report << "}";
			report.close();
			string str = "dot -o imagen.out reportCambios.dot" ;
			system("dot -Tpng reportPalabrasOrdenadas.dot -o reportPO.png");
			system(" reportPO.png &");
		}
	}*/
};
