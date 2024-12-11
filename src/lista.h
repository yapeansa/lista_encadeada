#ifndef LISTA
#define LISTA

typedef struct no
{
    int info;
    struct no *prox;
} no;

void menu(void);
no *lst_criar(void);
void inserir_inicio(no **head, int v);
void inserir_final(no **head, int v);
void inserir_ordenado(no **head, int v);
int remover(no **head, int v);
int busca(no *head, int v);
void listar(no *head);
void libera(no **head);

#endif
