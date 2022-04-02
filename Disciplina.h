#pragma once

#include <stdio.h>
#include <string.h>
#include "Aluno.h"

class Departamento;

class Disciplina
{
private:
	int id;
	char nome[100];

	Departamento* dptoFiliado;

	Disciplina* proxDscp;
	Disciplina* prevDscp;

	int maxAlunos;
	int conta_Alunos;
	ElAluno* pElAlunoI;
	ElAluno* pElAlunoF;

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

	// Lista de Disciplinas
	void setProxDscp(Disciplina* pd);
	Disciplina* getProxDscp();
	void setPrevDscp(Disciplina* pd);
	Disciplina* getPrevDscp();

	// Alunos pertencentes à disciplina
	void incluiAluno(Aluno* pa);
	void listeAlunos();
	/*void excluiAluno(Aluno* pa);*/
};