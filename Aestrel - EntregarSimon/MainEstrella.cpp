#include <cstdlib>
#include <iostream>
#include "Pila.h"
#include "Lista.h"
using namespace std;

//Funciones
void Aestre(int InC, int FN);//Aestrella
int Avanza(int n);//Verifica los posibles nuevos caminos
int CuateC(int nn1,int ff);///Busca a raiz igual de 2 caminios
bool Revisar();//Checa si existe un mejor camino
int RepoC(int ii, int ff,int cY);//mueve a la pila para redefinir el nuevo camino


//Variables
int InC=0,a=0, FN=6,TTm=6,k=0,kk2, i,n,n1;
bool ED0=false;
int mMm[1000][3];



//peso
int MatAd[7][7]={{0,0,4,3,8,0,0},
                {0,0,2,3,0,0,9},
				{4,2,0,0,0,0,0},
				{3,3,0,0,0,1,12},
				{8,0,0,0,0,0,1},
				{0,0,0,1,0,0,7},
				{0,9,0,12,1,7,0}};



//Si queremos llegar de A a F 
int MHeurA[]={0,4,2,5,3,4,0};
Lista *Lt   =  new Lista(0); //Creando lista
Pila  *pila =  new Pila(0);//Creando Pila



int Avanza(int n){
    int m=1000;
    cout<<"\nAvanza con:"<<char(n +65)<<endl;
    for(i=0; i<=TTm;i++){
               //Guardar todos los valroes de cada relacion      z
               if(MatAd[n][i]!=0 && Lt->buscarN(i+1)){
                    mMm[k][0]=n;       
                    mMm[k][1]=i;
                    mMm[k][2]=a + MatAd[n][i] + MHeurA[i];
                    for(int ij=0;ij<k;ij++){ if(mMm[ij][2]==0 && mMm[ij][1]==mMm[k][1]){ mMm[k][2]=0;}}
                    if((mMm[k][2]< m && mMm[k][2]!=0)){       m = MatAd[n][i] +  MHeurA[i];  
                                              n1=i; kk2=k; 
                    k++; }
                    
               }
    }
    for(i=0;i<k;i++){  cout<<char(mMm[i][0]+65)<<" > "<<char(mMm[i][1]+65)<<"="<<mMm[i][2<<"\n"; }
    return n1;
}




void Aestre(int InC, int FN){
         int n, n1,cY=1,auxk,hk;
         n=InC;
         //while(true){
         while(pila->getValorIni()!=FN){ //nOTa pal futuro: sera mientras exista un camino con menor cantidad
            
            n1=Avanza(n);
            auxk=kk2;
            //cout<<kk2<<endl;
            //Preguntar si por otro lugar es mas eficiente
            
            if(Revisar()){
              //Cuate en comun
              cout<<"Entro a if\n";
              n1=mMm[kk2][1];//nuevo recorrido
                hk=CuateC(auxk,kk2);
                //cout<<"comun:"<<char(hk+65)<<endl;
                cout<<"TTTTTTTT>>>: "<<hk;
                            //nel carna esta mal este bisne              
                while(pila->getValorIni()!=hk)//Hay que revisar
                { cout<<"\n\tRemoviendo: "<<char(pila->getValorIni()+65)<<endl; Lt->push(pila->getValorIni()+1,5);  pila->pop();  }
                
                
                n=mMm[RepoC(hk,kk2,cY)][1];
                
                a=mMm[kk2][2] - MHeurA[mMm[kk2][1]];
                //cout<<"aaaaaaaaaaaaaaaaaaaaaaaaa"<<a;
      
                
            } 
            else{ 
            a+=MatAd[n][n1];
                Lt->pop(n1+1);     pila->push(n1);
                //Borrar Valor de nodo que ya ha sido recorido
                
                n=n1;    cY++;  
            }
            for(i=0;i<k;i++){ if(mMm[i][1] == n1 && mMm[i][1]!=FN){ mMm[i][2] = 0; } }
            cout<<"\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
            pila->print(cY);
                //cout<<endl<<"Lista:"<<endl;
                //Lt->print();
            cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
            
                
            system("pause");
         }
         
         if(pila->getValorIni()==FN){ 
          cout<<"\n\n >>Mejor ruta para llegar de A a E"<<endl; pila->print(cY);
          cout<<"\n >>Distancia:  "<<a<<endl;}
         else{ cout<<"\n\n\n>>>Haver un error, encontralo tu deber sera.\n\t Que el compilador te acompañe"; }
}






int CuateC(int nn1,int ff){  //Encontral en que momento se pude cambir el camino
   int MMT[100],MMT2[100],j=ff,jj,jk=1,jk2=1,Rr;
   //cout<<"\n>>>>"<<char(mMm[nn1][0]+65)<<"   "<<char(mMm[ff][1]+65)<<endl;
   
   //hay que cambiar este sistema de busquedad de cuateee
   MMT[0]=mMm[j][0]; bool DR=false;
   while(mMm[j][0]!=0){
           for(jj=0;jj<k;jj++){ if(mMm[jj][1]==mMm[j][0] && mMm[jj][2]==0){ j=jj; } 
           //if(mMm[j][0]==0){ TB=false; }
           }
          //cout<<"ciclo1";
           MMT[jk]=mMm[j][0];
           jk++; 
   }
   /*   cout<<"\t>>>MMT: \n";
   for(i=0;i<jk;i++){  cout<<char(MMT[i]+65)<<"\n"; }
   system("pause>NULL");*/
   MMT[jk]=0;
      for(i=0;i<jk2;i++){  cout<<char(MMT[i]+65)<<"\n"; }
   j=nn1;
   system("pause>NULL");
   //cout<<endl<<endl<<"Cl2: "<<ff<<endl;
   MMT2[0]=mMm[j][0];
   while(mMm[j][0]!=0){
           for(jj=0;jj<k;jj++){ if(mMm[jj][1]==mMm[j][0] && mMm[jj][2]==0){ j=jj; } 
           //if(mMm[j][0]==0){ TB=false; }
           }
          //cout<<"ciclo1";
           MMT2[jk2]=mMm[j][0];
           jk2++; }
   MMT[jk2]=0;
   /*        
   while(TD){
               cout<<mMm[j][0]<<">>";        
           for(jj=0;jj<k;jj++){ cout<<mMm[jj][1]<<">"; if(mMm[jj][1]==mMm[j][0] && mMm[jj][2]==0 && Lt->buscarN(mMm[jj][0])){ j=jj; } 
           if(mMm[j][0]==0){ TB=false; }}
          cout<<"\nciclo2\n\n\n";
          system("pause");
          
           MMT2[jk2]=mMm[j][0];
   jk2++; 
   }
   */
   for(j=0;j<jk;j++){ 
      for(jj=0;jj<jk2;jj++){ 
          if(MMT2[jj]==MMT[j]){ DR=true; Rr=MMT2[jj]; }                  
      }
   }

   cout<<endl;
   for(i=0;i<jk2;i++){  cout<<char(MMT2[i]+65)<<"\n"; }
   system("pause>NULL");
   /*
   while(!DR){
              cout<<"\nciclo2\n";
           for(jj=0;jj<k;jj++){ if(mMm[jj][1]==mMm[j][0] && mMm[jj][2]==0){ cout<<char(mMm[jj][1]+65); j=jj; } }
           for(i=0;i<jk;i++){ if(MMT[i]==mMm[j][0] ){ DR=true; Rr=MMT[i]; cout<<"ññ"<<char(MMT[i]+65); } }
           system("pause>null");
   }*/
   cout<<"True "<<DR<<"pues mira: "<<Rr;
   if(DR){ return Rr; }
}






bool Revisar(){
    int An=0, aux;
    
    bool DD;
    DD=false;
    cout<<"Revisar: "<<char(mMm[kk2][1]+65)<<">"<<mMm[kk2][2]<<endl;
    //cout<<"Valor de a. "<<a<<endl;
    for(i=0;i<k;i++){
            //cout<<mMm[kk2][2]<<":  "<<mMm[i][2]<<endl;
            //cout<<mMm[i][2]<<" < "<<mMm[kk2][2]<<endl;
             if(mMm[i][2] < mMm[kk2][2] &&  mMm[i][2]!=0){ aux=i; DD=true; break; }
    }
    
    if(DD){ kk2=aux; cout<<endl<<"Simon si hay yun numero menor en: "<<char(mMm[aux][1]+65)<<"  = "<<mMm[aux][2]<<endl;}
    //cout<<DD;
    return DD;
}



int RepoC(int ii, int ff,int cY)
{//reposiciona nuestras pila y lista para seguir trabajando pos el camino mas eficente
   //cout<<"entra\tii="<<ii<<"\tff: "<<ff<<endl;
   //system("pause>Null");
  /*   if(ii!=ff){
       for(i=0;i<k;i++){ if(mMm[i][1]==mMm[ff][0]){ ff=i; } }
       RepoRecursivo(ii,ff);
     }
     pila->push(ff); Lt->pop(ff+1);
     */
     //cout<<"\nEntro a esta revoltura de codigo y se equivoca, o en algun putno\n";
    int MMT[1000],j=ff,jj,jk=1;
   //cout<<"\n>>>>"<<mMm[nn1][0]<<"   "<<mMm[ff][0]<<endl;
   MMT[0]=mMm[j][1]; 
   while(mMm[j][0]!=ii){
           for(jj=0;jj<k;jj++){ if(mMm[jj][1]==mMm[j][0]){ j=jj; } }
          
           MMT[jk]=mMm[j][0];
           jk++; }
   
   for(i=0;i<jk;i++){ // cout<<char(MMT[i]+65)<<"\n"; 
              pila->push(MMT[i]); Lt->pop(MMT[i]+1); 
              cY++;      
              //cout<<"neeeeeeeeeeeeee"; 
   }
     //system("pause>Null");
  return j;
}






int main(int argc, char *argv[])
{
   

         
    for(i=1;i<=TTm+1;i++){    Lt->push(i,10); }
    cout<<" >>Pueblos Disponibles: "; Lt->print();
    Lt->pop(InC+1);
    Aestre(InC,FN);
    //cout<<endl;
    for(i=0;i<k;i++){
     cout<<char(mMm[i][0]+65)<<":: "<<char(mMm[i][1]+65)<<">>"<<mMm[i][2]<<endl; 
    }
    cout<<"\n >>Pueblos sin visitar: "; Lt->print();
	cout<<"\n\n\t\t\t  By Bernardo Quintino\n\t'Codificando para un mundo mas PEREZOSO'";
    system("PAUSE>NULL");system("PAUSE>NULL");system("PAUSE>NULL");
    return EXIT_SUCCESS;
}
