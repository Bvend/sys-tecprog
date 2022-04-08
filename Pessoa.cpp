#include "Pessoa.h"

Pessoa::Pessoa(int i)
{
	id = i;
	inicializa(0, 0, 0);
}

Pessoa::Pessoa(int diaNasc, int mesNasc, int anoNasc, const char *n)
{
	inicializa(diaNasc, mesNasc, anoNasc, nome);
}

Pessoa::~Pessoa()
{
}

void Pessoa::inicializa(int diaNasc, int mesNasc, int anoNasc, const char* n)
{
	diaP = diaNasc;
	mesP = mesNasc;
	anoP = anoNasc;
	strcpy_s(nome, n);
	idadeP = -1;
}

void Pessoa::setNome(const char* n)
{
	strcpy_s(nome, n);
}

char* Pessoa::getNome()
{
	return nome;
}

void Pessoa::setId(int i)
{
	id = i;
}

int Pessoa::getId()
{
	return id;
}

void Pessoa::calc_idade(int diaAtual, int mesAtual, int anoAtual)
{
	idadeP = anoAtual - anoP;
	if (mesAtual < mesP)
	{
		idadeP--;
	}
	else if (mesAtual == mesP)
	{
		if (diaAtual < diaP)
		{
			idadeP--;
		}
	}
	return;
}

void Pessoa::imprime_idade()
{
	// substitui printf("A idade de %s seria %i\n", nomeP, idadeP);
	cout << "A idade de " << nome << " seria " << idadeP << endl;
}

void Pessoa::calc_imprime_idade(int diaAtual, int mesAtual, int anoAtual)
{
	calc_idade(diaAtual, mesAtual, anoAtual);
	imprime_idade();
}