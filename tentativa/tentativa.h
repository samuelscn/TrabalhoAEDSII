#ifndef TENTATIVA_H_INCLUDED
#define TENTATIVA_H_INCLUDED

#include<stdio.h>

#include<string.h>

#include<conio.h>

#include<stdlib.h>

#define MAX 10

typedef struct link

{

            int freq;

            char ch[MAX];

            struct link* right;

            struct link* left;

};

typedef struct link node;

void sorte(node *[], int);

node* create(char[], int);

void sright(node *[], int);

void Assign_Code(node*, int [], int);

void Delete_Tree(node *);





#endif // TENTATIVA_H_INCLUDED
