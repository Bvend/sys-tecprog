#pragma once

#include <stdio.h>

class ElAluno;
class Aluno;

class ListaAlunos
{
private:
	char nome[100];
	int maxAlunos;
	int conta_Alunos;
	ElAluno* pElAlunoI;
	ElAluno* pElAlunoF;

public:
	// Construtora e Destrutora
	ListaAlunos(const char* n = "");
	~ListaAlunos();

	void setNome(const char* n);
	char* getNome();

	void incluiAluno(Aluno* pa);
	void listaAlunos();
};