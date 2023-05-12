#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  heapElem* paquete =(heapElem*) pq->heapArray[0];
  if(paquete->data==NULL) return NULL;
  return paquete->data;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap* aux =(Heap*) malloc(sizeof(Heap));
  aux->capac=3;
  aux->size=0;
  aux->heapArray= (heapElem*) malloc(sizeof(heapElem)*aux->capac);
  return aux;
}
