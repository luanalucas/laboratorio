#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cerrno>
#include <stack>
#include <list>

using namespace std;

class BANCA{
    public:
    //dados aluno
    string aluno;
    int matricula;
    string curso;
    string email_aluno;

    //orientador nome
    string orientador;

    //frequencia
    double frequencia;

    //dados avaliadores
    string avaliadores;
    string instituicao;
    string email_avaliador;

    //dados da banca
    string titulo_banca;
    string resumo;
    double horario;
    string local;
    
    //dados aluno
    struct BANCA * prox;
    struct BANCA * ant;
};

BANCA * inicio = NULL;
BANCA * fim = NULL;

int tam = 0;

/*void salvar(){
    BANCA * aux = inicio;
    ofstream arquivo;

    arquivo.open("arquivo.txt");

    if(!arquivo.is_open()) {
        cerr << "Erro abrindo o arquivo para gravacao: " << std::strerror(errno) << endl;
        return 1;
    }
    for(int i = 0; i < tam; i++){ 
        arquivo.write("Aluno: %s\n", aux->aluno);
        arquivo.write("Matricula: %d\n", aux->matricula);
        arquivo.write("Curso: %s\n", aux->curso);
        arquivo.write("Email do aluno: %s\n", aux->email_aluno);
        arquivo.write("Orientador: %s\n", aux->orientador);
        arquivo.write("Frequencia: %lf\n", aux->frequencia);
        arquivo.write("Avaliadores: %s\n", aux->avaliadores);
        arquivo.write("Instituição: %s\n", aux->instituicao);
        arquivo.write("E-mail para contato: %s\n", aux->email_avaliador);
        arquivo.write("Título: %s\n", aux->titulo_banca);
        arquivo.write("Resumo: %s\n", aux->resumo);
        arquivo.write("Horário: %lf\n", aux->horario);
        arquivo.write("Local: %s\n", aux->local);

        aux = aux->prox;
    }

    for(auto n: v) { arquivo << n << endl; }

    arquivo.close();
    system("pause");
}*/

void cadastrar(string aluno, int matricula, string curso, string email_aluno, string orientador, double frequencia, string avaliadores,
string instituicao, string email_avaliador, string titulo_banca, string resumo, double horario, string local, int pos){

    if(pos >= 0 && pos <= tam){
   
        BANCA * novo = new(BANCA);
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
   
         string aluno;
         int matricula;
         string curso;
         string email_aluno;
         //orientador nome
         string orientador;
         //frequencia
         double frequencia;
         //dados avaliadores
         string avaliadores;
         string instituicao;
         string email_avaliador;
         //dados da banca
         string titulo_banca;
         string resumo;
         double horario;
         string local;
       
         cout << "------------------------CADASTRAR---------------------------------" << endl; 

         cout << "Digite o nome do aluno: "<< endl;
         cin >> aluno;
         cout << "Digite a matricula do aluno:"<< endl;
         cin >> matricula;
         cout << "Digite o curso do aluno: "<< endl;
         cin >>curso;
         cout << "Digite o e-mail do aluno: "<< endl;
         cin >>email_aluno;
         cout << "Digite o nome do orientador: "<< endl;
         cin >>orientador;
         cout << "Digite frequencia: "<< endl;
         cin >>frequencia;
         cout << "Digite o nome dos avaliadores: "<< endl;
         cin >>avaliadores;
         cout << "Digite a instituicao: "<< endl;
         cin >>instituicao;
         cout << "Digite o e-mail para contato: "<< endl;
         cin >>email_avaliador;
         cout << "Digite o título da banca: "<< endl;
         cin >>titulo_banca;
         cout << "Digite o resumo: "<< endl;
         cin >>resumo;
         cout << "Digite o horario: "<< endl;
         cin >>horario;
         cout << "Digite o local: "<< endl;
         cin >>local;

         cadastrar(aluno, matricula, curso, email_aluno, orientador, frequencia, avaliadores, instituicao, email_avaliador, titulo_banca, resumo, horario, local, 0);
         cout << "Banca cadastrada com sucesso!"<< endl;
 }

 void imprimir(){
     BANCA * aux = inicio;
     for(int i = 0; i < tam; i++){
         cout << "------------------------BANCAS CADASTRADAS---------------------------------"<< endl;       
         cout << "Aluno: " <<  aux->aluno << endl;
         cout << "Matricula: "<< aux->matricula<< endl;
         cout << "Curso: "<< aux->curso << endl;
         cout << "Email do aluno: "<< aux->email_aluno << endl;
         cout << "Orientador: "<< aux->orientador << endl;
         cout << "Frequencia: "<< aux->frequencia << endl;
         cout << "Avaliadores: "<< aux->avaliadores << endl;
         cout << "Instituição: "<< aux->instituicao << endl;
         cout << "E-mail para contato: "<< aux->email_avaliador << endl;
         cout << "Título: "<< aux->titulo_banca << endl;
         cout << "Resumo: "<< aux->resumo << endl;
         cout << "Horário: "<< aux->horario << endl;
         cout << "Local: "<< aux->local << endl;

         aux = aux->prox;
     }
}

 void remover(){ 
    
     string  aluno;
     int matricula;

     cout << "------------------------REMOVER---------------------------------" << endl;  

     cout << "Digite a matricula do aluno: "<< endl;
     cin >> matricula;

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
             cout << "Não foi encontrado! " << endl;
             return;
         }
         free(aux);
         tam--;
     }
     cout << "Banca removida com sucesso!" << endl;
 }

void atualizar(){ //Segmentation fault
    BANCA *aux = inicio;
    
    int mat;
    int opcao;
    string aluno;
    int matricula;
    string curso;
    string email_aluno;
    //orientador nome
    string orientador;
    //frequencia
    double frequencia;
    //dados avaliadores
    string avaliadores;
    string instituicao;
    string email_avaliador;
    //dados da banca
    string titulo_banca;
    string resumo;
    double horario;
    string local;

    cout <<"------------------------ATUALIZAR---------------------------------"<< endl;  

    cout <<"Digite a matricula do aluno: "<<endl; //PROCURAR POR matricula
    cin >> mat;
    
    while(aux->matricula != mat){
        aux = aux->prox;
    }

    cout <<"1-Aluno: " << aux->aluno <<endl;
    cout <<"2-Matricula: "<< aux->matricula <<endl;
    cout <<"3-Curso: "<< aux->curso <<endl;
    cout <<"4-Email do aluno: "<< aux->email_aluno <<endl;
    cout <<"5-Orientador: "<< aux->orientador <<endl;
    cout <<"6-Frequencia: "<< aux->frequencia <<endl;
    cout <<"7-Avaliadores: "<< aux->avaliadores <<endl;
    cout <<"8-Instituição: "<< aux->instituicao <<endl;
    cout <<"9-E-mail para contato: "<< aux->email_avaliador <<endl;
    cout <<"10-Título: "<< aux->titulo_banca <<endl;
    cout <<"11-Resumo: "<< aux->resumo <<endl;
    cout <<"12-Horário: "<< aux->horario <<endl;
    cout <<"13-Local: "<< aux->local <<endl; 

    cout <<"Digite o numero referente ao campo que voce quer alterar: "<<endl;
    cin >> opcao;

    switch(opcao){
            case 1: 
                cout <<"Digite o nome do aluno: " <<endl;
                cin >>  aluno;
                aux->aluno = aluno; 
                break; 
            case 2: 
                cout <<"Digite a matricula do aluno:" <<endl;
                cin >> matricula;
                aux->matricula = matricula; 
                break; 
            case 3: 
                cout <<"Digite o curso do aluno: " <<endl;
                cin >> curso;
                aux->curso = curso; 
                break; 
            case 4: 
                cout <<"Digite o e-mail do aluno: " <<endl;
                cin >> email_aluno;
                aux->email_aluno = email_aluno; 
                break; 
            case 5: 
                cout <<"Digite o nome do orientador: "<<endl;
                cin >> orientador;
                aux->orientador = orientador; 
                break; 
            case 6: 
                cout <<"Digite frequencia: "<<endl;
                cin >> frequencia;
                aux->frequencia = frequencia; 
                break; 
            case 7: 
                cout <<"Digite o nome dos avaliadores: "<<endl;
                cin >> avaliadores;
                aux->avaliadores = avaliadores; 
                break; 
            case 8: 
                cout <<"Digite o e-mail para contato: "<<endl;
                cin >> instituicao;
                aux->instituicao = instituicao; 
                break; 
            case 9: 
                cout <<"Digite o e-mail para contato: "<<endl;
                cin >> email_avaliador;
                aux->email_avaliador = email_avaliador; 
                break; 
            case 10: 
                cout <<"Digite o título da banca: "<<endl;
                cin >> titulo_banca;
                aux->titulo_banca = titulo_banca; 
                break; 
            case 11: 
                cout <<"Digite o resumo: "<<endl;
                cin >> resumo;
                aux->resumo = resumo; 
                break; 
            case 12: 
                cout <<"Digite o horario: "<<endl;
                cin >> horario;
                aux->horario = horario; 
                break; 
            case 13: 
                cout <<"Digite o local: "<<endl;
                cin >> local;
                aux->local = local; 
                break;   
        }
    cout << "Banca atualizada com sucesso!"<< endl;
}

int main(){  
    
    int x = 1;
    int menu;
    while(x==1){
        cout <<"--------------------------- MENU | CRUD ---------------------------"<<endl;
        cout <<"Para cadastrar uma banca, digite: 1"<<endl; //funcao que possa continuar cadastrando loop, no caso retornar menu
        cout <<"Para exibir as bancas cadastradas, digite: 2"<<endl;
        cout <<"Para remover uma banca cadastrada, digite: 3"<<endl;
        cout <<"Para atualizar uma banca, digite: 4"<<endl;
        cout <<"Para encerrar o programa, digite: 5"<<endl;
        cout <<"------------------------------------------------------------------"<<endl;
        cin >> menu;
        
        switch(menu){
            case 1: cadastrarEntrada(); break; //funcionando 
            case 2: imprimir(); break; //funcionando
            case 3: remover(); break; //funcionando 
            case 4: atualizar(); break;
            case 5: x = 0; break; //funcionando
        }
    }
    //salvar();

    return 0;
}
