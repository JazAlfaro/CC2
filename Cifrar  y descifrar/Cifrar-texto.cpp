#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int modulo(int a,int m){
	
	int q=a/m;
	
	/*cout<<"Q "<<q<<endl;
	cout<<"A: "<<a<<endl;
	cout<<"M: "<<m<<endl;
	cout<<"Q*M: "<<q*m<<endl;*/
	int r = a-(q*m);
	//cout<<"R1: "<<r<<endl;
	if(r<0)
		r+=m;
	//cout<<"R: "<<r<<endl;
	return r;
	
	
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





void cifrar(int private_key){
	ifstream archivo;
	string frase;
	archivo.open ("textito-original.txt");
	ofstream escribir ("example.txt", ios_base::ate);
	vector<int> ascii;
	while(!archivo.eof()){
		getline(archivo,frase);
		for(int i=0;i<frase.size();i++){
			ascii.push_back(frase[i]);
			//cout<<ascii[i]<<" ";
			//cout<<frase[i];
			if(i==frase.size()-1)
				cout<<endl;
		}
	}
	for(int i=0;i<ascii.size();i++){
		string datos;
		int c = ascii[i]* private_key;
		int e = modulo(c,256);
		//pls.push_back(e);
		//datos+=pls[i];
		datos+=e;
		cout<<datos<<endl;
		escribir<<datos;
		if(i==frase.size()-1){
			cout<<endl;
			escribir<<" "<<endl;
		}
		
		
		
	archivo.close();
}	
}

void descifrar(int public_key){
	ifstream archivo;
	string frase;
	
	archivo.open ("example.txt");
	ofstream escribir ("listo.txt", ios_base::ate);
	vector<int> nuevo;
	while(!archivo.eof()){
		getline(archivo,frase);
		for(int i=0;i<frase.size();i++){
			nuevo.push_back(frase[i]);
			cout<<nuevo[i]<<" ";
			if(i==frase.size()-1)
				cout<<endl;
		}
	}
	
	for(int i=0;i<nuevo.size();i++){
		int d = nuevo[i] * public_key;
		int x = modulo(d,256);
		string nuevito;
		nuevito+=x;
		cout<<nuevito;
		escribir<<nuevito;
		int o = frase.size();
		if(x==32)
			o++;
		if(i==o){
			
			escribir<<" "<<endl;
			cout<<endl;
		}
	}
	
}




int main(int argc, char *argv[]) {
	cifrar(29);
	descifrar(53);
	return 0;
}

