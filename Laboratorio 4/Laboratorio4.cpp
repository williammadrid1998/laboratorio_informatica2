
#include <iostream>

using namespace std;




// Ejercicio #1

bool divisionSegura(int numerador, int denominador, int* respuesta) {

    if (denominador == 0) {

        return  false;
    }
    else
    {
        *respuesta = numerador / denominador;
        return true;
    }
}

// Ejercicio #2

bool sumaMayor(int valores[], int cantidad, int** respuesta) {

    if (cantidad >= 2) {
        for (int i = 0; i < cantidad; i++) {

            for (int j = i + 1; j < cantidad; j++) {


                if (valores[i] < valores[j]) {
                    int temp = valores[i];
                    valores[i] = valores[j];
                    valores[j] = temp;
                }

            }
        }

        respuesta[1] = &valores[1];
        respuesta[0] = &valores[0];

        
        return true;


    }
    else
    {
        return false;
    }




}

// Ejercicio #3

int fibonacci(int n) { // esta es una funcion auxiliar para la funcion fibonacciN


    switch (n)
    {
    case 0:
        return 0;

        break;

    case 1:
        return 1;
        break;

    default:

        return fibonacci(n - 1) + fibonacci(n - 2);
        break;
    }



}


void fibonacciN(const int n, int* valores) {
    for (int i = 0; i < n; i++) {

        valores[i] = fibonacci(i);
        printf("%i ", valores[i]);
    }

}


// Ejercicio # 4

void fibonacciMejorada(const int n, int* valores) {

    switch (n)
    {
    case 0:
        valores[0] = 0;


    case 1:
        valores[0] = 0;
        valores[1] = 1;


    default:
        valores[0] = 0;
        valores[1] = 1;
        for (int i = 2; i < n; i++) {

            valores[i] =(valores[i-1] + valores[i -2 ]);
        }



    }

}

void fibonacciN_Optimizada(const int n, int* valores)
{
    valores[0] = 0;
    valores[1] = 1;

    for (int i = 2; i < n; i++)
    {
        valores[i] = valores[i - 2] + valores[i - 1];
    }
}

int main()
{
    int* hola = new int;
    int** arreglo1 = new (int*);
    int arreglo2[] = { 1,2,3,4,5,6,8 };


    // ejecucion del ejercicio #1
    std::cout << std::boolalpha << divisionSegura(9, 0, hola) << "\n";

   
    // ejecucion del ejercicio # 2
    std::cout << std::boolalpha << sumaMayor( arreglo2, 3, arreglo1 ) << "\n";

    


    // Ejecucion del ejercicio #3
    int vector3[5];
   fibonacciN(5, vector3);
   printf("\n");
    
    
    
    // Ejecucion del ejercicio # 4
    int arreglo4[10000];
    fibonacciMejorada(10000, arreglo4);
    std::cout << "el valor 10 de la cadena de fibonacci es:" << arreglo4[10];

}
