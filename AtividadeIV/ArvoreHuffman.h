#ifndef ARVOREHUFFMAN_H_INCLUDED
#define ARVOREHUFFMAN_H_INCLUDED

typedef struct huffman_no *Heap;

typedef struct huffman_no{
    char palavra[24];
    int peso;
    Heap pEsq, pDir;
}Huffman_No;

typedef struct{
    int tamanho;
    int maximo;
    Heap *vetor;
}Huffman;

int CriaNo(char palavra, int peso);
int CriaHeap(int maximo);
int Tamanho_Um(Huffman *Mini);
void InserirNovoNoHeap(Huffman *pMini, Heap pMiniNo);
void CriaMiniHeap(Huffman *MiniHeap);
void mHeap(Huffman *Mini, int aux);
void HeapAux(Heap *a, Heap *b);
void printArr(int vet[], int n);
int Folha(Heap raiz);
int CriaDefinitivoMiniHeap(char palavra[], int peso[], int tamanho);
int IniciaArvore(char palavra[], int peso[], int tamanho);
int extractMin(Huffman *Mini);

#endif // ARVOREHUFFMAN_H_INCLUDED
