#ifndef DEPENDENCY_H
#define DEPENDENCY_H
#include <iostream>
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <algorithm>
#include <tuple>

#define MAX_TAM 100
unsigned TEST = 1;

using namespace std;

void print_array(int *array, unsigned tamanho)
{
    cout << "\n Estado do array\n";
    cout << "[ ";
    for (int i = 0; i < tamanho; i++)
    {
        cout << array[i] << " ";
    }
    cout << " ]\n";
}

#endif