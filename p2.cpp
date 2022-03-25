#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "Digite um numero: ";
    cin >> x;
    if (!cin)
    {
        cout << "Voce nao digitou um numero!" << endl;
        return 1;
    }
    int y;
    cout << "Digite outro numero: ";
    if (!(cin >> y))
    {
        cout << "Voce nao digitou um numero!" << endl;
        return 1;
    }
    cout << "Voce digitou os valores: " << x << " e " << y << endl;

    cout << "Digite novamente dois numeros!" << endl;
    cin >> x >> y;
    cout << "x = " << x << " y = " << y << endl;

    return 0;
}