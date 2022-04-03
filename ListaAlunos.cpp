#include "ListaAlunos.h"
#include "Aluno.h"

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
