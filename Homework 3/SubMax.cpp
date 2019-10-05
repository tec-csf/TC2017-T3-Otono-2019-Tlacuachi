/*
    Sebastian Gonzalo Vives Faus | A01025211
    Tarea 3| Algoritmo Avido
Dada una secuencia X={x1 x2 ... xm}, se dice que Z={z1 z2 ... zk} es una subsecuencia de X (siendo k ≤ m) si existe una 
secuencia creciente {i1 i2 ... ik} de índices de X tales que para todo j = 1, 2, ..., k tenemos xij = zj.

Dadas dos secuencias X e Y, se dice que Z es una subsecuencia común de X e Y si es subsecuencia de X y subsecuencia de Y. 

Diseñe un algoritmo que permita determinar la subsecuencia de longitud máxima común a dos secuencias.

*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct secuencia{ //Estructura para las celdas de la tabla M*N, donde num es su valor numerico y pro es su procedencia (Diagonal, Superior o Izquierda)
    int num;
    char pro;
};

//Inserta valores aleatorios al arreglo
void scrambleXY(int *X, int *Y, int sizeX, int sizeY){
	srand (time(NULL));//Semilla aleatorio
	for(int i = 0; i<sizeX; i++){
		X[i] = rand() % 2;
	}
    for(int j = 0; j<sizeY; j++){
		Y[j] = rand() % 2;
	}

}

//Imprimir las secuencias
void print(int n, int *arr){
    cout<<"(";
	for(int i = 0; i<n; i++){
        if(i<n-1){
		    cout<<arr[i]<<" , ";
        }
        else{
            cout<<arr[i];
        }
	}
    cout<<")"<<endl;
}

void subMax(int *X, int *Y, int sizeX, int sizeY){
    secuencia L[sizeY+1][sizeX+1];//Tabla
    int i,j;

    //Rellenar los "casos base" de la primer columna y fila de la tabla.
    for(i=0; i<sizeY+1; i++){ // Fila de 0s
        L[i][0].num = 0;
        L[i][0].pro = ' ';
    }

    for(j=0; j<sizeX+1; j++){ // Columna de 0s
        L[0][j].num = 0;
        L[0][j].pro = ' ';
    }

    //Iniciar a rellenar la tabla.
    for(i=1; i<=sizeY; i++){
        for(j=1; j<=sizeX; j++){
            if(Y[i-1]==X[j-1]){//Si algun valor en la secuencia Y (columna) es igual a algun valor de la secuencia X (fila)
            //Obtengo el valor de la diagonal y le sumo 1. Guardo el char D para significar que el valor fue obtenido por la diagonal.
            L[i][j].num = L[i-1][j-1].num + 1;
            L[i][j].pro = 'D';
            }//end if

            //Comparar las celdas de la Izquierda y Arriba
            else if(L[i-1][j].num >= L[i][j-1].num){//Si la celda a arriba es superior a la de la izquierda, metemos la de arriba
                L[i][j].num = L[i-1][j].num;
                L[i][j].pro = 'S';// El valor de arriba for superior
            }//end else if

            else{//La celda de la izquierda fue superior a la de arriba, metemos la de la izquierda.
                L[i][j].num = L[i][j-1].num;
                L[i][j].pro = 'I';// El valor de la izquierda fue superior

            }//end else

        }//end for Y
    }//end for X

    

    //Obtener el LCS (Longest Common Subsequence) de X y Y
    int longXY = L[sizeY][sizeX].num; //Longitud de la subsecuencia
    int LCS[longXY]; //Arreglo donde voy a guardar la subsecuencia

     i = sizeY, j = sizeX;
     int counter = longXY;
     while(i>0 && j>0){//Mientras que j e i no lleguen a 0:
         if(L[i][j].pro == 'D'){//Si la casilla tiene la procedencia Diagonal, significa que los valores de Y y X coinciden.
            LCS[counter-1] = Y[i-1];
            i--; j--; counter--; //Me muevo diagonalmente hacia arriba [izq].
         }
         else if(L[i][j].pro == 'S'){//Si la casilla tiene la procedencia Superior, significa que nos tenemos que mover una casilla arriba.
             i--;
         }
         else{//Si la casilla tiene, como ultimo caso, la procedencia Izquierda, significa que nos tenemos que mover una casilla a la izquierda.
             j--;
         }

     }//end while

    //Imprimir la tabla con sus valores y procedencias
    for(i=0; i<sizeY+1; i++){
        for(j=0; j<sizeX+1; j++){
            cout<<L[i][j].num<<"|"<<L[i][j].pro<<"  ";
        }//end Y
        cout<<endl;
    }//end X

    cout<<"La longitud de la subsecuencia entre (X,Y) es de: "<<longXY<<endl;
    cout<<"La Subsecuencia Comun mas Larga entre X y Y fue: ";
    print(longXY, LCS);
}

int main(){
    int sizeX, sizeY;
    cout<<"Insertar tamaños de la secuencias X y Y: "<<endl;
    cin>>sizeX>>sizeY;

    int X[sizeX];
    int Y[sizeY];


    scrambleXY(X,Y,sizeX,sizeY);
    cout<<"Secuencia X: ";
    print(sizeX, X);
    cout<<"Secuencia Y: ";
    print(sizeY, Y);

    cout<<"Tabla Z: "<<endl;
    subMax(X,Y,sizeX,sizeY);
    
}

