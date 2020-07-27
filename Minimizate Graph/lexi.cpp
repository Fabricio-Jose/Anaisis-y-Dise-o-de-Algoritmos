#include <iostream>
#include <string>

using namespace std;

void swapp(string &a, string &b){
    string temp = a;
    a=b;
    b=temp;
}

int particion(string *A, int p, int r){
    string x=A[r];
    int i=p-1;
    for(int j=p;j<r;j++){
        if (A[j]<=x){
            i=i+1;
            swapp(A[i],A[j]);
        }
    }
    swapp(A[i+1],A[r]);
    return i+1;
}
void quickk(string *A, int p, int r){
    int q;
    if (p<r){
        q=particion(A,p,r);
        quickk(A,p,q-1);
        quickk(A,q+1,r);
    }
}

int main(){
    int tam;
    string x;
    cout<<"Ingrese cantidad de elementos del array"<<endl;
    cin>>tam;
    string *a = new string[tam];
    for (int k=0;k<tam;k++){
        cout<<"ingrese palabra: ";
        cin>>x;
        a[k]=x;
    }
    cout<<endl;
    for(int l=0;l<tam;l++)
        cout<<a[l]<<", ";
    quickk(a,0,tam-1);
    cout<<endl;
    cout<<"Ordenado:"<<endl;
    for(int l=0;l<tam;l++)
        cout<<a[l]<<", ";
    delete[] a;

    return 0;

}
