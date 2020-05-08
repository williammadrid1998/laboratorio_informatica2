#include <iostream>
#include <vector>

using namespace std;



//Ejercicio #1
class Coleccion {
    public:
    
    Coleccion(){};
    
    virtual int numEl() = 0;
    
    virtual void agregar(int num) = 0;
    
    virtual int& operator[](const int i) = 0;
    
};


//Ejercicio #2
class ColeccionVector : public Coleccion {
    
    public:
    ColeccionVector() : Coleccion(){};
    
    virtual int numEl() override{
        return v.size();        
    }
    
    virtual void agregar(int num) override{
        v.push_back(num);
    } 
    
    virtual int& operator[](const int i) override{
            return v[i];
    }
    
    private:
    vector<int> v;
};



//Ejercicio #3
class ColeccionLinkedList : public Coleccion {
    
    public:
    ColeccionLinkedList() : Coleccion (){
        value = 0;
        rest = nullptr;
    }
    
    virtual int numEl() override{
        ColeccionLinkedList* lista = (ColeccionLinkedList*)malloc(sizeof(ColeccionLinkedList));
        lista->value = value;
        lista->rest = rest;
	    int contador = 1;
	    if (lista->value == 0 && lista->rest == nullptr) {
		    return 0;
	    }
    	else {
		    while (lista->rest != nullptr) {
			    contador++;
			    lista = lista->rest;
		    }
		    return contador;
	    }
    }
    
    virtual void agregar(int valor) override{
        if(value == 0){
            value = valor;
        }
        else{
        ColeccionLinkedList *newRest = new ColeccionLinkedList;
        newRest->value = valor;
        newRest->rest = nullptr;
        
        ColeccionLinkedList* lista = this;
        
        while(lista->rest != nullptr){
            lista = lista->rest;
        }
        
        lista->rest = newRest;
        
        }
    }
    
    
    virtual int& operator[](const int indice) override{
        
        ColeccionLinkedList* lista = this;
        
        for(int i = 0; i<indice; i++){
            lista = lista->rest;
        }
        
        return lista->value;
    }
    
    
    private:
    int value;
    ColeccionLinkedList* rest;
    
    
};


//Ejercicio #4
//M�todo burbuja
void ordenar(Coleccion& valores){
    
    int aux;
    
    for (int i=0; i<valores.numEl() - 1; i++){
        for (int j = i + 1; j<valores.numEl(); j++){
            if(valores[i]>valores[j]){
                aux = valores[i];
                valores[i] = valores[j];
                valores[j] = aux;
            }
        }
    }
    
};




int main()
{
    
    //Pruebas
    
    //Ejercicio #2
    ColeccionVector v;
    cout<<"El vector tiene "<<v.numEl()<<" elementos"<<endl;
    v.agregar(2);
    v.agregar(3);
    v.agregar(1);
    cout<<"El valor en el �ndice 1 es: "<<v[1]<<endl;
    v[1]=4;
    cout<<"El valor en el �ndice 1, luego de modificarse es: "<<v[1]<<endl;
    cout<<"El vector ahora tiene "<<v.numEl()<<" elementos"<<endl;
    cout<<endl;
    
    
    //Ejercicio #3
    ColeccionLinkedList l;
    cout<<"La lista tiene "<<l.numEl()<<" elementos"<<endl;
    l.agregar(6);
    l.agregar(7);
    l.agregar(5);
    cout<<"El valor de la lista en el �ndice 1 es: "<<l[1]<<endl;
    l[1]=8;
    cout<<"El valor en el �ndice 1, luego de modificarse es: "<<l[1]<<endl;
    cout<<"La lista ahora tiene "<<l.numEl()<<" elementos"<<endl;
    cout<<endl;
    
    

    //Ejercicio #4
    cout<<"Antes de ordenarse, el primer valor del vector es "<<v[0]<<endl;
    ordenar(v);  
    cout<<"Luego de ordenarse, el primer valor del vector es "<<v[0]<<endl;
    cout<<endl;
    
    cout<<"Antes de ordenarse, el primer valor de la lista es "<<l[0]<<endl;
    ordenar(l);
    cout<<"Luego de ordenarse, el primer valor de la lista es "<<l[0]<<endl;

    return 0;
}

