#include <stdio.h>
#include <stdlib.h>

typedef struct Banca{
    //dados aluno
    char *aluno;
    int matricula;
    char *curso;
    char *email_aluno;
    //orientador nome
    char *orientador;
    //frequencia
    double frequencia;
    //dados avaliadores
    char *avaliadores;
    char *instituicao;
    char *email_avaliador;
    //dados da banca
    char *titulo_banca;
    char *resumo;
    double horario;
    char *local;
    //dados aluno
    struct Banca * prox;
    struct Banca * ant;
}BANCA;

BANCA * inicio = NULL;
BANCA * fim = NULL;

int tam = 0;

void cadastrar(char *aluno, int matricula, char *curso, char *email_aluno, char *orientador, float frequencia, char *avaliadores,
char *instituicao, char *email_avaliador, char *titulo_banca, char *resumo, float horario, char *local, int pos){

    if(pos >= 0 && pos <= tam){
   
        BANCA * novo = malloc(sizeof(BANCA));
        novo->aluno = aluno;
        novo->matricula = matricula;
        novo->curso = curso;
        novo->email_aluno = email_aluno;
        novo->orientador = orientador;
        novo->frequencia = frequencia;
        novo->avaliadores = avaliadores;
        novo->instituicao = instituicao;
        novo->email_avaliador = email_avaliador;
        novo->titulo_banca = titulo_banca;
        novo->resumo = resumo;
        novo->horario = horario;
        novo->local = local;
        novo->prox = NULL;
        novo->ant = NULL;
   
        if(inicio == NULL){ //lista vazia
            inicio = novo;
            fim = novo;
            tam++;
        }else if(pos == 0){//inicio
            inicio->ant = novo;
            novo->prox = inicio;
            inicio = novo;
            tam++;
        }else if(pos == tam){ //fim
            novo->ant = fim;
            fim->prox = novo;
            fim = novo;
            tam++;
        }else{ // "no meio"
           
            BANCA * aux = inicio;
            for(int i = 0; i < pos; i++){
                aux = aux->prox;
            }
            novo->prox = aux;
            novo->ant = aux->ant;
            aux->ant->prox = novo;
            aux->ant = novo;
            tam++;
        }
   
    }else{
        printf("Comando invalido\n");
    }
}


void imprimir(){
    BANCA * aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("""\n------------------------BANCAS CADASTRADAS---------------------------------\n""");        
        printf("Título: %s\n", aux->titulo_banca);
        printf("Resumo:  %s\n", aux->resumo);
        printf("Avaliadores: %s\n", aux->avaliadores);
        printf("Instituição: %s\n", aux->instituicao);
        printf("E-mail para contato: %s\n", aux->email_avaliador);
        printf("Horário: %f\n", aux->horario);
        printf("Local: %s\n", aux->local);

            aux = aux->prox;
    }
}

void cadastrarRemover(){  
        char * aluno = malloc(sizeof(aluno));
        int matricula;
        printf("""\n------------------------REMOVER---------------------------------\n""");  
        printf("Digite o nome do aluno:");
        scanf("%s", aluno);
        printf("\nDigite a matricula do aluno:");
        scanf("%d", &matricula);      
}

BANCA remover(char *aluno, int matricula){
   
    BANCA * aux= inicio;

    if(tam == 1 && inicio->aluno == aluno && inicio->matricula == matricula){
        inicio = NULL;
        fim = NULL; 
    }else{
        while(aux != fim && aux->aluno != aluno && aux->matricula != matricula){
            aux = aux->prox;
        }
        if(aux->aluno == aluno && aux->matricula == matricula){
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            if(inicio->aluno == aluno && inicio->matricula == matricula){
                inicio = inicio->prox;
            }
            if(fim->aluno == aluno && fim->matricula == matricula){
                fim = fim->prox;
            }
    free(aux);
    tam--;
        }else{
            printf("Não foi encontrado! \n");
        }
    }
    cadastrarRemover(aluno, matricula);
}

void cadastrarEntrada(){
   
        char *aluno = malloc(sizeof(aluno));
        int matricula;
        char *curso = malloc(sizeof(curso));
        char *email_aluno = malloc(sizeof(email_aluno));
        //orientador nome
        char *orientador = malloc(sizeof(orientador));
        //frequencia
        float frequencia;
        //dados avaliadores
        char *avaliadores = malloc(sizeof(avaliadores));
        char *instituicao = malloc(sizeof(instituicao));
        char *email_avaliador = malloc(sizeof(email_avaliador));
        //dados da banca
        char *titulo_banca = malloc(sizeof(titulo_banca));
        char *resumo = malloc(sizeof(resumo));
        float horario;
        char *local = malloc(sizeof(local));
       
        printf("""\n------------------------CADASTRAR---------------------------------\n""");  

        printf("Digite o nome do aluno:");
        scanf("%s", aluno);
        printf("%s", aluno);
        printf("\nDigite a matricula do aluno:");
        scanf("%d", &matricula);
        printf("Digite o curso do aluno: \n");
        scanf("%s", curso);
        printf("Digite o e-mail do aluno: \n");
        scanf("%s", email_aluno);
        printf("Digite o nome do orientador: \n");
        scanf("%s", orientador);
        printf("Digite frequencia: \n");
        scanf("%f", &frequencia);
        printf("Digite o nome dos avaliadores: \n");
        scanf("%s", avaliadores);
        printf("Digite a instituicao: \n");
        scanf("%s", instituicao);
        printf("Digite o e-mail para contato: \n");
        scanf("%s", email_avaliador);
        printf("Digite o título da banca: \n");
        scanf("%s", titulo_banca);
        printf("Digite o resumo: \n");
        scanf("%s", resumo);
        printf("Digite o horario: \n");
        scanf("%f", &horario);
        printf("Digite o local: \n");
        scanf("%s", local);

        cadastrar(aluno, matricula, curso, email_aluno, orientador, frequencia, avaliadores, instituicao, email_avaliador, titulo_banca, resumo, horario, local, 0);
}

BANCA atualizar(){
    //PASSAR OPCAO DE ESCOLHER QUAIS INFORMACOES QUER ATUALIZAR

    BANCA * aux= inicio;

    if(tam == 1 && inicio->aluno == aluno && inicio->matricula == matricula){
        inicio = NULL;
        fim = NULL; 
    }else{
        while(aux != fim && aux->aluno != aluno && aux->matricula != matricula){
            aux = aux->prox;
        }
        if(aux->aluno == aluno && aux->matricula == matricula){
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            if(inicio->aluno == aluno && inicio->matricula == matricula){
                inicio = inicio->prox;
            }
            if(fim->aluno == aluno && fim->matricula == matricula){
                fim = fim->prox;
            }
    free(aux);
    tam--;
        }else{
            printf("Não foi encontrado! \n");
        }
    }
}

int main(){  

    int menu;
    printf("\n---------------------------MENU | CRUD---------------------------\n");
    printf("\nPara cadastrar uma banca, digite: 1"); //funcao que possa continuar cadastrando loop, no caso retornar menu
    printf("\nPara exibir as bancas cadastradas, digite: 2");
    printf("\nPara remover uma banca cadastrada, digite: 3\n");
    printf("\nPara atualizar uma banca, digite: 4");
    printf("\n*Obs.: Utilioze apenas o caractere que se refere ao comando desejado!");
    printf("\n------------------------------------------------------------------\n");

    scanf("%d", &menu);

    switch(menu){
        //REMOV teste = remover();
        case 1: cadastrarEntrada(); break;
        case 2: imprimir(); break;
        case 3: cadastrarRemover(); break;
        case 4: printf(); break;
    }
 
    //printf("\n--------------------Cadatro removido eh:----------------\n");
    //printf("%s", teste.aluno, teste.matricula, teste.curso);
   
    return 0;
}
