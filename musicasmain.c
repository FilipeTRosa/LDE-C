#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musicas.h"
#include "pilha.h"
#include "fila.h"

int main (){

    desc_Playlist * lista = NULL;
    desc_Stack * stack = NULL;
    desc_queue * queue = NULL;
    nodo * nodo = NULL;
    musica * musica = NULL;
    

    char titulo [256], artista [256], letra[256];
    int opcaoMenu = 0, posicao = 0, menuPrincipal = 0, menuStack = 0, menuQueue = 0;

    do //inicio menu seleção de menu
    {
        printf("\nBem vindo ao Menu Principal!\n");
        printf("1 - Lista - LDE. \n");
        printf("2 - Pilha / Stack. \n");
        printf("3 - Fila / Queue. \n");
        printf("5 - Sair.\n");
        setbuf(stdin, NULL);
        scanf("%d", &menuPrincipal);

        switch (menuPrincipal)
        {
        case 1:
            //LDE
            do{
                setbuf(stdin, NULL);
                printf("\n -*/-*/-*/ [MENU LDE] -*/-*/-*/ \n");
                printf("1 = Criar nova Lista: \n");
                printf("2 = Criar nova Musica:\n");
                printf("3 = Inserir na lista\n");
                printf("4 = Imprimir lista\n");
                printf("5 = Altera musica em uma posicao desejada\n");
                printf("6 = Remover um item da lista\n");
                printf("7 = Buscar uma posicao na lista.\n");
                printf("8 = Voltar ao menu principal!\n");
                scanf("%d", &opcaoMenu);

                switch(opcaoMenu){

                    case 1:
                        //cria lista
                        lista = criaLista();
                        break;
                    case 2:
                        //cria musica
                        musica = criaMusica();
                        //printf("\n Musica criada\n\n[Titulo] = %s[Artista] = %s[Letra] = %s\n\n", musica->titulo, musica->artista, musica->letra);
                        break;
                    case 3:
                        //insere
                        printf("Digite a posicao que deseja inserir a musica\n");
                        scanf("%d", &posicao);
                        insereLDE(lista, musica, posicao);
                        break;
                    case 4: 
                        //imprime
                        imprimeLista(lista);
                        break;
                    case 5:
                        setMusica(lista);
                        break;
                    case 6: 
                        printf("Digite a posição do item que deseja remover\n");
                        scanf("%d", &posicao);
                        nodo = removeLDE(lista, posicao);
                        printf("\nA musica abaixo foi escluida da playlist!\n");
                        imprimeNodo(nodo);
                        printf("\n/*************/\n");
                        break;
                    case 7:
                        printf("\nDigite a posicao que deseja buscar. \n");
                        scanf("%d", &posicao);
                        nodo = buscaNodo(lista, posicao);
                        if(nodo == NULL){
                            break;
                        }else{
                            printf("Item encontrado\n");
                            imprimeNodo(nodo);
                        }
                        break;
                    default:
                        break;       
                }
            }while(opcaoMenu != 8); // fim while menu
                    break; // Fim LDE

        case 2:
            //Pilha / Stack
            do
            {
                printf("\nBem vindo ao Menu de Pilha/Stack!\n");
                printf("1 - Cria Pilha. \n");
                printf("2 - [PUSH] - Inserir na Pilha. \n");
                printf("3 - [TOP] - Retorna Elemento do topo \n");
                printf("4 - [POP] - Apaga o elemento do topo\n");
                printf("5 - [EMPTY] - Veririfcar se pilha está vazia\n");
                printf("6 - [MAKENUL] - Elimina todos os elementos da pilha\n");
                printf("7 - [LENGHT] - Retorna o tamanho da pilha\n");
                printf("8 - [PRINT] - Imprimir pilha\n");
                printf("9 - Sair\n");
                setbuf(stdin, NULL);
                scanf("%d", &menuStack);

                switch (menuStack)
                {
                case 1:
                    // cria pilha / stack
                    stack = createStack();
                    break;
                case 2:
                    // Insere na pilha / stack
                    musica = criaMusica();
                    nodo = criaNodo();
                    nodo->info = musica;
                    stack = pushStack(stack, nodo);
                    break;
                case 3:
                    // retorna o elemento do topo da pilha / stack
                    nodo = topStack(stack);
                    printf("A musica retornada foi: \n");
                    imprimeNodo(nodo);
                    break;
                case 4:
                    // Elimina o elemento no topo da pilha / stack
                    stack = popStack(stack);
                    break;
                case 5:
                    // verifica se está vazia a pilha / stack
                    if (emptyStack)
                    {
                        printf("A pilha não está vazia e seu tamanho eh %d. \n", stack->lenght);   
                        
                    }else{
                        printf("A pilha está vazia\n");
                    }
                    break;
                case 6:
                    // Eliminar os elementos da pilha / stack
                    makenullStack(stack);
                    break;
                case 7:
                    // retorna o tamanho da pilha / stack
                    printf("O tamanho da pilha eh %d. \n", lenghtStack(stack));
                    break;
                case 8:
                    // imprimir pilha / stack
                    printStack(stack);
                    break;
                default:
                    break;
                }
            } while (menuStack != 9);
            
            break; // Fim Stack
        case 3:
            //Fila / Queue
            do
            {
                printf("\nBem vindo ao Menu de Pilha/Stack!\n");
                printf("1 - Cria FILA. \n");
                printf("2 - [ENQUEUE] - Inserir na Fila. \n");
                printf("3 - [DEQUEUE] - Retorna e Remove o elemento no inicio da Fila\n");
                printf("4 - [DELETE] - Apaga totos os elementos da Fila\n");
                printf("5 - [EMPTY] - Veririfcar se Fila está vazia\n");
                printf("6 - [LENGHT] - Retorna o tamanho da pilha\n");
                printf("7 - [SHOW QUEUE] - Imprimir Fila\n");
                printf("8 - Sair\n");
                setbuf(stdin, NULL);
                scanf("%d", &menuQueue);

                switch (menuQueue)
                {
                case 1:
                    /* Cria Fila / Queue */
                    queue = createQueue();
                    break;
                case 2:
                    /* Insere na Fila / Queue */
                    musica = criaMusica();
                    nodo = criaNodo();
                    nodo->info = musica;
                    queue = enqueue(queue, nodo);
                    break;
                case 3:
                    /* Retorna e remove o elemento no inicio da Fila / Queue */
                    nodo = dequeue(queue);
                    printf("A musica retornada e excuila foi: \n");
                    imprimeNodo(nodo);
                    break;
                case 4:
                    /* Deleta a Fila / Queue */
                    
                    break;
                case 5:
                    /* Retorna verdadeiro para fila vazia*/
                    if (emptyQueue(queue))
                    {
                        printf("A lista está vazia \n");
                    }
                    else
                    {
                        printf("A lista não está vazia\n");
                        printf("Tamanho: %d\n", queue->tamanho);
                    }  
                    break;
                case 6:
                    /* Retorna o tamanho da fila*/
                    printf("\nTamanho da fila: %d\n", queue->tamanho);
                    break;
                case 7:
                    /* Imprime a Fila */
                    showQueue(queue);
                    break;
                default:
                    break;
                }


            } while (menuQueue != 8);
            
            break; //Fim Queue
        default:
            break;
        }
    } while (menuPrincipal != 5);//fim menu selecao de menu
    



    //free(lista);
   // free(nodo);
    //free(musica);
    liberaPlaylist(lista);
    return 0;
}