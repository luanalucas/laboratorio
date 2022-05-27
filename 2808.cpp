#include <iostream>

using namespace std;

int main(){

    char entrada[5];
   
    cout << "Digite a posicao inicial utilizando coluna e linha, exemplo -> (d5 b8): " << endl;
    cin >> entrada;
    
    char posIniX = entrada[0];
    char posIniY = entrada[1]; 
    char posFinX = entrada[2];
    char posFinY = entrada[3];

    if(posIniX + 2 ==posFinX && posIniY +1 == posFinY){
        cout << "VALIDO" << endl;
    }
    else if(posIniX + 1 ==posFinX && posIniY +2 == posFinY){
        cout << "VALIDO" << endl;
    }
    else if(posIniX - 1 ==posFinX && posIniY +2 == posFinY){
        cout << "VALIDO" << endl;
    }
    else if(posIniX - 2 ==posFinX && posIniY +1 == posFinY){
        cout << "VALIDO" << endl;
    }
    else if(posIniX - 2 ==posFinX && posIniY -1 == posFinY){
        cout << "VALIDO" << endl;
    }
    else if(posIniX - 1 ==posFinX && posIniY -2 == posFinY){
        cout << "VALIDO" << endl;
    }
    else if(posIniX + 2 ==posFinX && posIniY -1 == posFinY){
        cout << "VALIDO" << endl;
    }
    else if(posIniX + 1 ==posFinX && posIniY -2 == posFinY){
        cout << "VALIDO" << endl;
    }
    else{
        cout << "INVALIDO" << endl;
    } 

    return 0;
}
