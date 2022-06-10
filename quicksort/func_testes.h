#include "dependency.h"
#include "lista.h"
int array_num_acesso[MAX_TAM];

/* Lista gerada aleatoriamente em que o tamanho da lista vaira de 1 a MAX_TAM */
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

        l1.quicksort(l1.numbers, 0, l1.tamanho - 1);
        array_num_acesso[i - 1] = l1.NUM_ACCESS;

        printf("\n** Lista ordenada: **\n");
        l1.imprime();
        cout << "\nQtd acesso: " << array_num_acesso[i - 1] << "\n";
        l1.limpa();
        l1.NUM_ACCESS = 0;
        printf("\n---------------------------------------\n");
    }

    cout << "\n\nARRAY QTD DE ACESSO PARA ORDENAR CADA LISTA DE TAMANHO  1 <= n <= " << MAX_TAM;
    print_array(array_num_acesso, MAX_TAM);
};

/* Lista de tamanho fixo 100  gerada para o pior caso, lista crescente */
void pior_caso()
{
    int tam_vetor = 100;
    Lista l1;
    int vetor[100];

    // criar vetor crescente
    for (unsigned i = 0; i < tam_vetor; i++)
    {
        vetor[i] = i + 1;
    }
    // inserir vetor na lista;
    for (int i = 0; i < tam_vetor; i++)
    {
        l1.insere(i, vetor[i]);
    }
    cout << "Lista gerada: ";
    l1.imprime();
    l1.quicksort(l1.numbers, 0, l1.tamanho - 1);
    cout << "Qtd acesso: " << l1.NUM_ACCESS;
    l1.NUM_ACCESS = 0;
    l1.imprime();
}

/* Lista para teste pedido na orientação do trabalho */
void lista_definida()
{
    int vetor[20] = {70, 1, 12, 8, 99, 72, 5, 15, 20, 91, 14, 61, 66, 41, 81, 88, 16, 21, 34, 90};
    Lista l1;
    for (int i = 0; i < 20; i++)
    {
        l1.insere(i, vetor[i]);
    }
    cout << "\n Monstrando a lista definida: ";
    l1.imprime();
    printf("\n");
    l1.quicksort(l1.numbers, 0, l1.tamanho - 1);

    printf("\nLista ordenada: \n");
    l1.imprime();
    cout << "\n Qtd de acessso: " << l1.NUM_ACCESS << endl;
    l1.limpa();
    l1.NUM_ACCESS = 0;
}

/* Lista de que varia de  tamanho 1-100  gerada para o pior caso, lista crescente */
void lista_crescente()
{
    Lista l1;
    // tamanho de cada vetor
    for (int i = 1; i <= MAX_TAM; i++)
    { // construo vetor do tamanho i;
        cout << "TAMANHO: " << i << endl;
        for (int j = 0; j < i; j++)
        {
            l1.insere(j, j + 1);
        }
        cout << "lista gerada: ";
        l1.imprime();
        l1.quicksort(l1.numbers, 0, l1.tamanho - 1);
        array_num_acesso[i - 1] = l1.NUM_ACCESS;
        printf("\n** Lista ordenada: **\n");
        l1.imprime();
        cout << "\nQtd acesso: " << array_num_acesso[i - 1] << "\n";
        l1.limpa();
        l1.NUM_ACCESS = 0;
        printf("\n---------------------------------------\n");
    }

    cout << "\n\nARRAY QTD DE ACESSO PARA ORDENAR CADA LISTA DE TAMANHO  1 <= n <= " << MAX_TAM;
    print_array(array_num_acesso, MAX_TAM);
};

/* Lista  que varia de  tamanho 1-100 , lista decrescente */
void lista_decrescente()
{
    Lista l1;
    // tamanho de cada vetor
    for (int i = 1; i <= MAX_TAM; i++)
    { // construo vetor do tamanho i;
        cout << "TAMANHO: " << i << endl;
        int aux = 100;
        for (int j = 0; j < i; j++)
        {
            l1.insere(j, aux--);
        }
        cout << "lista gerada: ";
        l1.imprime();

        l1.quicksort(l1.numbers, 0, l1.tamanho - 1);
        array_num_acesso[i - 1] = l1.NUM_ACCESS;
        printf("\n** Lista ordenada: **\n");
        l1.imprime();
        cout << "\nQtd acesso: " << array_num_acesso[i - 1] << "\n";
        l1.limpa();
        l1.NUM_ACCESS = 0;
        printf("\n---------------------------------------\n");
    }

    cout << "\n\nARRAY QTD DE ACESSO PARA ORDENAR CADA LISTA DE TAMANHO  1 <= n <= " << MAX_TAM;
    print_array(array_num_acesso, MAX_TAM);
};