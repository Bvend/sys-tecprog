#pragma once

#include <stdio.h>

class ElDisciplina;
class Disciplina;

class ListaDisciplinas
{
private:
	char nome[100];
	ElDisciplina* pElDscpI;
	ElDisciplina* pElDscpF;

public:
	// Contrutora e Destrutora
	ListaDisciplinas(const char* n = "");
	~ListaDisciplinas();

	void getNome(char* n);
	char* setNome();

	void incluiDscp(Disciplina* pd);
	void listaDscp();
};