
 /* 
 EJEMPLO
 9 12 
 1 2 4 
 1 8 9 
 2 3 9 
 2 8 11 
 3 4 7 
 3 9 2 
 3 6 4 
 4 5 10 
 4 6 15 
 5 6 11 
 6 7 2 
 7 8 3 
 */ 
 
 #include <stdio.h> 
 #include <algorithm> 
 #include <cstring> 
 
 
 #define MAX 1005  //maximo numero de vertices 
 
 
 ///U
 int padre[ MAX ]; 
 
 
 //Metodo de inicializacion 
 void MakeSet( int n ){ 
     for( int i = 1 ; i <= n ; ++i ) padre[ i ] = i; 
 } 
 
 
 //Metodo para encontrar la raiz del vertice actual X 
 int Find( int x ){ 
     return ( x == padre[ x ] ) ? x : padre[ x ] = Find( padre[ x ] ); 
 } 
 
 
 
 void Union( int x , int y ){ 
     padre[ Find( x ) ] = Find( y ); 
 } 
 
 
 //Metodo que me determina 
 bool sameComponent( int x , int y ){ 
     if( Find( x ) == Find( y ) ) return true; 
     return false; 
 } 
 ///FIN U
 
 
 int V , E;      //numero de vertices y aristas 
 //Estructura arista
 struct Edge{ 
     int nodos;     //Vertice origen 
     int vertices;    //Vertice destino 
     int peso;       //Peso entre el vertice
     Edge(){} 
     
     
     
     bool operator<( const Edge &e ) const { 
         return peso < e.peso; 
     } 
 }arista[ MAX ];      //Arreglo de aristas para el uso en kruskal
 Edge MST[ MAX ];     //Arreglo de aristas del MST encontrado 
 
 
 void Kruskal(){ 
     int nodos , destino , peso; 
     int total = 0;          //Peso total del MST 
     int numAristas = 0;     //Numero de Aristas del MST 
 
 
     MakeSet( V );           //Inicializamos cada componente 
     std::sort( arista , arista + E );    //Ordenamos las aristas por su comparador 
 
 
     for( int i = 0 ; i < E ; ++i ){     //Recorremos las aristas ya ordenadas por peso 
         nodos = arista[ i ].nodos;    //Vertice origen de la arista actual 
         destino = arista[ i ].vertices;  //Vertice destino de la arista actual 
         peso = arista[ i ].peso;        //Peso de la arista actual 
 
 
         //Verificamos si estan o no en la misma componente conexa 
         if( !sameComponent( nodos , destino ) ){  //Evito ciclos 
             total += peso;              //Incremento el peso total del MST 
             MST[ numAristas++ ] = arista[ i ];  //Agrego al MST la arista actual 
             Union( nodos , destino );  //Union de ambas componentes en una sola 
         } 
     } 
 
 
    //  
     if( V - 1 != numAristas ){ 
         puts("No existe MST valido para el grafo ingresado, el grafo debe ser ingresado correctamente."); 
         return; 
     } 
     puts( "-----El Grafo contiene las siguientes aristas-----"); 
     for( int i = 0 ; i < numAristas ; ++i ) 
         printf("( %d , %d ) : %d\n" , MST[ i ].nodos , MST[ i ].vertices , MST[ i ].peso ); //( vertice u , vertice v ) : peso 
 
 
     printf( "El costo minimo de todas las aristas del es : %d\n" , total ); 
 } 
 
 
 int main(){ 
     int mst; 
 	 printf( "Ingresa los datos ---Nodos  ---Vertices  ---Peso: %d\n"  );
	   
		
     scanf("%d %d" , &V , &E ); 
 
 	  
     //Realizamos el ingreso del grafo, almacenando las aristas en un arreglo con los datos respectivos 
     for( int i = 0 ; i < E ; ++i ) 
         scanf("%d %d %d" , &arista[ i ].nodos , &arista[ i ].vertices , &arista[ i ].peso ); 
 
 
     Kruskal(); 
 
 
     return 0; 
 } 

