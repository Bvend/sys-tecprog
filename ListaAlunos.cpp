#include "ListaAlunos.h"
#include "Aluno.h"
#include <fstream>

ListaAlunos::ListaAlunos(const char* n)
{
	strcpy_s(nome, n);
	maxAlunos = 45;
	conta_Alunos = 0;
	pElAlunoI = NULL;
	pElAlunoF = NULL;
}

ListaAlunos::~ListaAlunos()
{
	ElAluno* aux = NULL;
	aux = pElAlunoI;
	while (aux != NULL)
	{
		pElAlunoI = pElAlunoI->getProxElAluno();
		delete(aux);
		aux = pElAlunoI;
	}

	pElAlunoF = NULL;
}

void ListaAlunos::limpaLista()
{
	ElAluno* aux = NULL;
	aux = pElAlunoI;
	while (aux != NULL)
	{
		pElAlunoI = pElAlunoI->getProxElAluno();
		delete(aux);
		aux = pElAlunoI;
	}

	pElAlunoF = NULL;
}

void ListaAlunos::setNome(const char* n)
{
	strcpy_s(nome, n);
}

char* ListaAlunos::getNome()
{
	return nome;
}

void ListaAlunos::incluiAluno(Aluno* pa)
{
	if (conta_Alunos == 45)
	{
		cout << "Aluno nao incluido. Turma cheia." << endl;
		return;
	}

	if (pa == NULL)
	{
		cout << "Erro na inclusao do aluno" << endl;
		return;
	}

	ElAluno* paux = NULL;

	paux = new ElAluno();

	paux->setPAluno(pa);

	if (pElAlunoI == NULL)
	{
		pElAlunoI = paux;
		pElAlunoF = paux;
	}
	else
	{
		pElAlunoF->setProxElAluno(paux);
		paux->setPrevElAluno(pElAlunoF);
		pElAlunoF = paux;
	}

	conta_Alunos++;
}

void ListaAlunos::listaAlunos()
{
	ElAluno* aux = NULL;
	aux = pElAlunoI;
	while (aux != NULL)
	{
		cout << (aux->getPAluno())->getNome() << endl;
		aux = aux->getProxElAluno();
	}
	cout << "===" << endl;
}

void ListaAlunos::graveAlunos()
{
	ifstream RecuperadorAlunos("alunos.dat", ios::in);
	if (!RecuperadorAlunos)
	{
		cerr << "Arquivo nao pode ser aberto" << endl;
		fflush(stdin);
		getchar();
		return;
	}

	limpaLista();

	Aluno* pauxAluno = NULL;
	int id;
	int ra;
	char nome[150];
	while (RecuperadorAlunos >> id >> ra >> nome)
	{
		if (0 != strcmp(nome, ""))
		{
			pauxAluno = new Aluno(-1);
			pauxAluno->setId(id);
			pauxAluno->setRa(ra);
			pauxAluno->setNome(nome);

			incluiAluno(pauxAluno);
		}
	}
	RecuperadorAlunos.close();
}

void ListaAlunos::recupereAlunos()
{
	ofstream GravadorAlunos("alunos.dat", ios::out);

	if (!GravadorAlunos)
	{
		cerr << "arquivo nao pode ser aberto" << endl;
		fflush(stdin);
		getchar();
		return;
	}

	ElAluno* pauxElAluno = NULL;
	Aluno* pauxAluno = NULL;

	pauxElAluno = pElAlunoI;

	while (pauxElAluno != NULL)
	{
		pauxAluno = pauxElAluno->getPAluno();

		GravadorAlunos << pauxAluno->getId() << ""
					   << pauxAluno->getRa() << ""
					   << pauxAluno->getNome() << endl;

		pauxElAluno = pauxElAluno->getProxElAluno();
	}

	GravadorAlunos.close();
}