#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void menu(void)
{
    printf("\nMENU\n");
    printf("(1) Inserir no início (2) Inserir no final\n(3) Listar elementos (4) Fazer uma busca\n");
    printf("(5) Remover elemento (6) Inserir em ordem crescente\n(7) Liberar lista\nEscolha uma opção: ");
}

node *init(void)
{
    return NULL;
}

void inserir_inicio(node **head, int v)
{
    node *novo_no = (node *)malloc(sizeof(node));
    novo_no->info = v;
    novo_no->prox = *head;
    *head = novo_no;
}

void inserir_final(node **head, int v)
{
    node *novo_no = (node *)malloc(sizeof(node));
    novo_no->info = v;
    novo_no->prox = NULL;

    if (*head == NULL)
        *head = novo_no;
    else
    {
        node *ant = *head;
        while (ant->prox != NULL)
            ant = ant->prox;
        ant->prox = novo_no;
    }
}

void inserir_ordenado(node **head, int v)
{
    node *ant = NULL;
    node *tmp = *head;

    node *novo = (node *)malloc(sizeof(node));
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

int remover(node **head, int v)
{
    node *ant = NULL;
    node *tmp = *head;

    while (tmp != NULL && tmp->info != v)
    {
        ant = tmp;
        tmp = tmp->prox;
    }

    if (tmp == NULL)
        return 0;

    if (ant == NULL)
        *head = (*head)->prox;
    else
        ant->prox = tmp->prox;

    free(tmp);
    return 1;
}

int busca(node *head, int v)
{
    for (node *x = head; x != NULL; x = x->prox)
        if (x->info == v)
            return 1;

    return 0;
}

void listar(node *head)
{
    if (head == NULL)
        printf("Lista vazia.\n");
    else
    {
        for (node *x = head; x != NULL; x = x->prox)
            printf("%d ", x->info);
        printf("\n");
    }
}

void libera(node **head)
{
    if (*head != NULL)
    {
        node *p = *head;
        while (p != NULL)
        {
            node *tmp = p->prox;
            free(p);
            p = tmp;
        }
    }
}
