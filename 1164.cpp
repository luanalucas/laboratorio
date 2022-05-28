
#include <iostream>

//recebe qtd de num q vai enviar menor q 20 e dps se eles sao ou n perfeitos
int num;

int a;
int b;
    if (a % b == 0){
        return 1;
    }else{
        return 0;
    }
}

int nperf(num){

    int soma = 0;

    for(int i = 1; i < num; i++){
        if(multiplo(num, i) == 1){
            soma = soma + i;
        }
    }

    if (soma == num){
        return cout << "%d eh perfeito" << num << endl;
    }else{
        return cout << "%d nao eh perfeito" << num << endl;
    }
    return 0;
}

int main() {

    int qnt;
    int lista [21];

    cout << "Digite um numero entre 1 e 20: " << endl;
    cin >> qnt;

    for(int i = 1; i <= qnt ; i++){
        cout << "Digite um numero: " << endl;
        cin >> num;
        nperf(num);
    } 
    
    return 0;
}
