#include <stdio.h>
#include <stdlib.h>
#include "arvoreb.h"

int main()
{
    Tipo_pag *arvore;
    reg teste;
    int i;
    teste.chave = 10;
    Inicializa(&arvore);
   // Insere(teste,&arvore);
   // printf("%d",teste.chave);
    Insere(teste, &arvore);
   // Pesquisa(teste,arvore);
    teste.chave = 15;
    Insere(teste,&arvore);
    teste.chave = 20;
    Insere(teste,&arvore);
    teste.chave = 15;
    Insere(teste,&arvore);
    teste.chave = 25;
    Insere(teste,&arvore);
    teste.chave = 1;
    Insere(teste,&arvore);
    for(i=0;i<2;i++)
    {
        printf("%d\n",arvore->registros[i].chave);

    }

    //Retira(10,&arvore);
    Imprime(arvore);
    altura(arvore);



    //Pesquisa(teste,arvore);
    //printf("%d",arvore->registros->chave);



    //arvore->registros[0].chave = 10;
    //arvore->registros [1].chave = 15;

    return 0;
}
