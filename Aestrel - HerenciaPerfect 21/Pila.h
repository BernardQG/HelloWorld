#include <iostream>
#include "NodoP.h"

using namespace std;

class Pila{
	private:
		NodoP *inicio;
		NodoP *fin;
		int numElementos;
	public:
		Pila(int v){
			inicio=fin=new NodoP(v);
			numElementos=1;
		}	
		Pila(){
			inicio=fin=0;
		}
		void push(int v){
			if(inicio==0){
				inicio=fin=new NodoP(v);
				numElementos=1;
			}
			else{
			NodoP *aux;
			aux=new NodoP(v,inicio);
			inicio=aux;
			numElementos++;
			// inicio=new Nodo(v,inicio);
		    }
		}
		void pop(){
			if(inicio!=0){
				inicio=inicio->getPtr();
				numElementos--;
			}
			else{
				cout<<"Pila vacia"<<endl;
			}
		}
		void print(int cY){
			NodoP *aux;
			aux=inicio;
			while(aux!=0){
                //if(aux->getValor()!=0){          
				cout<<"\tPueblo "<<cY<<": "<<char(aux->getValor() + 65)<<"\n";
				cY--; //}
				aux=aux->getPtr();
			}
			cout<<endl;
		}
		int getNumE(){
			return numElementos;
		}
		int getValorIni(){
			return inicio->getValor();
		}
};
