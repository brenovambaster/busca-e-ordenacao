#ifndef LISTA_BROKEN_H_INCLUDED
#define LISTA_BROKEN_H_INCLUDED
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

#define MAX_INTEIROS 100

class ListaBroken
{

public:
    int size = 0;
    int numbers[MAX_INTEIROS];

    ListaBroken()
    {
        size = 0;
    }

    ~ListaBroken()
    {
    }

    void insere(int posicao, int inteiro)
    {

        if (posicao > size)
        {
            cout << "Posicao incorreta" << endl;
            return;
        }

        if (MAX_INTEIROS == size)
        {
            cout << "Não há mais espaco na lista" << endl;
            return;
        }

        for (int i = size; i > posicao; i--)
        {
            numbers[i] = numbers[i - 1];
        }

        numbers[posicao] = inteiro;
        size++;
    }
    void limpa()
    {
        size = 0;
    }

    int merge_sort()
    {

        ListaBroken listaFinal;

        for (int i = 0; i < size; i++)
        {

            listaFinal.insere(i, numbers[i]);
        }

        return merge_sort(0, size, listaFinal.numbers, numbers);
    }

    int merge_sort(int inicio, int fim, int lista1[], int lista2[])
    {
        int qtd_acesso = 0;
        if (1 < fim - inicio)
        {

            int meio = (inicio + fim) / 2;

            merge_sort(inicio, meio, lista2, lista1);
            merge_sort(meio, fim, lista2, lista1);
            qtd_acesso += merge(inicio, meio, fim, lista1, lista2);
        }
        return qtd_acesso;
    }

    int merge(int inicio, int meio, int fim, int lista1[], int lista2[])
    {
        int qtd_acesso = 0;
        int inicio_copia = inicio;
        int meio_copia = meio;

        for (int i = inicio; i < fim; i++)
        {

            if ((inicio_copia < meio) && ((meio_copia >= fim) || (lista1[inicio_copia] < lista1[meio_copia])))
            {
                lista2[i] = lista1[inicio_copia];
                inicio_copia += 1;
                qtd_acesso++;
            }
            else
            {
                lista2[i] = lista1[meio_copia];
                meio_copia += 1;
                qtd_acesso++;
            }
        }
        return qtd_acesso;
    }

    void imprime()
    {

        for (unsigned u = 0; u < size; u++)
            cout << numbers[u] << "| ";
        cout << endl;
    }
};

#endif