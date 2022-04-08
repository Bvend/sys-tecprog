#pragma once

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#include "ElDepartamento.h"

class Universidade;
class Disciplina;
class ElDisciplina;
class ListaDisciplinas;

class Departamento
{
private:
	int id;
	char nome[100];

	Universidade* univFiliada;

	ListaDisciplinas* pObjLstDscps;

public:
	// Construtora e Destrutora
	Departamento(int i = -1);
	Departamento(const char* n);
	~Departamento();

	int getId();
	void setId(int i);
	void setNome(const char* n);
	char* getNome();

	void setUnivFiliada(Universidade* pu);

	void incluiDscp(Disciplina* pd);
	void listaDscp();
};