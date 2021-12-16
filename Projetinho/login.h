#include <iostream>
#include <stdio.h>
#include <string>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

using namespace std;

// declarando funções main
int main();
void cadastro();
void registr();
void login();
void welcome();
void forgot();
void menu();


void welcome()
{
	system("cls");
	cout << "Ola! Seja bem vindo de volta \n";
	menu();
}

void login()
{
	int exist = 0;
	string user, password, u, p;
	system("cls");
	cout << "=======================\n";
	cout << "Login\n";
	cout << "=======================\n";
	cout << "Ola! Por favor, digite seu nome de usuario: ";
	cin >> user;

	// VOLTAR AO MENU PRINCIPAL 
	if (user == "voltar" || user == "VOLTAR" || user == "Voltar")
	{
		system("cls");
		main();
	}
	cout << "Agora, por favor insira sua senha: ";
	cin >> password;
	if (password == "voltar" || password == "VOLTAR" || password == "Voltar")
	{
		system("cls");
		main();
	}

	// LEITURA DE DADOS
	ifstream input("data.txt");
	while (input >> u >> p)
	{
		if (u == user && p == password)
		{
			exist = 1; // se existir retorna 1 
		}
	}
	input.close();
	if (exist == 1)
	{
		welcome();
	}
	else if (exist == 0)
	{
		system("cls");
		cout << "Desculpe, login incorreto!\n";
		main();
	}
}

void registr()
{
	string ruser, rpassword, ru, rp;
	system("cls");
	cout << "=======================\n";
	cout << "Registro\n";
	cout << "=======================\n";
	cout << "Por favor, insira um nome de usuario: ";
	cin >> ruser;
	if (ruser == "voltar" || ruser == "VOLTAR" || ruser == "Voltar")
	{
		system("cls");
		main();
	}
	cout << "Otimo! Agora digite uma senha: ";
	cin >> rpassword;
	if (rpassword == "voltar" || rpassword == "VOLTAR" || rpassword == "Voltar")
	{
		system("cls");
		main();
	}

	// para registrar em um arquivo os dados
	ofstream reg("data.txt", ios::app);
	reg << ruser << ' ' << rpassword << endl;
	system("cls");
	cout << "Criacao de conta concluida!\nAgora voce ja pode fazer login\n";
	main();
}

void forgot()
{
	string searchuser, su, sp;
	system("cls");
	cout << "=======================\n";
	cout << "Recuperar senha!\n";
	cout << "=======================\n";
	cout << "Essa nao, voce esqueceu sua senha...\n";
	cout << "Nao se preocupe, estou aqui para te ajudar!\n";
	cout << "Mas para isso precisamos que voce informe o nome de usuario da senha que voce deseja recuperar..\n";
	cout << "Por favor digite o nome de usuario da sua conta: ";
	cin >> searchuser;
	if (searchuser == "voltar" || searchuser == "VOLTAR" || searchuser == "Voltar")
	{
		system("cls");
		main();
	}
	int count = 0;
	ifstream searchu("data.txt");
	while (searchu >> su >> sp)
	{
		if (su == searchuser)
		{
			count = 1;
		}
	}
	searchu.close();
	if (count == 1)
	{
		cout << "\n\nPode comemorar brasileirinho! Encontramos a sua conta!\n";
		cout << "\nSua senha e: " << sp << endl;
		system("pause");
		system("cls");
		main();
	}
	else
	{
		cout << "\nDesculpe, sua ID nao foi encontrada nos nossos arquivos :(\n";
		cout << "\nPor favor, tente novamente ou contate um administrador! @jaovitokkk\n";
		system("pause");
		system("cls");
		main();
	}
}
