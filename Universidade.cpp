#include "Universidade.h"
#include "string.h"

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
