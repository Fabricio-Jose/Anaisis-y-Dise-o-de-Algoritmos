#include<iostream>
#include<string>
#include <ctime> 
#include<stdio.h>
 
int t0, t1, t2, t3, t4, t5, t6, t7;

class lista{
	private:
		int longitud;
		int *array;

	public:
		int tamano=longitud;
		int tam(){
			return longitud;
		}
     	void CrearLista(){
		int contadorArrayDinamico = 0;
		std::cout<<"Ingrese numero de Elementos de la Lista:"<<std::endl;
		std::cin>>longitud;
		//SE CREA UNA LISTA DE ALTO NUMERO DE ELEMENTOS
		array = new int[longitud];
		for(int i=0;i<longitud;i++)
			array[i]=rand();	
		//ANALISIS DE CANTIDAD DE ASIGNACION DE MEMORIA
		contadorArrayDinamico = 1;
		std::cout<<"Contador de Array dinacmio: ";
		std::cout<<contadorArrayDinamico * 50 + longitud *10<<std::endl;
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
	void Insert(){//--------Se creara variables para contabilizar las asignaciones y comparaciones
		int comparaciones=0;
		int asignaciones=1;//se empieza con 1 por la unica y primera asignacion de i =1
		int i,j,x;
		i=1;
		while(i<longitud){
			comparaciones++;//por cada while se comparara i<logitud
			x=array[i];
			j=i-1;
			while( j>=0 && array[j]>x ){
				comparaciones=comparaciones + 2; //por cada while se ahra 2 comparaciones en la condicion del while mismo
				array[j+1]=array[j];
				j=j-1;
				asignaciones=asignaciones+2;//por las dos lineas de codigo anteriores
			}
			array[j+1]=x;
			i=i+1;
			asignaciones=asignaciones + 4;// 4 son las asignaciones q hace el while principal
		}
		std::cout<<"el numero de comparaciones del Insertsort es: "<<comparaciones<<" y multiplicado x2: "<<comparaciones*2<<std::endl;
		std::cout<<"el numero de asignaciones del Insertsort es: "<<asignaciones<<" y multiplicado x8: "<<asignaciones*8<<std::endl;

	}
	void InsertDecreciente(){//--------Se creara variables para contabilizar las asignaciones y comparaciones
		int comparaciones=0;
		int asignaciones=1;//se empieza con 1 por la unica y primera asignacion de i =1
		int i,j,x;
		i=1;
		while(i<longitud){
			comparaciones++;//por cada while se comparara i<logitud
			x=array[i];
			j=i-1;
			while( j>=0 && array[j]<x ){
				comparaciones=comparaciones + 2; //por cada while se ahra 2 comparaciones en la condicion del while mismo
				array[j+1]=array[j];
				j=j-1;
				asignaciones=asignaciones+2;//por las dos lineas de codigo anteriores
			}
			array[j+1]=x;
			i=i+1;
			asignaciones=asignaciones + 4;// 4 son las asignaciones q hace el while principal
		}
		std::cout<<"el numero de comparaciones del Insertsort es: "<<comparaciones<<" y multiplicado x2: "<<comparaciones*2<<std::endl;
		std::cout<<"el numero de asignaciones del Insertsort es: "<<asignaciones<<" y multiplicado x8: "<<asignaciones*8<<std::endl;

	}
	void swap(int &a, int &b){
		int aux;
		aux=a;
		a=b;
		b=aux;
	}
	void Burbuja(){////-------------------se creara variables para contabilizar y saber las asignaciones y comparaciones:
		int asignacion= 2; //tomamos la asignacion de i=0 y j = 0 q solo se dara una vez, para luego proceder a las demas asignaciones, por ello =  2
		int comparacion = 0;
		for(int i=0;i<longitud-1;i++){
			asignacion++;// dado el i++, aumenta en 1
			comparacion++;//dado el i<longitud, aumenta en 1
			for(int j=0;j<longitud-1;j++){
				asignacion++;
				comparacion++;
				if(array[j]>array[j+1]){
					comparacion++; //dada la comparacionarray[j]>array[j+1]
					swap(array[j],array[j+1]);
					asignacion=asignacion+3;//la funcion swap cuenta con 3 asignaciones
				}
			}
		}
		std::cout<<"-----la cantidad de comparaciones es: "<<comparacion<<"y multiplicado  x2 es : "<< comparacion*2<<std::endl;
		std::cout<<"-----la cantidad de asignaciones es: "<<asignacion<<" ymultiplicado x8 es : "<< asignacion*8<<std::endl;
	}
	void BurbujaDecreciente(){////-------------------se creara variables para contabilizar y saber las asignaciones y comparaciones:
		int asignacion= 2; //tomamos la asignacion de i=0 y j = 0 q solo se dara una vez, para luego proceder a las demas asignaciones, por ello =  2
		int comparacion = 0;
		for(int i=0;i<longitud-1;i++){
			asignacion++;// dado el i++, aumenta en 1
			comparacion++;//dado el i<longitud, aumenta en 1
			for(int j=0;j<longitud-1;j++){
				asignacion++;
				comparacion++;
				if(array[j]<array[j+1]){
					comparacion++; //dada la comparacionarray[j]>array[j+1]
					swap(array[j],array[j+1]);
					asignacion=asignacion+3;//la funcion swap cuenta con 3 asignaciones
				}
			}
		}
		std::cout<<"-----la cantidad de comparaciones es: "<<comparacion<<"y multiplicado  x2 es : "<< comparacion*2<<std::endl;
		std::cout<<"-----la cantidad de asignaciones es: "<<asignacion<<" ymultiplicado x8 es : "<< asignacion*8<<std::endl;
	}

};
int main(){
	//NOTA:
	//LOS CONTADORES DE ASIGNACION Y COMPARACION SE ENCUENTRAN DENTRO DE LAS FUNCIONES DE BUBBLE E INSERTION SORT 
	//SE CREA UN ARRAY DINAMICO Y SE LO COPIA EN OTRA CLASE PARA COMPARAR EL RENDIMIENTO DE BUBBLE E INSERTION
	int contadorObjeto = 0;
	lista primera;//creacion del unico objeto a usar en el codigo
	lista segunda;
	lista tercera;
	lista cuarta;
	contadorObjeto=2;
	std::cout<<" Se ha creado 1 objeto que equivaldria a un x200"<<std::endl;
	primera.CrearLista();
	segunda=primera;
	tercera=primera;
	cuarta=primera;
	std::cout<<std::endl;
	std::cout<<"se ha creado la siguiente lista desordenada...\n";
	primera.mostrar();
	std::cout<<std::endl;
	std::cout<<std::endl;

	std::cout<<"-------INSERT SORT CRECIENTE------"<<std::endl;
	t0=clock();
	primera.Insert();
	t1 = clock();
	std::cout<<"ordenamiento de insert sort...\n";
//	primera.mostrar();
	std::cout<<std::endl;
	std::cout<<std::endl;
	float time1 = t1-t0;
	std::cout << "Execution Time: " << time1 << std::endl;
	
	std::cout<<"-------BUBBLE SORT CRECIENTE------"<<std::endl;
	t2=clock();
	segunda.Burbuja();
	t3=clock();
	std::cout<<"ordenamiento de bubble sort...\n";
//	segunda.mostrar();
	std::cout<<std::endl;
	std::cout<<std::endl;	
	float time2 = t3-t2;
	std::cout << "Execution Time: " << time2 << std::endl;
	
	
	
	
	
	std::cout<<"-------INSERT SORT DECRECIENTE------"<<std::endl;
	t4=clock();
	tercera.InsertDecreciente();
	t5=clock();
	std::cout<<"ordenamiento de insert sort...\n";
//	tercera.mostrar();
	std::cout<<std::endl;
	std::cout<<std::endl;
	float time3 = t5-t4;
	std::cout << "Execution Time: " << time3 << std::endl;
	
	std::cout<<"-------BUBBLE SORT DECRECIENTE------"<<std::endl;
	t6=clock();
	cuarta.BurbujaDecreciente();
	t7=clock();
	std::cout<<"ordenamiento de bubble sort...\n";
	//cuarta.mostrar();
	std::cout<<std::endl;
	std::cout<<std::endl;	
	double time4 = t7-t6;
	std::cout << "Execution Time: " << time4 << std::endl;
	
	
	
	
	primera.delet();
	segunda.delet();
	tercera.delet();
	cuarta.delet();
	std::cout<<"Alumno: Fabricio Jose Barrionuevo Paredes   CUI:20131661"<<std::endl;
	return 0;
}


