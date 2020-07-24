#include <iostream>
using namespace std;


/*
 g++ divide.cpp -o divide.o
./divide.o<prueba.txt>salida.txt
 */
int max_2(int x, int y){
    if (x>y)
        return x;
    else
        return y;
}

int max_3(int x, int y, int z){
    if (x>y && x>z)
        return x;
    else if (y>x && y>z)
        return y;
    else
        return z;
}


int acumulado(int **A,int f_sub,int c_sup, int f_inf,int c_inf, int plano)
{
	if(f_sub==f_inf && c_sup==c_inf)	{
		return max(0,A[f_sub][c_sup]);
	}
	if(plano==1){
	if(c_sup!=c_inf){
		int q=(c_sup+c_inf)/2;

		int maxizq=acumulado(A,f_sub,c_sup,f_inf,q,0);
		int maxder=acumulado(A,f_sub,q+1,f_inf,c_inf,0);

		int max2izq=A[f_sub][q];
		int max2der=A[f_sub][q+1];
		int maxcruz=A[f_sub][q];
		for(int g=1;g<(f_inf+f_sub+2);g++){
		for(int k=f_sub;k<(f_inf-g+2);k++){
		    int suma=0;
		    for(int l=k;l<k+g;l++){
		 	suma=suma + A[l][q];
			//cout<<suma<<endl
			}
			max2izq=suma;
			for(int i =q-1;i>(c_sup-1);i--){
		            int temporal=0;
			    for(int l=k;l<k+g;l++){
				temporal=temporal+A[l][i];
			   //cout<<temporal<<endl
			    }
			    suma=suma+temporal;
			    max2izq=max_2(max2izq,suma);
			}
			suma =0;
			for(int l=k;l<k+g;l++){
				suma=suma+A[l][q+1];
			//cout<<suma<<endl                        
			}
			max2der=suma;
			for(int i =q+2;i<(c_inf+1);i++){
			    int temporal=0;
			    for(int l=k;l<k+g;l++)
			 	temporal=temporal+A[l][i];
	    //cout<<temporal<<endl
			suma=suma+temporal;
			max2der=max_2(max2der,suma);
			}
			maxcruz=max_2(maxcruz,max2izq+max2der);
		}
	}
            return max_3(maxder,maxizq,maxcruz);
	}
	else{
	    return acumulado(A,f_sub,c_sup,f_inf,c_inf,0);
	}
    }
	else{
	if(f_sub!=f_inf){
            int q=(f_sub+f_inf)/2;
	    int maxsup=acumulado(A,f_sub,c_sup,q,c_inf,0);
	    int maxinf=acumulado(A,q+1,c_sup,f_inf,c_inf,0);
	    int max2sup=A[q][c_sup];
	    int max2inf=A[q+1][c_sup];
	    int maxcruz=A[q][c_sup];
	    for(int g=1;g<(c_inf+c_sup+2);g++){
	    for(int k=c_sup;k<(c_inf-g+2);k++){
		int suma=0;
		for(int l=k;l<k+g;l++)
	            suma+=A[q][l];
		//cout<<suma<<endl                    
		max2sup=suma;
		for(int i =q-1;i>(f_sub-1);i--){
                    int temporal=0;
		    for(int l=k;l<k+g;l++)
		        temporal+=A[i][l];
		    //cout<<suma<<endl                        
		suma=suma+temporal;
		max2sup=max_2(max2sup,suma);
		}
		suma=0;
		for(int r=k;r<k+g;r++)
			suma+=A[q+1][r];
		max2inf=suma;

		for(int i =q+2;i<(f_inf+1);i++){
			int temporal=0;
		for(int l=k;l<k+g;l++)
	            temporal+=A[i][l];
		suma=suma+temporal;
		max2inf=max_2(max2inf,suma);
		}
		maxcruz=max_2(maxcruz,max2inf+max2sup);
		}
		}
		return max_3(maxinf,maxsup,maxcruz);
		}
	else{
		return acumulado(A,f_sub,c_sup,f_inf,c_inf,0);
	}
}
}


int main(){
    int x;
    int vect[] = {-2,0,8,-1,1,-4,1,-4,2,-6,2,9,0,-2,-7,0};
    int contador=0;
    
	int n;
	cin>>n;
    //n=4;
	int **arreglo = new int*[n];
	for (int i = 0; i < n; i++)	{
    	arreglo[i] = new int[n];
	}
	for(int i=0; i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arreglo[i][j];
    //       arreglo[i][j]=vect[contador];
	//       contador++;
		}
	}
	
	x=acumulado(arreglo,0,0,n-1,n-1,1);
    //cout<<"La suma maxima es: ";
	cout<<x<<endl;
    
//    cout<<"Fabricio Jose Barrionuevo Paredes"<<endl;
//    cout<<"Cui: 20131661"<<endl;
	return 0;
}

