#ifndef FUNC
#define FUNC

typedef struct no no;

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
