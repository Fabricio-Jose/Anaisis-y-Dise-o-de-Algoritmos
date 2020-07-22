#include <iostream>
#include <string>

using namespace std;

int main(){
    int x=0;
    cout<<"ingrese string: ";
    
    string a,t;
    cin>> a;
    t=a;
    cout<<"ingrese char";
    char b;
    cin>>b;
    for (int i=0;i<a.size();i++){
        if(a[i]==b)
            x=x+1;
    }
    cout<<"entonces essss : "<<x;
    for (int i=0;i<a.size();i++){
        t[i]=b;
    }
    cout<<"entonces baaaaa : "<<t;


    return 0;
}
