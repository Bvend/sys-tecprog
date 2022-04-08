#pragma once

#include <stdio.h>
#include "ElDepartamento.h"

class ElDepartamento;
class Departamento;

class ListaDepartamentos
{
private:
	char nome[100];
	ElDepartamento* pElDptoI;
	ElDepartamento* pElDptoF;

public:
	// Construtora e Detrutora
	ListaDepartamentos(const char* n = "");
	~ListaDepartamentos();

	void setNome(char* n);
	char* getNome();

	void incluiDpto(Departamento* pd);
	void listaDptos();

	Departamento* localizar(const char* n);
};