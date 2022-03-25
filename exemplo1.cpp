#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
    int x;

    cout << "Insira um numero " << endl;
    cin >> x;

    float S;
    int y = 0;

    while (x > 0)
    {
        S += 1 / pow(2, y);
        // cout << S << endl;
        x--;
        y++;
    }

    cout << setprecision(15) << S << endl;
    return 0;
}