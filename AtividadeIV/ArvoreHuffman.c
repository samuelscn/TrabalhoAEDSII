#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreHuffman.h"

int CriaNo(char palavra, int peso){
    Heap pAux;

    pAux = (Heap)malloc(sizeof(Huffman_No));
    pAux->pEsq = NULL;
    pAux->pDir = NULL;
    pAux->peso = peso;
    strcpy(pAux->palavra, palavra);

    return pAux;
}

int CriaHeap(int maximo){
    Huffman *MiniHeap;

    MiniHeap = (Huffman*)malloc(sizeof(Huffman));
    MiniHeap->tamanho = 0;
    MiniHeap->maximo = maximo;
    MiniHeap->vetor = (Heap*)malloc(MiniHeap->maximo*sizeof(Heap));

    return MiniHeap;
}

int Tamanho_Um(Huffman *Mini){
    return (Mini->tamanho == 1);
}

void InserirNovoNoHeap(Huffman *pMini, Heap pMiniNo){
    ++pMini->tamanho;
    int i;
    i = pMini->tamanho - 1;
    while(i && pMiniNo->peso < pMini->vetor[(i - 1 )/2]->peso){
        pMini->vetor[i] = pMini->vetor[(i - 1)/2];
        i = (i - 1) / 2;
    }
    pMini->vetor[i] = pMiniNo;
}

void CriaMiniHeap(Huffman *MiniHeap){
    int n;
    int i;

    n = MiniHeap->tamanho - 1;

    for(i = (n - 1)/2; i >= 0; i--){
        mHeap(MiniHeap, i);
    }
}

void mHeap(Huffman *Mini, int aux){
    int menor;
	int esq;
	int dir;

	menor = aux;
	esq = 2 * aux + 1;
	dir = 2 * aux + 2;

	if (esq < Mini->tamanho && Mini->vetor[esq]->peso < Mini->vetor[menor]->peso){
        menor = esq;
	}

	if (dir < Mini->tamanho && Mini->vetor[dir]->peso < Mini->vetor[menor]->peso){
        menor = dir;
	}

	if (menor != aux) {
		HeapAux(&Mini->vetor[menor], &Mini->vetor[aux]);
		CriaMiniHeap(Mini);
	}
}

void HeapAux(Heap *a, Heap *b){
    Heap t = *a;
    *a = *b;
    *b = t;
}

void printArr(int vet[], int n){
	int i;
	for (i = 0; i < n; ++i)
		printf("%d", vet[i]);

	printf("\n");
}

int Folha(Heap raiz){
    return !(raiz->pEsq) && !(raiz->pDir);
}

int CriaDefinitivoMiniHeap(char palavra[], int peso[], int tamanho){

	Huffman Mini = CriaHeap(tamanho);

	for (int i = 0; i < tamanho; ++i){
		Mini->vetor[i] = CriaNo(palavra[i], peso[i]);
	}
	Mini->tamanho = tamanho;
	CriaMiniHeap(Mini);

	return Mini;
}

int IniciaArvore(char palavra[], int peso[], int tamanho){
	Heap esq, dir, cima;
	Huffman Mini = CriaDefinitivoMiniHeap(palavra, peso, tamanho);

	while (!Tamanho_Um(Mini)) {

        left = extractMin(Mini);
		right = extractMin(Mini);

		top = newNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;

		insertMinHeap(minHeap, top);
	}

	return extractMin(minHeap);
}

int extractMin(Huffman *Mini){

	Heap pAux = Mini->vetor[0];
	Mini->vetor[0] = Mini->vetor[Mini->tamanho - 1];

	--Mini->tamanho;
	mHeap(Mini, 0);

	return pAux;
}
