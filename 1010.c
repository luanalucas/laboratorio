#include <stdio.h>

int cod_prod;
int quant;
double valor;

int cod_prod2;
int quant2;
double valor2;

void comprar(int cod_prod, int quant, double valor, int cod_prod2, int quant2, double valor2){
    if(quant>=1 && quant2>=1){
        
        double soma= (quant*valor) + (quant2*valor2);
        printf("\nValor a pagar: %f", soma);
           
    }
}

int main() {
    comprar(12, 1, 5.30, 16, 2, 5.10);
    comprar(13, 2, 15.30, 161, 4, 5.20);
    comprar(1, 1, 15.10, 2, 1, 15.10);
    
    return 0;
}
