#include <iostream>

class NodoP{
	private:
		int valor;
		NodoP * ptr;
	public:
		NodoP(int v){
			valor=v;
			ptr=0;
		}
		NodoP(int v, NodoP *ptro){
			valor=v;
			ptr=ptro;
		}
		void setValor(int v){
			valor=v;
		}
		void setPtr(NodoP *ptro){
			ptr=ptro;	
		}
		int getValor(){
			return valor;
		}
		NodoP * getPtr(){
			return ptr;
		}	
};
