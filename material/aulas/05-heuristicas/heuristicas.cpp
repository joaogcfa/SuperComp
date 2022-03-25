#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct item
{
    int id;
    int peso;
    int valor;
};

bool my_compare(item a, item b);

int main()
{
    int id = 0;

    int tamanho;
    int peso_max;

    cin >> tamanho >> peso_max;
    cout << "N: " << tamanho << " W: " << peso_max << endl;

    vector<item> v(tamanho);
    for (int x = 0; x < tamanho; x++)
    {
        v[id].id = id;
        cin >> v[id].peso >> v[id].valor;
        cout << v[id].peso << " " << v[id].valor << " " << v[id].id << endl;
        id++;
    }

    sort(v.begin(), v.end(), my_compare);

    for (int x = 0; x < tamanho; x++)
    {
        cout << v[id].peso << " " << v[id].valor << " " << v[id].id << endl;
        id++;
    }

    return 0;
}

bool my_compare(item a, item b)
{
    return a.valor > b.valor;
}