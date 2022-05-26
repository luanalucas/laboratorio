#include <stdio.h>

int main(){

int numero;
int numero2;
printf("\nDigite o numero referente a musica que deseja ouvir\n");
scanf("%d %d", &numero, &numero2);
int C = numero + numero2;

switch(C){

    case 0: printf("\n0 - PROXYCITY"); break;
    case 1: printf("\n1 - P.Y.N.G."); break;
    case 2: printf("\n2 - DNSUEY!"); break;
    case 3: printf("\n3 - SERVERS"); break;
    case 4: printf("\n4 - HOST!"); break;
    case 5: printf("\n5 - CRIPTONIZE"); break;
    case 6: printf("\n6 - OFFLINE DAY"); break;
    case 7: printf("\n7 - SALT"); break;
    case 8: printf("\n8 - ANSWER!"); break;
    case 9: printf("\n9 - RAR?"); break;
    case 10: printf("\n10 - WIFI ANTENNAS"); break;
    
}
    return 0;
}
