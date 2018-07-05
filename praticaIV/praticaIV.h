#ifndef PRATICAIV_H_INCLUDED
#define PRATICAIV_H_INCLUDED
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10

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

struct link
{
    int freq;
    char ch[MAX];
    struct link* right;
    struct link* left;
};

typedef struct link node;
void sort(node *[], int);
node* create(char[], int);
void sright(node *[], int);
void Assign_Code(node*, int [], int);
void Delete_Tree(node *);



#endif // PRATICAIV_H_INCLUDED
