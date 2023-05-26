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
    codMusica * codigoMusica = (codMusica*) malloc (sizeof(codMusica));
    codigoMusica->valor = 1;

    char titulo [256], artista [256], letra[256];
    int opcaoMenu = 0, posicao = 0, menuPrincipal = 0, menuStack = 0;

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
                /* code */
            } while (menuStack != 5);
            
            break; // Fim Stack
        case 3:
            //Fila / Queue
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