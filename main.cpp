#include <iostream>
using namespace std;

struct Produto {
    string nome;
    float preco;
    int quantidade;
};

Produto produtos[100]; 

void adicionarProdutos(Produto produtos[], int& quantidadeAtual) {
    if (quantidadeAtual < 100) {
        string nome; 
        float preco;
        int quantidade;

        cout << "Nome do Produto: ";
        cin >> nome;
        cout << "Preço do Produto: ";
        cin >> preco;
        cout << "Quantidade do Produto: ";
        cin >> quantidade;

        produtos[quantidadeAtual].nome = nome;
        produtos[quantidadeAtual].preco = preco;
        produtos[quantidadeAtual].quantidade = quantidade;

        quantidadeAtual++;
    } else {
        cout << "A lista de produtos está cheia." << endl;
    }
}

void exibirProdutos(const Produto produtos[], int quantidadeAtual) {
    for(int i = 0; i < 100; i++)
        cout << produtos[i];
}

int main() {
    int quantidadeAtual = 0;

    adicionarProdutos(produtos, quantidadeAtual);
    exibirProdutos(produtos, quantidadeAtual);

    return 0;
}
