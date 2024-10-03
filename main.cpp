#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Produto {
    int id;
    string nome;
    float preco;
    int quantidade;
    char status; 
};

Produto produtos[100];
int quantidadeAtual = 0;

void carregarProdutosDeFicheiro() {
    ifstream file("produtos.txt");
    if (file.is_open()) {
        while (file >> produtos[quantidadeAtual].id >> produtos[quantidadeAtual].nome >> produtos[quantidadeAtual].quantidade >> produtos[quantidadeAtual].preco >> produtos[quantidadeAtual].status) {
            quantidadeAtual++;
        }
        file.close();
    } else {
        cout << "O ficheiro nao foi encontrado, a criar uma nova lista de produtos." << endl;
    }
}

void salvarProdutosEmFicheiro() {
    ofstream file("produtos.txt");
    if (file.is_open()) {
        for (int i = 0; i < quantidadeAtual; i++) {
            file << produtos[i].id << " " << produtos[i].nome << " " << produtos[i].quantidade << " " << produtos[i].preco << " " << produtos[i].status << endl;
        }
        file.close();
    } else {
        cout << "Erro ao abrir o ficheiro." << endl;
    }
}

void adicionarProdutos() {
    if (quantidadeAtual < 100) {
        Produto p;
        p.id = quantidadeAtual + 1;
        cout << "Nome do Produto: ";
        cin >> p.nome;
        cout << "Preço do Produto: ";
        cin >> p.preco;
        cout << "Quantidade do Produto: ";
        cin >> p.quantidade;
        p.status = 'A';

        produtos[quantidadeAtual] = p;
        quantidadeAtual++;
        salvarProdutosEmFicheiro();
    } else {
        cout << "A lista de produtos esta cheia." << endl;
    }
}

void exibirProdutos() {
    for (int i = 0; i < quantidadeAtual; i++) {
        if (produtos[i].status == 'A') {
            cout << "Produto ID: " << produtos[i].id << endl;
            cout << "Nome: " << produtos[i].nome << endl;
            cout << "Preco: " << produtos[i].preco << endl;
            cout << "Quantidade: " << produtos[i].quantidade << endl;
            cout << "Status: " << (produtos[i].status == 'A' ? "Ativo" : "Eliminado") << endl;
            cout << "-----------------------" << endl;
        }
    }
}

void alterarProduto() {
    int id;
    cout << "Digite o ID do produto que deseja alterar: ";
    cin >> id;

    for (int i = 0; i < quantidadeAtual; i++) {
        if (produtos[i].id == id && produtos[i].status == 'A') {
            cout << "Nome atual: " << produtos[i].nome << ", insira novo nome: ";
            cin >> produtos[i].nome;
            cout << "Preço atual: " << produtos[i].preco << ", insira novo preço: ";
            cin >> produtos[i].preco;
            cout << "Quantidade atual: " << produtos[i].quantidade << ", insira nova quantidade: ";
            cin >> produtos[i].quantidade;

            salvarProdutosEmFicheiro();
            return;
        }
    }
    cout << "Produto com ID " << id << " não encontrado ou está eliminado." << endl;
}

void eliminarProduto() {
    int id;
    cout << "Digite o ID do produto que deseja eliminar: ";
    cin >> id;

    for (int i = 0; i < quantidadeAtual; i++) {
        if (produtos[i].id == id && produtos[i].status == 'A') {
            produtos[i].status = 'D'; 
            salvarProdutosEmFicheiro();
            cout << "Produto eliminado com sucesso." << endl;
            return;
        }
    }
    cout << "Produto com ID " << id << " nao encontrado ou já foi eliminado." << endl;
}

float calcularValorTotal() {
    float somaTotal = 0;
    for (int i = 0; i < quantidadeAtual; i++) {
        if (produtos[i].status == 'A') {
            somaTotal += produtos[i].preco * produtos[i].quantidade;
        }
    }
    return somaTotal;
}

int main() {
    carregarProdutosDeFicheiro();
    int opcao;

    do {
        cout << "1. Adicionar Produto" << endl;
        cout << "2. Exibir Produtos" << endl;
        cout << "3. Alterar Produto" << endl;
        cout << "4. Eliminar Produto" << endl;
        cout << "5. Calcular Valor Total" << endl;
        cout << "6. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarProdutos();
                break;
            case 2:
                exibirProdutos();
                break;
            case 3:
                alterarProduto();
                break;
            case 4:
                eliminarProduto();
                break;
            case 5: {
                float valorTotal = calcularValorTotal();
                cout << "Valor total dos produtos ativos: " << valorTotal << "€" << endl;
                break;
            }
            case 6:
                cout << "A sair do programa" << endl;
                salvarProdutosEmFicheiro();
                break;
            default:
                cout << "Opção invalida. Tente novamente" << endl;
        }
    } while (opcao != 6);

    return 0;
}
