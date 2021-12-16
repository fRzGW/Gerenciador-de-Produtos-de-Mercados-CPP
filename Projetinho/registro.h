#include <iostream>
#include <stdio.h>
#include <string>
#include <istream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void menu();

int produtosqntd;
int i;
int j = 0;
int index;
string inome, icodigo, imarca;
int iqntd, itipo;
char choice1;
int restante;
char choice3;

struct Produto
{
	string nome, codigo, marca;
	int qntd, tipo;

	void insertproduto(string snome, string scodigo, string smarca, int sqntd, int stipo)
	{
			tipo = stipo;
			nome = snome;
			codigo = scodigo;
			marca = smarca;
			qntd = sqntd;
	}

	void showproduto()
	{
		system("cls");
		cout << "Tipo [1. Bebida | 2. Alimento | 3. Objeto]: " << tipo << endl;
		cout << "Marca do produto: " << marca << endl;
		cout << "Nome do produto: " << nome << endl;
		cout << "Codigo do produto: " << codigo << endl;
		cout << "Quantidade restante: " << qntd << endl;
		cout << "-------------------------------------\n";
	}
};
	Produto* produtos = new Produto[100];
	Produto p1[100];
void cadastro()
{
	ofstream regprodutos;
	system("cls");
	cout << "============================\n";
	cout << "ADICIONANDO PRODUTOS\n";
	cout << "============================\n";
	cout << "Quantos produtos voce deseja cadastrar ? [MAX 100] >> ";
	cin >> produtosqntd;

	regprodutos.open("produtos.txt", ios::app);

	for (i = 0; i < produtosqntd; i++)
	{
		restante = produtosqntd;
		restante--;
		system("cls");
		cout << "============================\n";
		cout << "ADICIONANDO PRODUTOS\n";
		cout << "============================\n";
		cout << "Produto numero: " << i << endl;
		cout << "Restam: " << restante << " produtos.\n";
		cout << "Digite:\n";
		cout << "Tipo de produto [1. Bebida | 2. Alimento | 3. Objeto] >> ";
		cin >> itipo;
		cout << "Marca do produto: >> ";
		cin >> imarca;
		cout << "Nome do produto >> ";
		cin >> inome;
		cout << "Codigo do produto >> ";
		cin >> icodigo;
		cout << "Quantidade no estoque >> ";
		cin >> iqntd;
		produtos[i] = p1[i];
		produtos[i].insertproduto(inome, icodigo, imarca, iqntd, itipo);
		regprodutos << itipo << ' ' << imarca << ' ' << inome << ' ' << icodigo << ' ' << iqntd << endl;
	}
	restante = produtosqntd;
	regprodutos.close();

	system("pause");
	system("cls");
	cout << "Pronto! Produtos adicionados com sucesso!\n";
	listar:
	cout << "Voce deseja ver os produtos ? [Y/N] >> ";
	cin >> choice1;
	if (choice1 == 'y' || choice1 == 'Y')
	{
		for (i = 0; i < produtosqntd; i++)
		{
			produtos[i].showproduto();
			system("pause");
		}
		system("cls");
		cout << "Lista finalizada!\n";
		menu();
		
	}
	else if (choice1 == 'n' || choice1 == 'N')
	{
		cout << "Vamos te levar ao menu principal!\n";
		system("pause");
		system("cls");
		menu();
	}
	else
	{
		system("cls");
		cout << "Valor digitado incorreto, tente novamente!\n";
		goto listar;
	}

}


// LISTA


int calc = 0;

void list()
{
	i = 0;
	system("cls");
	choice:
	cout << "Voce deseja ver quais sao os itens que foram adicionados na lista? [Y/N]: ";
	cin >> choice3;
	if (choice3 == 'y' || choice3 == 'Y')
	{
		ifstream procurar("produtos.txt");
		string linha;
		while (getline(procurar, linha))
		{	
			calc++;
			cout << "Tipo  |  Marca  |  Nome  |  Codigo  |  Quantidade  | Produto numero: " << calc << '\n';
			cout << linha << endl;
			system("pause");
			system("cls");
		}
		system("cls");
		cout << "Lista finalizada!\nVamos voltar ao menu principal!\n";
		system("pause");
		system("cls");
		procurar.close();
		menu();
	}
	else if (choice3 == 'n' || choice3 == 'N')
	{
		cout << "\nEntao vamos voltar ao menu principal!\n";
		system("pause");
		system("cls");
		menu();
	}
	else
	{
		cout << "Valor digitado incorreto, tente novamente!\n";
		goto choice;
	}
}


// clear

char clear;

void clearprodutos()
{
	tryagain:
	cout << "Voce tem certeza que deseja limpar a lista e excluir todos os produtos ? [Y/N]\n";
	cout << "Escolha >> "; cin >> clear;
	if (clear == 'y' || clear == 'Y')
	{
		ofstream remove("produtos.txt");
		remove.open("produtos.txt", std::ofstream::out | std::ofstream::trunc);
		remove.close();
		system("cls");
		cout << "Lista apagada!\n";
		system("pause");
		system("cls");
		menu();
	}
	else if (clear == 'n' || clear == 'N')
	{
		cout << "Entao vamos voltar ao menu principal!\n";
		system("pause");
		system("cls");
		menu();
	}
	else
	{
		cout << "Valor incorreto, tente novamente!\n";
		goto tryagain;
	}



}





