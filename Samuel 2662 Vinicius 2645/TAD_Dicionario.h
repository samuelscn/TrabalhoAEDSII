#ifndef TAD_DICIONARIO_H_INCLUDED
#define TAD_DICIONARIO_H_INCLUDED
#include "TAD_NumeroLinhas.h"
#include "TAD_Palavras.h"
#include "TAD_Lista_Palavras.h"
#include "TAD_Letra_Alfabeto.h"

typedef struct{
    TAD_Letra_Alfabeto Vetor_Letra_Alfabeto[26]; //Vetor alfabeto para todas as letras
}TAD_Dicionario;

//Cabeçalho das funções
void Inicializa_Dicionario(TAD_Dicionario *pDicionario);
void Alimenta_Dicionario(TAD_Dicionario *pDicionario, char *p, int num);
void Remove_Palavra_Dicionario(TAD_Dicionario *pDicionario, char *p);
void Printa_Dicionario_Letra_Especifica(TAD_Dicionario *pDicionario, char *p);
void Printa_Dicionario_Total(TAD_Dicionario *pDicionario);
void Ordena_Dicionario_Letra_Especifica(TAD_Dicionario *pDicionario, char *p);
void Ordena_Dicionario_Total(TAD_Dicionario *pDicionario);
//void Funcao_Tempo();

#endif // TAD_DICIONARIO_H_INCLUDED
