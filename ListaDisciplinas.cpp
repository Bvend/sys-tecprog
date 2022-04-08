#include "ListaDisciplinas.h"
#include "Disciplina.h"

ListaDisciplinas::ListaDisciplinas(const char* n)
{
	strcpy_s(nome, n);
	pElDscpI = NULL;
	pElDscpF = NULL;
}

ListaDisciplinas::~ListaDisciplinas()
{
	ElDisciplina* aux = NULL;
	aux = pElDscpI;
	while (aux != NULL)
	{
		pElDscpI = pElDscpI->getProxElDscp();
		delete(aux);
		aux = pElDscpI;
	}

	pElDscpF = NULL;
}

void ListaDisciplinas::getNome(char* n)
{
	strcpy_s(nome, n);
}

char* ListaDisciplinas::setNome()
{
	return nome;
}

void ListaDisciplinas::incluiDscp(Disciplina* pd)
{
	if (pd == NULL)
	{
		cout << "Erro na inclusao da Disciplina" << endl;
		return;
	}

	ElDisciplina* paux = NULL;

	paux = new ElDisciplina();

	paux->setPDscp(pd);

	if (pElDscpI == NULL)
	{
		pElDscpI = paux;
		pElDscpF = paux;
	}
	else
	{
		(*pElDscpF).setProxElDscp(paux);
		paux->setPrevElDscp(pElDscpF);
		pElDscpF = paux;
	}
}

void ListaDisciplinas::listaDscp()
{
	ElDisciplina* aux = NULL;
	aux = pElDscpI;
	while (aux != NULL)
	{
		cout << (aux->getPDscp())->getNome() << endl;
		aux = aux->getProxElDscp();
	}
	cout << "===" << endl;
}