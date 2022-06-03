#include "dependency.h"
#include "lista.h"
#include <time.h>

// int vetor[MAX_TAM] = {80, 11, 10, 8, 9, 7, 50, 13, 25, 91, 16, 611, 666, 412, 810, 188, 164, 21, 34, 90};
int vetor[MAX_TAM] = {70, 1, 12, 8, 99, 72, 5, 15, 20, 91, 14, 61, 66, 41, 81, 88, 16, 21, 34, 90};
// int vetor[MAX_TAM] = {70, 10, 12, 8, 92, 72, 5, 17, 26, 92, 14, 65, 16, 45, 84, 88, 16, 1, 35, 91};

int main()
{
    Lista l1;
    // tamanho de cada vetor
    for (int i = 1; i <= MAX_TAM; i++)
    { // construo vetor do tamanho i;
        cout << "TAMANHO: " << i << endl;
        for (int j = 0; j < i; j++)
        {
            l1.insere(j, (rand() % 1000 + 1));
        }
        l1.imprime();
        printf("\n");
        l1.quicksort(l1.numbers, 0, l1.tamanho - 1);
        printf("\nLista ordenada: \n");
        l1.imprime();
        l1.limpa();
        printf("\n---------------------------------------\n");
    }

    /*
     l1.imprime();
     printf("\n");
     l1.quicksort(l1.numbers, 0, l1.tamanho);
     printf("\nLista ordenada: \n");
     l1.imprime();
     l1.limpa(); */
}
