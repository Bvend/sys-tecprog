#include "ElUniversidade.h"
#include "Universidade.h"

ElUniversidade::ElUniversidade()
{
	pUniv = NULL;
	proxElUniv = NULL;
	prevElUniv = NULL;
}

ElUniversidade::~ElUniversidade()
{
	pUniv = NULL;
	proxElUniv = NULL;
	prevElUniv = NULL;
}

void ElUniversidade::setPUniv(Universidade* pu)
{
	pUniv = pu;
}

Universidade* ElUniversidade::getPUniv()
{
	return pUniv;
}

void ElUniversidade::setProxElUniv(ElUniversidade* pEU)
{
	proxElUniv = pEU;
}

ElUniversidade* ElUniversidade::getProxElUniv()
{
	return proxElUniv;
}

void ElUniversidade::setPrevElUniv(ElUniversidade* pEU)
{
	prevElUniv = pEU;
}

ElUniversidade* ElUniversidade::getPrevElUniv()
{
	return prevElUniv;
}