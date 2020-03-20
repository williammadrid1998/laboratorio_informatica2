#include <iostream>
#include <math.h>

using namespace std;



struct Lista
{
    int valor;
    Lista* resto;
};

/*
Problema 1 (10%)
Defina la funcion "crear" que toma un arreglo de numeros (y su tamaño).
Esta funcion debe retornar un puntero a una "Lista" que tiene los
valores que se le han pasado en el arreglo.
*/

Lista* crear(const int* valores, const int cantidad) {

    Lista* lista = (Lista*)malloc(sizeof(Lista) * cantidad);
    if (cantidad == 0) {
        return nullptr;
    }
    else {
        for (int i = 0; i < cantidad; i++) {
            lista[i].valor = valores[i];

            if (i <= cantidad - 2) {
                lista[i].resto = &lista[i + 1];
            }
            else {
                lista[cantidad - 1].resto = nullptr; 
            }
        }
    }
    return lista;
}

/*
Problema 2
Defina la funcion "eliminar" esta funcion acepta un puntero a una
"Lista" y debe eliminar esta lista de memoria. Asegurese que sean
eliminados *todos* los elementos de la lista, no solo el primero.
Tambien debe asegurares que toda la memoria ocupada por la lista
sea liberada.
*/

void eliminar(Lista* valores) {//Elimina una lista

    while (valores != nullptr) {
        delete& valores->valor;//Elimina el puntero
        valores = valores->resto;
    }
    delete valores;
}

/*
Promblema 3
Defina la funcion "unir". Esta funcion acepta dos instancias de
"Lista" y debe unir la segunda al final de la primera. En otras palabras,
el ultimo "resto" de la primera lista debe apuntar a la segunda lista
en vez de apuntar a "nullptr"
*/

void unir(Lista* primera, Lista* segunda) {

    Lista* p;
    if (primera == nullptr) {
        primera = segunda;
    }
    else {
        if (segunda != nullptr) {
            p = primera;
            while (p->resto != nullptr) {
                p = p->resto;
            }
            p->resto = segunda;
        }
    }
}
/*
Problema 4 (10%)
Defina la funcion "longitud" que determina el numero de elementos
que tiene la lista que se ha pasado como parametro.
*/

int longitud(const Lista* valores) {
    int contador = 1;
    if (valores->resto == nullptr) {
        return 0;
    }

    else {

        while (valores->resto != nullptr) {
            contador++;
            valores = valores->resto;
        }

        return contador;
    }
}
/*
Problema 5 (20%)
Defina la funcion "lookup" que acepta un inidce (0,1,2,ect) y busca
el elemento que esta ubicado en dicho indice. Si el elemento existe,
se debe almacenar en la variable "resultado" que se dio como parametro
y retornar "true", de lo contrario, retornar "false".
*/
bool lookup(const Lista* valores, int indice, int& resultado) {
    int contador = longitud(valores);


    if (indice >= contador) {
        return false;
    }
    else {
        while (0 < indice) {
            indice--;
            valores = valores->resto;
        }
        resultado = valores->valor;
        return true;
    }
}

/*
Problema 6 (20%)
Defina un struct llamado "Triangulo" para representar triangulos
de *dos dimensiones* (triangulos planos). Luego cree una nueva
lista llamada ListaTriangulos para representar una lista que tiene
triangulos.
*/

struct Triangulo {
    int p1[2];
    int p2[2];
    int p3[2];
};

struct ListaTriangulos {
    Triangulo primero;
    ListaTriangulos* resto;
};

/*
Problema 7 (10%)
Defina una funcion llamada "area" que dado un triangulo, calcula
el area de dicho triangulo.
*/

float lado1(Triangulo triangulo) {//Longitud lado 1

    float x2 = pow((triangulo.p1[0] - triangulo.p2[0]), 2);
    float y2 = pow((triangulo.p1[1] - triangulo.p2[1]), 2);

    float resultado = sqrt(x2 + y2);

    return resultado;
}

float lado2(Triangulo triangulo) {//Longitud lado 2

    float x2 = pow((triangulo.p1[0] - triangulo.p3[0]), 2);
    float y2 = pow((triangulo.p1[1] - triangulo.p3[1]), 2);

    float resultado = sqrt(x2 + y2);

    return resultado;
}

float lado3(Triangulo triangulo) {//Longitud lado 3

    float x2 = pow((triangulo.p2[0] - triangulo.p3[0]), 2);
    float y2 = pow((triangulo.p2[1] - triangulo.p3[1]), 2);

    float resultado = sqrt(x2 + y2);

    return resultado;
}


float area(const Triangulo& triangulo) {
    //Utilizando fórmula de Herón (área de un triangulo con la longitud de los lados)

    float s = (lado1(triangulo) + lado2(triangulo) + lado3(triangulo)) / 2;

    float areat = sqrt(s * (s - lado1(triangulo)) * (s - lado2(triangulo)) * (s - lado3(triangulo)));

    return areat;
}

/*
Problema 8 (10%)
Defina la funcion "areaPromedio" que dada una lista de triangulos
calcula el area promedio de esos triangulos.
*/

int contarTriangulos(const ListaTriangulos* valores) {
    int contador = 1;
    if (valores->resto == nullptr) {
        return 0;
    }
    else {

        while (valores->resto != nullptr) {
            contador++;
            valores = valores->resto;
        }

        return contador;
    }
}

float areaPromedio(const ListaTriangulos* triangulos) {
    int cantidad = contarTriangulos(triangulos);

    int sumas = 0;

    for (int i = 0; i < cantidad; i++) {
        sumas = sumas + area(triangulos->primero);
        triangulos = triangulos->resto;
    }

    int promedio = sumas / cantidad;
    return promedio;
}


int main()
{

    Lista lista;
    lista.valor = 1;
    lista.resto = (Lista*)malloc(sizeof(Lista));

    lista.resto->valor = 2;
    lista.resto->resto = nullptr;

    cout << "Hello World: " << lista.valor << " y " << lista.resto->valor;