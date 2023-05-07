
typedef struct musica{
    char titulo[256];
    char artista[256];
    char letra[256];
    int codigo;
    int execucoes;
}musica;

typedef struct codMusica
{
    int valor;
}codMusica;


typedef struct nodo{
    struct nodo *prox;
    struct nodo *ant;
    struct musica *info;
}nodo;

typedef struct desc_Playlist{
    struct desc_Playlist * prox;
    struct desc_Playlist * ant;
    struct nodo * primeiramusica;
    struct nodo * ultimamusica;
    int tamanho;
}desc_Playlist;


/*– CriaLista
– Insere
– Remove
– Consulta
– Imprime */

desc_Playlist * criaLista (void); //ok
musica * criaMusica (char * titulo, char * artista, char * letra, int codigoMusica); //ok
nodo * criaNodo(void); //ok
void insereLDE (desc_Playlist* lista,musica * fmusica, nodo* fnodo, int posicao);
nodo * removeLDE (desc_Playlist* lista, int posicao);
void imprimeLista(desc_Playlist* lista);
void imprimeNodo(nodo * fnodo);
void limpar_buffer();
nodo * buscaNodo(desc_Playlist * lista, int posicao);
void liberaPlaylist(desc_Playlist * lista);
