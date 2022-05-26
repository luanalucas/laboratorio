#include <cmath>
#include <iostream>

using namespace std;

int main() {
    
    int cod_prod;
    int quant;
    double valor;

    int cod_prod2;
    int quant2;
    double valor2;

    if(quant>=1 && quant2>=1){  
        cout << "Digite o codigo do produto 1: " << endl;
        cin >> cod_prod;  
        cout << "Digite valor de quantidade do produto 1: " << endl;
        cin >> quant;
        cout << "Digite valor do produto 1: " << endl;
        cin >> valor;
        cout << "Digite o codigo do produto 1: " << endl;
        cin >> cod_prod2;
        cout << "Digite valor de quantidade do produto 2: " << endl;
        cin >> quant2;      
        cout << "Digite valor do produto 2: " << endl;
        cin >> valor2;

        double soma = (quant*valor) + (quant2*valor2);
        cout << "Valor a pagar: " << soma << endl;
           
    }
    
    return 0;
}
