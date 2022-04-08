#include "ElDepartamento.h"
#include "Departamento.h"

ElDepartamento::ElDepartamento()
{
	pDpto = NULL;
	proxElDpto = NULL;
	prevElDpto = NULL;
}

ElDepartamento::~ElDepartamento()
{
	pDpto = NULL;
	proxElDpto = NULL;
	prevElDpto = NULL;
}

void ElDepartamento::setPDpto(Departamento* pd)
{
	pDpto = pd;
}

Departamento* ElDepartamento::getPDpto()
{
	return pDpto;
}

void ElDepartamento::setProxElDpto(ElDepartamento* pED)
{
	proxElDpto = pED;
}

ElDepartamento* ElDepartamento::getProxElDpto()
{
	return proxElDpto;
}

void ElDepartamento::setPrevElDpto(ElDepartamento* pED)
{
	prevElDpto = pED;
}

ElDepartamento* ElDepartamento::getPrevElDpto()
{
	return prevElDpto;
}