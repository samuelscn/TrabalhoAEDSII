#ifndef PRATICAIV_H_INCLUDED
#define PRATICAIV_H_INCLUDED

typedef struct{
    char p[24];
    int peso;
}Palavra;

typedef struct{
    Palavra Vet_palavra[10];
}Armazena_palavra;

void Inicia_vPalavra(Armazena_palavra *pPalavra);
void Insere_palavra(char *vai, Armazena_palavra *pPalavra);
void Ordena(Armazena_palavra *pPalavra);
void Imprime(Armazena_palavra *pPalavra);

#endif // PRATICAIV_H_INCLUDED
