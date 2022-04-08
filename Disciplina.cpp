#include "Disciplina.h"
#include "Departamento.h"
#include "Aluno.h"

Disciplina::Disciplina(int i)
{
	id = i;
	strcpy_s(nome, "");
	dptoFiliado = NULL;
}

Disciplina::Disciplina(const char* n, Departamento* pd)
{
	strcpy_s(nome, n);
	dptoFiliado = pd;
}

Disciplina::~Disciplina()
{
	dptoFiliado = NULL;
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

void Disciplina::incluiAluno(Aluno* pa)
{
	objLstAlunos.incluiAluno(pa);
}

void Disciplina::listaAlunos()
{
	objLstAlunos.listaAlunos();
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
