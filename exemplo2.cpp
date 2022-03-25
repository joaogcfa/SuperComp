#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    int x;
    float y = 0.0;
    float S = 0.0;
    vector<int> v;
    size_t i = 0;

    cout << "Entre quantos numeros desejar" << endl;
    while (cin >> x)
    {
        v.push_back(x);
    }
    cout << endl;

    while (i < v.size())
    {
        S += v[i];
        i++;
    }
    S = S / v.size();
    cout << S << endl;
    i = 0;

    while (i < v.size())
    {
        y += pow(v[i] - S, 2);
        i++;
    }
    y = y / v.size();
    cout << y << endl;

    // cout << setprecision(15) << endl;
    return 0;
}