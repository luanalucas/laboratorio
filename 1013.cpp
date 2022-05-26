#include <cmath>
#include <iostream>

using namespace std;

int main(void) {
    int a;
    cout << "digite valor de A" << endl;
    cin >> a;
    int b;
    cout << "digite valor de B" << endl;
    cin >> b;
    int c;
    cout << "digite valor de C" << endl;
    cin >> c;

    int AB = ((a + b + abs(a-b)))/2;
    int C = (AB + c + abs(AB - c))/2;
    
    cout << "eh o maior: " << C << endl;

    return 0;
    
}
