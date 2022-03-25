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
};

bool my_compare(item a, item b)
{
    return a.peso < b.peso; // ordenando pelo mais leve
}

int main()
{
    std::default_random_engine generator;
    generator.seed(10);
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    double prob = distribution(generator);
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
    // ordenar
    sort(items.begin(), items.end(), my_compare);
    peso = 0;
    valor = 0;
    for (auto &el : items)
    {

        if (el.peso + peso <= W)
        {
            mochila.push_back(el);
            peso += el.peso;
            valor += el.valor;
        }
        if (prob > 0.75)
        {
            cout << "entrei" << endl;
            if (items.back().peso + peso <= W)
            {
                mochila.push_back(items.back());
                peso += items.back().peso;
                valor += items.back().valor;
                items.erase(items.end());
            }
        }
        prob = distribution(generator);
    }
    // ordenando para imprimir
    sort(mochila.begin(), mochila.end(), [](auto &i, auto &j)
         { return i.id < j.id; });
    cout << peso << " " << valor << " 0" << endl;
    for (auto &el : mochila)
    {
        cout << el.id << " ";
    }

    return 0;
}