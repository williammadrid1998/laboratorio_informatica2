


#include <iostream>

using namespace std;


struct mapa {
    bool** posiciones;
    int ancho;
    int largo;
};

struct vector {
    int x;
    int y;
};





// Ejercicio #1

class Vehiculo {

    private:// atributos internos de la clase Vehiculos
        vector velocidad;
        vector posicion;
        mapa mapa1;


    public:
        Vehiculo(mapa _mapa, vector _posicionInicial) { // Constructor Vehiculo, este recibe los parametros mapa y posicion inicial del vehiculo.
            
            posicion = _posicionInicial;

            mapa1 = _mapa;

            velocidad = vector{ 0,0 };
                    
        }

    // Ejercicio #2
        void estadoActual() { // metodo que imprime la el estado actual del vehiculo

            printf("El estado actual del vehiculo es: ");
            printf(" Posicion (%i, %i)  Velocidad (%i,%i) \n ", posicion.x, posicion.y, velocidad.x, velocidad.y);
        }

    // Ejercicio #3
        void acelerar(vector vectorNuevo){ // este metodo recibe un nuevo vector y se lo suma a la velocidad

            velocidad.x = velocidad.x + vectorNuevo.x;
            velocidad.y = velocidad.y + vectorNuevo.y;
             
        }

    // Ejercicio #4
        bool validarAvance(){
            vector suma;
            suma.x = posicion.x + velocidad.x;
            suma.y = posicion.y + velocidad.y;

            if (suma.x <= mapa1.ancho && suma.y <= mapa1.largo) {
                return true;
            }


        
        }

        //Problema 5
        void avanzar(int tiempo) {
            for (int i = 0; i < tiempo; i++) {

                posicion.x = posicion.x + velocidad.x;
                posicion.y = posicion.y + velocidad.y;

                if (posicion.x > mapa1.ancho) {

                    posicion.x = 0 + velocidad.x;
                }
                else if (posicion.y > mapa1.largo) {
                    posicion.y = 0 + velocidad.y;
                }
            }


        }
};

int main()
{
    //Para prueba de funcionamiento
    mapa _mapa2;
    _mapa2.posiciones;
    _mapa2.ancho = 3;
    _mapa2.largo = 3;

    vector _posicionInicial;
    _posicionInicial.x = 0;
    _posicionInicial.y = 0;

    vector aceleracion;
    aceleracion.x = 1;
    aceleracion.y = 1;

    //Prueba problema #1 
    Vehiculo vehiculo1 = Vehiculo(_mapa2, _posicionInicial);// Aqui se crea el objeto vehiculo1

    //Prueba problema #2 
    vehiculo1.estadoActual();//Imprime las condiciones actuales del vehículo

    //Prueba problema #3
    vehiculo1.acelerar(aceleracion);
    vehiculo1.estadoActual();
    //Prueba problema #4
    mapa _mapa3;
    _mapa3.posiciones;
    _mapa3.ancho = 5;
    _mapa3.largo = 7;

    Vehiculo vehiculo2 = Vehiculo(_mapa3, _posicionInicial);// Aqui se crea el objeto vehiculo2
    vehiculo2.validarAvance();

    //Prueba problema #5
    vehiculo1.avanzar(5);
    vehiculo1.estadoActual();

    vehiculo1.avanzar(7);
    vehiculo1.estadoActual();

    return 0;
}

