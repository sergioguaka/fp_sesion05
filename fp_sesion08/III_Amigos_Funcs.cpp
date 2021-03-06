/*
Sergio Campoy Maldonado
Fundamentos de Programaci�n
1�C

Programa que:
	1�) Pide dos n�meros enteros y comprueba si son n�meros amigos
	2�) Pide un n�mero entero (n) y comprueba si hay alg�n n�mero amigo en el
		 intervalo centrado en n y de radio n / 3
*/

#include <iostream>

#include <cmath>

using namespace std;


enum class Amigos
				{tiene, tiene_fuera, no_tiene};

/******************************************************************************/
//	Funci�n:		LeeNatural
//	Recibe:		string cadena: mensaje que env�a al usuario
//	Devuelve:	int n: numero natural (entero y positivo)
/******************************************************************************/

int LeeNatural (string cadena) {
	
	//	Declaraci�n de variables
	int n;
	
	//	Entrada de datos
	do {
		cout << cadena;
		cin >> n;
	} while (n <= 0);
	
	//	Return
	return n;
}

/******************************************************************************/
//	Funci�n:		Suma_Divisores_Propios
//	Recibe:		int n: Numero al cual se calcular� la suma de sus divisores
//	Devuelve:	int suma: Suma de los divisores propios de "n"
/******************************************************************************/

int Suma_Divisores_Propios (int n) {
	
	//	Declaraci�n de constantes
	const int TOPE = floor (sqrt (n));
	
	//	Declaraci�n de variables
	int suma = 0;
	double raiz = sqrt (n);
	
	//	C�lculos
	for (int i = 2; i <= TOPE; i++) {
		if (n % i == 0) {
			suma += i + n/i;
		}
	}
	
	if (raiz == TOPE)
	suma -= TOPE;
	
	
	return suma;
}

/******************************************************************************/
//	Funci�n:		Son_Amigos
//	Recibe:		int a: candidato a n�mero amigo n�1
//					int b: candidato a n�mero amigo n�2
//	Devuelve:	TRUE: a y b son n�meros amigos
//					FALSE: a y b no son n�meros amigos
/******************************************************************************/

bool Son_Amigos (int a, int b) {
	bool amigos_ab = (Suma_Divisores_Propios (a) + 1 == b);
	bool amigos_ba = (Suma_Divisores_Propios (b) + 1 == a);
	
	return (amigos_ab && amigos_ba);
}



int main (void) {
	//	Declaraci�n de variables
	int a, b;
	
	//	Entrada de datos
	a = LeeNatural ("Introduce un numero natural: ");
	b = LeeNatural ("Introduce otro numero natural: ");
	
	//	Comprobaci�n y salida
	if (Son_Amigos (a, b)) {
		cout << endl
			  << a << " y " << b << " son numeros amigos"
			  << endl << endl;
	}
	else {
		cout << endl
			  << a << " y " << b << " no son numeros amigos"
			  << endl << endl;
	}
	
	cout << endl;
	
/******************************************************************************/
/*******************************Segundo apartado*******************************/
/******************************************************************************/

	//	Declaraci�n de variables
	int n, radio, posible_amigo;
	Amigos amigo;
	
	//	Entrada de datos
	n = LeeNatural ("Introuce otro numero natural: ");
	
	//	C�lculos
	radio = n / 3;

	posible_amigo = Suma_Divisores_Propios (n) + 1;
	
	if (Son_Amigos (n, posible_amigo))
		if ((posible_amigo >= n - radio) && (posible_amigo <= n + radio))
			amigo = Amigos::tiene;
		else
			amigo = Amigos::tiene_fuera;
	else
		amigo = Amigos::no_tiene;
	
	
	//	Salida
	switch (amigo) {
		case Amigos::tiene:
			cout << endl
				  << n << " y " << posible_amigo << " son numeros amigos"
				  << endl << endl;
			break;
		
		case Amigos::tiene_fuera:
			cout << endl
				  << n << " no tiene numeros amigos dentro del rango."
				  << endl << endl;
			break;
			
		case Amigos::no_tiene:
			cout << endl
				  << n << " no tiene numeros amigos."
				  << endl << endl;
	}
	
	return 0;
}
