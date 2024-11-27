#ifndef FUNC
#define FUNC

// Estrutura da lista, representação do nó
typedef struct lista
{
    int info;
    struct lista *prox;
} Lista;

// Função para criar uma lista vazia (inicialização)
void lst_criar(Lista **l);
// Inserir no início
void inserir(Lista **l, int v);
// Função para inserir elemento no final da lista
void inserir_final(Lista **l, int v);
// Função para buscar um elemento específico
int busca(Lista *l, int v);
// Listar elementos da lista
void listar(Lista *l);
// Função para liberar a lista
void libera(Lista **l);

#endif
