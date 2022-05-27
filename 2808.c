#include <stdio.h>
#include <stdlib.h>

int main(){
    char entrada[5];
   
    printf("\nDigite a posicao inicial utilizando coluna e linha, exemplo -> (d5 b8): ");
    scanf("%s", entrada);
    
    char posIniX = entrada[0];
    char posIniY = entrada[1]; 
    char posFinX = entrada[2];
    char posFinY = entrada[3];

    if(posIniX + 2 ==posFinX && posIniY +1 == posFinY){
        printf("VALIDO");
    }
    else if(posIniX + 1 ==posFinX && posIniY +2 == posFinY){
        printf("VALIDO");
    }
    else if(posIniX - 1 ==posFinX && posIniY +2 == posFinY){
        printf("VALIDO");
    }
    else if(posIniX - 2 ==posFinX && posIniY +1 == posFinY){
        printf("VALIDO");
    }
    else if(posIniX - 2 ==posFinX && posIniY -1 == posFinY){
        printf("VALIDO");
    }
    else if(posIniX - 1 ==posFinX && posIniY -2 == posFinY){
        printf("VALIDO");
    }
    else if(posIniX + 2 ==posFinX && posIniY -1 == posFinY){
        printf("VALIDO");
    }
    else if(posIniX + 1 ==posFinX && posIniY -2 == posFinY){
        printf("VALIDO");
    }
    else{
        printf("INVALIDO");
    } 
    
    return 0;
}
