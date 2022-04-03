#pragma once

#include "Professor.h"
#include "Aluno.h"
#include "Disciplina.h"
#include "Universidade.h"
#include "ListaUniversidades.h"

class Principal
{
private:
	// Universidades
	Universidade Princeton;
	Universidade UTFPR;

	// Departamentos
	Departamento PrincetonFis;
	Departamento DAINF;
	Departamento DAELN;

	// Disciplinas
	Disciplina ED1;
	Disciplina ED2;
	Disciplina TecProg;

	// Professores
	Professor Eisten;

	// Aluno
	Aluno Joao;
	Aluno Pedro;

	// Data
	int diaAtual;
	int mesAtual;
	int anoAtual;

public:
	// Construtora e Destrutora
	Principal();
	~Principal();

	// Inicializações
	void inicializa();

	void inicializaUniv();
	void inicializaDpto();
	void inicializaDscp();
	void inicializaPrfs();
	void inicializaAlunos();

	void executar();

	void imprime_calc_idade();
	void imprime_onde_trabalho();
	void lista_dscp_por_dpto();
	void lista_alunos();
};