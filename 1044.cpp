#include <cmath>
#include <iostream>

using namespace std;

int main(){

    int A; 
    cout << "Digite o valor de A: " << endl;
    cin >> A;
    int B;
    cout << "Digite o valor de B: " << endl;
    cin >> B;

    if(B % A == 0){
        cout << "Sao Multiplos" << endl;
    }else{
        cout << "Nao sao Multiplos"<< endl;
    }

    return 0;
}
