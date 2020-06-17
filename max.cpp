#include <iostream>
#include <cstdlib>



using namespace std;


float maximo(int *A, int n){
	int max = A[0];
	float contador=0;
	for (int i=2;i<=n;i++){
		if (A[i] > max){
			max=A[i];
			contador++; //aumentara cada vez que se ejecute la línea 4
		}
	}
	return contador;
}

int main(){
	int tam = 524288;
	// x sera el tiempo de veces que se repita la linea 4, 
	float x=0;
	//p sera la variable promedio y se dividira entre 200 para obtener el promedio total
	float p = 0;
	
// El siguiente "for" permite obtener el promedio de todas los arreglos desde 256 hasta 2^20, sin embargo 
//mi computador no cuenta con la potencia
//	for(int i=0;i<20;i++){
	
		for (int j=0;j<200;j++){
			int *a = new int[tam];
			for (int k=0;k<tam;k++)
				a[k]=rand();
			x=maximo(a,tam);
			cout<< "x: "<<x<<" ";
			p=p+x;
			delete[] a;
		}
		cout<<"p total es: "<<p<<endl;
	p=p/200;
	cout<<"Promedio: "<< p <<endl;
	p=0;
	tam= tam *2;
//	}
	

	cout << "Alumno: Fabricio Jose Barrionuevo Paredes "<<endl;
	cout << "CUI: 20131661"<<endl;
	return 0;
}

