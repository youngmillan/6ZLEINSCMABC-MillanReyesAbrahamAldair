/*Codifique un programa donde el usuario ingrese un n�mero
 y el programa verifique si es un numero par o un n�mero impar
*/

#include<iostream>
using namespace std;
int main(){
	int numero;
	
	cout<<"Digite un numero:  ";
	cin>>numero;
	
	if(numero%2==0){
		cout<<"El numero es par";
	}
	else{
		cout<<"El numero es impar";
	}
	
	return 0;
}
