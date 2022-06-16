/*codifique un programa mediante el cual un 
usuario pueda introducir un n�mero y a partir de dicho numero el programa calcule y muestre todos 
los n�meros primos que se encuentran  entre el 0 y dicho n�mero.
*/

#include <iostream>
using namespace std;
int main(void){
	int N;
	
	cout<<"Ingrese un n�mero entero positivo: "<<endl;
	cin>>N;
	
	for(int i=2;i<N;i++){
		
		int creciente = 2;
		bool esPrimo = true;
		
		while(esPrimo && creciente<i){
			
		    if (i & creciente == 0){ //Evaluando si la divisi�n es exacta
		        esPrimo= false;
			}
			else{
				creciente++;
			}
		}
		
		if(esPrimo){
			cout<<i<< "Es un n�mero primo."<<endl;
		}
	}
}
