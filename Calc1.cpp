#include <iostream>
#include <vector>

using namespace std;

int modulo(int a,int m){
	
	int q=a/m;

	cout<<"Q "<<q<<endl;
	cout<<"A: "<<a<<endl;
	cout<<"M: "<<m<<endl;
	cout<<"Q*M: "<<q*m<<endl;
	int r = a-(q*m);
	cout<<"R1: "<<r<<endl;
	if(r<0)
		r+=m;
	cout<<"R: "<<r<<endl;
	return r;

	
}

int suma(int a,int b, int mod){
	int c = a+b;
	return modulo(c,mod);
}
int resta(int a, int b,int mod){
	int c = a-b;
	return modulo(c,mod);
}

int multiplicacion(int a, int b,int mod){
	int c = a*b;
	return modulo(c,mod);
}

void inverso(int a, int mod){
	int mod1 = mod;
	vector<int> ps;
	ps.push_back(0);
	ps.push_back(1);
	vector<int> qs;
	vector<int> rs;
	int r = 1;
	while(r!=0){
		int q = a/mod;
		r = modulo(a,mod);
		
		a = mod;
		mod = r;
		if(q>0){
		qs.push_back(q);
		rs.push_back(r);
		}
	}
	for(int i=0;i<qs.size();i++){
		cout<<qs[i]<< "   "<< rs[i]<<endl;
	}
	if(rs[rs.size()-2]==1){
		cout<<"Si tiene inverso"<<endl;
		cout<<"Q size"<<qs.size();
		for(int i=0;i<qs.size()-1;i++){
			cout<<"------"<<endl;
			cout<< ps[i]<<endl;
			cout<< qs[i]<<endl;
			cout<<ps[i+1]<<endl;
			int p = ps[i]-qs[i]*ps[i+1];
			cout<<"P: "<<p<<endl;
			int k = modulo(p,mod1);
			ps.push_back(k);
			cout<<k<<endl;
		}
		cout<<"El inverso es: " <<ps[ps.size()-1]<<endl;
		//return ps[ps.size()-1];
	}

	else
		cout<<"No tiene inverso";
	  // return 0;
	/*for(int i=0;i<ps.size();i++){
		cout<<"-_-_-_-_-_"<<endl;
		cout<<ps[i]<<endl;
	}
	*/
}

int main()
{
	char a;
	int b;
	int c;
	int mod;
	cout << "Ingrese un operador: " <<endl;
	cin >> a;
	if(a=='i'){
		cout << "Ingrese el modulo a trabajar: " << endl;
		cin >> mod;
		cout << "Ingrese el numero: "<<endl;
		cin >> a;
		
		inverso(a,mod);
	}/*
	else{
	
	cout << "Ingrese el modulo a trabajar: " << endl;
	cin >> mod;
	cout << "Ingrese el primer numero a operar: "<<endl;
	cin >> b;
	cout << "Ingrese el segundo numero a operar: "<<endl;
	cin >> c;
	
	if(a=='+')
	cout << "La respuesta es: " << suma(b,c,mod);
	if(a=='-')
	cout << "La respuesta es: " << resta(b,c,mod);
	if(a=='*')
	cout << "La respuesta es: " <<multiplicacion(b,c,mod);
	
	}
	*/
	//cout<<modulo(-291,74)<<endl;*/
	//
	//inverso(29,256);
	
	
	
	
	
	return 0;
}
