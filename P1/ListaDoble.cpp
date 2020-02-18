#include <iostream>
#include <string.h>
#include <fstream>


using namespace std;
static int posinicio = -1;
static int posfinal;

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
			//ultimo = nuevo;
			tam = 0;
		}
		else {
			Nodo *aux= primero;
			while(aux->sig != 0){
				aux = aux->sig;
			}
			aux->sig = nuevo;
			nuevo->ant = aux;
			
			tam++;
		}
	}
/*	void eliminarporPosicion(int pos){
		Nodo *aux = BuscarPos(pos);
		while(aux->sig->letra != ' '|| aux->sig != 0){
			aux->sig = aux->sig->sig;
			aux->sig->sig->ant = aux;
		}
		
	}*/
	//insertar a partir de una posición
	void reemplazar(Nodo *inicio, Nodo *nuevo, bool cabeza){
		if(cabeza){
			primero = nuevo;
		}
		if(inicio->ant != 0){
			inicio->ant->sig= nuevo;
		}
		nuevo->ant= inicio->ant;
		nuevo->sig = inicio;
		inicio->ant = nuevo;
	}
	void insertarPorPosicion( char letra, int posicion) {
		Nodo* nuevo = new Nodo(letra);
		Nodo* aux = primero;
		for (int i = 0; i <= posicion; i++) {
			if (i == posicion) {
				aux->sig = nuevo;
				nuevo->sig = aux->sig->sig;
				nuevo->ant = aux;
				aux->sig->ant = nuevo;
				tam++;
			}
			else {
				aux = aux->sig;
			}
		}
	}
	void eliminar(Nodo*inicio, int cantidad, string reemplazo){
		bool cabeza = false;
		if(inicio==primero){
			cabeza = true;
		}
		Nodo *empieza = inicio->ant;
		Nodo *aux = inicio;
		for(int i = 0; i< cantidad; i++){
			aux= aux->sig;
		}
		if (cabeza){
			primero = aux;
		}
		if(!cabeza){
			empieza->sig= aux;
			
		}
		aux->ant = empieza;
		Nodo *inicio_reemplazo= aux;
		for(int i = 0; i<reemplazo.size(); i++){
			Nodo* nuevo = new Nodo(reemplazo[i]);
			reemplazar(inicio_reemplazo,nuevo, cabeza);
			cabeza= false;
		}
	}
	void print() {
		if (vacia())
			cout << "Lista Vacia";
		else {
			Nodo *aux= primero;
			while(aux != 0){
				cout<<aux->letra;
				aux= aux->sig;
			}
			
		}

	}
	void buscar(string palabra, int longitud, Nodo*actual, string reemplazo){
		
		Nodo *inicio =actual;
		for(int i = 0; i<longitud; i++){
			if(actual->letra == palabra[i]){
				if(i==(longitud-1)&&(actual->sig->letra==' ')||actual->sig == primero){
					eliminar(inicio, longitud, reemplazo);
				}
				actual = actual->sig;
			}else{
				break;
			}
		}
		
		if(actual->sig == 0){
			return;
		}
		buscar(palabra, longitud, actual->sig, reemplazo);
	}
	void buscarReemplazar(string palabra, string reemplazo){
		int cantidad = palabra.size();
		buscar(palabra, cantidad,primero, reemplazo);
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
			system("dot -Tpng Reporte.dot -o reporteTexto.png");
			system(" reporte.png &");
		}

	}
};

/*

int cont = -1;
int main(){
ListaDoble *prueba= new ListaDoble();
string nombre;
cout<<"ingrese nombre"<<endl;
getline(cin, nombre);
cout<<nombre;
int c = nombre.size();
for(int i=0; i<=c; i++){
	prueba->insertar(nombre[i]);
}
prueba->print();

/*	ListaDoble *prueba= new ListaDoble();
prueba->insertar('u');
prueba->insertar('o');
prueba->insertar('L');
//prueba->buscarLD('uoL',cont);

prueba->print();
prueba->reporte();*/
//	return 0;
//}*/
