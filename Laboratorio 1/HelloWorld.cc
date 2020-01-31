


#include <iostream>

#include "mensaje.hh"
#include "Mensaje1.hh"
#include "Valor3.hh"

int main() {

    /*
    Se utiliza el prefijo std para aceder a los
    metodos incluidos en el lenguaje
    */
    std::printf(MENSAJE);

    std::printf("%s, %i\n", MENSAJE1, VALOR3);


    /*
    Retornams el valor 0 para indicar que
    el programa se ejecuto sin errores.
    */
    return 42;
}