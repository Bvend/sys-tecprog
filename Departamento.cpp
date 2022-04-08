#include "Departamento.h"
#include "Disciplina.h"
#include "ListaDisciplinas.h"

Departamento::Departamento(int i)
{
	id = i;
	strcpy_s(nome, "");

	univFiliada = NULL;

	pObjLstDscps = new ListaDisciplinas();
}

Departamento::Departamento(const char* n)
{
	id = -1;
	strcpy_s(nome, n);

	univFiliada = NULL;

	pObjLstDscps = new ListaDisciplinas();
}

Departamento::~Departamento()
{
	univFiliada = NULL;

	if (pObjLstDscps)
		delete pObjLstDscps;
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
	pObjLstDscps->incluiDscp(pd);
}

void Departamento::listaDscp()
{
	pObjLstDscps->listaDscp();
}