#ifndef TAD_LISTA_PALAVRAS_H_INCLUDED
#define TAD_LISTA_PALAVRAS_H_INCLUDED
#include "TAD_NumeroLinhas.h"
#include "TAD_Palavras.h"

typedef struct{
    TAD_Palavras PontePalavra;//Tad palavras
    int comparacao;
    int movimentacao;
}Itens_Vlista_Palavras;

typedef struct{
    Itens_Vlista_Palavras Vetor_Lpalavras[400]; //Vetor original de palavras
    Itens_Vlista_Palavras Copia_Vetor[400]; //Cópia do vetor de palavras, para a ordenação
    int pPrimeiro, pUltimo; //Índices
    int contapalavra;//Contador de palavras
}TAD_Lista_Palavras;

//Cabeçalho das funções

void Cria_Vlista_Palavra(TAD_Lista_Palavras *pLista_Palavra);
int Verifica_Palavra_Existente(TAD_Lista_Palavras *pLista_Palavra, char *p);
int Alimenta_Vlista_Palavra(TAD_Lista_Palavras *pLista_Palavra, char *p, int num);
int Remove_Vlista_Palavra_Dada(TAD_Lista_Palavras *pLista_Palavra, char *p);
void Printa_Total_Palavras(TAD_Lista_Palavras *pLista_Palavra);
void Printa_Vlista_Palavra(TAD_Lista_Palavras *pLista_Palavra);
void Ordena_BoobleS_Char(TAD_Lista_Palavras *pLista_Palavra, Itens_Vlista_Palavras *a);
void Ordena_SelectS_Char(TAD_Lista_Palavras *pLista_Palavra, Itens_Vlista_Palavras *a);
void Ordena_InsertS_Char(TAD_Lista_Palavras *pLista_Palavra, Itens_Vlista_Palavras *a);
void Ordena_ShellS_Char(TAD_Lista_Palavras *pLista_Palavra, Itens_Vlista_Palavras *a);
void QuickS_Char(TAD_Lista_Palavras *pLista_Palavra, Itens_Vlista_Palavras *a);
void Ordena(int Esq, int Dir, Itens_Vlista_Palavras *a);
void Particao(int Esq, int Dir, int *i, int *j, Itens_Vlista_Palavras *a);
void Ordena_HeapS_Char(TAD_Lista_Palavras *pLista_Palavra, Itens_Vlista_Palavras *a);
void Refaz(int Esq, int Dir, Itens_Vlista_Palavras *a);
void Constroi(Itens_Vlista_Palavras *a, TAD_Lista_Palavras *pLista_Palavra);
void Alimenta_Vetor_Copia(TAD_Lista_Palavras *pLista_Palavra);
void Printa_Vetor_Desordenado(TAD_Lista_Palavras *pLista_Palavra);
void Inicia_comparacao_movimentacao(Itens_Vlista_Palavras *a);

#endif // TAD_LISTA_PALAVRAS_H_INCLUDED
