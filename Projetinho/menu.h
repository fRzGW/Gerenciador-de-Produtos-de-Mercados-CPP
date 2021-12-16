#include <iostream>
#include <stdio.h>
#include <string>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "registro.h"

using namespace std;

int choice2;

void list();
void cadastro();
void clearprodutos();

void menu()
{
	cout << "=============================\n";
	cout << "MENU DE OPCOES\n";
	cout << "=============================\n";
	cout << "1. Cadastro de produtos\n2. Ver lista de produtos\n3. Apagar lista\n4. Sair\n";
	cout << "Escolha sua opcao >> ";
	cin >> choice2;
	switch (choice2)
	{
	case 1:
		cadastro();
		break;
	case 2:
		list();
		system("cls");
		break;
	case 3:
		system("cls");
		clearprodutos();
	case 4:
		system("cls");
		cout << "Obrigado por usar o programa!\nCriador: @jaovitokkk\n";
		system("pause");
		break;
	default:
		system("cls");
		cout << "Desculpe, o valor digitado esta incorreto!\n";
		menu();
	}

}
