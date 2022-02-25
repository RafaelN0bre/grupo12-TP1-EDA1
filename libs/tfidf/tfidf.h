#include <stdio.h>

#ifndef TFIDF_H
#define TFIDF_H

int ** ContaTodasP(int maxp, char *Vet_palavras);
int ** ContaNotaP(int maxp, char *Vet_palavras, int indice);
float ** CalculaTF(int *VetNotaPalavras, int *VetTotalPalavra, int maxp);
float ** CalculaIDF(int maxp, char *Vet_palavras);
float ** CalculoTFIDF(int maxp, float *VetTF, float *VetIDF);

#endif