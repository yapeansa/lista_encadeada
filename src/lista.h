#ifndef LISTA
#define LISTA

// Estrutura de um nó da lista
typedef struct node
{
    int info;
    struct node *prox;
} node;


// Inicializar
node *init(void);

// Exibição do menu
void menu(void);

// Inserir nó no início da lista
void inserir_inicio(node **head, int v);

// Inserir nó no final da lista
void inserir_final(node **head, int v);

// Inserir nós na lista de maneira ordenada (ordem crescente)
void inserir_ordenado(node **head, int v);

// Função para remover um nó da lista
int remover(node **head, int v);

// Função para buscar um nó por valor na lista
int busca(node *head, int v);

// Função para exibir os elementos da lista
void listar(node *head);

// Função para liberar a lista
void libera(node **head);

#endif
