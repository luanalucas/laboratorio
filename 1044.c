#include <stdio.h>

void multiplo(int A, int B){
    if(B % A == 0){
        printf("\nSao Multiplos");
    }else{
        printf("\nNao sao Multiplos");
    }
}

int main(){
    multiplo(6,24);
    multiplo(6,25);
    return 0;
}
