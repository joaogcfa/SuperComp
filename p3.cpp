#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int x;
    int w[] = {1, 2, 3};
    cout << w[0] << endl;
    vector<int> v;

    cout << "Entre quantos numeros desejar" << endl;
    while (cin >> x)
    {
        v.push_back(x);
    }
    cout << endl;

    int highest = v[0];
    int lowest = v[0];

    for (auto &e : v)
    {
        if (e > highest)
        {
            highest = e;
        }
        if (e < lowest)
        {
            lowest = e;
        }
    }
    cout << "Maior valor digitado: " << highest << endl;
    cout << "Menor valor digitado: " << lowest << endl;

    return 0;
}