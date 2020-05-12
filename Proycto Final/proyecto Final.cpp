#include <iostream>
#include <vector>

using namespace std;

vector<string> separarString(const string& stringIngresado)
{
    vector<string> separado;
    int indice = 0;

    for (int i = 0; i < (int)stringIngresado.size(); i++)
    {
        if (stringIngresado[i] == ',')
        {
            separado.push_back(string(stringIngresado, indice, i - indice));
            indice = i + 1;
        }
    }

    separado.push_back(string(stringIngresado, indice, stringIngresado.length() - indice));

    return separado;
}

// Función para determinar si entre dos vectores de strings, hay por lo menos 2 elementos comunes.
bool existenElementosSimilares(vector<string> lista1, vector<string> lista2)
{
    int elementosSimilares = 0;

    for (int i = 0; i < (int)lista1.size(); i++)
    {
        for (int j = 0; j < (int)lista2.size(); j++)
        {
            if (lista1[i] == lista2[j])
            {
                elementosSimilares++;
            }
        }
    }

    if (elementosSimilares >= 2)
    {
        return true;
    }

    else
    {
        return false;
    }
}

vector<string> encontrarElementosComunes(vector<string> lista1, vector<string> lista2)
{
    vector<string> unidos;

    for (int i = 0; i < (int)lista1.size(); i++)
    {
        for (int j = 0; j < (int)lista2.size(); j++)
        {
            if (lista1[i] == lista2[j])
            {
                unidos.push_back(lista1[i]);
            }
        }
    }

    return unidos;
}

// ordenar por medio del metodo burbuja
vector<string> ordenar(vector<string> lista1, vector<string> lista2)
{
    int ordenar = 0;
    string aux;
    vector<string> ordenado;

    for (int i = 0; i < (int)lista1.size(); i++)
    {
        for (int j = 0; j < (int)lista2.size(); j++)
        {
            if (lista1[i] > lista2[j])
            {
                aux = lista1[i];
                lista1[i] = lista2[j];
                lista2[j] = aux;
            }
        }
    }

    return ordenado;
}


// Struct que representa los productos más populares comprados juntos
struct Ventas
{
    string articulos;
    int compras = 1;
};



vector<Ventas> contarlos(vector<string> productos) {
    Ventas prods;
    int contador = 1;
    vector<Ventas> adquiridos;
    for (int i = 0; i < productos.size(); i++) {
        for (int j = 0; j < productos.size(); j++) {
            if (productos[i] == productos[j] && i != j) {
                contador++;
            }
        }
        prods.compras = contador;
        prods.articulos = productos[i];
        adquiridos.push_back(prods);
        contador = 1;
    }

    Ventas auxiliar;
    for (int i = 0; i < adquiridos.size(); i++) {
        int imin = i;
        for (int j = i + 1; j < adquiridos.size(); j++) {
            if (adquiridos[j].compras > adquiridos[imin].compras) {
                imin = j;
            }
        }
        auxiliar = adquiridos[i];
        adquiridos[i] = adquiridos[imin];
        adquiridos[imin] = auxiliar;
    }




    return adquiridos;
}



// Método que toma un vector de vector de strings y los junta en un solo vector de strings.
vector<string> juntarStrings(vector<vector<string>> vectorAJuntar)
{
    vector<string> nuevoVector;

    for (int i = 0; i < (int)vectorAJuntar.size(); i++)
    {
        string lista = "";

        for (int j = 0; j < (int)vectorAJuntar[i].size(); j++)
        {
            lista += vectorAJuntar[i][j];

            if (j != (int)vectorAJuntar[i].size() - 1)
            {
                lista += ",";
            }
        }

        nuevoVector.push_back(lista);
    }

    return nuevoVector;
}

int main()
{
    vector<string> v;
    vector<vector<string>> v_nuevo;
    int num;

    cout << "ingrese la cantidad de listas: ";
    cin >> num; // aqui se le pregunta la usuario cuantas listas va a ingresar

    for (int i = 0; i < num; i++)
    {
        string numero;
        cout << "ingrese la lista "<< i+1 << ": ";
        cin >> numero; // aqui es donde se ingresan las listas.

        v = separarString(numero);

        v_nuevo.push_back(v);
    }

    //comparar

    vector<vector<string>> v_nuevo2;

    // Ciclo doble para determinar si existen elementos comunes entre dos vectores.
    // Se comienza con el primer vector, el cual es comparado con todos los demás, luego,
    // el segundo se compara con todos los demás, excepto el primero y así, eventualmente.
    for (int i = 0; i < (int)v_nuevo.size(); i++)
    {
        for (int j = i + 1; j < (int)v_nuevo.size(); j++)
        {
            // Condición que determina si existen por lo menos 2 elementos comunes entre los vectores.
            if (existenElementosSimilares(v_nuevo[i], v_nuevo[j]))
            {
                v_nuevo2.push_back(encontrarElementosComunes(v_nuevo[i], v_nuevo[j]));
            }
        }
    }

    vector<string> productosComprados = juntarStrings(v_nuevo2);

    std::vector<Ventas> productosOrdenados = contarlos(productosComprados);

    cout << endl << endl;

    for (size_t i = 0; i < productosOrdenados.size(); i++)
    {
        if (productosOrdenados.size()==2){
          std::cout << "Los productos: " << productosOrdenados[i].articulos << " fueron comprados juntos " << (productosOrdenados[i].compras + 1) << " veces." << std::endl;  
        }
        
        else{
            std::cout << "Los productos: " << productosOrdenados[i].articulos << " fueron comprados juntos " << productosOrdenados[i].compras << " veces." << std::endl;
        
        }
    }
    
}

