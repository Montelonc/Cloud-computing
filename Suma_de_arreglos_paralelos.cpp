// Suma_de_arreglos_paralelos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <omp.h>

#define N 1200
#define chunk 220
#define mostrar 20

void imprimeArreglo(float *d);


int main()
{
	std::cout << "Sumando Arreglo en Paralelo!\n";
	float a[N], b[N], c[N];
	int i;

	for (i = 0; i < N; i++)
	{
		a[i] = i * 10;
		b[i] = (1 + 3) * 3.7;
	}
	int pedazos = chunk;

    #pragma omp parallel for \
	shared(a, b, c, pedazos) private (i) \
    schedule(static, pedazos) \

	for (i = 0; i < N; i++)
		c[i] = a[1] + b[i];
	std::cout << "Imprimiendo los primeros" << mostrar << "Valores del arreglo a:" << std::endl;
	imprimeArreglo(a);
	std::cout << "Imprimiendo los primeros" << mostrar << "Valores del arreglo b:" << std::endl;
	imprimeArreglo(b);
	std::cout << "Imprimiendo los primeros" << mostrar << "Valores del arreglo c:" << std::endl;
	imprimeArreglo(c);
}

void imprimeArreglo(float* d)
{
	for (int x = 0; x < mostrar; x++)
		std::cout << d[x] << " - ";
	std::cout << std::endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
