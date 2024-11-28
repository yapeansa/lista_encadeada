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
        menu();
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
                printf("O elemento %d está na lista.\n", v);
            else
                printf("O elemento %d não está na lista.\n", v);
            break;
        case 5:
            printf("Qual elemento você deseja remover.\n");
            scanf("%d", &v);
            if (remover(&l, v))
                printf("Elemento removido.\n");
            else
                printf("Elemento não encontrado.\n");
            break;
        case 6:
            libera(&l);
            break;
        default:
            printf("Por favor, digite uma opção válida.\n");
        }
    } while (opcao != 6);

    return 0;
}
