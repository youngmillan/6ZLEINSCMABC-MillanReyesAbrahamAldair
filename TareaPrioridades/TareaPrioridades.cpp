#include<iostream>
#include<stdlib.h>

using namespace std;

struct nodo{
	string dato;
	int cuenta;
	int cantidad;
	struct nodo *siguiente;
};

struct cola{
	nodo *delante;
	nodo *atras;
};

struct nodo *crearNodo(string x, int pri, int depo){
	struct nodo *nuevoNodo = new(struct nodo);
	nuevoNodo->dato = x;
	nuevoNodo->cuenta = pri;
	nuevoNodo->cantidad= depo;
	return nuevoNodo;
}

void encolar(struct cola &q, string valor, int cuenta, int cantidad){
	struct nodo *aux = crearNodo(valor, cuenta, cantidad);
	aux->siguiente = NULL;
	
	if(q.delante == NULL){
		q.delante = aux;
	}else{
		(q.atras)-> siguiente = aux;
	}
	q.atras = aux;
}
void mostrarCola(struct cola q){
	nodo *aux = new nodo();
	aux = q.delante;
	
	if(aux!=NULL){
		cout<<"\n\tFila de Tarjetahabientes";
		cout<<"\n\tTipo de Cuenta... \n\t1)VIP\n\t2)Empresarial\n\t3)Normal\n\t4)Sin Cuenta";
		cout<<"\n\t|Tarjetabiente"<<"|Tipo de Cuenta"<<"|Deposito"<<endl;
		while(aux!=NULL){
			cout<<"\t|"<<aux->dato<<"           |"<<aux->cuenta<<"             | $"<<aux->cantidad<<endl;
			aux = aux->siguiente;
		}
	}else{
		cout<<"\n\tFila Vacia\n";
	}	
}

void ordenarPrioridad(struct cola &q){
	struct nodo *aux1, *aux2;
	int p_aux;
	string c_aux;
	
	aux1 = q.delante;
	
	while(aux1->siguiente != NULL){
		aux2 = aux1->siguiente;
		
		while(aux2 != NULL){
			
			if(aux1->cuenta > aux2->cuenta){
				p_aux = aux1->cuenta;
				c_aux = aux1->dato;
				
				aux1->cuenta = aux2->cuenta;
				aux1->dato = aux2->dato;
				
				aux2->cuenta = p_aux;
				aux2->dato = c_aux;
			}
			aux2 = aux2->siguiente;
		}
		aux1 = aux1->siguiente;
	}
}

void insertar(struct cola &q, string turno, int cuenta, int cantidad){
	encolar(q,turno,cuenta,cantidad);
	ordenarPrioridad(q);
}

void menu(){
	cout<<""<<endl;
	cout<<"Tarjetabientes"<<endl;
	cout<<""<<endl;
	cout<<"1.Asignar Turno"<<endl;  
	cout<<"2.Mostrar Tarjetabientes"<<endl;
	cout<<"3.Salir"<<endl;
	cout<<""<<endl;
	cout<<"Opcion: "<<endl;
}

int main(){
	struct cola q;
	q.delante = NULL;
	q.atras  = NULL;
	
	string turno; 
	int cuenta, deposito, cantidad; 
	char op; 
	int x; 
	
	do{
		menu();
		cin>>op;
		
		switch(op){
			case '1':
				cout<<"\nNombre: "<<endl;
				cin>>turno;
				cout<<endl;
				cout<<"Tipo de Cuenta... \n\t1)VIP\n\t2)Empresarial\n\t3)Normal\n\t4)Sin Cuenta\n\tCuenta: "<<endl;
				cin>>cuenta;
				cout<<"\n?Desea Realizar un Deposito?\n\t1)Si\n\t2)No\n\tOpcion: "<<endl;
				cin>>deposito;
				if(deposito>=2){
					cout<<"\nSin Deposito"<<endl;
				}else{
					cout<<"\nCantidad a Depositar: "<<endl;
					cin>>cantidad;
				}
				cout<<endl;
				
				insertar(q, turno, cuenta, cantidad);
				
				cout<<"\nTarjetabiente: "<<turno<<" en Fila"<<endl;
			break;
			
			case '2':
				mostrarCola(q);
			break;
			
			default:
				cout<<"\n\tOpcion no Valida"<<endl;
				system("pause");
				exit(0);
			break;
		}
		system("pause");
		system("cls");
	}while(op!='2');
	return 0;
}
