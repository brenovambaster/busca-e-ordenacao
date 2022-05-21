#include <iostream>
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>
#include "ListaBroken.h"

#define N 100

int imprime(int *lista, int tamanho)
{

    for (int i = 0; i < tamanho; i++)
    {
        cout << lista[i] << " ";
    }
}

int main()
{
    int tamanho_lista[N];
    int qtd_acesso[N];
    int val_aleatorio = 0;
    ListaBroken lista1;
    for (int i = 0; i <= N; i++)
    {

        for (int j = 0; j < i; j++)
        {
            val_aleatorio = rand() % 1000 + 1;
            lista1.insere(j, val_aleatorio);
        }

        cout << "Lista gerada  tamanho: " << lista1.size << endl;
        lista1.imprime();

        cout << "Lista ordenada: \n";
        qtd_acesso[i - 1] = lista1.merge_sort();
        lista1.imprime();

        cout << "Qtd acesso: " << qtd_acesso[i - 1] << endl;
        tamanho_lista[i] = i;

        cout << "----------------\n";
        lista1.limpa();
        lista1.~ListaBroken();
    }
    imprime(tamanho_lista, N);
    cout << endl;
    imprime(qtd_acesso, N);
}