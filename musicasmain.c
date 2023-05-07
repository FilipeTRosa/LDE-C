#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musicas.h"


int main (){

    desc_Playlist * lista = NULL;
    nodo * nodo = NULL;
    musica * musica = NULL;
    codMusica * codigoMusica = (codMusica*) malloc (sizeof(codMusica));
    codigoMusica->valor = 1;

    char titulo [256], artista [256], letra[256];
    int opcaoMenu = 0, posicao = 0;

    do{
        setbuf(stdin, NULL);
        printf("\n -*/-*/-*/ [MENU LDE] -*/-*/-*/ \n");
        printf("1 = Criar nova Lista: \n");
        printf("2 = Criar nova Musica:\n");
        printf("3 = Criar novo Nodo\n");
        printf("4 = Inserir na lista\n");
        printf("5 = Imprimir lista\n");
        printf("6 = Remover um item da lista\n");
        printf("7 = Buscar uma posicao na lista.\n");
        printf("8 = Sair!\n");
        scanf("%d", &opcaoMenu);

        switch(opcaoMenu){

            case 1:
                lista = criaLista();
                break;
            case 2:
                printf("\nDigite o titulo da musica\n");
                limpar_buffer();
                fgets(titulo, 256, stdin);
                printf("Digite o artista\n");
                void limpar_buffer();
                fgets(artista, 256, stdin);
                printf("Digite a letra da musica\n");
                void limpar_buffer();
                fgets(letra, 256, stdin);
                codigoMusica->valor++;
                musica = criaMusica(titulo, artista, letra, codigoMusica->valor);
                printf("\n Musica criada\n\n[Titulo] = %s\n[Artista] = %s\n[Letra] = %s\n\n", musica->titulo, musica->artista, musica->letra);
                break;
            case 3:
                nodo = criaNodo();
                break;
            case 4: 
                printf("Digite a posicao que deseja inserir a musica\n");
                scanf("%d", &posicao);
                insereLDE(lista, musica, nodo, posicao);
                break;
            case 5:
                imprimeLista(lista);
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
                printf("Item encontrado\n");
                imprimeNodo(nodo);
                break;
            default:
                break;       
        
        }

       // fim while menu
    }while(opcaoMenu != 8);

    //free(lista);
   // free(nodo);
    //free(musica);
    liberaPlaylist(lista);
    return 0;
}