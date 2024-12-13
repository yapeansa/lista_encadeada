#ifndef LISTA
#define LISTA

// Estrutura de um nó da lista
typedef struct no
{
    int info;
    struct no *prox;
} no;

// Exibição do menu
void menu(void);

// Função para criar uma lista vazia (inicialização)
no *lst_criar(void);

// Inserir nó no início da lista
void inserir_inicio(no **head, int v);

// Inserir nó no final da lista
void inserir_final(no **head, int v);

// Inserir nós na lista de maneira ordenada (ordem crescente)
void inserir_ordenado(no **head, int v);

// Função para remover um nó da lista
int remover(no **head, int v);

// Função para buscar um nó por valor na lista
int busca(no *head, int v);

// Função para exibir os elementos da lista
void listar(no *head);

// Função para liberar a lista
void libera(no **head);

#endif
