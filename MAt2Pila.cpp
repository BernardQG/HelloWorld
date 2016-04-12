#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
int main()
{
    int i,j,x,n,n2,s,ct;  bool Contn;
    char Cd[40], Opr2s[]={".+/*^"};
    stack <char> Pil1;//Pila para Parentesis, corchetes y llaves
    stack <char> Pil2;//Pila para Operadores
    stack <char> Pil3;//Pila para Numeros negativos

    do{  i=x=n=n2=ct=0;  Contn=true;
    //Vaciado de pilas para retomar en el menu
    while(!Pil1.empty()){ Pil1.pop(); }
    while(!Pil2.empty()){ Pil2.pop(); }
    while(!Pil3.empty()){ Pil3.pop(); }
      cout<<"\n Ecuacion a evaluar:  "; cin>>Cd;
       //cuenta la cadena de operadores
    while(Cd[x]!='\0') { x++; }

    do{
             //Comprovando si es una contenedor
             if((Cd[i]=='(') || (Cd[i]=='{') || (Cd[i]=='['))
                     { Pil1.push(Cd[i]); }
             else { if((Cd[i]==')') || (Cd[i]=='}') || (Cd[i]==']'))
                     { if(Pil1.empty()){ Contn=false; }else { Pil1.pop(); }} }
             if(Cd[i]=='-'){ Pil3.push(Cd[i]);  if(n2>0){n2--;}}//para sistemas negativos
             if(Cd[i]=='.'){ n++; }//cuado existe punto decimal
             if(isdigit(Cd[i])){
                  //Validacion de numeros mayores a 10
                  if(isdigit(Cd[i-1]) && !Pil2.empty()){
                                     Pil2.pop();
                                     Pil2.push(Cd[i]);
                                     Pil3.push(Cd[i]);
                                     Pil3.pop();
                   }
                   //numero menores a 10
                   else {  Pil2.push(Cd[i]); if(!Pil3.empty()){ Pil3.pop();}  n2++; ct++;}
             }
             else {
                    //Comprovar si el valor de la cadena es un operador
                  for(j=0;j<strlen(Opr2s);j++)  {
                         if(Cd[i]==Opr2s[j] )  { n2--; ct--;
                                if(Cd[i-1]=='-') { Pil3.push(Cd[i]);   }
                                //no podra sacar valores de una pila vacia
                                if(Pil2.empty()){ Contn=false; }
                               else {    Pil2.pop();    }

                               if(n==1 && n!=0 && Cd[i]!='.') { n=0; }
                         }
                   }
             }
        i++;
    } while(i<x && Contn);   cout<<"\t\t\t\t\t\t\t\t";
       //puesto a que si no se ingresa valores numericos no sea erronea la interpretacion de la pila de numeros
      if(ct==0){ Pil2.push(2); n2=1;}
      //verificando si es correcta o no
    if(Pil1.empty()&& !Pil2.empty() && Pil3.empty() && Contn && n<=1 && n2==1){
         cout<<"<BIEN>";    }
    else { cout<<"<ERROR>";}
    //MEnu para repetir el proceso
    cout<<"\n\n Desea retomar? [1 - S1, 2 - No]"<<endl<<"  R: "; cin>>s;
    system("cls");
  }while(s!=2);

    system("pause>NULL");//Detiene el programa para que no se cierre
}
