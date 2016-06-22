#include <cstdlib>
#include <iostream>
#include "Pila.h"
#include "Lista.h"
using namespace std;
int InC=0,FN=4;
//peso
int MatAd[5][5]={{0,10,2,3,0},
                {10,0,4,2,10},
				{2,4,0,3,2},
				{3,2,3,0,0},
				{0,10,2,0,0}};
//Si queremos llegar de A a F 
int MHeurA[]={10,0,7,12,0};
Lista *Lt   =  new Lista(InC); //Creando lista
Pila  *pila =  new Pila(InC);//Creando Pila

void Aestre(bool EsCD, int InC, int FN){
         int a=0,n,n2, m, cY=1;
         n=InC;
         while(n!=FN){
            m=1000;
            //cout<<"A: "<<a<<endl;
            for(int i=InC; i<=FN;i++){
                            
                    if((a + MHeurA[i])< m && MatAd[n][i]!=0 && Lt->buscarN(i+1))
                    { m = MatAd[n][i] +  MHeurA[i]; /*cout<<"M: "<<m<<endl*/; n2=i;}
                    if(n2==FN){ EsCD = true; }
            }
         //Aestre(EsCD, n2, FN);
            
            //cout<<"valores: \n\tn:"<<n<<" n2: "<<n2;
            a+=MatAd[n][n2];
            //system("pause>NULL");
            Lt->pop(n2);     pila->push(n2);
            n=n2;    cY++; }
      
         if(EsCD){ cout<<"\n\n >>Mejor ruta para llegar de A a E"<<endl; pila->print(cY); }
         else{ cout<<"\n\n\n>>>Haver un error, encontralo tu deber sera.\n\t Que el compilador te acompañe"; }
}

int main(int argc, char *argv[])
{
    bool ED0=false;
    Lt->setPeso(100);     
    for(int i=InC+1;i<=FN+1;i++){    Lt->push(i,10); }
    cout<<" >>Pueblos Disponibles: "; Lt->print();
    Lt->pop(InC);
    
    
    Aestre(ED0,InC,FN);
    
    //cout<<"\nPueblos sin visitar: "; Lt->print();
	cout<<"\n\n\t\t\t  By Bernardo Quintino\n\t'Codificando para un mundo mas PEREZOSO'";
    system("PAUSE>NULL");
    return EXIT_SUCCESS;
}
