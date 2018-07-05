#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_NumeroLinhas.h"
#include "TAD_Palavras.h"
#include "TAD_Lista_Palavras.h"
#include "TAD_Letra_Alfabeto.h"

/* Cria o vetor com a letra do
alfabeto vazia*/

void Cria_Vletra_Alfabeto(TAD_Letra_Alfabeto *pLetra, char *p){
    pLetra->pPrimeiro = 0;
    pLetra->pUltimo = pLetra->pPrimeiro;
    strcpy(pLetra->Vetor_Lalfabeto.letra, "\0");
    Alimenta_Vletra_Alfabeto(pLetra, p);
    Cria_Vlista_Palavra(&(pLetra->Vetor_Lalfabeto.PonteListaPalavra));
}
//Insere uma letra nesse vetor

void Alimenta_Vletra_Alfabeto(TAD_Letra_Alfabeto *pLetra, char *p){
    strcpy(pLetra->Vetor_Lalfabeto.letra, p);
}
//Insere uma palavra na lista

void Alimenta_Vlistapalavra_Vpalavra_Lnumero(TAD_Letra_Alfabeto *pLetra, char *p, int num){
    Alimenta_Vlista_Palavra(&(pLetra->Vetor_Lalfabeto.PonteListaPalavra), p, num); // Utiliza a função para inserir a lista de palavras
}

//Imprime a letra do alfabeto

void Printa_Letra(TAD_Letra_Alfabeto *pLetra){
    printf("Letra do alfabeto: %s\n", pLetra->Vetor_Lalfabeto.letra);
}

//Imprime a letra e a palavra
void Printa_Vletra_Alfabeto(TAD_Letra_Alfabeto *pLetra){
    Printa_Letra(pLetra);//Utiliza essa função para chamar a letra
    Printa_Vlista_Palavra(&(pLetra->Vetor_Lalfabeto.PonteListaPalavra));//Utiliza essa função para imprimir a palavra
}

//Remoção da palavra dada
void Remove_Vletra_Palavra(TAD_Letra_Alfabeto *pLetra, char *p){
    Remove_Vlista_Palavra_Dada(&(pLetra->Vetor_Lalfabeto.PonteListaPalavra), p); //Utiliza a função para remover a palavra dada
}
