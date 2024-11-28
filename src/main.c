#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{
    no *l;
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
