
#include <vector>


#include<iostream>
#include <vector>
using namespace std;

/*
Laboratorio #9
Informatica II
Fecha de entrega: 23 de Abril, 2020 @ 11:59pm
*/

class LinkedList {
    
   LinkedList(const int valor)
    {
        value = valor;
        rest = nullptr;
    }

    public:
    /*
    Problema #1 (20%): Definir el metodo push que agrega un elemento al final de la lista encadenada.
    */
    struct Nodo{
        int elemento;
        Nodo *siguiente;
    };
    
    
      void push(Nodo *&LinkedList, int valor){
        Nodo *nuevo_nodo = new Nodo(); 
        nuevo_nodo -> elemento = valor;
        
        Nodo *aux1 = LinkedList;
        Nodo *aux2;
        
        aux2 -> siguiente = nuevo_nodo;
        nuevo_nodo -> siguiente = aux1;
    };
    
 
    

    /*
    Problema #2 (20%): Definir el metodo "toVector" el cual debe retornar un vector
    con los mismos elementos que esta lista encadenada.
    */
      vector<int> toVector(){
    	vector<int>lista; 
              
          LinkedList *aux = this;
		
          for(int i; i < lista.size(); i++){
          
              lista.push_back(aux->value);
              aux = aux->rest;
          }
          
          return lista;
	}
    

    /*
    Problema #3 (20%): Definir el "operador []" para la lista encadenada. Este operador debe retornar
    una referencia al indice dado como parametro. Puede asumir que los indices siempre son
    validos.
    https://en.cppreference.com/w/cpp/language/operators#Array_subscript_operator
    */
    int& operator[](Nodo *vector, int valor){
        Nodo *actual = new Nodo ();
        actual = lista;
        while ((actual != Null) && (actual->dato <= valor) ){
            return actual -> dato == valor;
        }
    }
        
    /*
    Problema #4: Definir el destructor para esta lista encadenada. Asegurese que
    todos los valores de la lista sean correctamente eliminados siguiendo
    los punteros que sean necesarios.
    https://en.cppreference.com/w/cpp/language/destructor
    */
    ~LinkedList(){
    	value = 0;
        delete rest;
	};

    /*
    Problema #5: Definir el "operador =" tal que copie todos los valores de la lista
    actual a la nueva lista. Asegurese que:
     * Se crea una nueva copia de cada uno de los elementos de la lista con este operador.
     * Se libera la memoria ocupada por los valores anteriores
    https://en.cppreference.com/w/cpp/language/copy_assignment
    */
    LinkedList& operator=(const LinkedList& otra){
        
        int contador;
        while(valor != null){
            contador++;
            otra[contador] = valor_nuevo[contador];
        }
        
        return valor_nuevo;
    
    }

    private:
    int value;

    /*
    Cuando la lista tiene mas valores, esto es un puntero a una instancia de LinkedList,
    de lo contrario, tiene el valor de "nullptr"
    */
    LinkedList* rest;
};

int main () {
    
    
};
