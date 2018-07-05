#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "praticaIV.h"

void Inicia_vPalavra(Armazena_palavra *pPalavra){
    int i;
    char aux[24];

    for(i=0; i<8; i++){
        strcpy(pPalavra->Vet_palavra[i].p, "\0");
        pPalavra->Vet_palavra[i].peso = NULL;
    }
}

void Insere_palavra(char *vai, Armazena_palavra *pPalavra){
    int i;

    for(i=0; i<8; i++){
        if(strcmp(pPalavra->Vet_palavra[i].p, "\0") == 0){
            strcpy(pPalavra->Vet_palavra[i].p, vai);
            pPalavra->Vet_palavra[i].peso = 1;
            break;
        }else{
            if(strcmp(pPalavra->Vet_palavra[i].p, vai) == 0){
                pPalavra->Vet_palavra[i].peso = pPalavra->Vet_palavra[i].peso + 1;
                break;
            }
        }
    }
}

void Imprime(Armazena_palavra *pPalavra){
    int i;

    for(i = 0; i<10; i++){
        if(strcmp(pPalavra->Vet_palavra[i].p, "\0") == 0){
            break;
        }else{
            printf("%s\n", pPalavra->Vet_palavra[i].p);
            printf("%d\n", pPalavra->Vet_palavra[i].peso);
        }
    }
}

void OrdenaVET(Armazena_palavra *pPalavra){
    int k, j, aux;
    char palavra[24];

    for (k = 1; k < 5; k++) {
        for (j = 0; j < 5 - 1; j++) {
            if (pPalavra->Vet_palavra[j].peso > pPalavra->Vet_palavra[j+1].peso) {
                aux = pPalavra->Vet_palavra[j].peso;
                strcpy(palavra, pPalavra->Vet_palavra[j].p);
                pPalavra->Vet_palavra[j].peso = pPalavra->Vet_palavra[j+1].peso;
                strcpy(pPalavra->Vet_palavra[j].p, pPalavra->Vet_palavra[j+1].p);
                pPalavra->Vet_palavra[j+1].peso = aux;
                strcpy(pPalavra->Vet_palavra[j+1].p, palavra);
            }
        }
    }
}





node* create(char a[], int x)

{
            node* ptr;
            ptr = (node *) malloc(sizeof(node));
            ptr->freq = x;
            strcpy( ptr->ch , a);
            ptr->right = ptr->left = NULL;
            return(ptr);
}

void sort(node* a[], int n)
{
            int i, j;
            node* temp;
            for (i = 0; i < n - 1; i++)
                        for (j = i; j < n; j++)
                                    if (a[i]->freq > a[j]->freq)
                                    {
                                                temp = a[i];
                                                a[i] = a[j];
                                                a[j] = temp;
                                    }
}

void sright(node* a[], int n)
{
            int i;
            for (i = 1; i < n - 1; i++)
                        a[i] = a[i + 1];
}

void Assign_Code(node* tree, int c[], int n)
{
            int i;
            if ((tree->left == NULL) && (tree->right == NULL))
            {
                        printf("%s code:", tree->ch);
                        for (i = 0; i < n; i++)
                         {
                          printf("%d", c[i]);
                         }
                        printf("\n");
            }
            else
            {
                        c[n] = 1;
                        n++;
                        Assign_Code(tree->left, c, n);
                        c[n - 1] = 0;
                        Assign_Code(tree->right, c, n);
            }
}

void Delete_Tree(node * root)
{
    if(root!=NULL)
    {
            Delete_Tree(root->left);
            Delete_Tree(root->right);
            free(root);
    }
}
