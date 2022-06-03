#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "dependency.h"
using namespace std;

class Lista
{
public:
    int numbers[MAX_TAM];
    unsigned tamanho;

    Lista()
    {
        tamanho = 0;
    }
    void limpa()
    {
        tamanho = 0;
    }
    void imprime()
    {
        for (int i = 0; i < tamanho; i++)
        {
            cout << numbers[i] << " |"; // estamos invocando o método imprime da classe aluno
        }
    }
    int verificaLimiteIntervalo(unsigned posicao, unsigned tamanho)
    {
        if (posicao > tamanho)
        {
            cout << "posicao > que tamanho permitido" << endl;
            return 0;
        }
        if (MAX_TAM == tamanho)
        {
            cout << "Lista cheia" << endl;
            return 0;
        }
        return 1;
    }
    void insere(unsigned posicao, unsigned valor)
    {
        if (verificaLimiteIntervalo(posicao, tamanho))
        {
            // deslocando todos lista de posicao em diante -- direita -> esquerda é melhor
            for (int i = tamanho; i > posicao; i--)
            {
                numbers[i] = numbers[i - 1];
            }

            numbers[posicao] = valor;
            tamanho++;
        }
    }

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

    ~Lista(){};
};
#endif