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
    for(int i = 0; i < quantidadeAtual; i++) {  
        cout << "Produto " << i + 1 << " :" << endl;
        cout << "Nome: " << produtos[i].nome << endl;
        cout << "Preço: " << produtos[i].preco << endl;
        cout << "Quantidade: " << produtos[i].quantidade << endl;
        cout << "-----------------------" << endl;
    }
}

float calcularValorTotal(const Produto produtos[], int quantidadeAtual) {
    float somaTotal = 0;
    
    for (int i = 0; i < quantidadeAtual; i++) {
        somaTotal += produtos[i].preco * produtos[i].quantidade;
    }
    return somaTotal;
}

int main() {
    int quantidadeAtual = 0;
    int opcao;

    do {
        cout << "1. Adicionar Produto" << endl;
        cout << "2. Exibir Produtos" << endl;
        cout << "3. Calcular Valor Total" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarProdutos(produtos, quantidadeAtual);
                break;
            case 2:
                exibirProdutos(produtos, quantidadeAtual);
                break;
            case 3: {
                float valorTotal = calcularValorTotal(produtos, quantidadeAtual);
                cout << "Valor total dos produtos: " << valorTotal << "€" << endl;
                break;
            }
            case 4:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 4);

    return 0;
}