#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_NumeroLinhas.h"
#include "TAD_Palavras.h"

/* Cria uma c�lula vazia para
receber um Tad palavra
*/

void Cria_Vpalavras_Vazia(TAD_Palavras *pPalavra){
    pPalavra->pPrimeiro = 0;
    pPalavra->pUltimo = pPalavra->pPrimeiro;
    strcpy(pPalavra->Vpalavra.palavra, "\0");
    Cria_Lnumero_Vazia(&(pPalavra->Vpalavra.Linhas_da_palavra));//Utiliza essa fun��o para cria��o de uma lista de n�meros vazia
}

/* Preenche o tad palavra
com a letra lida do arquivo
*/

void Alimenta_Vpalavras(TAD_Palavras *pPalavra, char *p){
    strcpy(pPalavra->Vpalavra.palavra, p);
}

/* Utiliza a fun��o Alimentaa_Lnumero
para inserir um n�mero corresponde a palavra
no Tad Tad_NumeroLinhas */

void Alimenta_Vpalavras_Lnumero(TAD_Palavras *pPalavra, int num){
    Alimenta_Lnumero(&(pPalavra->Vpalavra.Linhas_da_palavra), num);//Chama a fun��o para inserir n�mero na lista
}

/* Imprime a palavra contida no Tad Palavra e
utiliza a fun��o Printa_Lnumero para
imprimir o n�mero da linha */

void Printa_Vpalavras(TAD_Palavras *pPalavra){
    printf("Palavra: %s\n", pPalavra->Vpalavra.palavra);
    Printa_Lnumero(&(pPalavra->Vpalavra.Linhas_da_palavra));// Chama a fun��o para imprimir o n�mero da linha
}
