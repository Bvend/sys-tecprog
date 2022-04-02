#include "Disciplina.h"
#include "Departamento.h"
#include "Aluno.h"

Disciplina::Disciplina()
{
	id = -1;
	strcpy_s(nome, "");
	dptoFiliado = NULL;
	proxDscp = NULL;
	prevDscp = NULL;
	maxAlunos = 45;
	conta_Alunos = 0;
	pElAlunoI = NULL;
	pElAlunoF = NULL;
}

Disciplina::Disciplina(int identf, const char* n, Departamento* pd, int max)
{
	id = identf;
	strcpy_s(nome, n);
	dptoFiliado = pd;
	proxDscp = NULL;
	prevDscp = NULL;
	maxAlunos = max;
	conta_Alunos = 0;
	pElAlunoI = NULL;
	pElAlunoF = NULL;
}

Disciplina::~Disciplina()
{
	ElAluno* aux = NULL;
	aux = pElAlunoI;
	while (aux != NULL)
	{
		pElAlunoI = pElAlunoI->getProxElAluno();
		delete(aux);
		aux = pElAlunoI;
	}


	dptoFiliado = NULL;
	proxDscp = NULL;
	prevDscp = NULL;
	pElAlunoI = NULL;
	pElAlunoF = NULL;
}

void Disciplina::setId(int identf)
{
	id = identf;
}

int Disciplina::getId()
{
	return id;
}

void Disciplina::setNome(const char* n)
{
	strcpy_s(nome, n);
}

char* Disciplina::getNome()
{
	return nome;
}

void Disciplina::setDptoFiliado(Departamento* pd)
{
	dptoFiliado = pd;

	dptoFiliado->incluiDscp(this);
}

void Disciplina::setProxDscp(Disciplina* pd)
{
	proxDscp = pd;
}

Disciplina* Disciplina::getProxDscp()
{
	return proxDscp;
}

void Disciplina::setPrevDscp(Disciplina* pd)
{
	prevDscp = pd;
}

Disciplina* Disciplina::getPrevDscp()
{
	return prevDscp;
}

void Disciplina::incluiAluno(Aluno* pa)
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

void Disciplina::listeAlunos()
{
	ElAluno* aux = NULL;
	aux = pElAlunoI;
	cout << "Alunos da Disciplina " << nome << ": ";
	while (aux != NULL)
	{
		cout << (aux->getPAluno())->getNome() << "\t";
		aux = aux->getProxElAluno();
	}
	cout << endl;
}

// Nao Funciona - Falta alterar pAtualAluno
/*void Disciplina::excluiAluno(Aluno* pa)
{
	Aluno* aux = pPrimAluno;

	if (aux != NULL && aux == pa)
	{
		pPrimAluno = pPrimAluno->getProxAluno();

		if (aux->getPrevAluno() != NULL)
		{
			if (aux->getProxAluno() != NULL)
			{
				(aux->getPrevAluno())->setProxAluno(aux->getProxAluno());
			}
			else
			{
				(aux->getPrevAluno())->setProxAluno(NULL);
			}
		}

		if (aux->getProxAluno() != NULL)
		{
			if (aux->getPrevAluno() != NULL)
			{
				(aux->getProxAluno())->setPrevAluno(aux->getPrevAluno());
			}
			else
			{
				(aux->getProxAluno())->setPrevAluno(NULL);
			}
		}

		aux->setPrevAluno(NULL);
		aux->setProxAluno(NULL);

		return;
	}

	while (aux != NULL)
	{
		aux = aux->getProxAluno();

		if (aux == pa)
		{
			if (aux->getPrevAluno() != NULL)
			{
				if (aux->getProxAluno() != NULL)
				{
					(aux->getPrevAluno())->setProxAluno(aux->getProxAluno());
				}
				else
				{
					(aux->getPrevAluno())->setProxAluno(NULL);
				}
			}
			
			if (aux->getProxAluno() != NULL)
			{
				if (aux->getPrevAluno() != NULL)
				{
					(aux->getProxAluno())->setPrevAluno(aux->getPrevAluno());
				}
				else
				{
					(aux->getProxAluno())->setPrevAluno(NULL);
				}
			}
			
			aux->setPrevAluno(NULL);
			aux->setProxAluno(NULL);
			break;
		}
	}
}*/
