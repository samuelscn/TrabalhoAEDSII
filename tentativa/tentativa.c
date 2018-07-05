#include "tentativa.h"

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
