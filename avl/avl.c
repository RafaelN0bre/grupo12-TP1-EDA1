#include "avl.h"

#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó
struct Node {
  int key;
  struct Node *left;
  struct Node *right;
  int height;
};

// Calculate height
int height(struct Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// Criar um nó
struct Node *newNode(int key) {
  struct Node *node = (struct Node *) malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Rotação Direita
struct Node *rightRotate(struct Node *y) {
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

// Rotação Esquerda
struct Node *leftRotate(struct Node *x) {
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

// Pegar fator de balanceamento
int getBalance(struct Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

// Inserir Nó
struct Node *insertNode(struct Node *node, int key) {
  // Find the correct position to insertNode the node and insertNode it
  if (node == NULL)
    return (newNode(key));

  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  // Update the balance factor of each node and
  // Balance the tree
  node->height = 1 + max(height(node->left),
               height(node->right));

  int balance = getBalance(node);
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);

  if (balance < -1 && key > node->right->key)
    return leftRotate(node);

  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

struct Node *minValueNode(struct Node *node) {
  struct Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

// Printar a Árvore
void printPreOrder(struct Node *root) {
  if (root != NULL) {
    int altura_esquerda;
    int altura_direita;
    if(root->left->height)

    printf("%d ", root->key);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}

void printInOrder(struct Node *root){
  if(root != NULL){
    // Primeiro a esquerda, pois armazena os numeros menores
    printInOrder(root->left);
    printf(" %d \n", root->key);
    printInOrder(root->right);
  }
}


int desalocar(struct Node *root){
  // Nao faz nada caso o no esteja vazio, sai da recursao
  if (root == NULL){
    return 0;
  }

  // Processo recursivo para cada filho
  desalocar(root->left);
  desalocar(root->right);

  // Apos desalocar todos os filhos, liberamos o no pai
  free(root);
  return 0;
}
