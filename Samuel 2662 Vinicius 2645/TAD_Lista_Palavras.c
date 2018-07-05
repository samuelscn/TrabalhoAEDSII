#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TAD_NumeroLinhas.h"
#include "TAD_Palavras.h"
#include "TAD_Lista_Palavras.h"

/* Cria um vetor palavra vazio
para receber a lista de palavras em cada posi��o */
void Cria_Vlista_Palavra(TAD_Lista_Palavras *pLista_Palavra){
    pLista_Palavra->pPrimeiro = NULL;
    pLista_Palavra->pUltimo = pLista_Palavra->pPrimeiro;
    pLista_Palavra->contapalavra = 0;
}

/*Inicia o vetor comparacao*/
void Inicia_comparacao_movimentacao(Itens_Vlista_Palavras *a){
    a->comparacao = 0;
    a->movimentacao = 0;
}
/* Verifica se j� existe uma palavra existente
em alguma posi��o do vetor */

int Verifica_Palavra_Existente(TAD_Lista_Palavras *pLista_Palavra, char *p){
    int i;

    if(pLista_Palavra->pPrimeiro == pLista_Palavra->pUltimo) // Verifica se o vetor est� vazio
        return 0;
    else{//Percorre o vetor fazendo a busca
        for(i = 0; i < pLista_Palavra->contapalavra; i++){
            if(strcmp(pLista_Palavra->Vetor_Lpalavras[i].PontePalavra.Vpalavra.palavra, p) == 0)
                return 1;
        }
    }
    return 0;
}

/* Insere em cada posi��o do vetor um Tad com
a palavra e o n�mero da linha em que aparece */

int Alimenta_Vlista_Palavra(TAD_Lista_Palavras *pLista_Palavra, char *p, int num){
    int i;

    if(pLista_Palavra->pUltimo == 400)
        return 0;
    else if((Verifica_Palavra_Existente(pLista_Palavra, p)) == 0){ //Verifica se j� existe a palavra no vetor
        Cria_Vpalavras_Vazia(&(pLista_Palavra->Vetor_Lpalavras[pLista_Palavra->pUltimo].PontePalavra)); //Utiliza a fun��o para criar espa�o para o tad
        Alimenta_Vpalavras(&(pLista_Palavra->Vetor_Lpalavras[pLista_Palavra->pUltimo].PontePalavra), p); //Alimenta o vetor com tad de palavras
        Alimenta_Vpalavras_Lnumero(&(pLista_Palavra->Vetor_Lpalavras[pLista_Palavra->pUltimo].PontePalavra), num); //Insere o n�mero no tad de NumeroLinhas dentro do Tad Palavras no vetor
        pLista_Palavra->pUltimo++; //contador de posi��o
        pLista_Palavra->contapalavra++; //Contador de palavras
        return 1;
    }else{ //Se o vetor j� tiver a palavra, apenas adiciona a linha em que ela aparece novamente
        for(i = 0; i < pLista_Palavra->contapalavra; i++){
            if((strcmp(pLista_Palavra->Vetor_Lpalavras[i].PontePalavra.Vpalavra.palavra, p)) == 0){ //Procura onde est� a palavra lida novamente
                Alimenta_Vpalavras_Lnumero(&(pLista_Palavra->Vetor_Lpalavras[i].PontePalavra), num); // Insere a linha
                return 1;
            }
        }
    }
}
//Remove o tad com a palavra do vetor

int Remove_Vlista_Palavra_Dada(TAD_Lista_Palavras *pLista_Palavra, char *p){
    int i, j;

    if(pLista_Palavra->pPrimeiro == pLista_Palavra->pUltimo) //Verifica se o vetor est� cheio
        return 0;
    else{
        for(i = 0; i < pLista_Palavra->contapalavra; i++){
            if((strcmp(pLista_Palavra->Vetor_Lpalavras[i].PontePalavra.Vpalavra.palavra, p)) == 0){ //Procura pela palavra
                for (j = i + 1; j < pLista_Palavra->contapalavra; j++)
                    pLista_Palavra->Vetor_Lpalavras[j-1] = pLista_Palavra->Vetor_Lpalavras[j]; //Remo��o do tad com a palavra
                pLista_Palavra->pUltimo--;//Diminui o �ndice �ltimo
                pLista_Palavra->contapalavra--;//Diminui o contador de palavras
                printf("Palavra removida com sucesso!\n");
                return 1;
            }
        }
        printf("Palavra nao existe!\n");
        return 0;
    }
}
/*Imprime o total de Palavra */
void Printa_Total_Palavras(TAD_Lista_Palavras *pLista_Palavra){
    printf("Total de palavras: %d\n", pLista_Palavra->contapalavra);
}

/* Imprime a lista de palavras */
void Printa_Vlista_Palavra(TAD_Lista_Palavras *pLista_Palavra){
    int i;
    /*Percorre o dicionario chamando a fun��o
    para impress�o */

    Printa_Total_Palavras(pLista_Palavra);
    for(i = 0; i < pLista_Palavra->contapalavra; i++){
        Printa_Vpalavras(&(pLista_Palavra->Vetor_Lpalavras[i].PontePalavra));
    }
}

//Algoritmo de ordena��o, Booble Sort

void Ordena_BoobleS_Char(TAD_Lista_Palavras *pLista_Palavra, Itens_Vlista_Palavras *a){
    int i, j,
    comparacao = 0,
    movimentacao = 0;
    Itens_Vlista_Palavras aux;
    clock_t Ticks[2]; //Fun��o para c�lculo de tempo
    Ticks[0] = clock(); //Fun��o para c�lculo de tempo
    //Ordena��o do vetor de palavras
    //Controla as passadas
    for(i = 0; i < pLista_Palavra->contapalavra - 1; i++){
        //Percorre o vetor ordenando
        for(j = 1; j < pLista_Palavra->contapalavra - i; j++){
            if(strcmp(a[j].PontePalavra.Vpalavra.palavra, a[j-1].PontePalavra.Vpalavra.palavra) < 0 ){
                strcpy(aux.PontePalavra.Vpalavra.palavra, a[j].PontePalavra.Vpalavra.palavra);
                strcpy(a[j].PontePalavra.Vpalavra.palavra, a[j-1].PontePalavra.Vpalavra.palavra);
                strcpy(a[j-1].PontePalavra.Vpalavra.palavra, aux.PontePalavra.Vpalavra.palavra);
                movimentacao++; //Calcula quantidade de movimenta��es
            }
            comparacao++;//Calcula quantidade de compara��es
        }
    }
    printf("Numero de comparacoes do algoritmo: %d\n", comparacao);
    printf("Numero de movimentacoes do algoritmo: %d\n", movimentacao);
    //Imprime o vetor j� ordenado
    for(i = 0; i < pLista_Palavra->contapalavra; i++){
        printf("Palavra: %s\n", a[i].PontePalavra.Vpalavra.palavra);

    }
    Ticks[1] = clock();//Fun��o de tempo
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC; //Fun��o de tempo
    printf("Tempo gasto: %g ms.", Tempo); //Mostra o tempo gasto em cada ordena��o

    return 0;
}


//Algoritmo de ordena��o SelectSort
void Ordena_SelectS_Char(TAD_Lista_Palavras *pLista_Palavra, Itens_Vlista_Palavras *a){
    int i, j, Min,
    comparacao = 0,
    movimentacao = 0;
    Itens_Vlista_Palavras aux;
    clock_t Ticks[2]; //Fun��o de tempo
    Ticks[0] = clock();//Fun��o de tempo
    /*Procura pela palavra que vem primeiro
    na ordem alfab�tica */

    //Percorre o dicion�rio
    for(i = 0; i < pLista_Palavra->contapalavra - 1; i++){
        Min = i;//Menor recebe i
        /*Percorre o vetor procurando pela palavra que vem antes
        de acordo com o alfabeto */
        for(j = i + 1; j < pLista_Palavra->contapalavra; j++){
            if(strcmp(a[j].PontePalavra.Vpalavra.palavra, a[Min].PontePalavra.Vpalavra.palavra) < 0)
                Min = j;
            comparacao++;
        }
        //Faz a troca do menor com o vetor da  posi��o i
        strcpy(aux.PontePalavra.Vpalavra.palavra, a[Min].PontePalavra.Vpalavra.palavra);
        strcpy(a[Min].PontePalavra.Vpalavra.palavra, a[i].PontePalavra.Vpalavra.palavra);
        strcpy(a[i].PontePalavra.Vpalavra.palavra, aux.PontePalavra.Vpalavra.palavra);
        movimentacao++;
    }
    printf("Numero de comparacoes do algoritmo: %d\n", comparacao);
    printf("Numero de movimentacoes do algoritmo: %d\n", movimentacao);
    for(i = 0; i < pLista_Palavra->contapalavra; i++){
        printf("Palavra: %s\n", a[i].PontePalavra.Vpalavra.palavra);
    }
    Ticks[1] = clock();//Fun��o de tempo
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;//Fun��o de tempo
    printf("Tempo gasto: %g ms.", Tempo);//Imprime o tempo gasto

    return 0;
}

//Algoritmo de ordean��o Insert Sort

void Ordena_InsertS_Char(TAD_Lista_Palavras *pLista_Palavra, Itens_Vlista_Palavras *a){
    int i, j,
    comparacao = 0,
    movimentacao = 0;
    Itens_Vlista_Palavras aux;
clock_t Ticks[2];//Fun��o de tempo
    Ticks[0] = clock();//Fun��o de tempo

    //Percorre o vetor
    for(i = 1; i < pLista_Palavra->contapalavra; i++){
        strcpy(aux.PontePalavra.Vpalavra.palavra, a[i].PontePalavra.Vpalavra.palavra);
        j = i - 1;// j passa a estar uma posi��o atr�s do i
        //Compara a palavra atual(i) com os anteriores e arrasta os maiores para posi��o j+1
        while((j >=0 ) && ((strcmp(aux.PontePalavra.Vpalavra.palavra, a[j].PontePalavra.Vpalavra.palavra) < 0))){
            //arrasta o j, para a pr�xima posi��o
            strcpy(a[j+1].PontePalavra.Vpalavra.palavra, a[j].PontePalavra.Vpalavra.palavra);
            j--;
            movimentacao++;
        }
        //Insere a palavra nna posi��o correta
        strcpy(a[j+1].PontePalavra.Vpalavra.palavra, aux.PontePalavra.Vpalavra.palavra);
        movimentacao++;
        comparacao++;
    }
    printf("Numero de comparacoes do algoritmo: %d\n", comparacao);
    printf("Numero de movimentacoes do algoritmo: %d\n", movimentacao);
    for(i = 0; i < pLista_Palavra->contapalavra; i++){
        printf("Palavra: %s\n", a[i].PontePalavra.Vpalavra.palavra);
    }
    Ticks[1] = clock();//Fun��o de tempo
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;//Fun��o de tempo
    printf("Tempo gasto: %g ms.", Tempo);//Fun��o de tempo

    return 0;
}

//Algoritmo de ordena��o Shellsort

void Ordena_ShellS_Char(TAD_Lista_Palavras *pLista_Palavra, Itens_Vlista_Palavras *a){
    int i, j, h = 1,
    comparacao = 0,
    movimentacao = 0;
    Itens_Vlista_Palavras aux;
    clock_t Ticks[2];//Fun��o de tempo
    Ticks[0] = clock();//Fun��o de tempo

    do{ //Calcula a sequ�ncia a ser usada
        h = ((h * 3) + 1);
    }while (h < pLista_Palavra->contapalavra);
    do{
        //Calcula o h da pr�xima passada
        h = h/3;
        //Controla as passadas do algoritmo pela sequ�ncia
        for(i = h; i < pLista_Palavra->contapalavra ; i++){
            strcpy(aux.PontePalavra.Vpalavra.palavra, a[i].PontePalavra.Vpalavra.palavra);
            j = i;
            //Compara a palavra atual com a palavra da posi��o j-h
            while ((strcmp(a[j-h].PontePalavra.Vpalavra.palavra, aux.PontePalavra.Vpalavra.palavra)) > 0){
                strcpy(a[j].PontePalavra.Vpalavra.palavra, a[j-h].PontePalavra.Vpalavra.palavra);
                j = j - h; //Descrece o j
                movimentacao++;
                if(j < h)
                    break;
            }
            //Faz a troca e coloca as palavras nos lugares corretos
            strcpy(a[j].PontePalavra.Vpalavra.palavra, aux.PontePalavra.Vpalavra.palavra);
            movimentacao++;
            comparacao++;
        }
    }while (h != 1);
    printf("Numero de comparacoes do algoritmo: %d\n", comparacao);
    printf("Numero de movimentacoes do algoritmo: %d\n", movimentacao);
    for(i = 0; i < pLista_Palavra->contapalavra; i++){
        printf("Palavra: %s\n", a[i].PontePalavra.Vpalavra.palavra);
    }
    Ticks[1] = clock();//Fun��o de tempo
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;//Fun��o de tempo
    printf("Tempo gasto: %g ms.", Tempo);//Fun��o de tempo

    return 0;
}

//Algoritmo de ordena��o Quick Sort

void QuickS_Char(TAD_Lista_Palavras *pLista_Palavra, Itens_Vlista_Palavras *a){
    int i;
    clock_t Ticks[2];//Fun��o de tempo
    Ticks[0] = clock();//Fun��o de tempo

    //Utiliza a fun��o ordena para ir ordenando o vetor
    Ordena(0, pLista_Palavra->contapalavra - 1, a); // Passa par�metros iniciais
    for(i = 0; i < pLista_Palavra->contapalavra; i++){
        printf("Palavra: %s\n", a[i].PontePalavra.Vpalavra.palavra);
    }
    Ticks[1] = clock();//Fun��o de tempo
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;//Fun��o de tempo
    printf("Tempo gasto: %g ms.\n", Tempo);//Fun��o de tempo
    printf("Comparacao: %d\n", a->comparacao);
    printf("Movimentacao: %d\n", a->movimentacao);
    return 0;
}

void Ordena(int Esq, int Dir, Itens_Vlista_Palavras *a){
    int i, j, k;
    /*Cria as parti��es neces�rias para
    a ordena��o do vetor*/

    Particao(Esq, Dir, &i, &j, a);
    if (Esq < j)
        Ordena(Esq, j, a);
    if (i < Dir)
        Ordena(i, Dir, a);
}

//Ordena as parti��es criadas
void Particao(int Esq, int Dir, int *i, int *j, Itens_Vlista_Palavras *a){
    Itens_Vlista_Palavras aux, pivo;

    *i = Esq;
    *j = Dir;
    //Calcula o piv� a ser usado
    strcpy(pivo.PontePalavra.Vpalavra.palavra, a[((*i+*j)/2)].PontePalavra.Vpalavra.palavra);
    do{
        /*Compara o piv� com as palavras da esquerda
        at� o piv� for menor que a posil��o i do vetor pela esquerda*/
        a->comparacao++;
        while(strcmp(pivo.PontePalavra.Vpalavra.palavra, a[*i].PontePalavra.Vpalavra.palavra) > 0){
            a->comparacao++;
            (*i)++;
        }
        a->comparacao++;
        /*Compara o piv� com as palavras da direita
        at� o piv� ser maior do a posi��o j do vetor pela direita */
        while(strcmp(pivo.PontePalavra.Vpalavra.palavra, a[*j].PontePalavra.Vpalavra.palavra) < 0){
            a->comparacao++;
            (*j)--;
        }
        a->comparacao++;
        if(*i <= *j){
            //Faz a troca de posi�oes das palavras na posi��o i e j
            strcpy(aux.PontePalavra.Vpalavra.palavra, a[*i].PontePalavra.Vpalavra.palavra);
            strcpy(a[*i].PontePalavra.Vpalavra.palavra, a[*j].PontePalavra.Vpalavra.palavra);
            strcpy(a[*j].PontePalavra.Vpalavra.palavra, aux.PontePalavra.Vpalavra.palavra);
            (*i)++;
            (*j)--;
            a->movimentacao++;
        }
    }while(*i <= *j);
}

void Ordena_HeapS_Char(TAD_Lista_Palavras *pLista_Palavra, Itens_Vlista_Palavras *a){
    int Esq, Dir, n, i;
    Itens_Vlista_Palavras aux;
    clock_t Ticks[2];//Fun��o de tempo
    Ticks[0] = clock();//Fun��o de tempo
    Constroi(a, pLista_Palavra);//Chama a fun��o de constru��o
    Esq = 0;//Marcador Esquerda
    Dir = pLista_Palavra->contapalavra - 1;//Marcador Direita
    //Percorre at� direita for <= 0
    while(Dir > 0){
        strcpy(aux.PontePalavra.Vpalavra.palavra, a[0].PontePalavra.Vpalavra.palavra);
        strcpy(a[0].PontePalavra.Vpalavra.palavra, a[Dir].PontePalavra.Vpalavra.palavra);
        strcpy(a[Dir].PontePalavra.Vpalavra.palavra, aux.PontePalavra.Vpalavra.palavra);
        Dir--;
        Refaz(Esq, Dir, a);
        a->movimentacao++;
        a->comparacao++;
    }
    for(i = 0; i < pLista_Palavra->contapalavra; i++){
        printf("Palavra: %s\n", a[i].PontePalavra.Vpalavra.palavra);
    }
    Ticks[1] = clock();//Fun��o de tempo
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;//Fun��o de tempo
    printf("Tempo gasto: %g ms.\n", Tempo);//Fun��o de tempo
    printf("Comparacao: %d\n", a->comparacao);
    printf("Movimentacao: %d\n", a->movimentacao);
    return 0;
}

//Fun��o de constru��o do heap
void Constroi(Itens_Vlista_Palavras *a, TAD_Lista_Palavras *pLista_Palavra){
    int Esq, n;

    n = pLista_Palavra->contapalavra - 1;
    Esq = n/2+1;//Calcula a esquerda(piv�)
    while(Esq > 0){
        Esq--;
        Refaz(Esq, n, a);//Chama a fun��o refaz
    }
}

//Fun��o para refazer o heap

void Refaz(int Esq, int Dir, Itens_Vlista_Palavras *a){
    int j = Esq * 2;
    Itens_Vlista_Palavras aux;

    strcpy(aux.PontePalavra.Vpalavra.palavra, a[Esq].PontePalavra.Vpalavra.palavra);
    while(j <= Dir){//Compara o j com direita
        if((j < Dir) && (strcmp(a[j].PontePalavra.Vpalavra.palavra, a[j+1].PontePalavra.Vpalavra.palavra) < 0))
            j++;
            a->comparacao++;
        if(strcmp(aux.PontePalavra.Vpalavra.palavra, a[j].PontePalavra.Vpalavra.palavra) >= 0)
            break;
            a->comparacao++;
        strcpy(a[Esq].PontePalavra.Vpalavra.palavra, a[j].PontePalavra.Vpalavra.palavra);
        Esq = j;
        j = Esq * 2;
    }
    strcpy(a[Esq].PontePalavra.Vpalavra.palavra, aux.PontePalavra.Vpalavra.palavra);
}
/* Alimenta o vetor copia
que ser� usado nas ordena��es */
void Alimenta_Vetor_Copia(TAD_Lista_Palavras *pLista_Palavra){
    int i;

    for(i = 0; i < pLista_Palavra->contapalavra; i++){
        strcpy(pLista_Palavra->Copia_Vetor[i].PontePalavra.Vpalavra.palavra, pLista_Palavra->Vetor_Lpalavras[i].PontePalavra.Vpalavra.palavra);
    }
}
/*Imprime o vetor normal
desordenado */
void Printa_Vetor_Desordenado(TAD_Lista_Palavras *pLista_Palavra){
    int i;

    for(i = 0; i < pLista_Palavra->contapalavra; i++){
        printf("Palavra: %s\n", pLista_Palavra->Vetor_Lpalavras[i].PontePalavra.Vpalavra.palavra);
    }
}
