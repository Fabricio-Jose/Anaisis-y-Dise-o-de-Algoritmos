#include<iostream>
#include<string>
#include <ctime> 
#include<stdio.h>
 
class lista{
	private:
		int longitud;
		int *array;
	
		int *analisis;
	public:
		int tamano=longitud;
		int tam(){
			return longitud;
		}
			
     	void CrearLista(){
		int c;
		for (int j=0;j<2;j++){
		}
		std::cout<<"Ingrese numero de Elementos de la Lista:"<<std::endl;
		std::cin>>longitud;
		array = new int[longitud];
		for(int i=0;i<longitud;i++){
			std::cout<<"ingrese numero"<<std::endl;
			std::cin>>c;
			array[i]=c;	}
		}
	void mostrar(){
		std::cout<<"\n\nMostrando lista:\n";
		for(int i=0;i<longitud;i++){
			std::cout<<array[i]<<" ";}
		std::cout<<""<<std::endl;
	}
	void delet(){
		delete[] array;
	}
		/***
		void dv(int p, int r){
			if (p==r)
				return 
			int q=(p+r)/2;
			int maxizq = dv(p,q);
			int maxizq = dv(q,r);
			return
		}***/
	void lineal(){
		int sumamax,sum, e, d, i, f;
		sumamax=0;
		sum =0;
		e=0;
		d=-1;
		i=1;
		f=0;
		while (f<longitud){
			f=f+1;
			sum=sum+array[f];
			if (sum<0){
				sum=0;
				i=f+1;
			}else
			if(sum>sumamax){
				sumamax=sum;
				e=i;
				d=f;
			}
			
		}
		std::cout<<"Limite es entren:["<<e<<" , "<<d<<"]"<<std::endl;
		std::cout<<"sumamax: "<<sumamax<<std::endl;
	}
		


};
int main(){
	int contadorObjeto = 0;
	lista primera;

	primera.CrearLista();
	std::cout<<std::endl;
	std::cout<<"se ha creado la siguiente lista desordenada...\n";
	primera.mostrar();
	std::cout<<std::endl;
	std::cout<<std::endl;
	
	std::cout<<"-------Algoritmo Segmento de Suma Máximo------"<<std::endl;
	primera.lineal();
		
	primera.delet();

	std::cout<<"Alumno: Fabricio Jose Barrionuevo Paredes   CUI:20131661"<<std::endl;
	return 0;
}

