#ifndef TAD_NUMEROLINHAS_H_INCLUDED
#define TAD_NUMEROLINHAS_H_INCLUDED

//Definição de TADS
typedef struct{
    int Nlinhas; //Linha em que aparece no texto
}Numero_Linhas;

typedef struct Celula *Apontador; //apontador do tipo celula
typedef struct Celula{
    Numero_Linhas Item_Nlinhas; //Tad de linhas
    struct Celula *pProx;
}TAD_Celula;

typedef struct{
    Apontador pPrimeiro; //apontador para a primeira célula
    Apontador pUltimo; //apontador para a última célula
    int Total_linhas;//total de linha
}TAD_NumeroLinhas;

//Cabeçalho das funções
void Cria_Lnumero_Vazia(TAD_NumeroLinhas *pLinhas);
int Verifica_Lnumero_Vazia(TAD_NumeroLinhas *pLinhas);
int Alimenta_Lnumero(TAD_NumeroLinhas *pLinhas, int x);
int Remove_Lnumero(TAD_NumeroLinhas *pLinhas);
int Verifica_Lnumero_Existentes(TAD_NumeroLinhas *pLinhas, int x);
void Printa_Total_Nlinhas(TAD_NumeroLinhas *pLinhas);
void Printa_Lnumero(TAD_NumeroLinhas *pLinhas);

#endif // TAD_NUMEROLINHAS_H_INCLUDED
