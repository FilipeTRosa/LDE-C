#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musicas.h"
#include "pilha.h"

/* funcoes da pilha/stack */


desc_Stack * createStack (desc_Stack * fstack){
    desc_Stack * stack = (desc_Stack *) malloc (sizeof(desc_Stack));

    stack->first_stack = NULL;
    stack->last_stack = NULL;
    stack->lenght = 0;

    return stack;
}
desc_Stack * push (nodo * fnodo, desc_Stack * fstack){

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
desc_Stack * pop (desc_Stack * fstack){
   
    if (empty(fstac))
    {
        printf("Lista vazia");
        return flista;     
    }else
    {
        nodo * aux = fstack->first_stack;
        fstack->first_stack = aux->prox;
        fstack->lenght--;
        return fstack;
    }
    
}
nodo * top (desc_Stack * fstack){
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
void makenull (desc_Stack * fstack){}

int lenght (desc_Stack * fstack){
    return fstack->lenght;
}
void printStack (desc_Stack * fStack){
    nodo * aux = fstack->first_stack;
    while (aux != NULL)
    {
        imprimenodo(aux);
        aux = aux->prox;
    }
    
}
