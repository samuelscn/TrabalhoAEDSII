#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "praticaIV.h"

int main()
{
    node* ptr, * head;
    int j, n, total = 0, u, c[15];
    char str[24];
    node* a[12];
    int freq;
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
    Imprime(&h);
    printf(  "Huffman Algorithm\n\n\n\n\n");
    //Imprime(&h);
    printf("\nEnter the no. of letter to be coded:");/*input the no. of letters*/
    printf("ANTES DO FOR");
    //Imprime(&h);
    scanf("%d", &n);
        for (j = 0; j < n; j++)
            {
                Imprime(&h);
                //strcpy(str, h->Vet_palavra[j].p);
                //freq= h->Vet_palavra[j].peso;
                printf("%s", str);
                printf("%d", freq);
                a[j] = create(str, freq);
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
