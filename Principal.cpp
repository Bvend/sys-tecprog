#include "Principal.h"
#include <time.h>
#include <Windows.h>

Principal::Principal()
{
	//inicializa();
	//executar();
	Menu();
}

Principal::~Principal()
{
}

/*void Principal::inicializa()
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
}*/

void Principal::Menu()
{
	int op = -1;

	while (op != 3)
	{
		system("cls");
		cout << "Informe sua opcao:" << endl;
		cout << "1 - Cadastrar" << endl;
		cout << "2 - Executar" << endl;
		cout << "3 - Sair" << endl;
		cin >> op;

		switch (op)
		{
		case 1:
			MenuCad();
			break;
		case 2:
			MenuExe();
			break;
		case 3:
			cout << "Ate Nunca mais" << endl;
			getchar();
			getchar();
			break;
		default:
			cout << "Opcao Invalida" << endl;
			getchar();
			getchar();
			break;
		}
	}
}

void Principal::MenuCad()
{
	int op = -1;

	while (op != 4)
	{
		system("cls");
		cout << "Informe sua opcao:" << endl;
		cout << "1 - Cadastrar Disciplina" << endl;
		cout << "2 - Cadastrar Departamento" << endl;
		cout << "3 - Cadastrar Universidade" << endl;
		cout << "4 - SAIR" << endl;
		cin >> op;

		switch (op)
		{
		case 1:
			CadDisciplina();
			break;
		case 2:
			CadDepartamento();
			break;
		case 3:
			CadUniversidade();
			break;
		case 4:
			cout << "Saia daqui agora" << endl;
			break;
		default:
			cout << "Opcao Invalida" << endl;
			break;
		}
	}
}

void Principal::MenuExe()
{
	int op = -1;

	while (op != 4)
	{
		system("cls");
		cout << "Informe sua opcao:" << endl;
		cout << "1 - Listar Disciplinas" << endl;
		cout << "2 - Listar Departamentos" << endl;
		cout << "3 - Listar Universidades" << endl;
		cout << "4 - SAIR" << endl;
		cin >> op;

		switch (op)
		{
		case 1:
			LDscps.listaDscp();
			fflush(stdin);
			getchar();
			getchar();
			break;
		case 2:
			LDptos.listaDptos();
			fflush(stdin);
			getchar();
			getchar();
			break;
		case 3:
			LUnivs.listaUnivs();
			fflush(stdin);
			getchar();
			getchar();
			break;
		case 4:
			cout << "FIM BABY" << endl;
			getchar();
			getchar();
			break;
		default:
			cout << "Opcao Invalida" << endl;
			getchar();
			getchar();
			break;
		}
	}
}

void Principal::CadDisciplina()
{
	char nomeDpto[100];
	char nomeDscp[100];
	Departamento* pDpto = NULL;
	Disciplina* pDscp = NULL;

	cout << "Qual o nome do departamento da disciplina?" << endl;
	cin >> nomeDpto;
	pDpto = LDptos.localizar(nomeDpto);

	if (pDpto != NULL)
	{
		cout << "Qual o nome da disciplina?" << endl;
		cin >> nomeDscp;
		pDscp = new Disciplina();
		pDscp->setNome(nomeDscp);
		pDscp->setDptoFiliado(pDpto);
		LDscps.incluiDscp(pDscp);
		pDpto->incluiDscp(pDscp);
	}
	else
	{
		cout << "Departamento inexistente" << endl;
		getchar();
		getchar();
	}
}

void Principal::CadDepartamento()
{
	char nomeUniv[100];
	char nomeDpto[100];
	Universidade* pUniv = NULL;
	Departamento* pDpto = NULL;

	cout << "Qual o nome da universidade do departamento?" << endl;
	cin >> nomeUniv;
	pUniv = LUnivs.localizar(nomeUniv);

	if (pUniv != NULL)
	{
		cout << "Qual o nome do departamento?" << endl;
		cin >> nomeDpto;
		pDpto = new Departamento();
		pDpto->setNome(nomeDpto);
		pDpto->setUnivFiliada(pUniv);
		LDptos.incluiDpto(pDpto);
		pUniv->incluiDpto(pDpto);
	}
	else
	{
		cout << "Universidade inexistente" << endl;
		getchar();
		getchar();
	}
}

void Principal::CadUniversidade()
{
	char nomeUniv[100];
	Universidade* pUniv = NULL;

	cout << "Qual o nome da universidade?" << endl;
	cin >> nomeUniv;

	pUniv = new Universidade();
	pUniv->setNome(nomeUniv);
	LUnivs.incluiUniv(pUniv);
}
