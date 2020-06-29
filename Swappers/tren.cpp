//tren.cpp
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

/*

g++ tren.cpp -o tren.out
./tren.out > entrada.txt
g++ swap.cpp -o swap.o
./swap.o<entrada.txt > salida.txt

*/

//FUNCION RELLENADO llena el arreglo A de numeros que estan dentro del rango L y que no se repitan 
//para asi simular los numeros de los vagones

void rellenado(int *A, int L){
    int x=rand()%L;
    int j=0;
    for (int i=0;i<L;i++){
        j=0;
        while(j<i){
            if(A[j]==x){
                    j=-1;
                    x=rand()%L;
            }
            j++;
        }
        
        A[i]=x;
        cout<<A[i]<<" ";
        x=rand()%L;
    }
    cout<<endl;
}

int main() {
    int N;
    int L;
    //Insertamos numero de casos en a Consola
    cin>>N;
    cout<<N<<endl;
    for(int i=0; i<N; i++) {
        cin>>L;
        cout<<L<<endl;
        int *A= new int[L];
        
        rellenado(A,L);
        
        delete[] A;
        }
        return 0;
}
