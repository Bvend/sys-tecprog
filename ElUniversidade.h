#pragma once

#include <stdio.h>

class Universidade;

class ElUniversidade
{
private:
	Universidade* pUniv;
	ElUniversidade* proxElUniv;
	ElUniversidade* prevElUniv;

public:
	// Construtora e Destrutora
	ElUniversidade();
	~ElUniversidade();

	void setPUniv(Universidade* pu);
	Universidade* getPUniv();

	void setProxElUniv(ElUniversidade* pEU);
	ElUniversidade* getProxElUniv();
	void setPrevElUniv(ElUniversidade* pEU);
	ElUniversidade* getPrevElUniv();
};