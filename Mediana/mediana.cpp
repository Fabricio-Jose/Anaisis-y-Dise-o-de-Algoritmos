#include <iostream> 
#include <algorithm> 
#include <bits/stdc++.h> 


using namespace std; 
void swapp(int &a, int &b){
    int temp = a;
    a=b;
    b=temp;
}
int particion(int *A, int p, int r) 
{ 
    int x = A[r];
    int i = p; 
    for (int j = p; j <= r - 1; j++) { 
        if (A[j] <= x) { 
            swapp(A[i], A[j]); 
            i++; 
        } 
    } 
    swapp(A[i], A[r]); 
    return i; 
} 
  
int k_esimo(int *A, int p, int r, int k){ 

    if(k>0 && k<=r-p+1){ 
        int x = particion(A,p,r); 
        if (x-p==k-1) 
            return A[x]; 
        if (x-p>k-1)  
            return k_esimo(A,p,x-1,k); 
  
        return k_esimo(A,x+1,r,k-x+p-1); 
    } 
    return INT_MAX; 
} 


int main() 
{ 
    int n=8001;
    int k = 4001;
    int *a=new int[n];
    int x;
    for(int i=0;i<8000;i++){
        for (int i=0;i<8001;i++){
            cin>>x;
            a[i]=x;
        }
    cout <<k_esimo(a, 0, 8000, k); 

        cout<<endl;
    }
   
  
    return 0; 
  
} 
