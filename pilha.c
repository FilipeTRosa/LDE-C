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
desc_Stack * pop (desc_Stack * fstack){}
nodo * top (desc_Stack * fstack){}
int empty (desc_Stack * fstack){}
void makenull (desc_Stack * fstack){}
int lenght (desc_Stack * fstack){}
void printStack (desc_Stack * fStack){}
