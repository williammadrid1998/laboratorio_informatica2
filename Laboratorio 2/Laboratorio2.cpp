#include <iostream>
// Ejercicio #1 esta funcion retorna true si el valor es primo o false en caso contrario. Lo hace de forma recursiva

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
//Ejercicio #2

/* esta funcion retorna true si el valor es primo o false en caso contrario; lo hace de manera ciclica utilizando 
 el comando de interacion while. */

bool esPrimoCiclica(int valor1, int contador1 = 2) {


    while (contador1 < valor1)
    {
        if (valor1 == 2) {
            return true;
        }
        else if (valor1 == contador1) {
            return true;
        }
        else if (valor1 % contador1 == 0) {
            return false;
        }
        else if (contador1 == valor1 - 1) {
            return true;
        }
        else {

            contador1 = contador1 + 1; // aqui la variable aumenta en 1.
        }
    }
}

//Ejercicio #3

/* esta funcion toma un valor como parametro y se llama de manera recursiva para retornar un numero primo. */
int obtenerPrimoRec(int n, int contador = 1) {

    if (n == 1 && esPrimoRec(contador)) {
        return contador;
    }
    else if (!(esPrimoCiclica(contador)))
    {
        obtenerPrimoRec(n, (contador + 1));
    }
    else
    {
        return obtenerPrimoRec((n - 1), (contador + 1));
    }
}

//Ejercicio #4

/* esta funcion toma un valor como parametro para retornar un numero primo. */
int obtenerPrimoCiclico(int numero, int contador = 1) {

    while (contador < numero) {
        if (numero == 1 && esPrimoRec(contador)) {
            return contador;
        }
        else if (!(esPrimoCiclica(contador)))
        {
            obtenerPrimoRec(numero, (contador + 1));
        }
        else
        {
            return obtenerPrimoRec((numero - 1), (contador + 1));
        }
    }
}

int main()
{
    // prueba del ejercicio # 1-
    std::cout << std::boolalpha << esPrimoRec(98);
    // prueba del ejercicio # 2-
    std::cout << std::boolalpha << esPrimoCiclica(97);
    // prueba del ejercicio # 3-
    printf("%i \n\n", obtenerPrimoRec(5));
    // prueba del ejercicio # 4-
    printf("%i \n\n", obtenerPrimoCiclico(5));


}
