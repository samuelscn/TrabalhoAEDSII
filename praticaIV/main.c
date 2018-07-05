#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "praticaIV.h"

int main()
{
    Armazena_palavra *h;

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


            node* ptr, * head;
            int i, n, total = 0, u, c[15];
            char str[24];
            node* a[12];
            int freq;
            printf(  "Huffman Algorithm\n");
            printf("\nEnter the no. of letter to be coded:");/*input
the no. of letters*/
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                strcpy(str, h->Vet_palavra[i].p);
                freq= h->Vet_palavra[i].peso;
                        a[i] = create(str, freq);
            }
            while (n > 1)
            {
                        sort(a, n);
                        u = a[0]->freq + a[1]->freq;
                        strcpy(str,a[0]->ch);
                        strcat(str,a[1]->ch);
                        ptr = create(str, u);
                        ptr->right = a[1];
                        ptr->left = a[0];
                        a[0] = ptr;
                        sright(a, n);
                        n--;
            }
            Assign_Code(a[0], c, 0);
            getch();
            Delete_Tree(a[0]);
    return 0;
}
