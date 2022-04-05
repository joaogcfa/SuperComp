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

bool my_compare(item a, item b)
{
    return a.peso < b.peso; // ordenando pelo mais leve
}

int main()
{
    // Randomizacao
    std::default_random_engine generator;
    generator.seed(10);
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    int n = 0;
    int W = 0;
    vector<item> mochila;
    vector<item> items;
    vector<item> valores;
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
    // sort(items.begin(), items.end(), my_compare);
    peso = 0;
    valor = 0;

    int i = 0;
    while (i < 500)
    {

        for (auto &el : items)
        {

            double prob = distribution(generator);
            if (prob > 0.5)
            {

                if (el.peso + peso <= W)
                {
                    mochila.push_back(el);
                    peso += el.peso;
                    valor += el.valor;
                    el.pego = 1;
                }
            }
        }
        for (auto &el : items)
        {
            if (el.pego == 0)
            {
                if (el.peso + peso <= W)
                {
                    cout << "entrei" << endl
                         << endl;
                    mochila.push_back(el);
                    peso += el.peso;
                    valor += el.valor;
                }
            }
        }
        // ordenando para imprimir
        sort(mochila.begin(), mochila.end(), [](auto &i, auto &j)
             { return i.id < j.id; });

        for (auto &el : mochila)
        {
            cout << el.id << " ";
        }

        cout << endl;
        mochila.clear();
        peso = 0;
        valor = 0;
        i++;
    }
    return 0;
}