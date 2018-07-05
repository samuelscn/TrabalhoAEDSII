#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TAD_NumeroLinhas.h"
#include "TAD_Palavras.h"
#include "TAD_Lista_Palavras.h"
#include "TAD_Letra_Alfabeto.h"
#include "TAD_Dicionario.h"

int main()
{   //Função de leitura de arquivo
    FILE *arquivo;
    TAD_Dicionario k;
    Itens_Vlista_Palavras v[400];
    char palavra[60];
    char quebra_linha;
    char ler_palavra[44];
    int cont;
    int opcao;
    int n_linha;

    Inicializa_Dicionario(&k); //Cria o dicionario vazio
    cont = 1;
    if((arquivo = fopen("arquivo.txt", "r")) == NULL){
        printf("Nao foi possivel ler o arquivo!");
        return 0;
    }else{
        while(fscanf(arquivo, "%s", palavra)!= EOF){   //Leitura das palavras do texto
            quebra_linha = fgetc(arquivo);
            Alimenta_Dicionario(&k, &palavra, cont);
            if(quebra_linha == '\n')
                cont ++;
        }
    }
    fclose(arquivo);

    printf("Seja Bem-vindo ao Dicionario Virtual:\n");
    printf("Digite 1 para: Adicionar nova palavra no dicionario.\n");
    printf("Digite 2 para: Imprimir palavras por letra do alfabeto especifica.\n");
    printf("Digite 3 para: Imprimir todas as palavras existentes no dicionario.\n");
    printf("Digite 4 para: Remover palavra a sua escolha.\n");
    printf("Digite 5 para: Ordenar palavras por letra do alfabeto especifica.\n");
    printf("Digite 6 para: Ordenar todas as palavras existentes no dicionario.\n");
    printf("Digite 7 para: Sair\n");
    scanf("%d",&opcao);
   do{// Seleçiona qual opção o usúario deseja
    switch(opcao)
    {
    case 1:
        printf("\nEntre com a palavra :\n");
        scanf("%s",&ler_palavra);
        fflush(stdin);
        printf("\nEntre com a linha :\n");
        scanf("%d",&n_linha);
        fflush(stdin);
        Alimenta_Dicionario(&k,&ler_palavra,n_linha);
        printf("\nOpcao\n");
        scanf("%d",&opcao);
        break;

    case 2:
        printf("\nEntre com a letra a ser imprimida: \n");
        scanf("%s",&ler_palavra);
        Printa_Dicionario_Letra_Especifica(&k, &ler_palavra);
        printf("\nOpcao\n");
        scanf("%d",&opcao);
        break;

    case 3:
        printf("Exibir todo o dicionario\n");
        Printa_Dicionario_Total(&k);
        printf("\nOpcao\n");
        scanf("%d",&opcao);
        break;
     case 4:
        printf("Entre com a palavra a ser removida: \n");
        scanf("%s", &ler_palavra);
        Remove_Palavra_Dicionario(&k, &ler_palavra);
        printf("\nOpcao\n");
        scanf("%d",&opcao);
        break;
     case 5:
        printf("Entre com a letra a ser escolhida para ordenar: \n");
        scanf("%s", &ler_palavra);
        Ordena_Dicionario_Letra_Especifica(&k, &ler_palavra);
        printf("\nOpcao\n");
        scanf("%d",&opcao);
        break;
     case 6:
        Ordena_Dicionario_Total(&k);
        printf("\nOpcao\n");
        scanf("%d",&opcao);
        break;
     case 7:
        break;
     default:
        printf("Opcao invalida, digite novamente:\n");
        scanf("%d",&opcao);
    }
   }while(opcao!= 7);
    return 0;
}
