#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void lst_criar(Lista **l)
{
    *l = NULL;
}

void inserir(Lista **l, int v)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->info = v;
    novo->prox = *l;
    *l = novo;
}

void inserir_final(Lista **l, int v)
{
    Lista *x = (Lista *)malloc(sizeof(Lista));
    x->info = v;
    x->prox = NULL;

    if (*l == NULL)
        *l = x;
    else
    {
        Lista *y = *l;
        while (y->prox != NULL)
            y = y->prox;
        y->prox = x;
    }
}

int busca(Lista *l, int v)
{
    for (Lista *x = l; x != NULL; x = x->prox)
        if (x->info == v)
            return 1;

    return 0;
}

void listar(Lista *l)
{
    for (Lista *x = l; x != NULL; x = x->prox)
        printf("%d ", x->info);
    printf("\n\n");
}

void libera(Lista **l)
{
    printf("Liberando lista e saindo...\n\n");
    free(*l);
}
