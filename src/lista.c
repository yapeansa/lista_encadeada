#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Menu
void menu()
{
    printf("\nMENU\n");
    printf("(1) Inserir no início ");
    printf("(2) Inserir no final\n");
    printf("(3) Listar elementos ");
    printf("(4) Fazer uma busca\n");
    printf("(5) Remover elemento ");
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
    no *novo_no = (no *)malloc(sizeof(no));
    novo_no->info = v;
    novo_no->prox = *head;
    *head = novo_no;
}

// Função para inserir elemento no final da lista
void inserir_final(no **head, int v)
{
    no *novo_no = (no *)malloc(sizeof(no));
    novo_no->info = v;
    novo_no->prox = NULL;

    if (*head == NULL)
        *head = novo_no;
    else
    {
        no *ant = *head;
        while (ant->prox != NULL)
            ant = ant->prox;
        ant->prox = novo_no;
    }
}

// Função para inserir elementos de maneira ordenada (crescente)
void inserir_ordenado(no **head, int v)
{
    no *ant = NULL;
    no *tmp = *head;

    no *novo = (no *)malloc(sizeof(no));
    novo->info = v;

    while (tmp != NULL && tmp->info < v)
    {
        ant = tmp;
        tmp = tmp->prox;
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
    no *tmp = *head;

    while (tmp != NULL && tmp->info != v)
    {
        ant = tmp;
        tmp = tmp->prox;
    }

    if (tmp == NULL)
        return 0;

    if (ant == NULL)
        *head = tmp->prox;
    else
        ant->prox = tmp->prox;

    free(tmp);
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
    if (*head != NULL)
    {
        no *p = *head;
        while (p != NULL)
        {
            no *tmp = p->prox;
            free(p);
            p = tmp;
        }
    }
}
