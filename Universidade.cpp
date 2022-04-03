#include "Universidade.h"

Universidade::Universidade(const char* n)
{
	strcpy_s(nome, n);

	pObjListaDptos = new ListaDepartamentos();
}

Universidade::Universidade()
{
	strcpy_s(nome, "");

	pObjListaDptos = new ListaDepartamentos();
}

Universidade::~Universidade()
{
	delete(pObjListaDptos);
}

void Universidade::setNome(const char* n)
{
	strcpy_s(nome, n);
}

char *Universidade::getNome()
{
	return (nome);
}

void Universidade::incluiDpto(Departamento* pd)
{
	pObjListaDptos->incluiDpto(pd);
}

void Universidade::listaDptos()
{
	pObjListaDptos->listaDptos();
}
