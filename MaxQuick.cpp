#include <iostream>
using namespace std;


void swapp(int &a, int &b){
    int temp = a;
    a=b;
    b=temp;
}

int particion(int *A, int p, int r,float & c){
    int x=A[r];
    int i=p-1;
    for(int j=p;j<r;j++){
        if (A[j]<=x){
            i=i+1;
            swapp(A[i],A[j]);
            //el contador de las veces promedio que se hara...
            //... una comparacion e intercambio nuevos
            c=c +1;
        }
    }
    swapp(A[i+1],A[r]);
    return i+1;
}
void quickk(int *A, int p, int r, float & c){
    int q;
    if (p<r){
        q=particion(A,p,r,c);
        quickk(A,p,q-1,c);
        quickk(A,q+1,r,c);
    }
}

int main(){
	int tam = 256
	// x sera el tiempo de veces que se repita la linea 4,
	float x=0;
	//p sera la variable promedio y se dividira entre 200 para obtener el promedio total
	float p = 0;
	for (int j=0;j<200;j++){
		int *a = new int[tam];
		for (int k=0;k<tam;k++)
			a[k]=rand();
		quickk(a,0,tam-1,x);
		cout<< "x: "<<x<<" ";
		delete[] a;
	}
	p=x;
    cout<<"p total es: "<<p<<endl;
	p=p/200;
	cout<<"Promedio: "<< p <<endl;

	cout << "Alumno: Fabricio Jose Barrionuevo Paredes "<<endl;
	cout << "CUI: 20131661"<<endl;
	return 0;

}
