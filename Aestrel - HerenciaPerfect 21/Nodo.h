#include <iostream>

class Nodo{
	private:
		int valor;
		Nodo * ptr;
	public:
		Nodo(int v){
			valor=v;
			ptr=0;
		}
		Nodo(int v, Nodo *ptro){
			valor=v;
			ptr=ptro;
		}
		void setValor(int v){
			valor=v;
		}
		void setPtr(Nodo *ptro){
			ptr=ptro;	
		}
		int getValor(){
			return valor;
		}
		Nodo * getPtr(){
			return ptr;
		}	
};
