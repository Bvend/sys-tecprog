#pragma once

#include <stdio.h>
#include <string.h>
#include "Aluno.h"
#include "ElDisciplina.h"
#include "ListaAlunos.h"

class Departamento;

class Disciplina
{
private:
	int id;
	char nome[100];

	Departamento* dptoFiliado;

	ListaAlunos objLstAlunos;

public:
	// Construtora e Destrutora
	Disciplina();
	Disciplina(int identf, const char* n = "", Departamento* pd = NULL, int max = 45);
	~Disciplina();

	// Informações básicas
	void setId(int identf);
	int getId();
	void setNome(const char* n);
	char* getNome();

	// Departamento associado
	void setDptoFiliado(Departamento* pd);

	// Alunos pertencentes à disciplina
	void incluiAluno(Aluno* pa);
	void listaAlunos();
	/*void excluiAluno(Aluno* pa);*/
};