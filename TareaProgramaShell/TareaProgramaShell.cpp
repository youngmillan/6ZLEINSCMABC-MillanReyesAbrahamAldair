#include<iostream>
#include<conio.h>

using namespace std;
int Arreglo[96];
void LeerA(int Numero);
void EscribeA(int Numero);
void Shell(int Numero);

int main(){
    int Num;
     cout << endl;
    cout<<"Ingresa la cantidad de numeros que se ordenarán : ";
     cout << endl;
    cin>>Num;
    LeerA(Num);
    Shell(Num);
    cout<<endl;
    EscribeA(Num);
    return 0;
}

void LeerA(int Numero){
    int i;
    for(i=1;i<=Numero;i++)
    {
        cout<<"Valor ["<<i<<"]=";
        cin>>Arreglo[i];
    }
}

void EscribeA
(int Numero){
    int i;
     cout << endl;
    cout<<"Elementos ordenados por metodo Shell "<<endl;
     cout << endl;
    for(i=1;i<=Numero;i++)
    {
        
        cout<<"\t"<<Arreglo[i];
    }
}

void Shell(int Numero){
    int i,j,k,incremento,aux;
    
    incremento=Numero/2;
    
    while(incremento>0){
        for(i=incremento+1;i<=Numero;i++){
            j=i-incremento;
            while(j>0){
                if(Arreglo[j]>=Arreglo[j+incremento]){
                    aux = Arreglo[j];
                    Arreglo[j] = Arreglo[j+incremento];
                    Arreglo[j+incremento] = aux;
                }
                else{
                        j=0;
                    }
                j=j-incremento;
            }
        }
        incremento=incremento/2;
    }
}
