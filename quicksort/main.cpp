#include "dependency.h"
#include "lista.h"
#include <time.h>
int array_num_acesso[MAX_TAM];
// int vetor[MAX_TAM] = {80, 11, 10, 8, 9, 7, 50, 13, 25, 91, 16, 611, 666, 412, 810, 188, 164, 21, 34, 90};
// int vetor[MAX_TAM] = {70, 10, 12, 8, 92, 72, 5, 17, 26, 92, 14, 65, 16, 45, 84, 88, 16, 1, 35, 91};

void random_list()
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
        cout << "lista gerada: ";
        l1.imprime();
        printf("\n");
        array_num_acesso[i - 1] = l1.quicksort(l1.numbers, 0, l1.tamanho - 1);
        printf("\n** Lista ordenada: **\n");
        l1.imprime();
        cout << "\nQtd acesso: " << array_num_acesso[i - 1] << "\n";
        l1.limpa();
        printf("\n---------------------------------------\n");
    }
};

void pior_caso()
{
#define tam_vetor 100
    Lista l1;
    int vetor[tam_vetor];
    unsigned aux = 0;

    // criar vetor decrescente
    for (unsigned i = tam_vetor; i >= 1; i--)
    {
        vetor[i - 1] = aux++;
    }
    print_array(vetor, tam_vetor);

    // inserir vetor na lista;
    for (int i = 0; i < tam_vetor; i++)
    {
        l1.insere(i, vetor[i]);
    }

    cout << "num acesso: " << l1.quicksort(vetor, 0, tam_vetor - 1);
}

void lista_definida()
{
    int vetor[20] = {70, 1, 12, 8, 99, 72, 5, 15, 20, 91, 14, 61, 66, 41, 81, 88, 16, 21, 34, 90};
    Lista l1;
    for (int i = 0; i < 20; i++)
    {
        l1.insere(i, vetor[i]);
    }

    l1.imprime();
    printf("\n");
    array_num_acesso[0] = l1.quicksort(l1.numbers, 0, l1.tamanho - 1);
    printf("\nLista ordenada: \n");
    l1.imprime();
    l1.limpa();
}

int main()
{
    /*
    // lista definida
    lista_definida();
    cout <<"\n Array qtd de acessos:\n ";
    print_array(array_num_acesso, 1);
 */
    // lista aleatoria
    // random_list();
    cout << "\n Array qtd de acessos:\n ";
    // print_array(array_num_acesso, MAX_TAM);
    pior_caso();
}
