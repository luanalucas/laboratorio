#include <stdio.h>
#include <stdlib.h>

typedef struct Vertice{
   
    int id; //identificador unico de cada vertice
    
    //mecanismo p/ unir nos!
    struct Vertice * esq;
    struct Vertice * dir;
}VERTICE;

VERTICE * raiz = NULL;
int tam = 0;

VERTICE* buscar(int id, VERTICE *aux){
    
    if(aux != NULL){
        if(aux->id == id){
            return aux;
        }else if(id < aux->id){
            if(aux->esq != NULL){
                return buscar(id, aux->esq);
            }else{
                return NULL;
            }
        }else if(id > aux->id){
            if(aux->dir != NULL){
                return buscar(id, aux->dir);
            }else{
                return NULL;
            }
        }
    }else{
        return NULL;
    }
}


void adicionar(int x){

    VERTICE *aux = buscar(x, raiz);//criar o auxiliar + //chamar a funcao buscar!

    if(aux != NULL && aux->id == x){ //verificar se pode adicionar
        printf("insercao invalida\n");
    }else{

    VERTICE *novo = malloc(sizeof(novo));//criar o vertice - receber dados
    novo -> id = x;//setar dos dados
    novo -> esq = NULL;//setar dos dados
    novo -> dir = NULL;//setar dos dados
    
    if (aux == NULL){ //arvore vazia
        raiz = novo;
    }else{ //se sim, verifica se adiciona na esq ou na dir da variavel teste
        if(x < aux -> id){
            aux -> esq = novo;//na esq da variavel teste
        }else{
            aux -> dir = novo;//na dir da variavel teste
        }
    }
    }
}

void pre_ordem(VERTICE *aux){
    printf("%d", aux->id);
    if(aux->esq != NULL){
        pre_ordem(aux->esq);
    }
    if(aux->dir != NULL){
        pre_ordem(aux->dir);
    }
}

void in_ordem(VERTICE *aux){
    
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
    printf("%d", aux->id);
    if(aux->dir != NULL){
        in_ordem(aux->dir);
    }
}

void pos_ordem(VERTICE *aux){
    
    if(aux->esq != NULL){
        pos_ordem(aux->esq);
    }
    if(aux->dir != NULL){
        pos_ordem(aux->dir);
    }
    printf("%d", aux->id);
}



int main(){
    VERTICE *novo = buscar(0, raiz);
    adicionar(0);
    adicionar(1);
    adicionar(2);
    adicionar(3);
    adicionar(4);
    adicionar(5);
    adicionar(6);
    adicionar(7);
    adicionar(8);
    adicionar(9);
    printf("imprimindo...\n");
    in_ordem(raiz);
    printf(" \n");
    return 0;
}




