#include <iostream>
#include "Nodo.h"

using namespace std;

class Lista{
	private:
		Nodo *inicio;
		int nE;
		int peso;
	public:
		Lista(int v){
			inicio=new Nodo(v);
			nE=1;
			peso=0;
		}
		Nodo *getInicio(){
			return inicio;
		}
		int getPeso(){
			return peso;
		}
		void setPeso(int p){
			peso=p;
		}
		int getnE(){
			return nE;
		}
		void push(int v, int p){
			peso+=p;
			Nodo* aux;
			if(v<inicio->getValor()||v==inicio->getValor()){
				aux=new Nodo(v,inicio);
				inicio=aux;
			}
			else{
				aux=inicio;
				while((aux->getPtr()!=0) && (aux->getPtr()->getValor()<v)){
					aux=aux->getPtr();
				}
				Nodo *aux1;
		
        		aux1= new Nodo(v,aux->getPtr());
				aux->setPtr(aux1);
			}
			nE++;
		}
		bool buscarN(int vB){
			Nodo *aux;
			bool enc=false;
			aux=inicio;
			while(aux!=0 && !enc){
				if(aux->getValor()==vB){
					//cout<<"&&&&&&&&&&&&&&&&&Valor:"<<aux->getValor();
                    enc=true;
				}
				aux=aux->getPtr();   
			}
			return enc;
	    }
		Nodo * buscar(int vB, int numEle, Nodo * ni){
			Nodo *aux;
			aux=inicio;
			bool enc=false;
			if(aux->getValor()==vB){
				return aux;
			}
			else{
				while(aux->getPtr()!=0 && !enc){
				    if(aux->getPtr()->getValor()==vB){
					   enc=true;
					   return aux;
				     }
				     else{
				     	aux=aux->getPtr();   
					 }
				}
				if(aux->getPtr()==0){
					return 0;
				}
			}
		}
		void pop(int v){
			Nodo *aux;
			aux=buscar(v,nE,inicio);
			if (aux!=0){
			aux->setPtr(aux->getPtr()->getPtr());
			nE--;
		    }
		    else{
		    	cout<<"Lista->El valor: "<<v<<" NO ESTA "<<endl;
			}
		}
		
		void print(){
			Nodo* aux; 
			aux=inicio;
			while(aux!=0){//en busca del valor nulo
			     if(aux->getValor()!=0){
                 cout<<"|"<<char(aux->getValor() + 64)<<"|->";
                 
                 //cout<<"|"<<aux->getValor()<<"|->"; 
                 }
				
				aux=aux->getPtr();
			}
			cout<<endl;
		}
};
