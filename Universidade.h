#pragma once

#include "Departamento.h"
#include "ListaDepartamentos.h"
#include "ElDepartamento.h"

class Universidade
{
private:
	char nome[100];
	int id;

	ListaDepartamentos* pObjListaDptos;

public:
	// Construtora
	Universidade(int i = -1);
	Universidade(const char *n);
	// Destrutora
	~Universidade();

	void setNome(const char* n);
	char* getNome();

	void incluiDpto(Departamento* pd);
	void listaDptos();
};