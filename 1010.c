#include <stdio.h>

int cod_prod;
int quant;
float valor;

int cod_prod2;
int quant2;
float valor2;

int main() {
    
  printf("\nEntre com o valor 1: ");
  scanf("%d %d %f", &cod_prod, &quant, &valor);
  printf("\nEntre com o valor 2: ");
  scanf("%d %d %f", &cod_prod2, &quant2, &valor2);

   
   float soma= (quant*valor) + (quant2*valor2);
   printf("VALOR A PAGAR: R$ %.2f",soma);
       
    return 0;
}
