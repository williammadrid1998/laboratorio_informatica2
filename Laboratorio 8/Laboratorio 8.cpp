

#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <string>
using namespace std;
//Ejercicio #1 
float parseFloat(const string& real) {

    
    float resultado = strtof(real.c_str(), nullptr);

    return resultado;
}

vector<string> separar(string str, char separador = ',') {

	int inicial = 0;
	int contador = 0;
	string separada;
	vector<string> resultados;

	while (contador >= 0) {
		contador = str.find(separador, inicial);
		separada = str.substr(inicial, contador - inicial);
		inicial = contador + 1;
		resultados.push_back(separada);
	}

	return resultados;
}
class Vector3d {

public:

	Vector3d(string coordenadas) {
		vector<string> coords = separar(coordenadas);//Primero separa el vector en 3 strings

		
		x = parseFloat(coords[0]);
		y = parseFloat(coords[1]);
		z = parseFloat(coords[2]);
	}



	//Problema #3: calcula la distancia entre el vector y otro vector que toma como parámetro
	float distancia(Vector3d otro) {
		float xx = pow((x - otro.x), 2);
		float yy = pow((y - otro.y), 2);
		float zz = pow((z - otro.z), 2);

		return sqrt(xx + yy + zz);
	}

	//getters, definidos para hacer las pruebas después
	float getX() {
		return x;
	}
	float getY() {
		return y;
	}
	float getZ() {
		return z;
	}


private:

	//Variables de la clase
	float x;
	float y;
	float z;
};






int main()
{
	//Ejercicio #4

	vector<Vector3d> vectores;//Arreglo con todos los vectores que se ingresarán
	string numeros;//parametro del Vector3d
	float distanciaTotal = 0;
	int contador = 0;

	cout << "Ingrese los vectores de 3 dimensiones (x,y,z) que desee:\n";

	while (numeros != "\n") {
		getline(cin, numeros);

		if (!numeros.empty()) {
			vectores.push_back(Vector3d(numeros));
			contador++;
		}
		else {
			break;
		}
	}
	if (vectores.empty()) {
		distanciaTotal = 0;
	}
	else {
		for (int i = 0; i < contador - 1; i++) {

			distanciaTotal = distanciaTotal + vectores[i].distancia(vectores[i + 1]);
		}
	}

	cout << "La distancia total entre los vectores es: " << distanciaTotal;


	char x;
	std::cin >> x;
}

