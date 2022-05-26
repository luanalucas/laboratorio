#include <cmath>
#include <iostream>

using namespace std;

int main(){

    int numero;
    int numero2;
    cout << "\nDigite o numero referente a musica que deseja ouvir\n" << endl;
    cin >> numero >> numero2;
    int C = numero + numero2;

    switch(C){

        case 0: cout << "\nPROXYCITY" << endl; break;
        case 1: cout << "\nP.Y.N.G." << endl; break;
        case 2: cout << "\nDNSUEY!" << endl; break;
        case 3: cout << "\nSERVERS" << endl; break;
        case 4: cout << "\nHOST!" << endl; break;
        case 5: cout << "\nCRIPTONIZE" << endl; break;
        case 6: cout << "\nOFFLINE DAY" << endl; break;
        case 7: cout << "\nSALT" << endl; break;
        case 8: cout << "\nANSWER!" << endl; break;
        case 9: cout << "\nRAR?" << endl; break;
        case 10: cout << "\n10WIFI ANTENNAS" << endl; break;
        
    }
    return 0;
}
