#include <iostream>


using namespace std;

class Nodo {
public:
    string cadena;
    int vecesRepetidas;// se usara solo para la lista de palabras repetidas

    Nodo *izquierda, *derecha;

    Nodo(string cad): cadena(cad), izquierda(NULL), derecha(NULL){}
    Nodo(string cd, int veces): cadena(cd), vecesRepetidas(veces), izquierda(NULL), derecha(NULL){}
};

class Arbol {
public:
    Nodo *raiz;
    int cont;

    void insertar(Nodo *nuevo);
    void mostrarPreorden(Nodo *r);
    void repetidos(Nodo *r);

    Arbol(): raiz(NULL), cont(0){}
};
void Arbol::insertar(Nodo *nuevo){
Nodo *n = new Nodo(nuevo->cadena);

string temp;

if(raiz == NULL){
    raiz = nuevo;
}else{
    Nodo *aux = raiz;
    Nodo *padre;
    while(true){
        padre = aux;

        if( n->cadena < aux->cadena ){
            aux = aux->izquierda;
            if(aux == NULL){
                padre->izquierda = n;
                break;// finaliza el metodo
            }
        }else{

            aux = aux->derecha;

            if(aux == NULL){
                padre->derecha = n;
                break; // finaliza el metodo
            }
        }
    }
}
}
void Arbol::mostrarPreorden(Nodo *r){
if( r != NULL ){
    cout<<r->cadena<<endl;
    mostrarPreorden(r->izquierda);
    mostrarPreorden(r->derecha);
}
}

void Arbol::repetidos(Nodo *r){

if( r != NULL ){
    if( r->cadena == raiz->cadena ){
        cont++;
    }

    repetidos(r->izquierda);
    repetidos(r->derecha);
}

cout<<"la raiz se repite "<<cont<<endl;
}

int main()
{
Nodo *aux;
Arbol arbol;
string palabra;

char resp[3];
do{
    int opc;
    cout<<"------------- MENU --------------"<<endl;
    cout<<"     1. Anadir un nodo "<<endl;
    cout<<"     2. Mostrar nodos"<<endl;
    cout<<"     3. Mostrar repetidos de la raiz"<<endl;
    cin>>opc;

    switch(opc){
        case 1:
            cout<<"\nIngrese algo para agregar"<<endl;
            cin>>palabra;

            aux = new Nodo(palabra);
            arbol.insertar(aux);

            break;
        case 2:
            arbol.mostrarPreorden(arbol.raiz);
            break;
        case 3:
            arbol.repetidos(arbol.raiz);
            break;

    }

    cout<<"Desea volver a ingresar otro? (s/n)"<<endl;
    cin>>resp;
    system("cls");
}while( resp[0] == 'S' || resp[0] == 's' );

return 0;
}
