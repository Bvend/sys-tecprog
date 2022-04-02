#include "Universidade.h"

Universidade::Universidade(const char* n)
{
	strcpy_s(nome, n);
}

Universidade::Universidade()
{
	strcpy_s(nome, "");
}

Universidade::~Universidade()
{
}

void Universidade::setNome(const char* n)
{
	strcpy_s(nome, n);
}

char *Universidade::getNome()
{
	return (nome);
}

void Universidade::setDpto(Departamento* pd, int id)
{
	dptos.push_back(pd);
	(*pd).setId(id);
}

void Universidade::informaDptos()
{
	list<Departamento*>::iterator it;
	for (it = dptos.begin(); it != dptos.end(); it++)
	{
		cout << (*it)->getNome() << " " << (**it).getId() << endl;
	}
}
