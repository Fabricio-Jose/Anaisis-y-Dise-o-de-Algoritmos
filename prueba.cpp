#include <iostream>
#include <cstdlib>
#include <ctime>

int t0,t1,t2,t3;
using namespace std;

int compare(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}

void intercala(int *A,int p,int q,int r){
	int *B=new int[r+1];
	for(int i=p;i<=r;i++){
		B[i]=A[i];
	}
	for(int j=q+1;j<=r;j++){
		B[r+q+1-j]=A[j];
	}
	int i=p;
	int j=r;
	for(int k=p;k<=r;k++){
		if (B[i]<=B[j]){
			A[k]=B[i];
			i=i+1;}
		else{
			A[k]=B[j];
			j=j-1;
		}
	}
}
void Merge(int *A,int p, int r){
	if(p<r){
		int q=(p+r)/2;
		Merge(A,p,q);
		Merge(A,q+1,r);
		intercala(A,p,q,r);
	}
}

int main()
{
	int tam = 100000;
	for (int p=0;p<5;p++){
	
	int *a = new int[tam];
	int *b = new int[tam];

	for (int j=0;j<tam;j++){
		a[j]=rand();
		b[j]=a[j];

	}

	t0=clock();
	Merge(a,0,tam-1);
	t1=clock();
	float time1=t1-t0;
	
	t2=clock();
	qsort(b,tam,sizeof(int),compare);
	t3=clock();
	float time2=t3-t2;
	cout << endl << endl;

	//

	cout<<tam <<" Tiempo MergeSort: "<< time1 <<" tiempo Quick"<< time2 <<endl;
	delete[] a;
	delete[] b;
	tam=tam + 1000;

}

	cout << "Alumno: Fabricio Jose Barrionuevo Paredes "<<endl;
	cout << "CUI: 20131661"<<endl;
	return 0;
}

