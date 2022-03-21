#include "Pessoa.h"

Pessoa::Pessoa()
{
	inicializa(0, 0, 0);
}

Pessoa::Pessoa(int diaNasc, int mesNasc, int anoNasc, const char *nome)
{
	inicializa(diaNasc, mesNasc, anoNasc, nome);
}

Pessoa::~Pessoa()
{
}

void Pessoa::inicializa(int diaNasc, int mesNasc, int anoNasc, const char* nome)
{
	diaP = diaNasc;
	mesP = mesNasc;
	anoP = anoNasc;
	strcpy_s(nomeP, nome);
	idadeP = -1;
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
	cout << "A idade de " << nomeP << " seria " << idadeP << endl;
}

void Pessoa::calc_imprime_idade(int diaAtual, int mesAtual, int anoAtual)
{
	calc_idade(diaAtual, mesAtual, anoAtual);
	imprime_idade();
}

void Pessoa::setUnivFiliado(Universidade* pu)
{
	associadoUnivP = pu;
}

void Pessoa::ondeTrabalho()
{
	cout << nomeP << " trabalha em " << associadoUnivP->getNome() << endl;
}