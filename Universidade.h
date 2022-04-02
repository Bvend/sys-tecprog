#pragma once

#include "Departamento.h"

class Universidade
{
private:
	char nome[100];

	list<Departamento*> dptos;

public:
	// Construtora
	Universidade();
	Universidade(const char *n);
	// Destrutora
	~Universidade();

	void setNome(const char* n);
	char* getNome();
	void setDpto(Departamento* pd, int id);
	void informaDptos();
};
