#include <stdio.h>

int maior(int a, int b, int c){
int AB = ((a + b + abs(a-b)))/2;
int C = (AB + c + abs(AB - c))/2;

return C;
}

int main(void) {

    printf("%d eh o maior\n", maior(7, 14, 106));
    printf("%d eh o maior\n", maior(217, 14, 6));

    return 0;
}
