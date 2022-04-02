#include "Aluno.h"
#include <string.h>

Aluno::Aluno():
Pessoa()
{
	RA = -1;
	strcpy_s(nome, "");
}

Aluno::Aluno(int diaNasc, int mesNasc, int anoNasc, const char* n):
Pessoa(diaNasc, mesNasc, anoNasc, n)
{
	RA = -1;
	strcpy_s(nome, "");
}

Aluno::~Aluno()
{
}

void Aluno::setRa(int registro)
{
	RA = registro;
}

int Aluno::getRa()
{
	return RA;
}