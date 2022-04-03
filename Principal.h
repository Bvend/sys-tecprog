#pragma once

#include "Professor.h"
#include "Aluno.h"
#include "Disciplina.h"
#include "Universidade.h"
#include "ListaUniversidades.h"
#include "ListaDisciplinas.h"

class Principal
{
private:
	/*// Universidades
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
	int anoAtual;*/

	// Listas
	ListaUniversidades LUnivs;
	ListaDepartamentos LDptos;
	ListaDisciplinas LDscps;

public:
	// Construtora e Destrutora
	Principal();
	~Principal();

	// Inicializacoes
	void inicializa();

	void inicializaUniv();
	void inicializaDpto();
	void inicializaDscp();
	void inicializaPrfs();
	void inicializaAlunos();

	// Funcoes de Comandos
	void executar();

	void imprime_calc_idade();
	void imprime_onde_trabalho();
	void lista_dscp_por_dpto();
	void lista_alunos();

	// Menu e Funcoes Cadastrar
	void Menu();
	void MenuCad();
	void MenuExe();

	void CadDisciplina();
	void CadDepartamento();
	void CadUniversidade();
};