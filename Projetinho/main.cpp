#include <iostream>
#include <stdio.h>
#include <string>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "login.h"


using namespace std;

int choice;


// TELA PRINCIPAL DE LOGIN
int main()
{
	cout << " _____               _____ _       _     " << endl;
	cout << "| __  |___ _____ ___|  |  |_|___ _| |___ " << endl;
	cout << "| __ -| -_|     |___|  |  | |   | . | . |" << endl;
	cout << "|_____|___|_|_|_|     \___/|_|_|_|___|___|" << endl;
	cout << "\nGerenciador de produtos de mercado\n";
	cout << "Entre na sua secao para usar!\n";
	cout << "\n1. Nao tenho conta, desejo me registrar.\n2. Ja tenho conta, quero fazer login\n3. Esqueci minha senha\n4. Sair\n";
	cout << "Para voltar ao menu a qualquer momento voce pode digitar [voltar]\n";
	cout << "\nDigite sua escolha >> ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		registr();
		break;
	case 2:
		login();
		break;
	case 3:
		forgot();
		break;
	case 4:
		system("cls");
		cout << "Obrigado por usar o programa!\nCriador: @jaovitokkk\n";
		system("pause");
		break;
	default:
		system("cls");
		cout << "Desculpe, o valor digitado esta incorreto!\n";
		main();
	}

	return 0;
}
