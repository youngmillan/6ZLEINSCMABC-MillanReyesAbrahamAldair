#include <iostream>
using namespace std;
 
 
/*        Estructura de los nodos de la cola      */
struct nodo
{
    string nro;
    struct nodo *siguiente;
};
 
 
/*        Estructura de la cola      */
struct cola
{
    nodo *delante;
    nodo *atras  ;
};
 
 
/*       Encolar elemento      */
void encolar( struct cola &q, string valor )
{
     struct nodo *aux = new(struct nodo);
     
     aux->nro = valor;
     aux->siguiente = NULL;
     
     if( q.delante == NULL)
         q.delante = aux;   // encola el primero elemento
     else
         (q.atras)->siguiente = aux;
         
     q.atras = aux;        // puntero que siempre apunta al ultimo elemento
     
}
 
/*     Desencolar elemento    */
int desencolar( struct cola &q )
{
     string num ;
     struct nodo *aux ;
     
     aux = q.delante;      // aux apunta al inicio de la cola
     num = aux->nro;
     q.delante = (q.delante)->siguiente;
     delete(aux);          // libera memoria a donde apuntaba aux
     
    
}
 
/*     Mostrar Cola      */
void muestraCola( struct cola q )
{
     struct nodo *aux;
     
     aux = q.delante;
         
     while( aux != NULL )
     {
            cout<<"   "<< aux->nro ;
            aux = aux->siguiente;
     }    
}
 
/*   Eliminar todos los elementos de la Cola      */
void vaciaCola( struct cola &q)
{
     struct nodo *aux;
     
     while( q.delante != NULL)
     {
            aux = q.delante;
            q.delante = aux->siguiente;
            delete(aux);
     }
     q.delante = NULL;
     q.atras   = NULL;
     
}
 
/*    Menu de opciones    */
void menu()
{
    cout<<"\n\tPROGRAMA DE COLA DE COLORES\n\n";
    cout<<" 1. ENCOLAR                               "<<endl;
    cout<<" 2. DESENCOLAR                            "<<endl;
    cout<<" 3. MOSTRAR COLA                          "<<endl;
    cout<<" 4. VACIAR COLA                           "<<endl;
    cout<<" 5. SALIR                                 "<<endl;
 
    cout<<"\n INGRESE OPCION: ";
}
 
/*   Funcion Principal     */
int main()
{
    struct cola q;
   
    q.delante = NULL;
    q.atras   = NULL;
   
   
    string dato;  // numero a encolar
    int op;    // opcion del menu
    int x ;    // numero que devuelve la funcon pop
   
    system("color 0f");
 
    do
    {
        menu();  cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n COLOR A ENCOLAR: "; cin>> dato;
                 encolar( q, dato );
                 cout<<"\n\n\t\tCOLOR " << dato << " encolado...\n\n";
            break;
 
 
            case 2:
 
                 x = desencolar( q );
                 cout<<"\n\n\t\tCOLOR "<< x <<" desencolado...\n\n";
            break;
                 
 
            case 3:
 
                 cout << "\n\n MOSTRANDO COLA\n\n";
                 if(q.delante!=NULL) muestraCola( q );
                 else   cout<<"\n\n\tCola vacia...!\n\n"<<endl;
            break;
 
 
            case 4:
 
                 vaciaCola( q );
                 cout<<"\n\n\t\tHecho...\n\n";
            break;
           
         }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=5);
   
   
    return 0;
}
