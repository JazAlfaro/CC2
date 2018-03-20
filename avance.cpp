#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

const int maximo = 1000;

void swap(int* p1,int* p2){
	int aux = *p1;
	*p1 = *p2;
	*p2 = aux;
}

void print(int* i,int tam){
	for(int j=0;j<tam;j++)
		cout<<*(i+j)<<" ";
}

template <class T>
T* crearArray(int size){
	srand(time(NULL));
	T* array = new T[size];
	T* a = array;
	for (int i = 0; i < size; i++,a++ ){
		*a = 1+ rand() % maximo;
	}
	print(array,size);
	return array;
}


//void burbuja(T*(*func)(T) ,int tamano){
void burbuja(int* p,int tamano){
	bool ordenado=false;
	for(int i=0;i<tamano;i++){
		for(int j=0;j<tamano-1-i;j++){
			if(*(p+j)>*(p+j+1)){
				swap(p+j,p+j+1);
				ordenado=true;
			}
		}
	}
	//imp(p,tamano);
}





int main()
{
	/*int i[]={9,8,7,10,17,1,3,2,10};
	int tam=sizeof(i)/sizeof(i[0]);
	burbuja(i,tam);*/
	crearArray<int>(5);

	
	return 0;
}
