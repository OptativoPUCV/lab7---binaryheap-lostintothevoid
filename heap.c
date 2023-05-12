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
  if(pq->size==0 || pq==NULL) 
    return NULL;
  else return pq->heapArray[0].data;
}

void prioritycorrect(Heap* pq){
  Heap* aux=createHeap();
  for(int k=pq->size; k!=0; k--){
    if(pq->heapArray[k]==pq->heapArray[0]){
      pq->size++;
      return;
    }
    if(pq->heapArray[k].priority>pq->heapArray[k-1].priority){
      
      aux->heapArray[0] = pq->heapArray[k-1];
      pq->heapArray[k-1]=pq->heapArray[k];
      pq->heapArray[k] = aux->heapArray[0];
    }
  }
  pq->size++;
}

void heap_push(Heap* pq, void* data, int priority){
  if(pq->size==pq->capac){
    pq->heapArray=(heapElem*) realloc(pq->heapArray,sizeof(heapElem*)*pq->capac*2);
    pq->capac= pq->capac*2;
  }
  pq->heapArray[pq->size].data=data;
  pq->heapArray[pq->size].priority=priority;
  prioritycorrect(pq);
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
