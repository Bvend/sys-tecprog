#include "Professor.h"

Professor::Professor():
Pessoa()
{
	pUnivFiliado = NULL;
	pDptoFiliado = NULL;
}

Professor::Professor(int diaNasc, int mesNasc, int anoNasc, const char* n):
Pessoa(diaNasc, mesNasc, anoNasc, n)
{
	pUnivFiliado = NULL;
	pDptoFiliado = NULL;
}

Professor::~Professor()
{
	pUnivFiliado = NULL;
	pDptoFiliado = NULL;
}

void Professor::setUnivFiliado(Universidade* pu)
{
	pUnivFiliado = pu;
}

void Professor::setDptoFiliado(Departamento* pd)
{
	pDptoFiliado = pd;
}

void Professor::ondeTrabalho()
{
	cout << nome << " trabalha em " << pUnivFiliado->getNome()
		 << " no departamento de " << pDptoFiliado->getNome()
		 << endl;
}
