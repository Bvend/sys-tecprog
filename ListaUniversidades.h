#pragma once

#include <stdio.h>
#include "ElUniversidade.h"

class Universidade;

class ListaUniversidades
{
private:
	char nome[100];
	ElUniversidade* pElUnivI;
	ElUniversidade* pElUnivF;

public:
	// Construtora e Detrutora
	ListaUniversidades(const char* n = "");
	~ListaUniversidades();

	void setNome(char* n);
	char* getNome();

	void incluiUniv(Universidade* pu);
	void listaUnivs();

	Universidade* localizar(const char* n);
};