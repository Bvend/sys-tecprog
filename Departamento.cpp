#include "Departamento.h"
#include "Disciplina.h"

Departamento::Departamento()
{
	id = -1;
	strcpy_s(nome, "");

	univFiliada = NULL;

	pPrimDscp = NULL;
	pAtualDscp = NULL;
}

Departamento::Departamento(const char* n)
{
	id = -1;
	strcpy_s(nome, n);

	univFiliada = NULL;

	pPrimDscp = NULL;
	pAtualDscp = NULL;
}

Departamento::~Departamento()
{
	univFiliada = NULL;
	pPrimDscp = NULL;
	pAtualDscp = NULL;
}

int Departamento::getId()
{
	return 0;
}

void Departamento::setId(int i)
{
	id = i;
}

void Departamento::setNome(const char* n)
{
	strcpy_s(nome, n);
}

char* Departamento::getNome()
{
	return nome;
}

void Departamento::setUnivFiliada(Universidade* pu)
{
	univFiliada = pu;
}

void Departamento::incluiDscp(Disciplina* pd)
{
	if (pPrimDscp == NULL)
	{
		pPrimDscp = pd;
		pAtualDscp = pd;
	}
	else
	{
		pd->setPrevDscp(pAtualDscp);
		(*pAtualDscp).setProxDscp(pd);
		pAtualDscp = pd;
	}
}

void Departamento::listeDscp()
{
	Disciplina* aux = pPrimDscp;
	cout << "Disciplinas do " << nome << ": ";
	while (aux != NULL)
	{
		cout << aux->getNome() << "\t";
		aux = aux->getProxDscp();
	}
	cout << "\n";
}
