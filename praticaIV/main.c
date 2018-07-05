#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "praticaIV.h"

int main()
{
    Armazena_palavra *h;
    no* ptr, * head;
    int i, total = 0, u, c[15];
    int n=9;
    char str[MAX];
    no* a[12];

    Inicia_vPalavra(&h);
    Insere_palavra("para", &h);
    Insere_palavra("cada", &h);
    Insere_palavra("rosa", &h);
    Insere_palavra("rosa", &h);
    Insere_palavra("uma", &h);
    Insere_palavra("rosa", &h);
    Insere_palavra("e", &h);
    Insere_palavra("uma", &h);
    Insere_palavra("rosa", &h);
    OrdenaVET(&h);
    printf(  "Huffman Algorithm\n");
    for (i=0;i<n;i++){
        a[i] = create(h->Vet_palavra[i].p,h->Vet_palavra[i].peso);
    }
    while (n > 1)
    {
        ordena(a, n);
        printf("kjh");
        u = a[0]->peso + a[1]->peso;
        strcpy(h->Vet_palavra[9-n].p,a[0]->palavra);
        strcat(h->Vet_palavra[9-n].p,a[1]->palavra);
        ptr = create(h->Vet_palavra[9-n].p, u);
        ptr->direita = a[1];
        ptr->esquerda = a[0];
        a[0] = ptr;
        sdireita(a, n);
        n--;
    }
    Assign_Code(a[0], c, 0);
    getch();
    Delete_Tree(a[0]);

    return 0;
}
