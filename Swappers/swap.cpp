#include <iostream> 
#include <algorithm> 
#include <cstdlib>

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
    c=c+1;
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
int main() 
{ 
    int N;
    int L;
    int x;
    float c=0;
    cin>>N;
    //cout<<N<<endl;
    for(int i=0;i<N;i++){
        cin>>L;
        
        int *a=new int[L];
        for (int j=0;j<L;j++){
            cin>>x;
            a[j]=x;
        }
        quickk(a,0,L-1,c);
        cout<<c<<endl;
        c=0;
        delete[] a;
    }
   
  
    return 0; 
  
} 
