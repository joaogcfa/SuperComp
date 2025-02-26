#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main()
{
    struct item
    {
        int id;
        double peso;
        double valor;
    };

    int n = 0;
    int W = 0;
    int melhor_valor = 0;
    int amostras = 10;

    vector<item> mochila;

    cin >> n >> W; // numero de elementos e peso
    // cout << "Numero de elementos = " << n << "\n";
    // cout << "Capacidade da mochila = " << W << "\n";
    default_random_engine generator;
    // generator.seed(10);

    uniform_real_distribution<double> distribution(0.0, 1.0);

    vector<item> items;
    items.reserve(n);
    double peso, valor;
    for (int i = 0; i < n; i++)
    {
        cin >> peso;
        cin >> valor;
        items.push_back({i, peso, valor});
    }

    peso = 0;
    valor = 0;
    int i = 1; // controla a posicao para selecionar item ainda nao obtido
    while (amostras > 0)
    {
        double var = distribution(generator);
        // cout << "var: " << var << endl;
        // cout << "i: " << i << endl;

        for (auto &el : items)
        {

            if (el.peso + peso <= W)
            {
                mochila.push_back(el);
                peso = peso + el.peso;
                valor = valor + el.valor;
                // cout<<"inclui o elemento = " << el.id << "\n";
            }

            if (var > 0.5 && i < n)
            {
                // escolha aleatoria de todos os outros itens
                uniform_int_distribution<int> distributionInt(i, n - 1);
                int p = distributionInt(generator);
                // cout << "p: " << p << endl;
                cout << "obtive o valor p = " << p << " com id = " << i << "\n";
                if (items[p].peso + peso <= W)
                {
                    mochila.push_back(items[p]);
                    peso = peso + items[p].peso;
                    valor = valor + items[p].valor;
                    // cout<<"removi elemento p = " << p << " com id de = " << items[p].id << "\n";
                    items.erase(items.begin() + p - 1);
                    n = n - 1;
                    // cout << "n = " << n << endl;
                }
            }
            i = i + 1;
        }
        // essa ordenacao é necessaria para atender apenas o solicitado.
        sort(mochila.begin(), mochila.end(), [](auto &i, auto &j)
             { return i.id < j.id; });
        cout << peso << " " << valor << " 0"
             << "\n";

        for (auto &el : mochila)
        {
            cout << el.id << " ";
        }
        cout << endl;
        i = 1;
        amostras--;
    }
    return 0;
}