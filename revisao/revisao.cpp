#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct acao
{
    int id;
    double valor;
    double retorno;
    double imposto;
};

double knapSack2(int O, vector<acao> acoes, vector<acao> &usados, vector<acao> &melhor)
{
    cout << O << endl;
    double valor = 0.0;
    double retorno = 0.0;
    double imposto = 0.0;
    double sem_i = 0.0, com_i = 0.0;
    vector<acao> acoes2 = acoes;
    if (acoes.empty() || O == 0)
    {
        cout << "Return 0" << endl;
        return 0;
    }

    if (acoes[0].valor <= O)
    {
        usados.push_back(acoes[0]);
        valor = acoes[0].valor;
        retorno = acoes[0].retorno;
        imposto = acoes[0].imposto;
        acoes.erase(acoes.begin());
        com_i = knapSack2(O - valor, acoes, usados, melhor);
    }
    acoes2.erase(acoes2.begin());
    sem_i = knapSack2(O, acoes2, usados, melhor);
    double valor_atual = 0.0, valor_melhor = 0.0;
    for (auto &el : usados)
    {
        valor_atual += (el.retorno - el.imposto);
    }
    for (auto &el : melhor)
    {
        valor_melhor += (el.valor - el.imposto);
    }
    if (valor_atual > valor_melhor)
        melhor = usados;
    usados.clear();
    return max(sem_i, retorno - imposto + com_i);
}

// double knapSack(int W, std::vector<item> items){
//     if(items.empty() || W == 0){
//         return 0;
//     }
//     if(items[0].peso > W){
//         items.erase(items.begin());
//         return knapSack(W,items);
//     }
//     else {
//         double valor = items[0].valor;
//         double peso = items[0].peso;

//         items.erase(items.begin());
//         return max(valor + knapSack(W - peso,items), knapSack(W, items));
//      }
// }

int main()
{

    int n = 0;
    int O = 0;

    vector<acao> carteira;

    cin >> n >> O; // numero de elementos e orcamento
    // cout << "Numero de elementos = " << n << "\n";
    // cout << "Capacidade da mochila = " << W << "\n";
    vector<acao> acoes;
    vector<acao> usado;
    vector<acao> melhor;
    acoes.reserve(n);
    usado.reserve(n);
    double valor, retorno, imposto;
    for (int i = 0; i < n; i++)
    {
        cin >> valor;
        cin >> retorno;
        cin >> imposto;
        acoes.push_back({i, valor, retorno, imposto});
    }

    cout << "RESULTADO = " << knapSack2(O, acoes, usado, melhor) << "\n";
    for (auto &el : melhor)
    {
        cout << el.id << " ";
    }

    // //ordenacao dos itens
    // sort(items.begin(), items.end(), [](auto& i, auto& j){return i.valor > j.valor;});
    // peso = 0;
    // valor = 0;
    // for(auto& el : items){
    //    if (el.peso + peso <= W) {
    //        mochila.push_back(el);
    //        peso = peso + el.peso;
    //        valor = valor + el.valor;
    //    }
    // }
    // essa ordenacao é necessaria para atender apenas o solicitado.
    // sort(mochila.begin(), mochila.end(), [](auto& i , auto& j){return i.id < j.id;});
    // cout << peso << " " << valor << " 0" << "\n";

    // for(auto& el: mochila) {
    //     cout << el.id << " ";
    // }
    return 0;
}