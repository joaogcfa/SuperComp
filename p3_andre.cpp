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

    size_t i = 0;
    size_t greatest_index = 0;
    size_t least_index = 0; // size_t ocupa muito menos a memoria do que int

    while (i < v.size())
    {
        if (v[i] > v[greatest_index])
            greatest_index = i;
        if (v[i] < v[least_index])
            least_index = i;
        i += 1;
    }

    if (v.empty())
    {
        cout << "O vetor é vazio" << endl;
    }
    else
    {
        cout << "Maior valor digitado: " << v[greatest_index] << endl;
        cout << "Menor valor digitado: " << v[least_index] << endl;
    }

    return 0;
}