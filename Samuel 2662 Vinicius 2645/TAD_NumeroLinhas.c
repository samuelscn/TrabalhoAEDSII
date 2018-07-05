#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_NumeroLinhas.h"

/*Cria uma c�lula vazia para armazenar
o tad com o n�mero da linha */

void Cria_Lnumero_Vazia(TAD_NumeroLinhas *pLinhas){
    pLinhas->pPrimeiro = (Apontador)malloc(sizeof(TAD_Celula));
    pLinhas->pUltimo = pLinhas->pPrimeiro;
    pLinhas->pUltimo->pProx = NULL;
    pLinhas->Total_linhas = 0;
}

// Verifica se a lista est� vazia
int Verifica_Lnumero_Vazia(TAD_NumeroLinhas *pLinhas){
    return (pLinhas->pPrimeiro == pLinhas->pUltimo);
}

/* Insere um tad contendo o n�mero de linhas
na �ltima c�lula */

int Alimenta_Lnumero(TAD_NumeroLinhas *pLinhas, int x){
    if((Verifica_Lnumero_Existentes(pLinhas, x)) == 0){
        pLinhas->pUltimo->pProx = (Apontador)malloc(sizeof(TAD_Celula));
        pLinhas->pUltimo = pLinhas->pUltimo->pProx;
        pLinhas->pUltimo->Item_Nlinhas.Nlinhas = x;
        pLinhas->pUltimo->pProx = NULL;
        pLinhas->Total_linhas++;
    }else{
        return 0;
    }
}

/* Remove a c�lula contendo
o tad com o n�mero de linha e
a c�lula anterior passa a ser a �ltima */

int Remove_Lnumero(TAD_NumeroLinhas *pLinhas){
    Apontador pAux;
    Apontador pPenultimo;

    if (pLinhas->pPrimeiro == pLinhas->pUltimo)
        return 0;
    else{
        pAux = NULL;
        pPenultimo = NULL;
        pAux = pLinhas->pPrimeiro->pProx;
        while(pAux->pProx != NULL){
            pPenultimo = pAux;
            pAux = pAux->pProx;
        }
        pAux = pLinhas->pUltimo;
        pLinhas->pUltimo = pPenultimo;
        pLinhas->pUltimo->pProx = NULL;
        pLinhas->Total_linhas--;
        free(pAux);
        return 1;
    }
}
/* Verifica a exist�ncia de tad's com n�meros
iguais */


int Verifica_Lnumero_Existentes(TAD_NumeroLinhas *pLinhas, int x){
    Apontador pAux;

    if (pLinhas->pPrimeiro == pLinhas->pUltimo)
        return 0;
    else{
        pAux = pLinhas->pPrimeiro->pProx;
        while(pAux != NULL){
            if(pAux->Item_Nlinhas.Nlinhas == x)
                return 1;
            pAux = pAux->pProx;
        }
        return 0;
    }
}

//Imprime o n�mero total de linhas

void Printa_Total_Nlinhas(TAD_NumeroLinhas *pLinhas){
    printf("Total numero de linhas: %d\n", pLinhas->Total_linhas);
}

//Imprime o n�mero de uma linha

void Printa_Lnumero(TAD_NumeroLinhas *pLinhas){
    Apontador pAux;

    pAux = pLinhas->pPrimeiro->pProx;
    while(pAux != NULL){
        printf("Numero da linha: %d\n", pAux->Item_Nlinhas.Nlinhas);
        pAux = pAux->pProx;
    }
    printf("\n");
}
