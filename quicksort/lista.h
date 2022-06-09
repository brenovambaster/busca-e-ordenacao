#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "dependency.h"

class Lista
{
public:
    int NUM_ACCESS = 0;
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
        cout << " { ";
        for (int i = 0; i < tamanho; i++)
        {
            cout << " " << numbers[i]; // estamos invocando o método imprime da classe aluno
        }
        cout << " }\n";
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

    /* Retorna dois valores, [int posicao_pivo, int qtd_acesso], */
    std::tuple<int, int> partition(int *v, int inicio, int fim)
    {
        int pivo = v[fim], qtd_acesso = 0;
        int i = inicio;
        for (int j = inicio; j <= fim - 1; j++)
        {
            cout << "\npivo: " << pivo << endl;
            if (v[j] <= pivo)
            {
                // imprime();
                cout << endl;
                int aux;
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                i++;
                qtd_acesso += 3;
                imprime();
                cout << endl;
            }
        }
        int aux = v[i];
        v[i] = v[fim];
        v[fim] = aux;
        qtd_acesso += 3;
        imprime();
        cout << endl;
        return make_tuple(i, qtd_acesso);
    }

    int quicksort(int *v, int inicio, int fim)
    {
        int pivo;

        if (inicio < fim)
        {
            auto valores = partition(v, inicio, fim);
            pivo = get<0>(valores);
            NUM_ACCESS += get<1>(valores);
            // cout << "Pivo: " << v[pivo] << endl;
            // print_array(v, fim);
            quicksort(v, inicio, pivo - 1);
            quicksort(v, pivo + 1, fim);
        }

        return NUM_ACCESS;
    }

    ~Lista(){};
};
#endif