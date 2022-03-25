#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

struct item
{
    int id;
    double peso;
    double valor;
    int pego = 0;
};

int valormochila(int n, int W, vector<item> mochila, vector<item> items)
{
    if (W == 0 || n == 0)
    {
        return 0;
    }

    if (W < items[n - 1].peso)
    {
        return valormochila(n - 1, W, mochila, items);
    }

    valormochila(n, W, mochila, items);

    return 0;
}

int main()
{

    int n = 0;
    int W = 0;

    vector<item> mochila;
    vector<item> items;

    cin >> n >> W;
    items.reserve(n);
    double peso, valor;

    for (int i = 0; i < n; i++)
    {
        cin >> peso;
        cin >> valor;
        items.push_back({i, peso, valor});
    }

    valormochila(n, W, mochila, items);

    return 0;
}