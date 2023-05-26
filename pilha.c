#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musicas.h"
#include "pilha.h"

/* funcoes da pilha/stack */


desc_Stack * createStack (){
    desc_Stack * stack = (desc_Stack *) malloc (sizeof(desc_Stack));

    stack->first_stack = NULL;
    stack->last_stack = NULL;
    stack->lenght = 0;

    return stack;
}
desc_Stack * pushStack (nodo * fnodo, desc_Stack * fstack){

    if(empty(fstack)){//pilha vazia
        fstack->first_stack = fnodo;
        fstack->last_stack = fnodo;
        fstack->lenght ++;
        return fstack;
    }else{
        nodo * aux = fstack->first_stack;
        fnodo->prox = aux;
        fstack->first_stack = fnodo;
        fstack->lenght++;
        return fstack;
    }

}
desc_Stack * popStack (desc_Stack * fstack){
   
    if (empty(fstack))
    {
        printf("Lista vazia");
        return fstack;     
    }else
    {
        nodo * aux = fstack->first_stack;
        fstack->first_stack = aux->prox;
        fstack->lenght--;
        return fstack;
    }
    
}
nodo * topStack (desc_Stack * fstack){
    return fstack->first_stack;    
}
int empty (desc_Stack * fstack){
    if (fstack->lenght == 0)
    {
        return 1;
    }else
    {
        return 0;
    }
}
void makenullStack (desc_Stack * fstack){
    fstack->first_stack = NULL;
    fstack->lenght = 0;
}

int lenghtStack (desc_Stack * fstack){
    return fstack->lenght;
}
void printStackStack (desc_Stack * fstack){
    nodo * aux = fstack->first_stack;
    while (aux != NULL)
    {
        imprimenodo(aux);
        aux = aux->prox;
    }
    
}
