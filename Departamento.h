#pragma once

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <list>
using namespace std;

class Universidade;
class Disciplina;

class Departamento
{
private:
	int id;
	char nome[100];

	Universidade* univFiliada;
	
	Disciplina* pPrimDscp;
	Disciplina* pAtualDscp;

public:
	// Construtora e Destrutora
	Departamento();
	Departamento(const char* n);
	~Departamento();

	int getId();
	void setId(int i);
	void setNome(const char* n);
	char* getNome();

	void setUnivFiliada(Universidade* pu);

	void incluiDscp(Disciplina* pd);
	void listeDscp();
};