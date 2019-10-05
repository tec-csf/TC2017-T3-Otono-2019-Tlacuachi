/*
    Sebastian Gonzalo Vives Faus | A01025211
    Tarea 3| Algoritmo Avido

Supongamos que tenemos n hombres y n mujeres y dos matrices M y H que contienen las preferencias de los unos por los otros. 
Más concretamente, la fila M[i,·] es una ordenación (de mayor a menor) de las mujeres según las preferencias del i-ésimo hombre y, 
análogamente, la fila H[i,·] es una ordenación (de mayor a menor) de los hombres según las preferencias de la i-ésima mujer.

Diseñe un algoritmo que encuentre, si es que existe, un emparejamiento de hombres y mujeres tal que todas las parejas formadas sean estables. 
Una pareja (h,m) es estable si no se da ninguna de estas dos circunstancias:

Existe una mujer m’ (que forma la pareja (h’,m’)) tal que el hombre h la prefiere sobre la mujer m y además la mujer m’ también prefiere a h sobre h’. 
Existe un hombre h” (que forma la pareja (h”,m”)) tal que la mujer m lo prefiere sobre el hombre h y además el hombre h” también prefiere a m sobre la mujer m”. 

Con ayuda del codigo https://www.geeksforgeeks.org/stable-marriage-problem/

La complejidad del algoritmo es de O(n^2).

*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
#define N 4 //Numero de hombres y mujeres (Definido para facilitar la insercion de matrices en las funciones).

//Imprime la matriz de las preferencias de Hombres / Mujeres
void print(int arr[2*N][N], int n){
    for(int i = 0; i<n*2; i++){
        for(int j = 0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}
//Inserta preferencias del hombre / mujer en su arreglo
void scramble(int HM[2*N][N], int n){
    srand (time(NULL));//Semilla aleatorio
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            HM[i][j] = rand() % n+1;
        }
    }

    for(int i = n; i<n*2; i++){
        for(int j = 0; j<n; j++){
            HM[i][j] = j;
        }
    }

}

bool mujerPrefiere_hombre2_A_hombre(int HM[2*N][N], int mujer, int hombre, int hombre2){
    for(int i = 0; i<N; i++){//Checamos si la mujer prefiere a hombre sobre hombre2
        if(HM[mujer][i]==hombre2){ //Si el hombre2 viene antes que hombre, la mujer prefiere a hombre2
            return true;
        }//end if

        if(HM[mujer][i]==hombre){//Pero, si hombre viene antes que hombre2, la mujer se cambia a estar con hombre.
            return false;
        }//end if

    }//end for
}

void MatchHM(int HM[2*N][N]){
    //Declaracion de variables
    int Mconpareja[N];
    bool Hlibre[N];

    for(int i = 0; i<N; i++){
        Mconpareja[i] = -1;
        Hlibre[i] = false;
    }
    int HlibresCount = N; //Cantidad de hombres libres que quedan.

    while(HlibresCount>0){//Mientras hayan hombres libres...
        int hombre;

        for(hombre = 0; hombre<N; hombre++){//Buscamos al primer hombre en la lista que esta soltero.
            if(Hlibre[hombre] == false){
                //cout<<"Hombre "<<hombre<<" es soltero!"<<endl;
                break; //Si encontramos a algun hombre soltero, nos salimos del loop.
            }
        }//end for [encontrar hombre soltero]
        for(int i = 0; i< N && Hlibre[hombre] == false; i++){//Analizamos mujer por mujer por las prefencias del hombre.
            int mujer = HM[hombre][i];
            if(Mconpareja[mujer-N] == -1){//La preferencia de la mujer esta libre, asi que hombre y esta mujer se vuelven pareja.
                Mconpareja[mujer-N] = hombre;
                Hlibre[hombre] = true;//El hombre ya no esta libre.
                HlibresCount--;//Se decrementa la cantidad de hombres solteros.
                cout<<"Mujer "<<mujer<<" es soltera! al igual que el Hombre "<<hombre<<"! Ahora estan juntos"<<endl;
            }

            else{//La mujer no estaba disponible
                int hombre2 = Mconpareja[mujer-N];//hombre'

                if(mujerPrefiere_hombre2_A_hombre(HM,mujer,hombre,hombre2) == false){//Si la mujer prefiere estar con hombre en vez de hombre2
                    Mconpareja[mujer-N] = hombre;
                    Hlibre[hombre]=true;
                    Hlibre[hombre2] = false;//El hombre con el que estaba ahora esta disponible.
                    cout<<"Mujer "<<mujer<<" prefiere al Hombre "<<hombre<<" que al Hombre"<<hombre2<<endl;
                }

            }//end else
        }//end for [mujer por mujer]
    }//end while

    cout<<"Parejas que funcionaron: "<<endl;
    cout<<"Mujer | Hombre"<<endl;
    for(int i = 0; i< N; i++){
        cout<<i<<"\t"<<Mconpareja[i]<<endl;
    }
}



int main(){
    int HM[2*N][N] = 
        //Hombres
        { {7, 5, 6, 4}, 
        {5, 4, 6, 7}, 
        {4, 5, 6, 7}, 
        {4, 5, 6, 7}, 
        //Mujeres
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
    }; 
    //OBS: Obtener elementos aleatorios en el arreglo de los hombres que cumplan.
    print(HM,N);

    MatchHM(HM);

    return 0;
}

