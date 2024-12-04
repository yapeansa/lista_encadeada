#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Estrutura da lista, representação do nó
typedef struct no
{
    int info;
    struct no *prox;
} no;

// Menu
void menu()
{
    printf("\nMENU\n");
    printf("(1) Inserir no início\n");
    printf("(2) Inserir no final\n");
    printf("(3) Listar elementos\n");
    printf("(4) Fazer uma busca\n");
    printf("(5) Remover elemento\n");
    printf("(6) Inserir em ordem crescente\n");
    printf("(7) Liberar lista\n");
    printf("Escolha uma opção: ");
}

// Função para criar uma lista vazia (inicialização)
no *lst_criar()
{
    return NULL;
}

// Inserir no início
void inserir_inicio(no **head, int v)
{
    no *novo = (no *)malloc(sizeof(no));
    novo->info = v;
    novo->prox = *head;
    *head = novo;
}

// Função para inserir elemento no final da lista
void inserir_final(no **head, int v)
{
    no *x = (no *)malloc(sizeof(no));
    x->info = v;
    x->prox = NULL;

    if (*head == NULL)
        *head = x;
    else
    {
        no *ant = *head;
        while (ant->prox != NULL)
            ant = ant->prox;
        ant->prox = x;
    }
}

// Função para inserir elementos de maneira ordenada (crescente)
void inserir_ordenado(no **head, int v)
{
    no *ant = NULL;
    no *aux = *head;

    no *novo = (no *)malloc(sizeof(no));
    novo->info = v;

    while (aux != NULL && aux->info < v)
    {
        ant = aux;
        aux = aux->prox;
    }

    if (ant == NULL)
    {
        novo->prox = *head;
        *head = novo;
    }
    else
    {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
}

// Função para retirar elemento da lista
int remover(no **head, int v)
{
    no *ant = NULL;
    no *aux = *head;

    while (aux != NULL && aux->info != v)
    {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL)
        return 0;

    if (ant == NULL)
        *head = aux->prox;
    else
        ant->prox = aux->prox;

    free(aux);
    return 1;
}

// Função para buscar um elemento específico
int busca(no *head, int v)
{
    for (no *x = head; x != NULL; x = x->prox)
        if (x->info == v)
            return 1;

    return 0;
}

// Listar elementos da lista
void listar(no *head)
{
    if (head == NULL)
        printf("Lista vazia.\n");
    else
    {
        for (no *x = head; x != NULL; x = x->prox)
            printf("%d ", x->info);
        printf("\n");
    }
}

// Função para liberar a lista
void libera(no **head)
{
    printf("Liberando lista e saindo...\n\n");
    free(*head);
}
