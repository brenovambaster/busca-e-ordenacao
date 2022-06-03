#include <iostream>
#include <vector>   // std::vector
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <algorithm>

using namespace std;
int partition(int *v, int inicio, int fim)
{
    int pivo = v[fim];
    int i = inicio;
    for (int j = inicio; j <= fim - 1; j++)
    {
        if (v[j] <= pivo)
        {

            int aux;
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
        }
    }
    int aux = v[i];
    v[i] = v[fim];
    v[fim] = aux;
    return i;
}

void quicksort(int *v, int inicio, int fim)
{
    int pivo;
    if (inicio < fim)
    {
        pivo = partition(v, inicio, fim);
        quicksort(v, inicio, pivo - 1);
        quicksort(v, pivo + 1, fim);
    }
}

int main()
{
    // int vetor[100] = {80, 11, 10, 8, 9, 7, 50, 13, 25, 91, 16, 611, 666, 412, 810, 188, 164, 21, 34, 90};
    int vetor[100] = {70, 1, 12, 8, 99, 72, 5, 15, 20, 91, 14, 61, 66, 41, 81, 88, 16, 21, 34, 90};
    //  int vetor[100] = {70, 10, 12, 8, 92, 72, 5, 17, 26, 92, 14, 65, 16, 45, 84, 88, 16, 1, 35, 91};

    quicksort(vetor, 0, 20);

    for (int i = 0; i < 20; i++)
    {
        cout << vetor[i] << "|";
    }
    return 0;
}