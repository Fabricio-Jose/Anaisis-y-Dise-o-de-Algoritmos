#include<iostream>
using namespace std;
//superior..............
//......................
//...............inferior
int acumulado(int **A, int pos_i, int pos_j,int lim_i,int lim_j){
    if(lim_i==0 && lim_j==0){
        
        if(pos_i==0 && pos_j==0){
            return A[0][0];        
        }else if(pos_i==0 && pos_j>0){
            int h=acumulado(A,pos_i,pos_j-1,0,0);
            return A[pos_i][pos_j] + h;
        }else if(pos_i>0 && pos_j==0){
            int g=acumulado(A,pos_i-1,pos_j,0,0);
            return A[pos_i][pos_j]+g;
        }else if(pos_i>0 && pos_j>0){
        int arr,iz,diago;
        arr=acumulado(A,pos_i-1,pos_j,0,0);
        iz=acumulado(A,pos_i,pos_j-1,0,0);
        diago=acumulado(A,pos_i-1,pos_j-1,0,0);
        return A[pos_i][pos_j] + arr + iz - diago;
        }
    }else if(lim_i==0 && lim_j>0){
        if(pos_i==lim_i && pos_j==lim_j){
            return A[pos_i][pos_j]; 
        }else if(pos_i>0 && pos_j==0){
            int q_arr = acumulado(A,lim_i,pos_j,0,0);
            int g=acumulado(A,pos_i-1,pos_j,0,0);
            return A[pos_i][pos_j]+g-q_arr;
        }else if(pos_i==0 && pos_j>0){
            int p_iz = acumulado(A,pos_i,lim_j,0,0);
            int h=acumulado(A,pos_i,pos_j-1,0,0);
            return A[pos_i][pos_j] + h - p_iz;
        }else if(pos_i>0 && pos_j>0){
            
        int arr,iz,diago, q_arr, p_iz, diago_r;
        arr=acumulado(A,pos_i-1,pos_j,0,0);
        iz=acumulado(A,pos_i,pos_j-1,0,0);
        diago=acumulado(A,pos_i-1,pos_j-1,0,0);
        
        q_arr=0;
        p_iz=acumulado(A,pos_i,lim_j-1,0,0);
        diago_r=0;
        
        return (A[pos_i][pos_j] + arr + iz - diago) - q_arr - p_iz + diago_r;
        }
    } else if(lim_i>0 && lim_j==0){
        if(pos_i==lim_i && pos_j==lim_j){
            return A[pos_i][pos_j]; 
        }else if(pos_i>0 && pos_j==0){
            int q_arr = acumulado(A,lim_i,pos_j,0,0);
            int g=acumulado(A,pos_i-1,pos_j,0,0);
            return A[pos_i][pos_j]+g-q_arr;
        }else if(pos_i==0 && pos_j>0){
            int p_iz = acumulado(A,pos_i,lim_j,0,0);
            int h=acumulado(A,pos_i,pos_j-1,0,0);
            return A[pos_i][pos_j] + h - p_iz;
        }else if(pos_i>0 && pos_j>0){
            
        int arr,iz,diago, q_arr, p_iz, diago_r;
        arr=acumulado(A,pos_i-1,pos_j,0,0);
        iz=acumulado(A,pos_i,pos_j-1,0,0);
        diago=acumulado(A,pos_i-1,pos_j-1,0,0);
        
        q_arr=acumulado(A,lim_i-1,pos_j,0,0);
        p_iz=0;
        diago_r=0;
        
        return (A[pos_i][pos_j] + arr + iz - diago) - q_arr - p_iz + diago_r;
        }
    }else if(lim_i>0 && lim_j>0){
        if(pos_i==lim_i && pos_j==lim_j){
            return A[pos_i][pos_j]; 
        }else if(pos_i>0 && pos_j==0){
            int q_arr = acumulado(A,lim_i,pos_j,0,0);
            int g=acumulado(A,pos_i-1,pos_j,0,0);
            return A[pos_i][pos_j]+g-q_arr;
        }else if(pos_i==0 && pos_j>0){
            int p_iz = acumulado(A,pos_i,lim_j,0,0);
            int h=acumulado(A,pos_i,pos_j-1,0,0);
            return A[pos_i][pos_j] + h - p_iz;
        }else if(pos_i>0 && pos_j>0){
            
        int arr,iz,diago, q_arr, p_iz, diago_r;
        arr=acumulado(A,pos_i-1,pos_j,0,0);
        iz=acumulado(A,pos_i,pos_j-1,0,0);
        diago=acumulado(A,pos_i-1,pos_j-1,0,0);
        
        q_arr=acumulado(A,lim_i-1,pos_j,0,0);
        p_iz=acumulado(A,pos_i,lim_j-1,0,0);
        diago_r=acumulado(A,lim_i-1,lim_j-1,0,0);

        return (A[pos_i][pos_j] + arr + iz - diago) - q_arr - p_iz + diago_r;
        }
    }       
}

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

int sumaMaxima(int **A,int tam){
    int k,l,sum,tempo;
    sum=A[0][0];
    for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            l=i;
            while(l>=0){
                k=j;
                while(k>=0){
                    tempo=acumulado(A,i,j,l,k);
                    cout<<"tempo: "<<tempo <<endl;
                    sum=max_2(tempo,sum);
                    k=k-1;
                }
                l=l-1;
            }
        }
    }    
    return sum;
}



int dv(int **A, int p, int r,int li,int lj){
    if(p==r){
        int pos=A[p][p];
        return max_2(0,pos);
    }
    int x,y;
    int q,maxizq,maxder,max2izq,max2der,suma,maxcruz;
    q=(p+r)/2;
    maxizq=dv(A,p,q,li,lj);
    maxder=dv(A,q+1,r,li,lj);
    suma=A[q][q];
    max2izq=suma;
    for(int i=q-1;i>=p;i--){
        for(int j=q-1;j>=p;i--){
            x=acumulado(A,i,j,p,p);
            suma=suma+x;
            max2izq=max_2(max2izq,suma);
	}
    }
    for(int i=q-1;i=p;i--){
	x=acumulado(A,i,i,p,p);
	suma=suma+x;
	max2izq=max_2(max2izq,suma);
    	
    }
    suma=A[q+1][q+1];
    max2der=suma;
    for(int i=q+2;i<=r;i++){
	for(int j=q+2;j<=r;j++){
	    y=acumulado(A,i,j,0,0);
            suma=suma+y;
            max2der=max_2(max2der,suma);
	}
    }
    for(int i=q+2;i<=r;i++){
        y=acumulado(A,i,i,p,p);
	suma=suma+y;
	max2der=max_2(max2der,suma);
    }
    maxcruz=max2izq+max2der;
    return max_3(maxizq,maxder,maxcruz);
}

int main() 
{       
    //MATRIIIIIIZ
    int tam,x;
    //cin>>tam;
    tam=4;
    //Recibir matriz
    int **matriz = new int*[tam];
    for(int i=0; i<tam; i++) {
        matriz[i] = new int[tam];
        }
    int vect[] = {-2,0,8,-1,1,-4,1,-4,2,-6,2,9,0,-2,-7,0};
    int contador=0;
    //llenar matriz
    for(int i=0;i<tam;i++){
        for (int j=0;j<tam;j++){
//            cin>>x;
            matriz[i][j]=vect[contador];
	    contador++;
        }
    }
    
    //mostrar matriz
    for(int i=0;i<tam;i++){
        for (int j=0;j<tam;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
    
    /*
    int li,lj,posi,posj;
    li=2-1;
    lj=1-1;
    posi=3-1;
    posj=4-1;	    
    x=acumulado(matriz,posi,posj,li,lj);
    */

    //Divide y conquista
    //x=dv(matriz,0,tam-1,0,0);
    x=sumaMaxima(matriz,tam);
    cout<<"suma maxima: "<<x<<endl;
    
    cout<<"Fabricio Jose Barrionuevo Paredes"<<endl;
    cout<<"Cui: 20131661"<<endl;
  
    return 0; 
  
} 
