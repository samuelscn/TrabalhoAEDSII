#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_NumeroLinhas.h"
#include "TAD_Palavras.h"

/* Cria uma célula vazia para
receber um Tad palavra
*/

void Cria_Vpalavras_Vazia(TAD_Palavras *pPalavra){
    pPalavra->pPrimeiro = 0;
    pPalavra->pUltimo = pPalavra->pPrimeiro;
    strcpy(pPalavra->Vpalavra.palavra, "\0");
    Cria_Lnumero_Vazia(&(pPalavra->Vpalavra.Linhas_da_palavra));//Utiliza essa função para criação de uma lista de números vazia
}

/* Preenche o tad palavra
com a letra lida do arquivo
*/

void Alimenta_Vpalavras(TAD_Palavras *pPalavra, char *p){
    strcpy(pPalavra->Vpalavra.palavra, p);
}

/* Utiliza a função Alimentaa_Lnumero
para inserir um número corresponde a palavra
no Tad Tad_NumeroLinhas */

void Alimenta_Vpalavras_Lnumero(TAD_Palavras *pPalavra, int num){
    Alimenta_Lnumero(&(pPalavra->Vpalavra.Linhas_da_palavra), num);//Chama a função para inserir número na lista
}

/* Imprime a palavra contida no Tad Palavra e
utiliza a função Printa_Lnumero para
imprimir o número da linha */

void Printa_Vpalavras(TAD_Palavras *pPalavra){
    printf("Palavra: %s\n", pPalavra->Vpalavra.palavra);
    Printa_Lnumero(&(pPalavra->Vpalavra.Linhas_da_palavra));// Chama a função para imprimir o número da linha
}
