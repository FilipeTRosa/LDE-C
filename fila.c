#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musicas.h"
#include "pilha.h"
#include "fila.h"

/*
typedef struct desc_queue{
struct nodo *head;
struct nodo *tail;
int tamanho;
}desc_queue;

*/

desc_queue * createQueue (){
    desc_queue * novaQueue = (desc_queue *) malloc (sizeof(desc_queue));
    novaQueue->head = NULL;
    novaQueue->tail = NULL;
    novaQueue->tamanho = 0;

    return novaQueue;
}

void * resetQueue (desc_queue * fqueue){
     fqueue->head = NULL;
     fqueue->tail = NULL;
     fqueue->tamanho = 0;
}

desc_queue * deleteQueue (desc_queue * fqueue){}

int emptyQueue (desc_queue * fqueue){
    if (fqueue->tamanho == 0)
    {
        return 1;
    }else
    {
        return 0;
    }    
}

desc_queue * enqueue (desc_queue * fqueue, nodo * fnodo){
    
    if (fqueue->tamanho == 0)
    {   
        fqueue->head = fnodo;
        fqueue->tail = fnodo;
        fqueue->tamanho++;
        return fqueue;        
    }else
    {
        nodo * aux = fqueue->head;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = fnodo;
        fnodo->ant = aux;
        fqueue->tail = fnodo;
        fqueue->tamanho++;
        return fqueue;
    }
    
}

nodo * dequeue (desc_queue * fqueue){
    
    if (fqueue->tamanho == 0)
    {
        printf("Lista Vazia.\n");
        return fqueue->head;
    }else
    {
        nodo * fnodo = fqueue->head;
       if (fqueue->tamanho == 1)
       {
            resetQueue(fqueue);
            return fnodo;
       }
               
    }
    
    
}

int lenghtQueue (desc_queue * fqueue){}

void showQueue (desc_queue * fqueue){}



