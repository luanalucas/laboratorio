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

void salvar(){
    BANCA * aux = inicio;
    FILE * file;
    char *arquivo =  malloc(sizeof(arquivo));
    
    file = fopen ("arquivo.txt","w"); //abrindo arquivo
        if(file == NULL){
                printf("Erro na abertura!\n");
                system("pause");
                exit(1);//aborta o programa
        }
        
    for(int i = 0; i < tam; i++){ 

        fprintf(file, "Aluno: %s\n", aux->aluno);
        fprintf(file, "Matricula: %d\n", aux->matricula);
        fprintf(file, "Curso: %s\n", aux->curso);
        fprintf(file, "Email do aluno: %s\n", aux->email_aluno);
        fprintf(file, "Orientador: %s\n", aux->orientador);
        fprintf(file, "Frequencia: %lf\n", aux->frequencia);
        fprintf(file, "Avaliadores: %s\n", aux->avaliadores);
        fprintf(file, "Instituição: %s\n", aux->instituicao);
        fprintf(file, "E-mail para contato: %s\n", aux->email_avaliador);
        fprintf(file, "Título: %s\n", aux->titulo_banca);
        fprintf(file, "Resumo:  %s\n", aux->resumo);
        fprintf(file, "Horário: %lf\n", aux->horario);
        fprintf(file, "Local: %s\n", aux->local);       



        aux = aux->prox;
    }
    fclose(file);
    system("pause");
}



void cadastrar(char *aluno, int matricula, char *curso, char *email_aluno, char *orientador, double frequencia, char *avaliadores,
char *instituicao, char *email_avaliador, char *titulo_banca, char *resumo, double horario, char *local, int pos){

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
   
        if(inicio == NULL){ 
            inicio = novo;
            fim = novo;
            tam++;
        }else if(pos == 0){
            inicio->ant = novo;
            novo->prox = inicio;
            inicio = novo;
            tam++;
        }else if(pos == tam){ 
            novo->ant = fim;
            fim->prox = novo;
            fim = novo;
            tam++;
        }else{ // 
           
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

void cadastrarEntrada(){
   
        char *aluno = malloc(sizeof(aluno)*50);
        int matricula;
        char *curso = malloc(sizeof(curso)*50);
        char *email_aluno = malloc(sizeof(email_aluno)*50);
        //orientador nome
        char *orientador = malloc(sizeof(orientador)*50);
        //frequencia
        double frequencia;
        //dados avaliadores
        char *avaliadores = malloc(sizeof(avaliadores)*50);
        char *instituicao = malloc(sizeof(instituicao)*50);
        char *email_avaliador = malloc(sizeof(email_avaliador)*50);
        //dados da banca
        char *titulo_banca = malloc(sizeof(titulo_banca)*50);
        char *resumo = malloc(sizeof(resumo)*50);
        double horario;
        char *local = malloc(sizeof(local)*50);
       
        printf("""\n------------------------CADASTRAR---------------------------------\n""");  

        printf("Digite o nome do aluno: ");
        fgets(aluno, 50, stdin);
        printf("\nDigite a matricula do aluno:");
        scanf("%d", &matricula);
        printf("\nDigite o curso do aluno: ");
        fgets(curso, 50, stdin);
        printf("\nDigite o e-mail do aluno: ");
        fgets(email_aluno, 50, stdin);
        printf("\nDigite o nome do orientador: ");
        fgets(orientador, 50, stdin);
        printf("\nDigite frequencia: ");
        scanf("%lf", &horario);
        printf("\nDigite o nome dos avaliadores: ");
        fgets(avaliadores, 50, stdin);
        printf("\nDigite a instituicao: ");
        fgets(instituicao, 50, stdin);
        printf("\nDigite o e-mail para contato: ");
        fgets(email_avaliador, 50, stdin);
        printf("\nDigite o título da banca: ");
        fgets(titulo_banca, 50, stdin);
        printf("\nDigite o resumo: ");
        fgets(resumo, 50, stdin);
        printf("\nDigite o horario: ");
        scanf("%lf", &horario);
        printf("\nDigite o local: ");
        fgets(local, 50, stdin);

        cadastrar(aluno, matricula, curso, email_aluno, orientador, frequencia, avaliadores, instituicao, email_avaliador, titulo_banca, resumo, horario, local, 0);
        printf("Banca cadastrada com sucesso!");
}

void imprimir(){
    BANCA * aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("\n------------------------BANCAS CADASTRADAS---------------------------------\n");        
        printf("Aluno: %s\n", aux->aluno);
        printf("Matricula: %d\n", aux->matricula);
        printf("Curso: %s\n", aux->curso);
        printf("Email do aluno: %s\n", aux->email_aluno);
        printf("Orientador: %s\n", aux->orientador);
        printf("Frequencia: %lf\n", aux->frequencia);
        printf("Avaliadores: %s\n", aux->avaliadores);
        printf("Instituição: %s\n", aux->instituicao);
        printf("E-mail para contato: %s\n", aux->email_avaliador);
        printf("Título: %s\n", aux->titulo_banca);
        printf("Resumo:  %s\n", aux->resumo);
        printf("Horário: %lf\n", aux->horario);
        printf("Local: %s\n", aux->local); 

        aux = aux->prox;
    }
}

void remover(){ //Segmentation fault BANCA *remover()
    
    char * aluno = malloc(sizeof(aluno));
    int matricula;

    printf("\n------------------------REMOVER---------------------------------\n");  

    printf("\nDigite a matricula do aluno: ");
    scanf("%d", &matricula);

   if(tam == 1 && inicio->matricula == matricula){
        BANCA *lixo = inicio;
        inicio = NULL;
        inicio = NULL;
        free(lixo);
        tam--;
    }else{
        BANCA * aux = inicio;
        while(aux != fim && aux->matricula != matricula){
            aux = aux->prox;
        }

        if(inicio->matricula == matricula){
            inicio = inicio->prox;
        }
        else if(fim->matricula == matricula){
            fim = fim->prox;
        }
        else if(aux->matricula == matricula){
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
        }
        else{
            printf("Não foi encontrado! \n");
            return;
        }
        free(aux);
        tam--;
    }
    printf("Banca removida com sucesso!");
}

void atualizar(){ //Segmentation fault
    BANCA *aux = inicio;
    
    int mat;
    int opcao;
    char *aluno = malloc(sizeof(aluno));
    int matricula;
    char *curso = malloc(sizeof(curso));
    char *email_aluno = malloc(sizeof(email_aluno));
    //orientador nome
    char *orientador = malloc(sizeof(orientador));
    //frequencia
    double frequencia;
    //dados avaliadores
    char *avaliadores = malloc(sizeof(avaliadores));
    char *instituicao = malloc(sizeof(instituicao));
    char *email_avaliador = malloc(sizeof(email_avaliador));
    //dados da banca
    char *titulo_banca = malloc(sizeof(titulo_banca));
    char *resumo = malloc(sizeof(resumo));
    double horario;
    char *local = malloc(sizeof(local));

    printf("\n------------------------ATUALIZAR---------------------------------\n");  

    printf("Digite a matricula do aluno: "); //PROCURAR POR matricula
    scanf("%d", &mat);
    
    while(aux->matricula != mat){
        aux = aux->prox;
    }

    printf("1-Aluno: %s\n", aux->aluno);
    printf("2-Matricula: %d\n", aux->matricula);
    printf("3-Curso: %s\n", aux->curso);
    printf("4-Email do aluno: %s\n", aux->email_aluno);
    printf("5-Orientador: %s\n", aux->orientador);
    printf("6-Frequencia: %lf\n", aux->frequencia);
    printf("7-Avaliadores: %s\n", aux->avaliadores);
    printf("8-Instituição: %s\n", aux->instituicao);
    printf("9-E-mail para contato: %s\n", aux->email_avaliador);
    printf("10-Título: %s\n", aux->titulo_banca);
    printf("11-Resumo:  %s\n", aux->resumo);
    printf("12-Horário: %lf\n", aux->horario);
    printf("13-Local: %s\n", aux->local); 

    printf("Digite o numero referente ao campo que voce quer alterar: "); 
    scanf("%d", &opcao);

    switch(opcao){
            case 1: 
                printf("Digite o nome do aluno: ");
                scanf("%s", aluno);
                aux->aluno = aluno; 
                break; 
            case 2: 
                printf("\nDigite a matricula do aluno:");
                scanf("%d", &matricula);
                aux->matricula = matricula; 
                break; 
            case 3: 
                printf("\nDigite o curso do aluno: ");
                scanf("%s", curso);
                aux->curso = curso; 
                break; 
            case 4: 
                printf("\nDigite o e-mail do aluno: ");
                scanf("%s", email_aluno);
                aux->email_aluno = email_aluno; 
                break; 
            case 5: 
                printf("\nDigite o nome do orientador: ");
                scanf("%s", orientador);
                aux->orientador = orientador; 
                break; 
            case 6: 
                printf("\nDigite frequencia: ");
                scanf("%lf", &frequencia);
                aux->frequencia = frequencia; 
                break; 
            case 7: 
                printf("\nDigite o nome dos avaliadores: ");
                scanf("%s", avaliadores);
                aux->avaliadores = avaliadores; 
                break; 
            case 8: 
                printf("\nDigite o e-mail para contato: ");
                scanf("%s", instituicao);
                aux->instituicao = instituicao; 
                break; 
            case 9: 
                printf("\nDigite o e-mail para contato: ");
                scanf("%s", email_avaliador);
                aux->email_avaliador = email_avaliador; 
                break; 
            case 10: 
                printf("\nDigite o título da banca: ");
                scanf("%s", titulo_banca);
                aux->titulo_banca = titulo_banca; 
                break; 
            case 11: 
                printf("\nDigite o resumo: ");
                scanf("%s", resumo);
                aux->resumo = resumo; 
                break; 
            case 12: 
                printf("\nDigite o horario: ");
                scanf("%lf", &horario);
                aux->horario = horario; 
                break; 
            case 13: 
                printf("\nDigite o local: ");
                scanf("%s", local);
                aux->local = local; 
                break;   
        }
    printf("Banca atualizada com sucesso!");
}

int main(){  

    int x = 1;
    while(x==1){
        int menu;
        printf("\n--------------------------- MENU | CRUD ---------------------------\n");
        printf("\nPara cadastrar uma banca, digite: 1"); //funcao que possa continuar cadastrando loop, no caso retornar menu
        printf("\nPara exibir as bancas cadastradas, digite: 2");
        printf("\nPara remover uma banca cadastrada, digite: 3");
        printf("\nPara atualizar uma banca, digite: 4");
        printf("\nPara encerrar o programa, digite: 5");
        printf("\n------------------------------------------------------------------\n");
        scanf("%d%*c", &menu);
        
        switch(menu){
            case 1: cadastrarEntrada(); break; //funcionando 
            case 2: imprimir(); break; //funcionando
            case 3: remover(); break; //funcionando 
            case 4: atualizar(); break;
            case 5: x = 0; break; //funcionando
        }
    }
    salvar();
    

    return 0;
}
