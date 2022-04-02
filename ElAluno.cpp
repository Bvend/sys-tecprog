#include "ElAluno.h"
#include "Aluno.h"

ElAluno::ElAluno()
{
	pAluno = NULL;
	proxElAluno = NULL;
	prevElAluno = NULL;
}

ElAluno::~ElAluno()
{
	pAluno = NULL;
	proxElAluno = NULL;
	prevElAluno = NULL;
}

void ElAluno::setPAluno(Aluno* pa)
{
	pAluno = pa;
}

Aluno* ElAluno::getPAluno(void)
{
	return pAluno;
}

void ElAluno::setProxElAluno(ElAluno* pEA)
{
	proxElAluno = pEA;
}

ElAluno* ElAluno::getProxElAluno()
{
	return proxElAluno;
}

void ElAluno::setPrevElAluno(ElAluno* pEA)
{
	prevElAluno = pEA;
}

ElAluno* ElAluno::getPrevElAluno()
{
	return prevElAluno;
}
