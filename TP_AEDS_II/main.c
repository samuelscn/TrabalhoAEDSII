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
    teste.chave = 105;
    Insere(teste,&arvore);
teste.chave = 25;
    Insere(teste,&arvore);
    teste.chave = 1;
    Insere(teste,&arvore);
    teste.chave = 17;
    Insere(teste,&arvore);
    teste.chave= 18 ;
    Insere(teste,&arvore);
    teste.chave = 29;
    Insere(teste,&arvore);
    teste.chave = 11;
    Insere(teste,&arvore);
    teste.chave = 12;
    Insere(teste,&arvore);
    teste.chave= 180 ;
    Insere(teste,&arvore);
    teste.chave = 251;
    Insere(teste,&arvore);
    teste.chave = 19;
    Insere(teste,&arvore);
    teste.chave = 172;
    Insere(teste,&arvore);
    teste.chave= 2 ;
    Insere(teste,&arvore);


    //Retira(10,&arvore);
    Imprime(arvore);
    altura(arvore);



    //Pesquisa(teste,arvore);
    //printf("%d",arvore->registros->chave);



    //arvore->registros[0].chave = 10;
    //arvore->registros [1].chave = 15;

    return 0;
}
