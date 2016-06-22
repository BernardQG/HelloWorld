#include <iostream>
#include "Pila.h"
#include "Lista.h"
using namespace std;
//Funciones
void Aestre();//Aestrella
int Avanza(int n);//Verifica los posibles nuevos caminos
int CuateC(int QuieroIr,int DondeEstoy);///Busca a raiz igual de 2 caminios
bool Revisar(int Rev);//Checa si existe un mejor camino
void RepoC(int Cuatt, int QuieroIr);//mueve a la pila para redefinir el nuevo camino
void establecerPueblos();
//variables
int  Tacos[1000][3];
int inicio, fin,tamano, a=0;
int i,j,k; //contadores
int posTraslacion, posicion ,auxPos,posTacos=1;//posicionadores
Lista *abierta   =  new Lista(0); //Creando lista
Pila  *cerrada =  new Pila(0);//Creando Pila
//##########################################3
//peso
int MatAd[7][7]={{0,0,4,3,8,0,0},
                {0,0,2,3,0,0,9},
				{4,2,0,0,0,0,0},
				{3,3,0,0,0,14,12},
				{8,0,0,0,0,0,1},
				{0,0,0,14,0,0,7},
				{0,9,0,12,1,7,0}};
//Si queremos llegar de A a F 
int MHeurA[]={0,4,1,5,6,1,0};
//###########################################3
//Funcion Principal
int main()
{
    inicio=posicion=0; fin=6; tamano=6;
    Tacos[0][0]=Tacos[0][1]=posicion;
    Tacos[0][2]=0;
    establecerPueblos();
    Aestre();
    system("pause>Null");
    
     
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void establecerPueblos(){    
    for(i=1;i<=tamano+1;i++){    abierta->push(i,10); }
    cout<<" >>Pueblos Disponibles: "; abierta->print();
    abierta->pop(inicio+1);
    
   
}
void Aestre(){
     int cuatt,aux;

     while(cerrada->getValorIni()!=fin){
           auxPos=Avanza(posicion);
           aux=posTraslacion;
           
           if(Revisar(Tacos[posTraslacion][2])){
                cuatt=CuateC(posTraslacion, aux);
                RepoC(cuatt,posTraslacion);
                a=Tacos[posTraslacion][2] - MHeurA[Tacos[posTraslacion][1]]- MatAd[Tacos[posTraslacion][0]][Tacos[posTraslacion][1]]; 
                posicion=Tacos[posTraslacion][0];
           }
                else {                                          
                      a+=MatAd[posicion][auxPos];
                      abierta->pop(auxPos+1);     cerrada->push(auxPos);
                      posicion=auxPos;
           }
              
     for(i=0;i<posTacos;i++){ if(Tacos[i][1] == posicion && Tacos[i][1]!=fin){ Tacos[i][2] = 0; } }
     }
  
     
     if(cerrada->getValorIni()==fin){ 
              cout<<"\n\n >>Mejor ruta para llegar de A a E"<<endl; cerrada->print();
              cout<<"\n >>Distancia:  "<<a<<endl;}
     else{ cout<<"\n\n\n>>> haber un error, encontralo tu deber sera.\n\t Que el compilador te acompañe"; }

}
int Avanza(int n){
    int mayor=1000,aux1;   
    for(i=0;i<=tamano;i++){
           //Guardar todos los valroes de cada relacion revisada
           
           if(MatAd[n][i]!=0 && abierta->buscarN(i+1)){
                                                        
                    Tacos[posTacos][0]=n;    Tacos[posTacos][1]=i;
                    Tacos[posTacos][2]=a + MatAd[n][i] + MHeurA[i];     
                    cout<<"\npT: "<<abierta->buscarN(i+1)<<">"<<posTacos<<" "<<char(Tacos[posTacos][0]+65)<<":"<<char(Tacos[posTacos][1]+65)<<"="<<Tacos[posTacos][2];   
                    for(j=0;j<posTacos;j++){ if(Tacos[j][2]==0 && Tacos[j][1]==Tacos[posTacos][1])
                                   { Tacos[posTacos][2]=0;}}
                      //cout<<endl<<Tacos[posTacos][2]<<" <"<< mayor;
                    if((Tacos[posTacos][2] < mayor) && Tacos[posTacos][2]!=0)
                    {       mayor = a + MatAd[n][i] +  MHeurA[i];  
                            aux1=i; posTraslacion=posTacos;   
                    }    
            posTacos++;
           }
           
    }
    
    return aux1;
}

bool Revisar(int Rev){
     int auxT; bool DD=false;
    
     for(i=0;i<posTacos;i++)
     {
            if(Tacos[i][2]<Rev && Tacos[i][2]!=0 && Tacos[i][2]!=-1 && Tacos[i][0]!=cerrada->getValorIni()){ auxT=i; DD=true; break; }
     }
     if(DD){ posTraslacion=auxT; 
     //cout<<"\nSimon si hay un numero menor en: "<<char(Tacos[auxT][1]+65)<<"  = "<<Tacos[auxT][2]<<endl;
     } 
     return DD;
}
int CuateC(int QuieroIr,int DondeEstoy){
    int PCompa[100]; j=0; int auxj;
       while(Tacos[DondeEstoy][1]!=0){
          for(i=0;i<posTacos;i++){ 
              if(Tacos[i][1]==Tacos[DondeEstoy][0] && Tacos[i][2]==0)
              {         
                DondeEstoy=i;  
                PCompa[j]=Tacos[i][0];  
                j++;                                
              }
          }
       }
       //cout<<endl;  for(i=0;i<j;i++){ cout<<PCompa[i]<<"/"; }
       while(Tacos[QuieroIr][1]!=0){
          for(i=0;i<posTacos;i++){ 
              if(Tacos[i][1]==Tacos[QuieroIr][0] && Tacos[i][2]==0)
              {         
                QuieroIr=i;
                for(k=0;k<j;k++){
                    if(PCompa[k]==Tacos[i][0]){ auxj=PCompa[k]; break; }                                                   
                } 
              }
          }
       }
       
       return auxj;
}
void RepoC(int Cuatt, int QuieroIr){
      int PCompa[100]; j=0;
      while(cerrada->getValorIni()!=Cuatt)
      {  
         for(i=0;i<posTacos;i++){ if(Tacos[i][0]==cerrada->getValorIni()){ Tacos[i][2]=-1; }
                                  //if(Tacos[i][1]==cerrada->getValorIni()){ Tacos[i][2]=-2; }
                                  }
         abierta->push(cerrada->getValorIni()+1,5);  cerrada->pop();  
      }
       while(Tacos[QuieroIr][0]!=Cuatt){
          for(i=0;i<posTacos;i++){ 
              if(Tacos[i][1]==Tacos[QuieroIr][0] && Tacos[i][2]==0)
              {         
                QuieroIr=i;
                PCompa[j]=Tacos[i][0];  
                j++; 
              }
          }
       }
       for(i=0;i<j;i++){ 
         cerrada->push(PCompa[i]); abierta->pop(PCompa[i]+1);
       }                 
}
