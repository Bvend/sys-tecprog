#pragma once

#include "Pessoa.h"
#include "ElAluno.h"

class Departamento;

class Aluno : public Pessoa
{
private:
	int RA;

public:
	// Construtora e destrutora
	Aluno(int i = -1);
	Aluno(int diaNasc, int mesNasc, int anoNasc, const char* n);
	~Aluno();

	void setRa(int registro);
	int getRa();
};