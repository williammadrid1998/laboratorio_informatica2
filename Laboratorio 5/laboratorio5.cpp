

#include <iostream>
using namespace std;

// EJercicio #1 

int* copiar( int* valores,  int cantidad) {

    int* resultado = (int*)malloc(sizeof(int) * cantidad);

    for (int i = 0; i < cantidad;i++) {

        resultado[i] = valores[i];
    }

    return resultado;
}



// Ejercicio # 2


bool esPrimoRec(int valor1, int contador = 2) {

    if (valor1 == 2) {
        return true;
    }
    else if (valor1 == contador) {
        return true;
    }
    else if (valor1 % contador == 0) {
        return false;
    }
    else if (contador == valor1 - 1) {
        return true;
    }
    else {

        return esPrimoRec(valor1, contador + 1);
    }


}

int esprimo(int valor) {

    int contador = 0;


    for (int i = 0; i < valor; i++) {
        if (esPrimoRec(valor)) {
            contador++;
        }
        else
        {
            contador;
        }

    }

    return contador;


}

int* primos(const int maximo) {

    int tamano = sizeof(int) * (esprimo(maximo));

    int* arreglo = (int*)malloc(tamano);
    int contador = 0;

    for (int i = 2; i < maximo; i++) {
        if (esPrimoRec(i)) {
            arreglo[contador] = i;
            contador++;
        }
    }
    return arreglo;  

   
}

// Ejercicio #3

float distanciaEuclideana(int x, int y) {
    float resultado = (sqrt((pow((x - 0), 2)) + (pow((y - 0), 2))));

    return resultado;
}


bool menorDistancia(int* vectores, int distancia) {
    int x = vectores[0];
    int y = vectores[1];

    if (distanciaEuclideana(x, y) < distancia) {
        return true;
    }
    else {
        return false;
    }
}


int contadorVec(int** vectores, const int cantidad, const int distancia) {
    int c = 0;

    for (int i = 0; i < cantidad; i++) {
        if (menorDistancia(vectores[i], distancia)) {
            c++;
        }
    }
    return c;
}


int** vectoresCercanos(int** vectores, const int cantidad, const int distancia) {

    int tamanoVect = sizeof(int) * 2; 
    int tamanoVecVec = contadorVec(vectores, cantidad, distancia); 

    int** arreglo = (int**)malloc(tamanoVect * tamanoVecVec);
    int c = 0;

    for (int i = 0; i < cantidad; i++) {
        if (menorDistancia(vectores[i], distancia)) {
            arreglo[c] = vectores[i];
            c++;
        }
    }
    return arreglo;
}




int main()

{   
    
    // Ejecucion del ejercicio #1
     
    int arreglo1[] = { 1,2,3 };

    int* copia = copiar(arreglo1, 3);

    for (int i = 0; i < 3; i++) {
        printf("Los elementos de la copia son: %i\n", copia[i]);
    }    
    
    
    // ejecucion del ejercicio #2
    int* nPrim = primos(8);
    
    printf("Los primos menores a 8 son: %i,%i,%i,%i \n", nPrim[0], nPrim[1], nPrim[2], nPrim[3]);


    // ejecucion del ejercicio #3 
    int vec[] = { 1,2 };
    int vec2[] = { 5,6 };
    int vec3[] = { 3,4 };

    int* vecTotal[] = { vec, vec2, vec3 }; //Arreglo de vectores

    int** vecvec = vectoresCercanos(vecTotal, 3, 6);//Guardar la función con valores en una variable

    printf("Los vectores cuya distancia con (0,0) es menor a 6 son: (%i,%i), (%i,%i)", vecvec[0][0], vecvec[0][1], vecvec[1][0], vecvec[1][1]);
    
}

