#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    cout<<"ingrese numero de estados: "<<endl;
    int tam,q0,aceptacion_n,inicial,falso;
    falso=0;    
    cin >> tam ;
    char ***matriz = new char**[tam];
    for(int i=0; i<tam; i++) {
        matriz[i] = new char*[tam];
        for(int j=0; j<tam; j++){
            matriz[i][j] = new char[2];
        }
    } 
    //ingresando estado inicial
    cout<<"ingrese el estado inicial: ";
    cin>>q0;
    //ingresando estados de aceptación
    cout<<"cuantos estados de aceptacion tendra? ";
    cin>>aceptacion_n;
    int *aceptacion = new int[aceptacion_n];
    cout<<"ingrese el/los estados de aceptacion: "<<endl;
    for(int i=0; i<aceptacion_n;i++){
    cin>>aceptacion[i];
    }
    //llenando matriz
    for(int i=0; i<tam; i++){
        for(int j=0; j<tam; j++){
            cout<<"Ingrese dato a leer ["<<i<<"]["<<j<<"]: ";
            cin>>matriz[i][j][0] ;
            if(matriz[i][j][0]!='n'){
                cout<<"Ingrese Transduccion: ";
                cin>>matriz[i][j][1];
            }
        }
    }
    //mostrando matriz de adyacencia
    for (int i=0; i<tam; i++){
        for (int j=0; j<tam; j++){
            cout<<"["<<matriz[i][j][0]<<","<<matriz[i][j][1]<<"]"<<" ";
        }
        cout<<endl;
    }
	char y;
    y='y';
    int q=q0;
	while(y=='y'){
    //validamos cadena y transformamos
    int fin;
    string cadena, transducida;
    cout<<"ingresar cadena de enteros: ";
    cin>>cadena;
    transducida=cadena;
    for(int i=0; i<cadena.size(); i++){        
        for(int j=0; j<tam; j++){
            if(cadena[i]==matriz[q][j][0]){
                transducida[i]=matriz[q][j][1];
                fin=j;
                q=fin;
                break;
            }            
        }
    }
    
    //confirmamos estado final
    for (int i=0; i<aceptacion_n;i++){
        if(fin==aceptacion[i]){
            cout<<"cadena ingresada: "<<cadena<<endl;
            cout<<"cade transducida: "<<transducida<<endl;
        }
        if((fin!=aceptacion[i]) && (i==aceptacion_n-1))
            cout<<"cadena no aceptada"<<endl;        
    }
    //repetir proceso
    cout<<"desea continuar? y/n: ";
    cin>>y;    
	q=q0;
    }

    return 0;
}
