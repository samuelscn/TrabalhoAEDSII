#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TAD_NumeroLinhas.h"
#include "TAD_Palavras.h"
#include "TAD_Lista_Palavras.h"
#include "TAD_Letra_Alfabeto.h"
#include "TAD_Dicionario.h"

/* Fun��o para cria��o do
dicion�rio vazio */

void Inicializa_Dicionario(TAD_Dicionario *pDicionario){
    int i;
    char caractere;
    /*Percorre o vetor chamando a
    fun��o para adicionar a
    letra no vetor */

    for(i = 0; i < 26; i++){
        caractere = 97 + i;
        Cria_Vletra_Alfabeto(&(pDicionario->Vetor_Letra_Alfabeto[i]), &caractere);
    }
}
/*Insere as palavras no
dicion�rio */

void Alimenta_Dicionario(TAD_Dicionario *pDicionario, char *p, int num){
    int i, b, c;
    /*Percorre o vetor
    adicionando a palavra e
    o n�mero na lista */

    c = p[0];//Pega a primeira letra da palavra
    for(i = 0; i < 26; i++){
        b = 97+i;
        if( b == c ){ //Compara com a letra do vetor com a primeira letra da palavraa
            Alimenta_Vlistapalavra_Vpalavra_Lnumero(&(pDicionario->Vetor_Letra_Alfabeto[i]), p, num); //Utiliza essa fun��o para passar a letra e o n�mero
        }
    }
}
/* Remove a palavra
entrada pelo usu�rio */

void Remove_Palavra_Dicionario(TAD_Dicionario *pDicionario, char *p){
    int i, b, c;

    c = p[0]; //Pega a primeira letra da palavra

    for(i = 0; i < 26; i++){
        b = 97+i;
        if( b == c) //Compara com a letra do vetor com a primeira letra da palavraa
            Remove_Vletra_Palavra(&(pDicionario->Vetor_Letra_Alfabeto[i]), p); //Chama a fun��o de remo��o do Tad Letra_alfabeto
    }
}

/* Imprime letra especifica
do diocion�rio */
void Printa_Dicionario_Letra_Especifica(TAD_Dicionario *pDicionario, char *p){
    int i, b, c;

    c = p[0];//Pega a primeira letra da palavra

    for(i = 0; i < 26; i++){
        b = 97+i;
        if( b == c) //Compara com a letra do vetor com a primeira letra da palavraa
            Printa_Vletra_Alfabeto(&(pDicionario->Vetor_Letra_Alfabeto[i]));//Chama a fun��o apenas para a letra especifica
    }
}

//Imprime o dicion�rio todo
void Printa_Dicionario_Total(TAD_Dicionario *pDicionario){
    int i;

    //Percorre o vetor imprimindo todo o dicionario
    for(i = 0; i < 26; i++)
        Printa_Vletra_Alfabeto(&(pDicionario->Vetor_Letra_Alfabeto[i]));
}
/* Ordena letra especifica do
dicionario, selecionando um dos
m�todos de ordena��o */


void Ordena_Dicionario_Letra_Especifica(TAD_Dicionario *pDicionario, char *p){
    int i, b, c, j, opcao;

    c = p[0];//Pega a primeira letra da palavra

    for(i = 0; i < 26; i++){
        b = 97+i;
        if(b == c){
            Printa_Vetor_Desordenado(&(pDicionario->Vetor_Letra_Alfabeto[i].Vetor_Lalfabeto.PonteListaPalavra));//Impress�o do dicion�rio desordenado
            printf("\n");
            Alimenta_Vetor_Copia(&(pDicionario->Vetor_Letra_Alfabeto[i].Vetor_Lalfabeto.PonteListaPalavra));//Alimenta a c�pia do vetor
            printf("Selecione o algoritmo de ordenacao:\n");
            printf("Digite 1 para: BubbleSort\n");
            printf("Digite 2 para: SelectSort\n");
            printf("Digite 3 para: InsertSort\n");
            printf("Digite 4 para: ShellSort\n");
            printf("Digite 5 para: QuickSort\n");
            printf("Digite 6 para: HeapSort\n");
            printf("Digite 7 para: Sair\n");
            scanf("%d",&opcao);
            do{
                switch(opcao)
                {
                case 1:
                    //Seleciona a fun��o de bubble sort
                    printf("\nBubbleSort\n");
                    //Chama a fun��o de ordena��o Bubble Sort
                    Ordena_BoobleS_Char(&(pDicionario->Vetor_Letra_Alfabeto[i].Vetor_Lalfabeto.PonteListaPalavra), &(pDicionario->Vetor_Letra_Alfabeto[i].Vetor_Lalfabeto.PonteListaPalavra.Copia_Vetor));
                    printf("\nOpcao\n");
                    scanf("%d",&opcao);
                    break;

                case 2:
                    //Seleciona a fun��o de Select sort
                    printf("\SelectSort\n");
                    //Chama a fun��o de ordena��o Select Sort
                    Ordena_SelectS_Char(&(pDicionario->Vetor_Letra_Alfabeto[i].Vetor_Lalfabeto.PonteListaPalavra), &(pDicionario->Vetor_Letra_Alfabeto[i].Vetor_Lalfabeto.PonteListaPalavra.Copia_Vetor));
                    printf("\nOpcao\n");
                    scanf("%d",&opcao);
                    break;

                case 3:
                    //Seleciona a fun��o de Insert Sort
                    printf("\InsertSort\n");
                    //Chama a fun��o de ordena��o Insert Sort
                    Ordena_InsertS_Char(&(pDicionario->Vetor_Letra_Alfabeto[i].Vetor_Lalfabeto.PonteListaPalavra), &(pDicionario->Vetor_Letra_Alfabeto[i].Vetor_Lalfabeto.PonteListaPalavra.Copia_Vetor));
                    printf("\nOpcao\n");
                    scanf("%d",&opcao);
                    break;
                 case 4:
                     //Seleciona a fun��o de Shell Sort
                    printf("\ShellSort\n");
                    //Chama a fun��o de ordena��o Shell Sort
                    Ordena_ShellS_Char(&(pDicionario->Vetor_Letra_Alfabeto[i].Vetor_Lalfabeto.PonteListaPalavra), &(pDicionario->Vetor_Letra_Alfabeto[i].Vetor_Lalfabeto.PonteListaPalavra.Copia_Vetor));
                    printf("\nOpcao\n");
                    scanf("%d",&opcao);
                    break;
                 case 5:
                     //Seleciona a fun��o de Quick Sort
                    printf("\QuickSort\n");
                    //Chama a fun��o de ordena��o Quick Sort
                    QuickS_Char(&(pDicionario->Vetor_Letra_Alfabeto[i].Vetor_Lalfabeto.PonteListaPalavra), &(pDicionario->Vetor_Letra_Alfabeto[i].Vetor_Lalfabeto.PonteListaPalavra.Copia_Vetor));
                    printf("\nOpcao\n");
                    scanf("%d",&opcao);
                    break;
                 case 6:
                     //Seleciona a fun��o de Heap Sort
                    printf("\HeapSort\n");
                    //Chama a fun��o de ordena��o Heap Sort
                    Ordena_HeapS_Char(&(pDicionario->Vetor_Letra_Alfabeto[i].Vetor_Lalfabeto.PonteListaPalavra), &(pDicionario->Vetor_Letra_Alfabeto[i].Vetor_Lalfabeto.PonteListaPalavra.Copia_Vetor));
                    printf("\nOpcao\n");
                    scanf("%d",&opcao);
                    break;
                 case 7:
                    break;
                 default:
                    printf("Opcao invalida, digite novamente:\n");
                    scanf("%d",&opcao);
                }
           }while(opcao!= 7);
        }
    }
}

/*void Funcao_Tempo(){


} */
//Ordena o todo o dicion�rio
void Ordena_Dicionario_Total(TAD_Dicionario *pDicionario){
    int i, j, b, c, opcao;
    clock_t Ticks[2];//fun��o de tempo
    Ticks[0] = clock();//fun��o de tempop

    for(i = 0; i < 26; i++){
        c = 97 + i;
        printf("Vetor letra: %c\n", c);
        Printa_Vetor_Desordenado(&(pDicionario->Vetor_Letra_Alfabeto[i].Vetor_Lalfabeto.PonteListaPalavra));//Imprime vetor desordenado
        printf("\n");
    }
            printf("Selecione o algoritmo de ordena��o:\n");
            printf("Digite 1 para: BubbleSort\n");
            printf("Digite 2 para: SelectSort\n");
            printf("Digite 3 para: InsertSort\n");
            printf("Digite 4 para: ShellSort\n");
            printf("Digite 5 para: QuickSort\n");
            printf("Digite 6 para: HeapSort\n");
           // printf("Digite 7 para: Sair\n");
            scanf("%d",&opcao);
                switch(opcao)
                {
                case 1:
                    //Seleciona a fun��o de bubble sort
                    printf("\nBubbleSort\n");
                    for(j = 0; j < 26; j++){
                        b = 97 + j;
                        printf("Vetor letra: %c\n", b);
                        //Inicializa comparacao e movimentacao com zero
                        Inicia_comparacao_movimentacao(&(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra));
                        //Alimenta a copia do vetor
                        Alimenta_Vetor_Copia(&(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra));
                        //Chama a fun��o para utilizar o bubble sort
                        Ordena_BoobleS_Char(&(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra), &(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra.Copia_Vetor));
                        printf("\n");
                    }
                    break;
                case 2:
                    //Seleciona a fun��o de Select sort
                    printf("\SelectSort\n");
                    for(j = 0; j < 26; j++){
                        b = 97 + j;
                        printf("Vetor letra: %c\n", b);
                        //Inicializa comparacao e movimentacao com zero
                        Inicia_comparacao_movimentacao(&(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra));
                        //Alimenta a copia do vetor
                        Alimenta_Vetor_Copia(&(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra));
                        //Chama a fun��o para utilizar o shell sort
                        Ordena_SelectS_Char(&(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra), &(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra.Copia_Vetor));
                        printf("\n");
                    }
                    break;

                case 3:
                    //Seleciona a fun��o de Insert sort
                    printf("\InsertSort\n");
                    for(j = 0; j < 26; j++){
                        b = 97 + j;
                        printf("Vetor letra: %c\n", b);
                        //Inicializa comparacao e movimentacao com zero
                        Inicia_comparacao_movimentacao(&(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra));
                        //Alimenta a copia do vetor
                        Alimenta_Vetor_Copia(&(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra));
                        //Chama a fun��o para utilizar o Insert Sort
                        Ordena_InsertS_Char(&(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra), &(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra.Copia_Vetor));
                        printf("\n");
                    }
                    break;
                 case 4:
                     //Seleciona a fun��o de Shell sort
                    printf("\ShellSort\n");
                    for(j = 0; j < 26; j++){
                        b = 97 + j;
                        printf("Vetor letra: %c\n", b);
                        //Inicializa comparacao e movimentacao com zero
                        Inicia_comparacao_movimentacao(&(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra));
                        //Alimenta a copia do vetor
                        Alimenta_Vetor_Copia(&(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra));
                        //Chama a fun��o para utilizar o Shell Sort
                        Ordena_ShellS_Char(&(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra), &(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra.Copia_Vetor));
                        printf("\n");
                    }
                    break;
                 case 5:
                     //Seleciona a fun��o de Quick sort
                    printf("\QuickSort\n");
                    for(j = 0; j < 26; j++){
                        b = 97 + j;
                        printf("Vetor letra: %c\n", b);
                        //Inicializa comparacao e movimentacao com zero
                        Inicia_comparacao_movimentacao(&(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra));
                        //Alimenta a copia do vetor
                        Alimenta_Vetor_Copia(&(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra));
                        //Chama a fun��o para utilizar o Quick Sort
                        QuickS_Char(&(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra), &(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra.Copia_Vetor));
                        printf("\n");
                    }
                    break;
                 case 6:
                     //Seleciona a fun��o de Heap sort
                    printf("\HeapSort\n");
                    for(j = 0; j < 26; j++){
                        b = 97 + j;
                        printf("Vetor letra: %c\n", b);
                        //Inicializa comparacao e movimentacao com zero
                        Inicia_comparacao_movimentacao(&(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra));
                        //Alimenta a copia do vetor
                        Alimenta_Vetor_Copia(&(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra));
                        //Chama a fun��o para utilizar o Heap Sort
                        Ordena_HeapS_Char(&(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra), &(pDicionario->Vetor_Letra_Alfabeto[j].Vetor_Lalfabeto.PonteListaPalavra.Copia_Vetor));
                        printf("\n");
                    }
                    break;
                }
                Ticks[1] = clock(); //fun��o de tempo
                double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC; //fun��o de tempo
                printf("Tempo total gasto: %g ms.", Tempo);//Mostra tempo total gasto na ordena��o
}

