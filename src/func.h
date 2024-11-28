#ifndef FUNC
#define FUNC

// Estrutura da lista, representação do nó
typedef struct no no;
// Menu
void menu(void);
// Função para criar uma lista vazia (inicialização)
void lst_criar(no **head);
// Inserir no início
void inserir(no **head, int v);
// Função para inserir elemento no final da lista
void inserir_final(no **head, int v);
// Função para inserir elementos de maneira ordenada (crescente)
void inserir_ordenado(no **head, int v);
// Função para retirar elemento da lista
int remover(no **head, int v);
// Função para buscar um elemento específico
int busca(no *head, int v);
// Listar elementos da lista
void listar(no *head);
// Função para liberar a lista
void libera(no **head);

#endif
