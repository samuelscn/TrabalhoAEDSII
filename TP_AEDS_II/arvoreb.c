#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvoreb.h"

void Inicializa(apontador *no)
{
    *no = NULL;

}

int Pesquisa(reg registro,apontador no)
{
    int i = 1;


    if(no == NULL)
    {
        printf("Registro nao encontrado");
        return 0; ///Registro não encontrado
    }
    while(i<no->n && registro.chave > no->registros[i-1].chave)
        i++ ;
    if(registro.chave == no->registros[i-1].chave)
    {
        printf("Registro Encontrado\n");
        registro = no->registros[i-1];
        return registro.chave ;
    }
    if(registro.chave < no->registros[i-1].chave)
        Pesquisa(registro,no->p[i-1]);
    else
        Pesquisa(registro,no->p[i]);


}


void Insere_pagina (apontador ap, reg registro, apontador pdir)
{
    short nao_achou;
    int k;
    k = ap->n;
    nao_achou = (k>0);
    while(nao_achou)
    {
        if(registro.chave>=ap->registros[k-1].chave)
        {
            nao_achou = FALSE;
            break;
        }
        ap->registros[k] = ap->registros[k-1];
        ap->p[k+1] = ap->p[k];
        k--;
        if(k<1)
            nao_achou = FALSE;
    }
    ap->registros[k] = registro;
    ap->p[k+1] = pdir;
    ap->n++;






}

void Ins(reg registro, apontador ap,short *Cresceu, reg *retorno_reg, apontador *retorno_apontador  )
{
    int i = 1;
    int j;
    apontador ap_temp;
    if(ap == NULL)
    {

        (*Cresceu) = TRUE;
        (*retorno_reg) = registro;
        (*retorno_apontador) = NULL;
        return; ///Coloquei o return e o código funciona, tirei e parava de funcionar


    }

    while ( i < ap->n && registro.chave > ap->registros[i-1].chave)
    {
        i++ ;


    }
    if(registro.chave == ap->registros[i-1].chave)
    {
        printf("Registro ja existe na arvore");
        (*Cresceu )= FALSE;
        return;
    }
    if(registro.chave<ap->registros[i-1].chave)
        i--;
    Ins(registro,ap->p[i],Cresceu,retorno_reg,retorno_apontador);
    if(!*Cresceu)
        return ;
    if(ap->n < MM)
    {
        Insere_pagina(ap,*retorno_reg,*retorno_apontador);
        (*Cresceu) = FALSE;
        return;
    }
    ap_temp = (apontador) malloc(sizeof(Tipo_pag));
    ap_temp->n = 0;
    ap_temp->p[0] = NULL;
    if(i<M+1)
    {
        Insere_pagina(ap_temp,ap->registros[MM-1],ap->p[MM]);
        ap->n -- ;
        Insere_pagina(ap,*retorno_reg,*retorno_apontador);
    }
    else
        Insere_pagina(ap_temp,*retorno_reg,*retorno_apontador);
    for ( j = M + 2; j<= MM; j++)
        Insere_pagina(ap_temp,ap->registros[j-1],ap->p[j]);
    ap->n = M;
    ap_temp->p[0] = ap->p[M+1];
    *retorno_reg = ap->registros[M];
    *retorno_apontador = ap_temp;
}


void Insere(reg registro, apontador *ap)
{
    short Cresceu;
    reg Retornoreg;
    Tipo_pag *ap_retorno, *ap_temp;
    Ins(registro, *ap,&Cresceu,&Retornoreg,&ap_retorno);
    if(Cresceu)
    {
        ap_temp = (Tipo_pag*) malloc(sizeof(Tipo_pag));
        ap_temp->n =1 ;
        ap_temp->registros[0] = Retornoreg;
        ap_temp->p[1] = ap_retorno;
        ap_temp->p[0] =  *ap;
        *ap = ap_temp;

    }

}

void Reconstitui (apontador p_pag,apontador p_pai,int posicao_pai, short *diminuiu)
{
    Tipo_pag *aux;
    int D_aux;
    int j;
    if( posicao_pai < p_pai->n)
    {
        aux = p_pai->p[posicao_pai+1];
        D_aux = (aux->n - M +1) /2 ;
        p_pag->registros[p_pag->n] = p_pai->registros[posicao_pai];
        p_pag->p[p_pag->n +1 ] = aux->p[0];
        p_pag->n ++ ;
        if(D_aux>0)
        {
            for(j=1; j<D_aux; j++)
                Insere_pagina(p_pag, aux->registros[j-1],aux->p[j]);
            p_pai->registros[posicao_pai] = aux->registros[D_aux - 1];
            aux->n -=D_aux;
            for(j=0; j<aux->n; j++)
                aux->registros[j] = aux->registros[j+D_aux];
            for(j=0; j<=aux->n; j++)
                aux->p[j] = aux->p[j+D_aux];
            *diminuiu = FALSE;
        }
        else
        {
            for(j=1; j<=M; j++)
                Insere_pagina(p_pag, aux->registros[j-1],aux->p[j]);
            free(aux);
            for(j = posicao_pai+1; j<p_pai->n; j++)
            {
                p_pai->registros[j-1] = p_pai->registros[j];
                p_pai->p[j] = p_pai->p[j+1];
            }
            p_pai->n -- ;
            if(p_pai->n >= M)
                *diminuiu = FALSE;
        }

    }
    else
    {
        aux = p_pai->p[posicao_pai - 1];
        D_aux = (aux->n - M +1) / 2 ;
        for(j = p_pag->n; j>=1; j--)
            p_pag->registros[j] = p_pag->registros[j-1];
        p_pag->registros[0] = p_pai->registros[posicao_pai - 1];
        for(j = p_pag->n; j>= 0; j--)
            p_pag->p[j+1] = p_pag->p[j];
        p_pag->n ++ ;
        if(D_aux > 0)
        {
            for(j = 1; j< D_aux; j++)
                Insere_pagina(p_pag,aux->registros[aux->n-j],aux->p[aux->n-j +1]);
            p_pag->p[0] = aux->p[aux->n -D_aux +1];
            p_pai->registros[posicao_pai - 1 ] = aux->registros[aux->n -D_aux ];
            aux->n -= D_aux;
            *diminuiu = FALSE;
        }
        else
        {
            for(j =1; j<=M; j++)
                Insere_pagina(aux,p_pag->registros[j-1],p_pag->p[j]);
            free(p_pag);
            p_pai->n --;
            if(p_pai->n >= M)
                *diminuiu = FALSE;
        }
    }

}

void Antecessor (apontador ap,int indice,apontador p_pai,short *diminuiu)
{
    if(p_pai->p[p_pai->n] != NULL)
    {
        Antecessor(ap,indice,p_pai->p[p_pai->n],diminuiu);
        if(*diminuiu)
        {
            Reconstitui(p_pai->p[p_pai->n],p_pai,p_pai->n,diminuiu);
            return;
        }
        ap->registros[indice - 1] = p_pai->registros[p_pai->n -1];
        p_pai->n --;
        *diminuiu = (p_pai->n < M);
    }

}
void Ret (int item, apontador *ap,short *diminuiu)
{
    int j;
    int indice = 1;
    apontador pag;
    if(*ap == NULL)
    {
        printf("Registro nao existente");
        *diminuiu = FALSE;
        return;

    }
    pag = *ap;
    while (indice < pag->n && item>pag->registros[indice-1].chave)
        indice ++ ;
    if(item == pag->registros[indice - 1].chave)
    {
        if(pag->p[indice -1 ] == NULL)
        {

            pag->n -- ;
            *diminuiu = (pag->n < M);
            for(j = indice; j<=pag->n; j++)
            {
                pag->registros[j-1] = pag->registros[j];
                pag->p[j]= pag->p[j+1];
            }
            return;
        }
        Antecessor(*ap,indice,pag->p[indice-1],diminuiu);
        if(*diminuiu) //Conferir se esse if não vai dar erro
            Reconstitui(pag->p[indice-1],*ap,indice-1,diminuiu);
        return;
    }
    if(item>pag->registros[indice-1].chave)
        indice ++;
    Ret(item,&pag->p[indice-1],diminuiu);
    if(*diminuiu)
        Reconstitui(pag->p[indice-1],*ap,indice-1,diminuiu  );

}
void Retira(int item, apontador *ap)
{
    short diminuiu;
    apontador aux;
    Ret(item,ap,&diminuiu);
    if(diminuiu && (*ap)->n == 0)
    {
        aux = *ap;
        *ap = aux->p[0];
        free(aux);
    }
}

void Printar (apontador ap,int nivel)
{
    int i;
    if(ap == NULL)
        return;
    printf("Nivel  %d :\n",nivel);
    for(i=0;i< ap->n;i++)
    {
        printf("Chave: %d\n",ap->registros[i].chave);

    }
    nivel++;
    for(i=0;i<=ap->n;i++)
    {
        Printar(ap->p[i],nivel);
    }

}

void Imprime (apontador p)
{
    int n=0;
    Printar(p,n);
}

void altura(apontador p)
{
    int h = 0;
    alturah(p,h);
    printf("Altura da arvore : %d\n",h);
}

void alturah(apontador p, int h)
{
    //printf("Altura: h : %d\n",h);
    //printf(" altura : %d\n",h);
    int i =0;
    if( p == NULL)
        imprime_altura(h);
        return;

    h++;
    for(i=0;i<=p->n;i++)
    {
        alturah(p->p[i],h);
    }
    /*for(i=0;i<=p->n;i++)
    {
        h++;
        alturah(p->p[i],h);
    }
    if(p == NULL)
    {
        imprime_altura(h);

    } */

   // printf("Altura da arvore %d \n",h);
    //h++;
        //alturah(p->p[i],&h);



   // printf("Altura da arvore : %d\n",h);


}

void imprime_altura(int h)
{
    printf("Altura da arvore : %d\n",h);
}

