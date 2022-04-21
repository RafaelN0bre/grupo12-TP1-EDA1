#include "avl.h"

#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó
struct No {
  int chave;
  struct No *pEsq;
  struct No *pDir;
  int altura;
  int FatBal;
};

// Criar um nó
struct No *novoNo(int chave) {
  struct No *no = (struct No *) malloc(sizeof(struct No));
  no->chave = chave;
  no->pEsq = NULL;
  no->pDir = NULL;
  no->FatBal = NULL;
  no->altura = 1;
  return (no);
}

// Pegar fator de balanceamento
int pegarFatBal(struct No *N) {
  if (N == NULL)
    return 0;
  return altura(N->pEsq) - altura(N->pDir);
}

// Inserir Nó
struct No *inserirNo(struct No *no, int chave) {

  if (no == NULL)
    return (novoNo(chave));

  if (chave < no->chave)
    no->pEsq = inserirNo(no->pEsq, chave);
  else if (chave > no->chave)
    no->pDir = inserirNo(no->pDir, chave);
  else
    return no;

  // Atualiza a altura do nó
  no->altura = 1 + max(altura(no->pEsq), altura(no->pDir));

  return no;
}

void imprimirOrdemCresc(struct No *root){
  if(root != NULL){
    // Primeiro a esquerda, pois armazena os numeros menores
    imprimirOrdemCresc(root->pEsq);
    printf("|\t%d\t|\t%d\t|\n", root->chave, root->FatBal);
    printf("---------------------------------\n");
    imprimirOrdemCresc(root->pDir);
  }
}

void calculaFatBal(struct No *root){
  if(root != NULL){
    calculaFatBal(root->pEsq);
    calculaFatBal(root->pDir);

    root->FatBal = pegarFatBal(root);
  }
}

int desalocar(struct No *root){
  // Nao faz nada caso o no esteja vazio, sai da recursao
  if (root == NULL){
    return 0;
  }

  // Processo recursivo para cada filho
  desalocar(root->pEsq);
  desalocar(root->pDir);

  // Apos desalocar todos os filhos, liberamos o no pai
  free(root);
  return 0;
}

int altura(struct No *N) {
  if (N == NULL)
    return 0;
  return N->altura;
}

int FatBal(struct No *N){
  if(N == NULL)
    return 0;
  return N->FatBal;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}