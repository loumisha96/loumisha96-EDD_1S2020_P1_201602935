#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class nodoPC {
public:
	string wordsearch;//palabra buscada
	string wordreplace;//palabra reemplazada
	bool estado;
	string palabra;
	int posicion;
	nodoPC* sig;
	nodoPC() {
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
	nodoPC* primero;
	int tamPC;
	Pila() {
		this->primero = 0;
	}
	
	bool vacia() {
		return primero = 0;
	}
	
	//insertar para buscar y reemplazar
	
	void pushSearch(string wordsearch, string wordreplace) {
		nodoPC* aux = new nodoPC();
		aux->sig = primero;
		primero = aux;
		primero->setBuscarReemplazar(wordsearch, wordreplace);
		primero->setEstado(false);//preguntar
		if(tamPC == 0)
			tamPC++;
		else
			tamPC=0;

	}
	
	void pop() {
		nodoPC* aux = primero;
		primero = aux->sig;
		aux->sig = 0;
		tamPC--;
	}
	
	void pushEditar(string wordsearch, string wordreplace) {
		nodoPC* aux = new nodoPC();
		aux->sig = primero;
		primero = aux;
		tamPC++;
	}
	void print(){
		nodoPC*aux = primero;
		while(aux->sig != 0){
			cout<<aux->wordsearch;
			aux = aux->sig;
		}
		cout<<aux->wordsearch;
	}
	
	void reporte(){
		ofstream report;
		report.open("reportCambios.dot", ios::out);
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
			system("dot -Tpng reportCambios.dot -o reportCambios.png");
			system(" reportCambios.png &");
		}
	}
};
/*
int main(){
	Pila *pc= new Pila();
	pc->pushSearch("buscar", "reemplazar");
	pc->pushSearch("buscar1", "reemplazar");
	pc->pushSearch("buscar2", "reemplazar");
	pc->pushSearch("buscar3", "reemplazar");
	pc->print();
	pc->reporte();
	return 0;
}*/
