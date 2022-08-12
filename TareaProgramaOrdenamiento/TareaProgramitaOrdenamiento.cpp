#include<iostream>
#include<string.h>
#include<conio.h>
#define cls system("CLS");

FILE *doc;
int guardar();
int cargar();

using namespace std;

#define MAX 50
struct fecha
 {
  char dia[3];
  char mes[3];
  char annio[5];

 };
struct trabajador
 {
  char codigo[9];
  char nombre[MAX];
  char apellido[MAX];
  struct fecha fecnac;

 };

 void leerpersonal(int,struct trabajador[]) ;
 void ordenaxfecha(int,struct trabajador[]) ;
 void listado(int,struct trabajador[]) ;
 int bBinariafecha(int,struct trabajador[],struct fecha) ;
 

int opcion;  
     int n,pos ;
				struct fecha f;                                                                               
				struct trabajador x[MAX] ;
 int main()
 {
    do
    { 
        // Menu principal
        cout << endl;
        cout << "ELIJA UNA OPCION:" << endl;
        cout << endl;
        cout << "1.- Ingresar datos de un nuevo empleado" << endl;
        cout << "2.- Buscar por fecha" << endl;
        cout << "3.- Mostrar listado" << endl;
        cout << "4.- Guardar lista ordenada en un archivo" << endl;
        cout << "5.- Salir" << endl;
 
        cin >> opcion;
 
        // Hacemos una cosa u otra seg?n la opci?n escogida
       
		switch(opcion)
        {
            case 1: // A?adir un dato nuevo
 
 				cout << "BIENVENIDO, DIGITA ( 1 ) Y METE LOS DATOS " << endl;
  				cout << endl;
 				cin>>n ;
 				leerpersonal(n,x) ;
 				ordenaxfecha(n,x) ;
 				 				
                break;
 
            case 2: // bUSCAR por fecha
                cout<<"ingrese fecha a buscar"<<endl ;
 				cout << endl;
 				cout<<"dia:" ;cin>>f.dia ;
 				cout << endl;
 				cout<<"mes:" ;cin>>f.mes ;
  				cout << endl;
 				cout<<"annio:" ;cin>>f.annio ;
 				pos=bBinariafecha(n,x,f) ;
 				if(pos==-1)cout<<"no se encuentra";
 				
 				else cout<<"lo encontre en la posicion"<<pos;
                break;
 
            case 3: // Mostrar seg?n el tama?o
            cout << endl;
                cout << "Mostrando la lista ...... ";
                cout << endl;
                listado(n,x) ;
                break;
 
            case 4: // Ver todos los datos (pocos) de un fichero
                cout << "Guardando los datos";
                
				 cls
				 
                doc = fopen("EMPLEADOS.txt","a+");
                 if(doc == NULL)
 				{
 				printf("\n ERROR\n ");	
  				printf("SE CERRARA EL PROGRAMA---INGRESA DATOS DEL ALUMNO ");
 				} 
 				{
				 for(int i=0;i<n;i++)
 				fprintf(doc,"  CODIGO= ");
 				fprintf(doc,x->codigo);
 				fprintf(doc,"  APELLIDO= ");
 				fprintf(doc,x->apellido);
 				fprintf(doc,"  NOMBRE= ");
 				fprintf(doc,x->nombre);
 				fprintf(doc,"  DIA DE NACIMIENTO= ");
 				fprintf(doc,x->fecnac.dia);
 				fprintf(doc,"  MES DE NACIMIENTO= ");
 				fprintf(doc,x->fecnac.mes);
 				fprintf(doc,"  ANNIO DE NACIMIENTO= ");
 				fprintf(doc,x->fecnac.annio);
 			
 				}
 				fclose(doc);
 				cls
 				cout<<"\nARCHIVO GUARDADO CON EXITO"<<endl;
                
                break;
 
            case 5: // Salir: avisamos de que salimos
            cout << endl;
                cout << "Fin del programa" << endl;
                break;
 
            default: // Otra opcion: no v?lida
                cout << "Opcion desconocida!" << endl;
                break;
        }
    }while (opcion != 5);  // Si la opcion es 5, terminamos
}
    
 

 


 void leerpersonal(int n,struct trabajador x[])
 {for(int i=0;i<n;i++)
 {cout<<"codigo:";cin>>x[i].codigo;
 	cout << endl;
 cout<<"apellido:";cin>>x[i].apellido;
 	cout << endl;
 cout<<"nombre:";cin>>x[i].nombre;
 	cout << endl;
 cout<<"dia nacimiento:";cin>>x[i].fecnac.dia;
 	cout << endl;
 cout<<"mes nacimiento:";cin>>x[i].fecnac.mes;
 	cout << endl;
 cout<<"annio nacimiento:";cin>>x[i].fecnac.annio;
 cout<<endl;
 }
}
 void ordenaxfecha(int n,struct trabajador x[])
 {struct trabajador temp;
 char f1[9],f2[9];
 for(int i=1;i<n;i++)
 for(int j=n-1;j>=1;j--)
 {strcpy(f1,"");strcpy(f2,"");
 strcat(f1,x[j-1].fecnac.annio);
 strcat(f1,x[j-1].fecnac.mes);
 strcat(f1,x[j-1].fecnac.dia);
 strcat(f2,x[j].fecnac.annio);
 strcat(f2,x[j].fecnac.mes);
 strcat(f2,x[j].fecnac.dia);
if(strcmp(f1,f2)>0)
{temp=x[j-1];
x[j-1]=x[j];
x[j]=temp;

}
}
}
void listado(int n,struct trabajador x[])
{cout<<endl<<"Listado de personal.-"<<endl;
for(int i=0;i<n;i++)
cout<<x[i].codigo<<"\t"<<x[i].apellido<<"\t"
<<x[i].nombre<<"\t"<<x[i].fecnac.dia
<<"/"<<x[i].fecnac.mes<<"/"<<x[i].fecnac.annio
<<endl;
cout<<endl;
}
int bBinariafecha(int n,struct trabajador x[],struct fecha f)
{char f1[9],f2[9];
int izq=0,der=n-1,mitad;
while(izq<=der)
{mitad=(izq+der)/2;
strcpy(f1,"");strcpy(f2,"");
strcat(f1,f.annio);
strcat(f1,f.mes);
strcat(f1,f.dia);
strcat(f2,x[mitad].fecnac.annio);
strcat(f2,x[mitad].fecnac.mes);
strcat(f2,x[mitad].fecnac.dia);
if(strcmp(f1,f2)>0)izq=mitad+1;
else if(strcmp(f1,f2)<0)der=mitad-1;
else return mitad;
}
return -1;
}

