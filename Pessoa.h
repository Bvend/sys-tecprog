#pragma once

#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "Universidade.h"

class Pessoa
{
protected:
	int diaP, mesP, anoP, idadeP;
	char nome[100];

public:
	Pessoa();
	Pessoa(int diaNasc, int mesNasc, int anoNasc, const char *n = "");
	void inicializa(int diaNasc, int mesNasc, int anoNasc, const char* n = "");
	~Pessoa();

	void setNome(const char* n);
	char* getNome();

	void calc_idade(int diaAtual, int mesAtual, int anoAtual);
	void imprime_idade();
	void calc_imprime_idade(int diaAtual, int mesAtual, int anoAtual);
};
