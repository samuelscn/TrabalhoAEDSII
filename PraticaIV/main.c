#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "praticaIV.h"

int main()
{
    Armazena_palavra *h;

    Inicia_vPalavra(&h);
    Insere_palavra("para", &h);
    Insere_palavra("cada", &h);
    Insere_palavra("rosa", &h);
    Insere_palavra("rosa", &h);
    Insere_palavra("uma", &h);
    Insere_palavra("rosa", &h);
    Insere_palavra("e", &h);
    Insere_palavra("uma", &h);
    Insere_palavra("rosa", &h);
    Ordena(&h);
    Imprime(&h);
    return 0;
}
