#include <stdio.h>
#include <stdlib.h>

// Estrutura da lista, representação do nó
typedef struct lista
{
    int info;
    struct lista *prox;
} Lista;

// Função para criar uma lista vazia (inicialização)
void lst_criar(Lista **l)
{
    *l = NULL;
}

// Inserir no início
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

// Função para buscar um elemento específico
int busca(Lista *l, int v)
{
    for (Lista *x = l; x != NULL; x = x->prox)
        if (x->info == v)
            return 1;

    return 0;
}

// Listar elementos da lista
void listar(Lista *l)
{
    for (Lista *x = l; x != NULL; x = x->prox)
        printf("%d ", x->info);
    printf("\n\n");
}

// Função para liberar a lista
void libera(Lista **l)
{
    printf("Liberando lista e saindo...\n\n");
    free(*l);
}

int main()
{
    Lista *l;
    int opcao = 0, v;
    lst_criar(&l);

    do
    {
        printf("\n(1) Inserir no início\n");
        printf("(2) Inserir no final\n");
        printf("(3) Listar elementos\n");
        printf("(4) Fazer uma busca\n");
        printf("(5) Liberar lista\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o elemento a inserir no início: ");
            scanf("%d", &v);
            inserir(&l, v);
            break;
        case 2:
            printf("Digite o elemento a inserir no final: ");
            scanf("%d", &v);
            inserir_final(&l, v);
            break;
        case 3:
            listar(l);
            break;
        case 4:
            printf("Qual elemento você deseja buscar? ");
            scanf("%d", &v);
            if (busca(l, v))
                printf("O elemento %d está na lista.\n\n", v);
            else
                printf("O elemento %d não está na lista.\n\n", v);
            break;
        case 5:
            libera(&l);
            break;
        default:
            printf("Por favor, digite uma opção válida.\n\n");
        }
    } while (opcao != 5);

    return 0;
}
