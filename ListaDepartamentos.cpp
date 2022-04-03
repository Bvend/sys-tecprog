#include "ListaDepartamentos.h"
#include "Departamento.h"
#include "ElDepartamento.h"


ListaDepartamentos::ListaDepartamentos(const char* n)
{
	strcpy_s(nome, n);
	pElDptoI = NULL;
	pElDptoF = NULL;
}

ListaDepartamentos::~ListaDepartamentos()
{
	ElDepartamento *aux = NULL;
	aux = pElDptoI;
	while (aux != NULL)
	{
		pElDptoI = pElDptoI->getProxElDpto();
		delete aux;
		aux = pElDptoI;
	}

	pElDptoF = NULL;
}

void ListaDepartamentos::setNome(char* n)
{
	strcpy_s(nome, n);
}

char* ListaDepartamentos::getNome()
{
	return nome;
}

void ListaDepartamentos::incluiDpto(Departamento* pd)
{
	if (pd == NULL)
	{
		cout << "Ponteiro para Departamento é NULL" << endl;
		return;
	}

	ElDepartamento* paux = NULL;

	paux = new ElDepartamento();

	paux->setPDpto(pd);

	if (NULL == pElDptoI)
	{
		pElDptoI = paux;
		pElDptoF = paux;
	}
	else
	{
		pElDptoF->setProxElDpto(paux);
		paux->setPrevElDpto(pElDptoF);
		pElDptoF = paux;
	}
}

void ListaDepartamentos::listaDptos()
{
	ElDepartamento* aux = NULL;
	aux = pElDptoI;
	while (aux != NULL)
	{
		cout << (aux->getPDpto())->getNome() << endl;
		aux = aux->getProxElDpto();
	}
	cout << "===" << endl;
}

Departamento* ListaDepartamentos::localizar(const char* n)
{
	ElDepartamento* paux = NULL;
	paux = pElDptoI;
	while (paux != NULL)
	{
		if (0 == strcmp(n, (paux->getPDpto()->getNome())))
		{
			return paux->getPDpto();
		}
		paux = paux->getProxElDpto();
	}
	return NULL;
}
