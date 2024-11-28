#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void lst_criar(no **head)
{
    *head = NULL;
}

void inserir(no **head, int v)
{
    no *novo = (no *)malloc(sizeof(no));
    novo->info = v;
    novo->prox = *head;
    *head = novo;
}

void inserir_final(no **head, int v)
{
    no *x = (no *)malloc(sizeof(no));
    x->info = v;
    x->prox = NULL;

    if (*head == NULL)
        *head = x;
    else
    {
        no *y = *head;
        while (y->prox != NULL)
            y = y->prox;
        y->prox = x;
    }
}

int busca(no *head, int v)
{
    for (no *x = head; x != NULL; x = x->prox)
        if (x->info == v)
            return 1;

    return 0;
}

void listar(no *head)
{
    for (no *x = head; x != NULL; x = x->prox)
        printf("%d ", x->info);
    printf("\n\n");
}

void libera(no **head)
{
    printf("Liberando lista e saindo...\n\n");
    free(*head);
}
