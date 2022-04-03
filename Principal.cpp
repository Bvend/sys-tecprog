#include "Principal.h"
#include <time.h>
#include <Windows.h>

Principal::Principal()
{
	inicializa();
	executar();
}

Principal::~Principal()
{
}

void Principal::inicializa()
{
	inicializaUniv();
	inicializaDpto();
	inicializaDscp();
	inicializaPrfs();
	inicializaAlunos();
}

void Principal::inicializaUniv()
{
	// Iniciliza Princeton
	Princeton.setNome("Princeton");
	Princeton.incluiDpto(&PrincetonFis);

	// Inicializa UTFPR
	UTFPR.setNome("Universidade Tecnologica Federal do Parana");
	UTFPR.incluiDpto(&DAINF);
	UTFPR.incluiDpto(&DAELN);

	// Imprime departamentos com universidade
	//Princeton.informaDptos();
	//Cambridge.informaDptos();
}

void Principal::inicializaDpto()
{
	// Inicializa departamento de Física de Princeton
	PrincetonFis.setNome("PrincetonFis");
	PrincetonFis.setUnivFiliada(&Princeton);

	// Inicializa DAINF
	DAINF.setNome("Departamento Academico de Informatica");
	DAINF.setUnivFiliada(&UTFPR);

	// Inicializa DAELN
	DAELN.setNome("Departamento Academico de Eletronica");
	DAELN.setUnivFiliada(&UTFPR);
}

void Principal::inicializaDscp()
{
	// Inicializa ED1
	ED1.setNome("Estrutura de Dados 1");
	ED1.setDptoFiliado(&DAINF);
	ED1.incluiAluno(&Joao);
	ED1.incluiAluno(&Pedro);

	// Inicializa ED2
	ED2.setNome("Estrutura de Dados 2");
	ED2.setDptoFiliado(&DAINF);

	// Inicializa TecProg
	TecProg.setNome("Tecnicas de Programacao");
	TecProg.setDptoFiliado(&DAINF);

	// Inicializa FDP
}

void Principal::inicializaPrfs()
{
	// Inicializa Eisten
	Eisten.inicializa(14, 3, 1879, "Eisten");
	Eisten.setUnivFiliado(&Princeton);
	Eisten.setDptoFiliado(&PrincetonFis);
}

void Principal::inicializaAlunos()
{
	// Joao
	Joao.inicializa(9, 9, 2003, "Jaaaooo");
	
	// Pedro
	Pedro.inicializa(25, 1, 2002, "PDAVK");
}

void Principal::executar()
{
	imprime_calc_idade();
	imprime_onde_trabalho();
	lista_dscp_por_dpto();
	lista_alunos();
}

void Principal::imprime_calc_idade()
{
	// Atualiza dia
	SYSTEMTIME st;
	GetSystemTime(&st);

	diaAtual = st.wDay;
	mesAtual = st.wMonth;
	anoAtual = st.wYear;

	Eisten.calc_imprime_idade(diaAtual, mesAtual, anoAtual);
	Joao.calc_imprime_idade(diaAtual, mesAtual, anoAtual);
	Pedro.calc_imprime_idade(diaAtual, mesAtual, anoAtual);
}

void Principal::imprime_onde_trabalho()
{
	Eisten.ondeTrabalho();
}

void Principal::lista_dscp_por_dpto()
{
	DAINF.listaDscp();
}

void Principal::lista_alunos()
{
	ED1.listaAlunos();
}
