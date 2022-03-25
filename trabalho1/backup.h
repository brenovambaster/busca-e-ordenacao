#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED
#include "Aluno.h"
#include "Nodo.h"

using namespace std;

class ListaEncadeada
{

public:
    Nodo *inicio;
    int tamanho = 0;
    ListaEncadeada()
    {
        inicio = NULL;
        tamanho = 0;
    }
    ~ListaEncadeada()
    {
        Nodo *prox;
        while (inicio)
        {
            prox = inicio->proximo;
            delete inicio;
            inicio = prox;
        }
    }
    void imprime() const
    {
        cout << "\n------Lista encadeada------\n";
        Nodo *novoNodo = inicio;
        while (novoNodo)
        {
            cout << novoNodo->valor;
            novoNodo = novoNodo->proximo;
            cout << " ";
        }
        cout << "\n------FIM DA LISTA-------------\n";
    }
    void insere(int posicao, int valor)
    {
        Nodo *novoNodo = new Nodo(valor);
        Nodo *nodoAnterior = inicio;
        if (posicao == 0)
        {
            novoNodo->proximo = inicio;
            inicio = novoNodo;
            tamanho++;
            return;
        }
        if (posicao > tamanho)
        {
            cout << "Posicao invalida\n";
            return;
        }
        for (int i = 0; i < posicao - 1; i++)
        {
            nodoAnterior = nodoAnterior->proximo;
        }
        novoNodo->proximo = nodoAnterior->proximo;
        nodoAnterior->proximo = novoNodo;
        tamanho++;
    }

    int buble_sort_otimizado(int op)
    {
        bool mudou = true;

        int ultima_alteracao = tamanho;
        int aux = tamanho - 1;
        Nodo *c, *b, *a, *aux2, *nodo_atual;

        while (mudou)
        {
            mudou = false;
            for (int i = 0; i <= ultima_alteracao - 2; i++)
            {
                if (inicio->valor > inicio->proximo->valor)
                {

                    mudou = true;
                    aux = i;
                    a = inicio;
                    b = inicio->proximo;
                    c = b->proximo;

                    cout << inicio->valor << "--- " << inicio->proximo->valor << endl;

                    inicio->proximo->proximo = inicio;
                    inicio->proximo = c; // a->c
                    inicio = b;

                    cout << "------------\n";
                    cout << "indice: " << i;
                }
            }

            ultima_alteracao = aux++;
        }

        /* Implenetar buble_sort
            var cont_acesso;
            if (op == 1)
        {
            imprime();
        }
        */

        if (op == 2)
        {
            // return cont_acesso
        }
        /* else
        {
            cout << "op inválido";
            return -1;
        } */
    }

    /* retorna -1 quando não encontra o valor*/
    int *busca(int chave)
    {
        Nodo *nodo1 = inicio;
        while (nodo1)
        {
            if (nodo1->valor == chave)
            {
                return &(nodo1->valor);
            }
            nodo1 = nodo1->proximo;
        }
        return NULL;
    }

    void remover(int chave)
    {
        Nodo *nodoAtual = inicio;
        Nodo *prev = NULL;
        while (nodoAtual)
        {
            if (nodoAtual->valor == chave)
                break;
            prev = nodoAtual;
            nodoAtual = nodoAtual->proximo;
        }
        if (!nodoAtual)
            cout << "chave invalida";
        else
        {
            if (prev)
                prev->proximo = nodoAtual->proximo;
            else
                inicio = nodoAtual->proximo;
            delete nodoAtual;
            cout << "chave " << chave << " removida com sucesso";
        }
    }
};

#endif