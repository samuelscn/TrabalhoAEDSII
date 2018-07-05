#ifndef TAD_PALAVRAS_H_INCLUDED
#define TAD_PALAVRAS_H_INCLUDED
#include "TAD_NumeroLinhas.h"

typedef struct{
    char palavra[20];//Palavra do texto
    TAD_NumeroLinhas Linhas_da_palavra; //Tad com o numero da linha
}Itens_Vpalavra;

typedef struct{
    Itens_Vpalavra Vpalavra;
    int pPrimeiro, pUltimo;//índices
}TAD_Palavras;
//Cabeçalho das funções

void Cria_Vpalavras_Vazia(TAD_Palavras *pPalavra);
void Alimenta_Vpalavras(TAD_Palavras *pPalavra, char *p);
void Alimenta_Vpalavras_Lnumero(TAD_Palavras *pPalavra, int num);
void Printa_Vpalavras(TAD_Palavras *pPalavra);

#endif // TAD_PALAVRAS_H_INCLUDED
