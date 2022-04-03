#include "ListaUniversidades.h"
#include "Universidade.h"
#include "ElUniversidade.h"

ListaUniversidades::ListaUniversidades(const char* n)
{
	strcpy_s(nome, n);
	pElUnivI = NULL;
	pElUnivF = NULL;
}

ListaUniversidades::~ListaUniversidades()
{
	ElUniversidade* aux = NULL;
	aux = pElUnivI;
	while (aux != NULL)
	{
		pElUnivI = pElUnivI->getProxElUniv();
		delete aux;
		aux = pElUnivI;
	}

	pElUnivF = NULL;
}

void ListaUniversidades::setNome(char* n)
{
	strcpy_s(nome, n);
}

char* ListaUniversidades::getNome()
{
	return nome;
}

void ListaUniversidades::incluiUniv(Universidade* pu)
{
	if (pu == NULL)
	{
		cout << "Erro na inclusao da Universidade" << endl;
		return;
	}

	ElUniversidade* paux = NULL;

	paux = new ElUniversidade();

	paux->setPUniv(pu);

	if (pElUnivI == NULL)
	{
		pElUnivI = paux;
		pElUnivF = paux;
	}
	else
	{
		pElUnivF->setProxElUniv(paux);
		paux->setPrevElUniv(pElUnivF);
		pElUnivF = paux;
	}
}

void ListaUniversidades::listaUnivs()
{
	ElUniversidade* aux = NULL;
	aux = pElUnivI;
	while (aux != NULL)
	{
		cout << (aux->getPUniv())->getNome() << endl;
		aux = aux->getProxElUniv();
	}
	cout << "===" << endl;
}

Universidade* ListaUniversidades::localizar(const char* n)
{
	ElUniversidade* paux = NULL;
	paux = pElUnivI;
	while (paux != NULL)
	{
		if (0 == strcmp(n, (paux->getPUniv())->getNome()))
		{
			return paux->getPUniv();
		}
		paux = paux->getPrevElUniv();
	}
	return NULL;
}
