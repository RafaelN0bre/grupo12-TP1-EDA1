#ifndef AVL_H  
#define AVL_H

struct No;

int altura(struct No *N);

int max(int a, int b);

struct No *novoNo(int key);

int pegarFatBal(struct No *N);

struct No *inserirNo(struct No *node, int key);

void imprimirOrdemCresc(struct No *root);

int desalocar(struct No *root);

#endif