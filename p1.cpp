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
    cout << "Voce digitou o valor: " << x << endl;

    return 0;
}