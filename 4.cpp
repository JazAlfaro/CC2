#include <iostream>
using namespace std;
class operacion
{
public:	
	int operator()(int a, int b){ 
		return a+b;
	}
};

template<typename T>
class operador{
private:
	T op;
public:

	void operator()(int *a)
	{
		int temp = *(a+1);
		*(a+1) = op(*a, *(a+1));
		*a = temp;
	}
};

int main(int argc, char *argv[]) {
	int *a = new int[2];
	*a = 0;
	*(a+1) = 1;
	//espacio por rellenar
	operador<operacion> nombre;
	//fin espacio
	for (int i = 0; i <=10; i++){
		//espacio por rellenar
		//bueno pos aca no iba nada xdd
		//fin espacio
		cout << *a << endl;
		//espacio por rellenar
		nombre(a);
		//fin espacio
	}
	return 0;
}
