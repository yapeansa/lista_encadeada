#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    no *lista = lst_criar();
    int opcao = 0, v;

    do
    {
        menu();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o elemento a inserir no início: ");
            scanf("%d", &v);
            inserir_inicio(&lista, v);
            break;
        case 2:
            printf("Digite o elemento a inserir no final: ");
            scanf("%d", &v);
            inserir_final(&lista, v);
            break;
        case 3:
            listar(lista);
            break;
        case 4:
            printf("Qual elemento você deseja buscar? ");
            scanf("%d", &v);
            if (busca(lista, v))
                printf("O elemento %d está na lista.\n", v);
            else
                printf("O elemento %d não está na lista.\n", v);
            break;
        case 5:
            printf("Qual elemento você deseja remover?\n");
            scanf("%d", &v);
            if (remover(&lista, v))
                printf("Elemento removido.\n");
            else
                printf("Elemento não encontrado.\n");
            break;
        case 6:
            printf("Digite o elemento a inserir: ");
            scanf("%d", &v);
            inserir_ordenado(&lista, v);
            break;
        case 7:
            printf("Liberando a lista...\n");
            libera(&lista);
            break;
        default:
            printf("Por favor, digite uma opção válida.\n");
        }
    } while (opcao != 7);

    return 0;
}
