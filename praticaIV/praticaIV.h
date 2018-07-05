#ifndef PRATICAIV_H_INCLUDED
#define PRATICAIV_H_INCLUDED
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
struct link
{
    int peso;
    char palavra[MAX];
    struct link* direita;
    struct link* esquerda;
};
typedef struct link no;

typedef struct{
    char p[24];
    int peso;
}Palavra;

typedef struct{
    Palavra Vet_palavra[10];
}Armazena_palavra;

void Inicia_vPalavra(Armazena_palavra *pPalavra);
void Insere_palavra(char *vai, Armazena_palavra *pPalavra);
void OrdenaVET(Armazena_palavra *pPalavra);
void Imprime(Armazena_palavra *pPalavra);
void ordena(no *[12], int);
no* create(char a[40], int x);
void sdireita(no *[12], int);
void Assign_Code(no*, int c[], int);
void Delete_Tree(no *);


#endif // PRATICAIV_H_INCLUDED
