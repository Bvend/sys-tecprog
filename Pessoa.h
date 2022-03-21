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
private:
	int diaP, mesP, anoP, idadeP;
	char nomeP[30];

	// Referência a um objeto associado
	Universidade* associadoUnivP;
public:
	Pessoa();
	Pessoa(int diaNasc, int mesNasc, int anoNasc, const char *nome = "");
	void inicializa(int diaNasc, int mesNasc, int anoNasc, const char* nome = "");
	~Pessoa();

	void calc_idade(int diaAtual, int mesAtual, int anoAtual);
	void imprime_idade();
	void calc_imprime_idade(int diaAtual, int mesAtual, int anoAtual);

	// Associa Pessoa a uma Universidade
	void setUnivFiliado(Universidade* pu);
	void ondeTrabalho();
};
