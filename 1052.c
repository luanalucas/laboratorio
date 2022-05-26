#include <stdio.h>

int main(){

int mes;
scanf("%dDigite o numero referente ao mês: ", &mes);

switch(mes){
    
    case 1: printf("\nJanuary"); break;
    case 2: printf("\nFebruary"); break;
    case 3: printf("\nMarch"); break;
    case 4: printf("\nApril"); break;
    case 5: printf("\nMay"); break;
    case 6: printf("\nJune"); break;
    case 7: printf("\nJuly"); break;
    case 8: printf("\nAugust"); break;
    case 9: printf("\nSEptember"); break;
    case 10: printf("\nOctober"); break;
    case 11: printf("\nNovember"); break;
    case 12: printf("\nDecember"); break;
    default: printf("Inválido"); break;
}
    return 0;
}
