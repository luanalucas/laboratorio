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
    BANCA * file;
    
    file = fopen ("arquivo.txt","w"); //abrindo arquivo
        if(file == NULL){
                printf("Erro na abertura!\n");
                system("pause");
                exit(1);//aborta o programa
        }
    //fseek(file, 2*sizeof(struct BANCA), SEEK_SET);
    //rewind(file);
    //fread(&c,sizeof(struct BANCA),1,file);
        
    for(int i = 0; i < tam; i++){ 

        fprintf(file, "Aluno: %s\n", aux->aluno);
        fprintf(file, "Matricula: %d\n", aux->matricula);
        fprintf(file, "Curso: %s\n", aux->curso);
        fprintf(file, "Email do aluno: %s\n", aux->email_aluno);
        fprintf(file, "Orientador: %s\n", aux->orientador);
        fprintf(file, "Frequencia: %s\n", aux->frequencia);
        fprintf(file, "Avaliadores: %s\n", aux->avaliadores);
        fprintf(file, "Instituição: %s\n", aux->instituicao);
        fprintf(file, "E-mail para contato: %s\n", aux->email_avaliador);
        fprintf(file, "Título: %s\n", aux->titulo_banca);
        fprintf(file, "Resumo:  %s\n", aux->resumo);
        fprintf(file, "Horário: %f\n", aux->horario);
        fprintf(file, "Local: %s\n", aux->local);       



        aux = aux->prox;
    }
    fclose(file);
    system("pause");
}

void carregarArquivo(file){

    file = fopen ("arquivo.txt","rb"); //abrindo arquivo
        if(file == NULL){
                printf("Erro na abertura!\n");
                system("pause");
                exit(1);//aborta o programa
        }
    BANCA cad;
    fread(&cad,sizeof(struct BANCA),1,file);
    printf("%s\n%d\n%s\n%s\n%s\n%f\n%s\n%s\n%s\n%s\n%f\n%s\n", cad.aluno, cad.matricula, cad. curso, cad.curso, cad.email_aluno, cad.orientador, cad.frquencia, cad.avaliadores,
    cad.institucao, cad.email_avaliador, cad.titulo_banca, cad.resumo, cad.horario, cad.local);  
    //Pegar o que ta no arquivo, read
    //salvar na lista p sempre
    //funcao atualizar dados
}


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

        printf("Digite o nome do aluno: ");
        scanf("%s", aluno);
        printf("\nDigite a matricula do aluno:");
        scanf("%d", &matricula);
        printf("\nDigite o curso do aluno: ");
        scanf("%s", curso);
        printf("\nDigite o e-mail do aluno: ");
        scanf("%s", email_aluno);
        printf("\nDigite o nome do orientador: ");
        scanf("%s", orientador);
        printf("\nDigite frequencia: ");
        scanf("%f", &frequencia);
        printf("\nDigite o nome dos avaliadores: ");
        scanf("%s", avaliadores);
        printf("\nDigite a instituicao: ");
        scanf("%s", instituicao);
        printf("\nDigite o e-mail para contato: ");
        scanf("%s", email_avaliador);
        printf("\nDigite o título da banca: ");
        scanf("%s", titulo_banca);
        printf("\nDigite o resumo: ");
        scanf("%s", resumo);
        printf("\nDigite o horario: ");
        scanf("%f", &horario);
        printf("\nDigite o local: ");
        scanf("%s", local);

        cadastrar(aluno, matricula, curso, email_aluno, orientador, frequencia, avaliadores, instituicao, email_avaliador, titulo_banca, resumo, horario, local, 0);
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

BANCA remover(){ //nao ta apagando
   
    BANCA * aux= inicio;

    char * aluno = malloc(sizeof(aluno));
    int matricula;

    printf("""\n------------------------REMOVER---------------------------------\n""");  

        printf("Digite o nome do aluno: ");
        scanf("%s", aluno);
        printf("%s", aluno);
        printf("\nDigite a matricula do aluno: ");
        scanf("%d", &matricula);

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

BANCA* atualizar(){ 
    BANCA *aux = inicio;
    char *alt;

    char *aluno;
    int matricula;
    char *curso;
    char *email_aluno;//@
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

    printf("""\n------------------------ATUALIZAR---------------------------------\n""");  

        printf("Digite a matricula do aluno: "); //PROCURAR POR matricula
        scanf("%d", &matricula);
        printf("Qual alteracao deseja realizar? "); //variavel que quer mudar 
        scanf("%s", alt);

    for(int i = 0; i < tam; i++) //ou* while(aux-> matricula != matricula){     
            aux = aux->prox;
        } 
}


int main(){  
    
    //------------------------------criando menu de opcoes CRUD---------------------------------------
    int x = 1;
    while(x==1){
        int menu;
        printf("\n---------------------------MENU | CRUD---------------------------\n");
        printf("\nPara cadastrar uma banca, digite: 1"); //funcao que possa continuar cadastrando loop, no caso retornar menu
        printf("\nPara exibir as bancas cadastradas, digite: 2");
        printf("\nPara remover uma banca cadastrada, digite: 3");
        printf("\nPara atualizar uma banca, digite: 4");
        printf("\nPara encerrar o programa, digite: 5");
        printf("\n------------------------------------------------------------------\n");
        scanf("%d", &menu);
        
        switch(menu){
            case 1: cadastrarEntrada(); break; //funcionando a parte de solicitar
            case 2: imprimir(); break; 
            case 3: remover(); break; //funcionando a parte de solicitar
            case 4: atualizar(); break;
            case 5: x = 0; break; 
        }
    }
    salvar();

    return 0;
}
