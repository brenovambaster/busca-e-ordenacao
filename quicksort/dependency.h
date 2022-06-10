#ifndef DEPENDENCY_H
#define DEPENDENCY_H
#include <iostream>
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <algorithm>
#include <tuple>

#define MAX_TAM 100
#define MSTR_ESTADO 0 // Mostrar estado da lista a cada interação

using namespace std;

void print_array(int *array, unsigned tamanho)
{
    // cout << "\nEstado do array\n";
    cout << "\n[ ";
    for (int i = 0; i < tamanho; i++)
    {
        cout << array[i] << " ";
    }
    cout << " ]\n";
}

#endif