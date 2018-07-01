#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED
#define M 2
#define MM  (M * 2)
#define FALSE 0
#define TRUE  1

typedef struct
{
    int chave;

}reg;

typedef struct Tipo_pag *apontador;

typedef struct Tipo_pag
{
    int n;
    reg registros[MM];
    apontador p [MM +1];

} Tipo_pag;


void Inicializa(apontador *no) ;
int Pesquisa(reg registro,apontador no);
void Insere_pagina (apontador ap, reg registro, apontador pdir);
void Ins(reg registro, apontador ap,short *Cresceu, reg *retorno_reg, apontador *retorno_apontador  );
void Insere(reg registro , apontador *ap);
void Reconstitui (apontador p_pag,apontador p_pai,int posicao, short *diminuiu);
void Antecessor (apontador ap,int indice,apontador p_pai,short *diminuiu);
void Ret (int item, apontador *ap,short *diminuiu);
void Retira(int item, apontador *ap);
void Printar (apontador ap,int nivel);
void Imprime (apontador p);
void altura(apontador p);
void alturah(apontador p, int h);
void imprime_altura(int h);
#endif // ARVOREB_H_INCLUDED
