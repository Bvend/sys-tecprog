#include "ElDisciplina.h"

ElDisciplina::ElDisciplina()
{
	pDscp = NULL;
	proxElDscp = NULL;
	prevElDscp = NULL;
}

ElDisciplina::~ElDisciplina()
{
	pDscp = NULL;
	proxElDscp = NULL;
	prevElDscp = NULL;
}

void ElDisciplina::setPDscp(Disciplina* pd)
{
	pDscp = pd;
}

Disciplina* ElDisciplina::getPDscp()
{
	return pDscp;
}

void ElDisciplina::setProxElDscp(ElDisciplina* pED)
{
	proxElDscp = pED;
}

ElDisciplina* ElDisciplina::getProxElDscp()
{
	return proxElDscp;
}

void ElDisciplina::setPrevElDscp(ElDisciplina* pED)
{
	prevElDscp = pED;
}

ElDisciplina* ElDisciplina::getPrevElDscp()
{
	return prevElDscp;
}
