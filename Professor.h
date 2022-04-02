#pragma once

#include "Pessoa.h"

class Professor : public Pessoa
{
private:
	Universidade* pUnivFiliado;
	Departamento* pDptoFiliado;

public:
	// Construtoras e destrutoras
	Professor();
	Professor(int diaNasc, int mesNasc, int anoNasc, const char* n);
	~Professor();

	void setUnivFiliado(Universidade* pu);
	void setDptoFiliado(Departamento* pd);
	void ondeTrabalho();
};