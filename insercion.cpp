#include <iostream>
using namespace std;

void print(int *inicio, int *fin){
	for(inicio;inicio<fin;inicio++){
		cout<<*inicio<<"  ";
	}
}

/*
void insercion(int *inicio, int *fin, int tam){
	int *begin = inicio;
	int *temp;
	int valor;
	for(begin;begin<fin;begin++){
		valor = *begin;
		temp = begin;
		
		while(temp > inicio && *(temp-1)>valor){
			*temp = *(temp-1);
			temp--;
		}
		*temp = valor;
		
		for(int i=0;i<tam;i++){
			cout<<inicio[i]<<"  ";
		}
		cout<<endl;
	
	}
}
*/

void insercion(int *inicio, int *fin){
	int *begin = inicio+1; //evitar una iteracion
	//cout<<"BEGIN: "<<*begin<<endl;
	int *temp;
	int valor;
	for(begin;begin<fin;begin++){
		//cout<<"BEGIN for: "<<*begin<< "  Address: "<<begin<<endl;
		valor = *begin;
		temp = begin;
		
		while(temp > inicio && *(temp-1)>valor){ //inicio va cambiando primero es 47,luego 9,3,2
			*temp = *(temp-1);
			temp--;
			//cout<<" ----> TEMP while: "<<*temp<< "  Address: "<<temp<<endl;
		}
		*temp = valor;
		//cout<<"BEGIN saliendo: "<<*begin <<"  Address: "<<begin<<endl;
		//cout<<" --> TEMP saliendo: "<<*temp<< "  Address: "<<temp<<endl;
		
	}
}

int main(int argc, char *argv[]) {
	int arreglo[] = {47,9,32,3,7,2,15,10};
	int tam=sizeof(arreglo)/sizeof(arreglo[0]);
	print(arreglo,arreglo+tam);
	cout<<endl;
	
	insercion(arreglo,arreglo+tam);
	
	cout<<endl;
	print(arreglo,arreglo+tam);
	return 0;
}

