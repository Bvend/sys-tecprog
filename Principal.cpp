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
	// Princeton.setNome("Princeton");
	// Princeton.incluiDpto(&PrincetonFis);

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
	// PrincetonFis.setNome("PrincetonFis");
	// PrincetonFis.setUnivFiliada(&Princeton);

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
	// Eisten.inicializa(14, 3, 1879, "Eisten");
	// Eisten.setUnivFiliado(&Princeton);
	// Eisten.setDptoFiliado(&PrincetonFis);

	// Inicializa Bogdan
	Bogdan.inicializa(0, 0, 0, "Bogdan");
	Bogdan.setUnivFiliado(&UTFPR);
	Bogdan.setDptoFiliado(&DAINF);
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

	// Eisten.calc_imprime_idade(diaAtual, mesAtual, anoAtual);
	Bogdan.calc_imprime_idade(diaAtual, mesAtual, anoAtual);
	Joao.calc_imprime_idade(diaAtual, mesAtual, anoAtual);
	Pedro.calc_imprime_idade(diaAtual, mesAtual, anoAtual);
}

void Principal::imprime_onde_trabalho()
{
	// Eisten.ondeTrabalho();
	Bogdan.ondeTrabalho();
}

void Principal::lista_dscp_por_dpto()
{
	DAINF.listaDscp();
}

void Principal::lista_alunos()
{
	ED1.listaAlunos();
}

void Principal::Menu()
{
	int op = -1;

	while (op != 5)
	{
		system("cls");
		cout << "Informe sua opcao:" << endl;
		cout << "1 - Cadastrar" << endl;
		cout << "2 - Executar" << endl;
		cout << "3 - Gravar" << endl;
		cout << "4 - Recuperar" << endl;
		cout << "5 - Sair" << endl;
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
			MenuGravar();
			break;
		case 4:
			//MenuRecuperar();
			break;
		case 5:
			cout << "Ate Nunca mais" << endl;
			getchar();
			getchar();
			break;
		default: // op tem que ser um int (se passar um char da merda)
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

	while (op != 5)
	{
		system("cls");
		cout << "Informe sua opcao:" << endl;
		cout << "1 - Cadastrar Disciplina" << endl;
		cout << "2 - Cadastrar Departamento" << endl;
		cout << "3 - Cadastrar Universidade" << endl;
		cout << "4 - Cadastrar Aluno" << endl;
		cout << "5 - SAIR" << endl;
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
			CadAluno();
			break;
		case 5:
			cout << "Saia daqui agora" << endl;
			break;
		default:
			cout << "Opcao Invalida" << endl;
			getchar();
			getchar();
			break;
		}
	}
}

void Principal::MenuExe()
{
	int op = -1;

	while (op != 5)
	{
		system("cls");
		cout << "Informe sua opcao:" << endl;
		cout << "1 - Listar Disciplinas" << endl;
		cout << "2 - Listar Departamentos" << endl;
		cout << "3 - Listar Universidades" << endl;
		cout << "4 - Listar Alunos" << endl;
		cout << "5 - SAIR" << endl;
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
			LAlunos.listaAlunos();
			fflush(stdin);
			getchar();
			getchar();
			break;
		case 5:
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

void Principal::MenuGravar()
{
	int op = -1;
	while (op != 6)
	{
		system("cls");
		cout << "Informe sua opcao:" << endl;
		cout << "0 - Gravar tudo" << endl;
		cout << "1 - Gravar Universidades" << endl;
		cout << "2 - Gravar Departamentos" << endl;
		cout << "3 - Gravar Disciplinas" << endl;
		cout << "4 - Gravar Alunos" << endl;
		cout << "5 - Gravar Professores" << endl;
		cout << "6 - Sair" << endl;
		cin >> op;
		
		switch (op)
		{
		case 1:
			GravarTudo();
			break;
		case 2:
			GravarUniversidades();
			break;
		case 3:
			GravarDepartamentos();
			break;
		case 4:
			GravarDisciplinas();
			break;
		case 5:
			GravarAlunos();
			break;
		case 6:
			GravarProfessores();
			break;
		default:
			cout << "Opcao Invalida" << endl;
			getchar();
			getchar();
			break;
		}

	}
}

void Principal::MenuRecuperar()
{
	int op = -1;
	while (op != 6)
	{
		system("cls");
		cout << "Informe sua opcao:" << endl;
		cout << "0 - Recuperar tudo" << endl;
		cout << "1 - Recuperar Universidades" << endl;
		cout << "2 - Recuperar Departamentos" << endl;
		cout << "3 - Recuperar Disciplinas" << endl;
		cout << "4 - Recuperar Alunos" << endl;
		cout << "5 - Recuperar Professores" << endl;
		cout << "6 - Sair" << endl;
		cin >> op;

		switch (op)
		{
		case 1:
			RecuperarTudo();
			break;
		case 2:
			RecuperarUniversidades();
			break;
		case 3:
			RecuperarDepartamentos();
			break;
		case 4:
			RecuperarDisciplinas();
			break;
		case 5:
			RecuperarAlunos();
			break;
		case 6:
			RecuperarProfessores();
			break;
		default:
			cout << "Opcao Invalida" << endl;
			getchar();
			getchar();
			break;
		}

	}
}

void Principal::CadAluno()
{
	char nomeAluno[100];
	int ra;
	Aluno* pAluno = NULL;

	cout << "Qual o nome do aluno?" << endl;
	cin >> nomeAluno;

	cout << "Qual o RA do aluno?" << endl;
	cin >> ra;

	pAluno = new Aluno(cont_idAluno);
	cont_idAluno++;
	pAluno->setNome(nomeAluno);
	pAluno->setRa(ra);

	LAlunos.incluiAluno(pAluno);
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
		pDscp = new Disciplina(cont_idDscp);
		cont_idDscp++;
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
		pDpto = new Departamento(cont_idDpto++);
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

void Principal::GravarTudo()
{
}

void Principal::GravarUniversidades()
{
}

void Principal::GravarDepartamentos()
{
}

void Principal::GravarDisciplinas()
{
}

void Principal::GravarAlunos()
{
	LAlunos.graveAlunos();
}

void Principal::GravarProfessores()
{
}

void Principal::RecuperarTudo()
{
}

void Principal::RecuperarUniversidades()
{
}

void Principal::RecuperarDepartamentos()
{
}

void Principal::RecuperarDisciplinas()
{
}

void Principal::RecuperarAlunos()
{
	LAlunos.recupereAlunos();
}

void Principal::RecuperarProfessores()
{
}