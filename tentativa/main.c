#include <stdio.h>
#include <stdlib.h>
#include "tentativa.h"



main()

{

    node* ptr, * head;

    int i, n, total = 0, u, c[15];

    char str[MAX];

    node* a[12];

    int freq;



    printf(  "Huffman Algorithm\n");

    printf("\nEnter the no. of letter to be coded:");/*input
the no. of letters*/

    scanf("%d", &n);

    for (i = 0; i < n; i++)

    {

        printf("Enter the letter & frequency:");/*input the letter & frequency*/

        scanf("%s %d", str, &freq);

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

}


