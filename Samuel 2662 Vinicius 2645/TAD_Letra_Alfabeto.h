#ifndef TAD_LETRA_ALFABETO_H_INCLUDED
#define TAD_LETRA_ALFABETO_H_INCLUDED
#include "TAD_NumeroLinhas.h"
#include "TAD_Palavras.h"
#include "TAD_Lista_Palavras.h"

typedef struct{
    char letra[2];//Letra corresponde a lista de palavras
    TAD_Lista_Palavras PonteListaPalavra;//Tad lista de palavras
}Itens_Vletra_Alfabeto;

typedef struct{
    Itens_Vletra_Alfabeto Vetor_Lalfabeto; //Tad letra do alfabeto
    int pPrimeiro, pUltimo;//Índices
}TAD_Letra_Alfabeto;

//Cabeçalho das funções
void Cria_Vletra_Alfabeto(TAD_Letra_Alfabeto *pLetra, char *p);
void Alimenta_Vletra_Alfabeto(TAD_Letra_Alfabeto *pLetra, char *p);
void Alimenta_Vlistapalavra_Vpalavra_Lnumero(TAD_Letra_Alfabeto *pLetra, char *p, int num);
void Printa_Letra(TAD_Letra_Alfabeto *pLetra);
void Printa_Vletra_Alfabeto(TAD_Letra_Alfabeto *pLetra);
void Remove_Vletra_Palavra(TAD_Letra_Alfabeto *pLetra, char *p);

#endif // TAD_LETRA_ALFABETO_H_INCLUDED
