
#include <iostream>

using namespace std;

// Ejercicio # 1

void imprimirBinario(int numero) {
    
    

    for (int contador = 0; contador < 32; contador++){
        if ((numero % 2) == 0 ) {
            printf("%i \n", 0);
            numero = numero / 2;
        }
        else if ((numero % 2) != 0) {
            printf("%i \n", 1);
            numero = (numero - 1) / 2;
        }
       
    }

    
}

// Ejercicio # 2 
bool existe(char valor, long numero) {
    int contador = 0; 

    while (contador < 64)
    {
        if ((valor & numero)) {
            return true;
        }
        else {
            contador = contador + 1;
        }
    }

    return false; 
}



// Ejercicio # 3 
short conteo(long numero) {

    int contador1 = 0;

    for (int contador = 0; contador < 32; contador++) {

        if ((numero % 2) == 0) {
            
            numero = numero / 2;
        }
        else if ((numero % 2) != 0) {
            
            numero = (numero - 1) / 2;
            
            contador1 = contador1 + 1;            
        }

        
    }
    
    return contador1;

}

// Ejercicio # 4 
int andOr(int valor1, int valor2) {

    int numero = 0;
     
    
        for (int contador = 0; contador < 32; contador++) {

            if ((contador % 2) == 0) {

                numero = valor1 & valor2;
            }
            else if ((contador % 2) != 0) {

                numero = valor1 | valor2;
            }



        }

    
    return numero ;
}




//Ejercicio # 5 
int codificar(char c1, char c2, char c3, char c4) {
    int resultado = 0;
        resultado = resultado << 8  | c1;
        resultado = resultado << 8 | c2;
        resultado = resultado << 8 | c3;
        resultado = resultado << 8 | c4;

        return resultado; 
    

    

}

int main() 
{
    imprimirBinario(25);
    std::cout << std::boolalpha << existe(9, 10);
    printf("%i \n", conteo(25));
    printf("%i \n", codificar(25,8,12,4));
    printf("%i \n", andOr(6,10));
    
   
    
    return 0;
}
    


