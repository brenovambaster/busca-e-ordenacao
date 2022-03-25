#include <iostream>
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>
#define TAM_MAX 100
using namespace std;

int imprime(int *array, int tamanho)
{
    cout << "[";
    for (int i = 0; i < tamanho; i++)
    {
        cout << array[i] << " ";
    }
    cout << "]";
}

/* Retorna o numero de acesso feito na memória */
int bubble_sort(int *array, int tamanho, int op)
{
    int mudou = true;
    int ultima_alteracao = tamanho, num_acessos = 0;
    int aux = tamanho - 1;
    while (mudou)
    {
        mudou = false;
        for (int i = 0; i <= ultima_alteracao - 2; i++)
        {
            if (array[i] > array[i + 1])
            {
                mudou = true;
                aux = i;
                swap(array[i], array[i + 1]);
                num_acessos += 3;
            }
        }
        ultima_alteracao = aux + 1;
        if (op == 1)
        {
            imprime(array, tamanho);
            cout << endl;
        }
    }
    if (op == 2)
        printf("numero de acessos:%i ", num_acessos);
    return num_acessos;
}

int teste2(int *array, int tamanho_max)
{
    /*  para cada vetor gerado, armazenar o número de acesso e a quantidade de valores no array */
    int array_num_acessos[TAM_MAX], array_qtd_valores[TAM_MAX];

    for (int i = 1; i <= tamanho_max; i++)
    {
        // gerar vetor aleatorio;
        for (int j = 0; j < i; j++)
        {
            array[j] = rand() % 1000 + 1;
        }
        cout << "array:" << i << endl;
        cout << "  array gerado:";
        imprime(array, i);
        array_num_acessos[i - 1] = bubble_sort(array, i, 0);
        array_qtd_valores[i - 1] = i;
        cout << "\n  array organizado:";
        imprime(array, i);
        cout << "\n\n";
    }

    imprime(array_num_acessos, tamanho_max);
    imprime(array_qtd_valores, tamanho_max);
}
int pior_caso(int *array, int tamanho_max)
{

    /*  para cada vetor gerado, armazenar o número de acesso e a quantidade de valores no array */
    int array_num_acessos[TAM_MAX], array_qtd_valores[TAM_MAX];

    for (int i = 1; i <= tamanho_max; i++)
    {
        // gerar vetor aleatorio;
        for (int j = 0; j < i; j++)
        {
            array[j] = tamanho_max - j;
        }
        cout << "array:" << i << endl;
        cout << "  array gerado:";
        imprime(array, i);
        array_num_acessos[i - 1] = bubble_sort(array, i, 0);
        array_qtd_valores[i - 1] = i;
        cout << "\n  array organizado:";
        imprime(array, i);
        cout << "\n\n";
    }

    imprime(array_num_acessos, tamanho_max);
    // imprime(array_qtd_valores, tamanho_max);
}
int main()
{

    int array[TAM_MAX] = {70, 1, 12, 8, 99, 72, 5, 15, 20, 91, 14, 61, 66, 41, 81, 88, 16, 21, 34, 90};

    int op;

    cout << "Digite [1] para mostrar o estado da lista a cada iteração do algoritmo" << endl;
    cout << "Digite [2] Mostrar o número de acessos à estrutura de dados" << endl;
    // cin >> op;
    op = 1;
    // bubble_sort(array, 20, 2);
    //  imprime(array, 20);
    pior_caso(array, 100);
}