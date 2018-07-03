#include <stdio.h>
#include <stdlib.h>
#include "arvoreb.h"

int main()
{
    Tipo_pag *arvore;
    reg teste;
    FILE *arquivo;
    Inicializa(&arvore);
    if((arquivo = fopen("arquivo.txt", "r")) == NULL)
    {
        printf("Nao foi possivel ler o arquivo!");
        return 0;
    }
    else
    {
        while(fscanf(arquivo, "%d", teste.chave!= EOF){
            Insere(teste,&arvore);
        }

    }
    fclose(arquivo);


}
